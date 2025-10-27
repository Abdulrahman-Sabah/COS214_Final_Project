
#include "Rose.h"
#include "CareScheduleObserver.h"
#include "BasicPlant.h"
#include "PlantDecorations.h"
#include <iostream>
#include <iomanip>
#include "PotDecorator.h"
#include "CardDecorator.h"
#include "WrapDecorator.h"

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

    cout << "=== PLANT DECORATOR PATTERN TEST ===\n" << endl;
    
    cout << "TEST 1: Basic Plant" << endl;
    cout << "-------------------" << endl;
    Plant* basicRose = new BasicPlant("Rose", "Beautiful red rose", 15.99);
    cout << "Description: " << basicRose->description() << endl;
    cout << "Price: $" << fixed << setprecision(2) << basicRose->price() << endl;
    cout << "Name: " << basicRose->getName() << endl;
    cout << endl;
    
    cout << "TEST 2: Plant with Pot Decorator" << endl;
    cout << "-------------------------------" << endl;
    Plant* potRose = new PotDecorator(basicRose, "Ceramic", 8.99);
    cout << "Description: " << potRose->description() << endl;
    cout << "Price: $" << potRose->price() << endl;
    cout << "Name: " << potRose->getName() << endl;
    cout << endl;
    
    cout << "TEST 3: Plant with Multiple Decorations" << endl;
    cout << "--------------------------------------" << endl;
    Plant* basicTulip = new BasicPlant("Tulip", "Yellow spring tulip", 12.50);
    Plant* tulipWithPot = new PotDecorator(basicTulip, "Terracotta", 6.50);
    Plant* tulipWithCard = new CardDecorator(tulipWithPot, "Get Well Soon!", 3.25);
    Plant* giftTulip = new WrapDecorator(tulipWithCard, "Gift Wrap", 4.75);
    
    cout << "Description: " << giftTulip->description() << endl;
    cout << "Price: $" << giftTulip->price() << endl;
    cout << "Name: " << giftTulip->getName() << endl;
    cout << endl;
    
    cout << "TEST 4: Different Decoration Combination" << endl;
    cout << "---------------------------------------" << endl;
    Plant* basicOrchid = new BasicPlant("Orchid", "Elegant white orchid", 25.00);
    Plant* orchidWithCard = new CardDecorator(basicOrchid, "Congratulations!", 3.25);
    Plant* wrappedOrchid = new WrapDecorator(orchidWithCard, "Premium Wrap", 7.50);
    
    cout << "Description: " << wrappedOrchid->description() << endl;
    cout << "Price: $" << wrappedOrchid->price() << endl;
    cout << endl;
    
    cout << "TEST 5: Cloning Decorated Plants" << endl;
    cout << "-------------------------------" << endl;
    Plant* clonedGiftTulip = giftTulip->clone();
    cout << "Original: " << giftTulip->description() << endl;
    cout << "Cloned:   " << clonedGiftTulip->description() << endl;
    cout << "Original Price: $" << giftTulip->price() << endl;
    cout << "Cloned Price:   $" << clonedGiftTulip->price() << endl;
    cout << "Clone successful: " << (giftTulip->price() == clonedGiftTulip->price() ? "YES" : "NO") << endl;
    cout << endl;
    
    cout << "TEST 6: Price Breakdown" << endl;
    cout << "----------------------" << endl;
    Plant* basic = new BasicPlant("Cactus", "Desert cactus", 8.00);
    cout << "Basic plant: $" << basic->price() << endl;
    
    Plant* withPot = new PotDecorator(basic, "Plastic", 3.00);
    cout << " + Pot: $" << withPot->price() << " (+$3.00)" << endl;
    
    Plant* withCard = new CardDecorator(withPot, "Happy Birthday", 2.50);
    cout << " + Card: $" << withCard->price() << " (+$2.50)" << endl;
    
    Plant* withWrap = new WrapDecorator(withCard, "Basic Wrap", 2.00);
    cout << " + Wrap: $" << withWrap->price() << " (+$2.00)" << endl;
    
    cout << "Total: $" << withWrap->price() << endl;
    cout << endl;
    
   
    
   
    
    cout << "CLEANUP" << endl;
    cout << "-------" << endl;
    delete potRose;           
    delete giftTulip;        
    delete wrappedOrchid;      
    delete clonedGiftTulip;   
    delete withWrap;          
    
    cout << "All plants deleted successfully!" << endl;
    
    return 0;
}
    
