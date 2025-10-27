#ifndef CUSTOMER_FACADE_H
#define CUSTOMER_FACADE_H

#include "Inventory.h"
#include "RoseBuilder.h"
#include "LavenderBuilder.h"
#include "CactusBuilder.h"

#include <vector>
#include <memory>
#include <string>

class CustomerFacade
{
    private:
        Inventory& inventory;
        std::vector<std::unique_ptr<Plant>> cart;

    public:
        void browsePlants() const;
        void addToCart(const std::string& name);
        void removeFromCart(const std::string& name);
        void viewCart() const;
        void checkout();
};

#endif