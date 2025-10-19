#ifndef SELLINGSTATE_H
#define SELLINGSTATE_H

#include "PlantLifeCycleState.h"

class SellingState : public PlantLifeCycleState {
public:
    SellingState();

    ~SellingState() override;

    void advance(Plant* plant) override;

    std::string name() override;

    void enter(Plant* plant);

	void exit(Plant* plant);

	bool needsAttention(Plant* plant);

    bool canSell() override;
};

#endif
