#ifndef PLANT_H
#define PLANT_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

// #include "CareStrategy.h"
// #include "PlantLifeCycleState.h"
// #include "Observer.h"

class Plant {   
private:
	std::string name;

	std::string careType;

	std::string state;

	std::string season;

    // CareStrategy* careStrategy;

    // PlantLifeCycleState* lifeCycleState;
    
    // std::vector<Plant*> plants;

public:
	Plant(std::string n, std::string c, std::string s, std::string se, CareStrategy* strategy, PlantLifeCycleState* life);

    virtual ~Plant();

    virtual Plant* clone() = 0;

	std::string getName();

	std::string getCareType();

	std::string getStateText();

	std::string getSeason();

    // CareStrategy* getCareStrategy();

    // PlantLifeCycleState* getLifeCycleState();

    // std::vector<Plant*> getPlants();

	void setName(std::string n);

	void setCareType(std::string t);

	void setStateText(std::string s);

	void setSeason(std::string s);

    // void setCareStrategy(CareStrategy* cs);

    // void setLifeCycle(PlantLifeCycleState* st);

    // void setState(PlantLifeCycleState* s);

    // void setPlants(std::list<Plant*> p);

	void show();

    // void addObserver(IObserver* o);

	Plant* findById(std::string id);

	void registerPlant(Plant* p);

	void notify();

    // void removeObserver(IObserver* o);

	void advanceLifeCycle();

	bool removeById(std::string id);

	size_t count();

	void applyCare();

	// std::list<Plant*> all();

	bool readyForSale();

	bool needsAttention();
};

#endif
