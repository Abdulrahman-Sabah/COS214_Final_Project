// API Client for C++ backend
class PlantNurseryAPI {
    constructor(baseURL = 'http://localhost:8081') {
        this.baseURL = baseURL;
    }

    async getPlants() {
        try {
            const response = await fetch(`${this.baseURL}/api/plants`);
            if (!response.ok) throw new Error('API not available');
            return await response.json();
        } catch (error) {
            console.log('API not available, using demo mode');
            return this.getDemoPlants();
        }
    }

    async addPlant(type) {
        try {
            const response = await fetch(`${this.baseURL}/api/add/${type}`, { 
                method: 'POST' 
            });
            return await response.json();
        } catch (error) {
            return { status: 'demo', message: 'Added in demo mode' };
        }
    }

    getDemoPlants() {
        return {
            plants: [
                { name: "Red Rose", careType: "Moderate", state: "Budding", season: "Spring", price: 45.99 },
                { name: "Aloe Vera", careType: "Low", state: "Mature", season: "Summer", price: 25.50 },
                { name: "Barrel Cactus", careType: "Low", state: "Young", season: "Summer", price: 35.00 },
                { name: "Lavender", careType: "Moderate", state: "Flowering", season: "Spring", price: 28.75 },
                { name: "Baobab Tree", careType: "High", state: "Seedling", season: "Year-round", price: 150.00 },
                { name: "Jade Plant", careType: "Low", state: "Mature", season: "Year-round", price: 32.00 },
                { name: "Peace Lily", careType: "Moderate", state: "Flowering", season: "Spring", price: 55.00 },
                { name: "Snake Plant", careType: "Low", state: "Mature", season: "Year-round", price: 40.00 }
            ]
        };
    }
}

// Plant class implementation
class Plant {
    constructor(name, careType, state, season, price) {
        this.name = name;
        this.careType = careType;
        this.state = state;
        this.season = season;
        this.plantPrice = price;
    }

    getName() { return this.name; }
    getCareType() { return this.careType; }
    getStateText() { return this.state; }
    getSeason() { return this.season; }
    price() { return this.plantPrice; }
    
    description() {
        return `${this.name} - A beautiful plant for your garden`;
    }

    getSprite() {
        const sprites = {
            'Red Rose': '🌹',
            'Aloe Vera': '🌵',
            'Barrel Cactus': '🌵',
            'Lavender': '💜',
            'Baobab Tree': '🌳',
            'Jade Plant': '🪴',
            'Peace Lily': '🌸',
            'Snake Plant': '🌿',
            'Rose': '🌹',
            'Cactus': '🌵'
        };
        return sprites[this.name] || '🌱';
    }
}

// Iterator implementation
class PlantIterator {
    constructor(plants) {
        this.plants = plants;
        this.currentIndex = 0;
    }

    first() { this.currentIndex = 0; }
    next() { if (!this.isDone()) this.currentIndex++; }
    prev() { if (this.currentIndex > 0) this.currentIndex--; }
    isDone() { return this.currentIndex >= this.plants.length; }
    current() { return this.isDone() ? null : this.plants[this.currentIndex]; }
    getPosition() { return this.currentIndex; }
    getTotal() { return this.plants.length; }
}

// Inventory class
class Inventory {
    constructor() {
        this.plants = [];
    }

    addPlant(plant) {
        if (plant) this.plants.push(plant);
    }

    removePlant(plant) {
        const index = this.plants.indexOf(plant);
        if (index > -1) {
            this.plants.splice(index, 1);
            return true;
        }
        return false;
    }

    getSize() { return this.plants.length; }
    
    createIterator() {
        return new PlantIterator(this.plants);
    }
}

// Main Application
class PlantNurseryApp {
    constructor() {
        this.api = new PlantNurseryAPI();
        this.inventory = new Inventory();
        this.basket = new Map(); // Map to store plant -> quantity
        this.selectedPlant = null;
        this.balance = 500.00;
        this.purchasedCount = 0;
        this.init();
    }

    async init() {
        await this.loadPlants();
        this.renderInventory();
    }

