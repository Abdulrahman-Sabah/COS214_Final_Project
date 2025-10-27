
#include "Rose.h"
#include "CareScheduleObserver.h"
#include <iostream>

using namespace std;

int main() {
    cout << "=== PLANT OBSERVER PATTERN TEST ===" << endl;
    cout << "Creating a rose plant..." << endl;
    
    Rose* rose = new Rose();
    
    CareSchedulerObserver* scheduler = new CareSchedulerObserver();
    
    cout << "\nAttaching CareSchedulerObserver to the rose..." << endl;
    rose->attach(scheduler);
    
    cout << "\n--- Testing Notifications ---" << endl;
    
    cout << "\n1. Changing plant state:" << endl;
    rose->setStateText("Flowering");
    
    cout << "\n2. Changing season:" << endl;
    rose->setSeason("Summer");
    
    cout << "\n3. Changing care type:" << endl;
    rose->setCareType("High");
    
    cout << "\n4. Changing name (no observer for this):" << endl;
    rose->setName("Red Rose");
    cout << "Name changed to: " << rose->getName() << " (no notification expected)" << endl;
    
    cout << "\n5. Detaching observer and making changes:" << endl;
    rose->detach(scheduler);
    rose->setStateText("Mature");
    cout << "State changed to Mature (no notification expected - observer detached)" << endl;
    
    cout << "\n6. Re-attaching observer:" << endl;
    rose->attach(scheduler);
    rose->setSeason("Autumn");
    
    cout << "\n--- Testing Plant Information ---" << endl;
    cout << "Plant Description: " << rose->description() << endl;
    cout << "Plant Price: $" << rose->price() << endl;
    
    cout << "\n=== CLEANUP ===" << endl;
    delete rose;
    delete scheduler;
    
    cout << "Test completed successfully!" << endl;
    
    return 0;
}
