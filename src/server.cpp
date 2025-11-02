#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#else
#include <dirent.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

// Include your existing classes
#include "Cactus.h"
#include "Inventory.h"
#include "InventorySerializer.h"
#include "Lavender.h"
#include "Plant.h"
#include "Rose.h"

class PlantNurseryServer {
private:
  Inventory inventory; // Local inventory for the server

public:
  PlantNurseryServer() {
    // Load from file at startup
    InventorySerializer::loadFromFile(inventory, "inventory_state.json");
    std::cout << "Server loaded " << inventory.getSize()
              << " plants from file\n";
  }

  bool start(int port = 8081) {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
      std::cerr << "Failed to initialize Winsock" << std::endl;
      return false;
    }
#endif

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
      std::cerr << "Failed to create socket" << std::endl;
      return false;
    }

    // Allow socket reuse
    int opt = 1;
#ifdef _WIN32
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
               sizeof(opt));
#else
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
#endif

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (bind(serverSocket, (sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
      std::cerr << "Failed to bind to port " << port << std::endl;
#ifdef _WIN32
      closesocket(serverSocket);
      WSACleanup();
#else
      close(serverSocket);
#endif
      return false;
    }

    if (listen(serverSocket, 10) < 0) {
      std::cerr << "Failed to listen on socket" << std::endl;
#ifdef _WIN32
      closesocket(serverSocket);
      WSACleanup();
#else
      close(serverSocket);
#endif
      return false;
    }

    std::cout << "Plant Nursery Server running on http://localhost:" << port
              << std::endl;
    std::cout << "Serving files from: gui/" << std::endl;
    handleRequests(serverSocket);

#ifdef _WIN32
    closesocket(serverSocket);
    WSACleanup();
#else
    close(serverSocket);
#endif

    return true;
  }

  void handleRequests(int serverSocket) {
    while (true) {
      sockaddr_in clientAddr;
#ifdef _WIN32
      int clientLen = sizeof(clientAddr);
#else
      socklen_t clientLen = sizeof(clientAddr);
#endif

      int clientSocket =
          accept(serverSocket, (sockaddr *)&clientAddr, &clientLen);
      if (clientSocket < 0) {
        std::cerr << "Failed to accept connection" << std::endl;
        continue;
      }

      char buffer[4096];
      int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
      if (bytesRead > 0) {
        buffer[bytesRead] = '\0';
        std::string request(buffer);
        std::string response = handleHTTPRequest(request);
        send(clientSocket, response.c_str(), response.length(), 0);
      }

#ifdef _WIN32
      closesocket(clientSocket);
#else
      close(clientSocket);
#endif
    }
  }

  std::string handleHTTPRequest(const std::string &request) {
    std::cout << "Request: " << request.substr(0, request.find('\n'))
              << std::endl;

    // Serve inventory_state.json file directly
    if (request.find("GET /inventory_state.json") != std::string::npos) {
      return serveFile("inventory_state.json", "application/json");
    }

    // API Routes
    if (request.find("GET /api/plants") != std::string::npos) {
      return getPlantsJSON();
    }
    if (request.find("POST /api/add/rose") != std::string::npos) {
      inventory.addPlant(new Rose());
      return "HTTP/1.1 200 OK\r\nContent-Type: "
             "application/json\r\nAccess-Control-Allow-Origin: "
             "*\r\n\r\n{\"status\":\"success\",\"message\":\"Rose added\"}";
    }
    if (request.find("POST /api/add/cactus") != std::string::npos) {
      inventory.addPlant(new Cactus());
      return "HTTP/1.1 200 OK\r\nContent-Type: "
             "application/json\r\nAccess-Control-Allow-Origin: "
             "*\r\n\r\n{\"status\":\"success\",\"message\":\"Cactus added\"}";
    }
    if (request.find("POST /api/add/lavender") != std::string::npos) {
      inventory.addPlant(new Lavender());
      return "HTTP/1.1 200 OK\r\nContent-Type: "
             "application/json\r\nAccess-Control-Allow-Origin: "
             "*\r\n\r\n{\"status\":\"success\",\"message\":\"Lavender added\"}";
    }
    if (request.find("POST /api/care/") != std::string::npos) {
      return "HTTP/1.1 200 OK\r\nContent-Type: "
             "application/json\r\nAccess-Control-Allow-Origin: "
             "*\r\n\r\n{\"status\":\"success\",\"message\":\"Plant cared "
             "for\"}";
    }
    if (request.find("POST /api/remove/") != std::string::npos) {
      return "HTTP/1.1 200 OK\r\nContent-Type: "
             "application/json\r\nAccess-Control-Allow-Origin: "
             "*\r\n\r\n{\"status\":\"success\",\"message\":\"Plant removed\"}";
    }

    // Serve GUI files
    if (request.find("GET / ") != std::string::npos ||
        request.find("GET /index.html") != std::string::npos) {
      return serveFile("gui/index.html", "text/html");
    }
    if (request.find("GET /style.css") != std::string::npos) {
      return serveFile("gui/style.css", "text/css");
    }
    if (request.find("GET /script.js") != std::string::npos) {
      return serveFile("gui/script.js", "application/javascript");
    }
    if (request.find("GET /inventory_state.json") != std::string::npos) {
      return serveFile("inventory_state.json", "application/json");
    }

    // Default to index.html
    return serveFile("gui/index.html", "text/html");
  }

  std::string getPlantsJSON() {
    std::stringstream json;
    json << "HTTP/1.1 200 OK\r\nContent-Type: "
            "application/json\r\nAccess-Control-Allow-Origin: *\r\n\r\n";
    json << "{\"plants\":[";

    PlantIterator *it = inventory.createIterator();
    bool first = true;

    for (it->first(); !it->isDone(); it->next()) {
      Plant *plant = it->current();
      if (plant) {
        if (!first)
          json << ",";
        json << "{";
        json << "\"name\":\"" << plant->getName() << "\",";
        json << "\"careType\":\"" << plant->getCareType() << "\",";
        json << "\"state\":\"" << plant->getStateText() << "\",";
        json << "\"season\":\"" << plant->getSeason() << "\",";
        json << "\"price\":" << plant->price();
        json << "}";
        first = false;
      }
    }

    delete it;
    json << "]}";

    std::cout << "Sent " << inventory.getSize() << " plants from file\n";
    return json.str();
  }

  std::string serveFile(const std::string &filename,
                        const std::string &contentType) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
      std::cerr << "File not found: " << filename << std::endl;
      return "HTTP/1.1 404 Not Found\r\n\r\nFile not found: " + filename;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string response = "HTTP/1.1 200 OK\r\nContent-Type: " + contentType +
                           "\r\n\r\n" + buffer.str();
    std::cout << "Served: " << filename << " (" << buffer.str().length()
              << " bytes)" << std::endl;
    return response;
  }
};

int main() {
  std::cout << "Starting Plant Nursery Server..." << std::endl;

  PlantNurseryServer server;
  if (!server.start(8081)) {
    std::cerr << "Failed to start server!" << std::endl;
    return 1;
  }

  return 0;
}