    async loadPlants() {
        try {
            const data = await this.api.getPlants();
            this.inventory.plants = data.plants.map(plantData => 
                new Plant(
                    plantData.name,
                    plantData.careType,
                    plantData.state,
                    plantData.season,
                    plantData.price || 0
                )
            );
            console.log('Loaded plants from server:', this.inventory.plants);
        } catch (error) {
            console.log('Using demo plants');
            this.loadDemoPlants();
        }
    }

    loadDemoPlants() {
        const demoPlants = [
            new Plant("Red Rose", "Moderate", "Budding", "Spring", 45.99),
            new Plant("Aloe Vera", "Low", "Mature", "Summer", 25.50),
            new Plant("Barrel Cactus", "Low", "Young", "Summer", 35.00),
            new Plant("Lavender", "Moderate", "Flowering", "Spring", 28.75),
            new Plant("Baobab Tree", "High", "Seedling", "Year-round", 150.00),
            new Plant("Jade Plant", "Low", "Mature", "Year-round", 32.00),
            new Plant("Peace Lily", "Moderate", "Flowering", "Spring", 55.00),
            new Plant("Snake Plant", "Low", "Mature", "Year-round", 40.00)
        ];
        
        demoPlants.forEach(plant => this.inventory.addPlant(plant));
    }

    renderInventory() {
        const grid = document.getElementById('plant-grid');
        if (!grid) {
            console.error('plant-grid element not found');
            return;
        }
        grid.innerHTML = '';

        const iterator = this.inventory.createIterator();
        let currentPosition = 0;
        let selectedPosition = -1;
        
        for (iterator.first(); !iterator.isDone(); iterator.next()) {
            const plant = iterator.current();
            if (plant) {
                const card = this.createPlantCard(plant);
                grid.appendChild(card);
                
                // Track position of selected plant
                if (plant === this.selectedPlant) {
                    selectedPosition = currentPosition;
                }
                currentPosition++;
            }
        }

        // Update iterator display with selected plant position
        if (selectedPosition !== -1) {
            this.updateIteratorDisplay(selectedPosition);
        } else {
            this.updateIteratorDisplay(0);
        }
        
        this.updateStats();
    }

    createPlantCard(plant) {
        const card = document.createElement('div');
        card.className = 'plant-card';
        if (plant === this.selectedPlant) card.classList.add('selected');

        card.innerHTML = `
            <div class="season-badge">${plant.getSeason()}</div>
            <div class="plant-sprite">${plant.getSprite()}</div>
            <div class="plant-name">${plant.getName()}</div>
            <div class="plant-price">R${plant.price().toFixed(2)}</div>
            <div class="plant-info">${plant.getCareType()} Care</div>
        `;

        card.addEventListener('click', () => this.selectPlant(plant));
        return card;
    }

    selectPlant(plant) {
        this.selectedPlant = plant;
        
        // Find the index of the selected plant for iterator display
        const iterator = this.inventory.createIterator();
        let currentPosition = 0;
        let found = false;
        
        for (iterator.first(); !iterator.isDone(); iterator.next()) {
            if (iterator.current() === plant) {
                found = true;
                break;
            }
            currentPosition++;
        }
        
        this.renderInventory();
        this.renderPlantDetails(plant);
        
        // Update iterator display with correct position
        this.updateIteratorDisplay(currentPosition);
    }

    // Update the iterator display method
    updateIteratorDisplay(currentPosition) {
        const iteratorPos = document.getElementById('iterator-pos');
        const iteratorTotal = document.getElementById('iterator-total');
        
        if (iteratorPos && iteratorTotal) {
            iteratorPos.textContent = currentPosition + 1;
            iteratorTotal.textContent = this.inventory.getSize();
        }
    }

