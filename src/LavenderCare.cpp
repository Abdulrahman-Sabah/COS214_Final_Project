#include "LavenderCare.h"
#include "Plant.h"

void LavenderCare::applyCare(Plant *plant) {
  std::cout << plant->getName()
            << " is being watered regularly, keeping the soil consistently "
               "moist but not soggy."
            << std::endl;
  std::cout << plant->getName()
            << " is now being placed in full sun to partial shade, depending "
               "on the variety."
            << std::endl;
  std::cout << plant->getName()
            << " is being potted in fertile, well-drained soil enriched with "
               "organic matter."
            << std::endl;
}