    renderPlantDetails(plant) {
        const detailsDiv = document.getElementById('plant-details');
        if (!detailsDiv) return;
        
        detailsDiv.innerHTML = `
            <div class="plant-detail">
                <div class="detail-sprite">${plant.getSprite()}</div>
                <div class="detail-row">
                    <span class="detail-label">Name:</span>
                    <span class="detail-value">${plant.getName()}</span>
                </div>
                <div class="detail-row">
                    <span class="detail-label">Price:</span>
                    <span class="detail-value">R${plant.price().toFixed(2)}</span>
                </div>
                <div class="detail-row">
                    <span class="detail-label">Care Level:</span>
                    <span class="detail-value">${plant.getCareType()}</span>
                </div>
                <div class="detail-row">
                    <span class="detail-label">State:</span>
                    <span class="detail-value">${plant.getStateText()}</span>
                </div>
                <div class="detail-row">
                    <span class="detail-label">Season:</span>
                    <span class="detail-value">${plant.getSeason()}</span>
                </div>
            </div>
        `;
    }

    browseNext() {
        if (!this.selectedPlant || this.inventory.getSize() === 0) return;

        const iterator = this.inventory.createIterator();
        let found = false;
        
        for (iterator.first(); !iterator.isDone(); iterator.next()) {
            if (found) {
                this.selectPlant(iterator.current());
                return;
            }
            if (iterator.current() === this.selectedPlant) {
                found = true;
            }
        }
        
        // Wrap around to first plant
        iterator.first();
        if (!iterator.isDone()) {
            this.selectPlant(iterator.current());
        }
    }

    // BASKET FUNCTIONALITY
    addToBasket(plant) {
        if (!plant) {
            this.showNotification("Please select a plant first!", "error");
            return;
        }
        
        const currentQuantity = this.basket.get(plant) || 0;
        this.basket.set(plant, currentQuantity + 1);
        
        this.updateBasketDisplay();
        this.showNotification(`Added ${plant.getName()} to basket! 🛒`);
    }

    removeFromBasket(plant) {
        if (!plant || !this.basket.has(plant)) return;
        
        const currentQuantity = this.basket.get(plant);
        if (currentQuantity > 1) {
            this.basket.set(plant, currentQuantity - 1);
        } else {
            this.basket.delete(plant);
        }
        
        this.updateBasketDisplay();
        this.showNotification(`Removed ${plant.getName()} from basket`);
    }

    // Calculate basket total
    getBasketTotal() {
        let total = 0;
        for (const [plant, quantity] of this.basket) {
            total += plant.price() * quantity;
        }
        return total;
    }

    // Get total quantity in basket
    getBasketQuantity() {
        let total = 0;
        for (const quantity of this.basket.values()) {
            total += quantity;
        }
        return total;
    }

    // Update basket display
    updateBasketDisplay() {
        const basketCount = document.getElementById('basket-count');
        const basketTotal = document.getElementById('basket-total');
        
        if (basketCount) basketCount.textContent = this.getBasketQuantity();
        if (basketTotal) basketTotal.textContent = `R${this.getBasketTotal().toFixed(2)}`;
    }

    purchaseBasket() {
        const total = this.getBasketTotal();
        if (total === 0) {
            this.showNotification("Basket is empty!", "error");
            return;
        }

        if (this.balance < total) {
            this.showNotification("Insufficient funds!", "error");
            return;
        }

        this.balance -= total;
        this.purchasedCount++;
        this.showNotification(`Purchased basket for R${total.toFixed(2)}! 🎉`);

        // Clear basket after purchase
        this.basket.clear();
        this.updateBasketDisplay();
        this.updateStats();
    }

    updateStats() {
        const inventoryCount = document.getElementById('inventory-count');
        const balance = document.getElementById('balance');
        const purchasedCount = document.getElementById('purchased-count');
        
        if (inventoryCount) inventoryCount.textContent = this.inventory.getSize();
        if (balance) balance.textContent = `R${this.balance.toFixed(2)}`;
        if (purchasedCount) purchasedCount.textContent = this.purchasedCount;
        
        this.updateBasketDisplay();
    }

    showNotification(message, type = 'success') {
        const notification = document.createElement('div');
        notification.className = `notification ${type}`;
        notification.textContent = message;
        document.body.appendChild(notification);

        setTimeout(() => {
            notification.remove();
        }, 3000);
    }
}

// Initialize app - make it global
let app;

document.addEventListener('DOMContentLoaded', () => {
    app = new PlantNurseryApp();
});