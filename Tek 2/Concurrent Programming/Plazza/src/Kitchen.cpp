/*
** EPITECH PROJECT, 2023
** B-CCP-400-MPL-4-1-theplazza-enzo.daumalle
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include <memory>

using namespace Plazza;

Kitchen::Kitchen(double multiplier, int cooks, int refillTime) : _multiplier(multiplier), _cooksNumber(cooks), _refillTime(refillTime), _currentNbPizza(0)
{
    _messageQueue = mq_open(MESSAGE_QUEUE_NAME, O_RDWR | O_NONBLOCK);
    if (_messageQueue == -1) {
        perror("mq_open");
        return;
    }

    _ingredients.resize(9);
    _ingredients[ChiefLove] = 5;
    _ingredients[Dough] = 5;
    _ingredients[Eggplant] = 5;
    _ingredients[GoatCheese] = 5;
    _ingredients[Gruyere] = 5;
    _ingredients[Ham] = 5;
    _ingredients[Mushrooms] = 5;
    _ingredients[Steak] = 5;
    _ingredients[Tomato] = 5;
}

Kitchen::Kitchen() = default;

std::pair<PizzaType, PizzaSize> getPizzaType(std::string type, std::string size)
{
    PizzaType PType;
    PizzaSize PSize;
    if (type == "regina")
        PType = Regina;
    else if (type == "margarita")
        PType = Margarita;
    else if (type == "americana")
        PType = Americana;
    else if (type == "fantasia")
        PType = Fantasia;
        
    if (size == "S")
        PSize = S;
    else if (size == "M")
        PSize = M;
    else if (size == "L")
        PSize = L;
    else if (size == "XL")
        PSize = XL;
    else if (size == "XXL")
        PSize = XXL;
    return std::make_pair(PType, PSize);
}

bool Kitchen::checkIngredients(PizzaType type, int NbPizza) {
    if (type == Regina) {
        if (_ingredients[Dough] < 1 * NbPizza)
            return false;
        if (_ingredients[Tomato] < 1 * NbPizza)
            return false;
        if (_ingredients[Gruyere] < 1 * NbPizza)
            return false;
        if (_ingredients[Ham] < 1 * NbPizza)
            return false;
        if (_ingredients[Mushrooms] < 1 * NbPizza)
            return false;
    } else if (type == Margarita) {
        if (_ingredients[Dough] < 1 * NbPizza)
            return false;
        if (_ingredients[Tomato] < 1 * NbPizza)
            return false;
        if (_ingredients[Gruyere] < 1 * NbPizza)
            return false;
    } else if (type == Americana) {
        if (_ingredients[Dough] < 1 * NbPizza)
            return false;
        if (_ingredients[Tomato] < 1 * NbPizza)
            return false;
        if (_ingredients[Gruyere] < 1 * NbPizza)
            return false;
        if (_ingredients[Steak] < 1 * NbPizza)
            return false;
    } else if (type == Fantasia) {
        if (_ingredients[Dough] < 1 * NbPizza)
            return false;
        if (_ingredients[Tomato] < 1 * NbPizza)
            return false;
        if (_ingredients[Eggplant] < 1 * NbPizza)
            return false;
        if (_ingredients[GoatCheese] < 1 * NbPizza)
            return false;
        if (_ingredients[ChiefLove] < 1 * NbPizza)
            return false;
    }
    return true;
}

void Kitchen::removeIngredients(PizzaType type) {
    if (type == Regina) {
        _ingredients[Dough] -= 1;
        _ingredients[Tomato] -= 1;
        _ingredients[Gruyere] -= 1;
        _ingredients[Ham] -= 1;
        _ingredients[Mushrooms] -= 1;
    } else if (type == Margarita) {
        _ingredients[Dough] -= 1;
        _ingredients[Tomato] -= 1;
        _ingredients[Gruyere] -= 1;
    } else if (type == Americana) {
        _ingredients[Dough] -= 1;
        _ingredients[Tomato] -= 1;
        _ingredients[Gruyere] -= 1;
        _ingredients[Steak] -= 1;
    } else if (type == Fantasia) {
        _ingredients[Dough] -= 1;
        _ingredients[Tomato] -= 1;
        _ingredients[Eggplant] -= 1;
        _ingredients[GoatCheese] -= 1;
        _ingredients[ChiefLove] -= 1;
    }
}

void Kitchen::cookPizza(const std::string& message)
{
    std::istringstream iss(message);
    std::string type, size, quantity;
    if (!(iss >> type >> size >> quantity))
        return;

    // Cook the pizzas
    int numPizzas = std::stoi(quantity);

    std::pair<PizzaType, PizzaSize> pizzaType = getPizzaType(type, size);
    PizzaType PType = pizzaType.first;
    PizzaSize PSize = pizzaType.second;

    std::unique_ptr<APizza> pizza = std::make_unique<APizza>(PType, PSize, _multiplier);
    int pizzaId = _nextPizzaId++;
    _pizzas[pizzaId] = std::move(pizza);

    if (checkIngredients(PType, numPizzas) == false) {
        _pizzas[pizzaId]->setStatus("Cancelled : Not enough ingredients");
        std::cout << "Cancelled : Not enough ingredients" << std::endl;
        return;
    }

    int cookingTime = getCookingTime(type);
    _pizzas[pizzaId]->setStatus("Cooking");

    // Start the timer
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point end = start + std::chrono::seconds(cookingTime);

    // Update the status every second until the timer expires
    while (std::chrono::steady_clock::now() < end) {
        int remainingTime = std::chrono::duration_cast<std::chrono::seconds>(end - std::chrono::steady_clock::now()).count();
        _pizzas[pizzaId]->setStatus("Cooking (" + std::to_string(remainingTime) + "s remaining)");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    removeIngredients(PType);
    _pizzas[pizzaId]->setStatus("Cooked");

    std::lock_guard<std::mutex> lock(_mutex);
    _currentNbPizza -= numPizzas;
}

void Kitchen::createNewKitchen()
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    } else if (pid == 0) {
        Kitchen kitchen(_multiplier, _cooksNumber, _refillTime);
        kitchen.run();
        return;
    }
}

void Kitchen::responseStatus()
{
    std::cout << "------------------" << std::endl;
    displayStock();
    std::string response = "  Pizzas:\n";
    if (_pizzas.empty()) {
        response += "    No pizzas\n";
    }
    for (const auto& [id, pizza] : _pizzas) {
        response += "  - " + pizza->getTypeString() + " " + pizza->getSizeString() + " " + pizza->getStatus() + "\n";
    }
    std::cout << response << std::endl;
    std::cout << "------------------" << std::endl;
}

void Kitchen::startCooking()
{
    auto lastRefillTime = std::chrono::steady_clock::now();

    while (true) {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastRefillTime).count();

        if (elapsed >= _refillTime) {
            refill();
            lastRefillTime = now;
        }

        char buffer[MAX_MESSAGE_SIZE];
        ssize_t bytes_read;
        bytes_read = mq_receive(_messageQueue, buffer, MAX_MESSAGE_SIZE, NULL);
        if (bytes_read < 0) {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            continue;
        }
        buffer[bytes_read] = '\0';
        std::string message(buffer);

        if (message == "status") {
            responseStatus();
            continue;
        }
            
        std::istringstream iss(message);
        std::string type, size, quantity;
        if (!(iss >> type >> size >> quantity))
            continue;

        int numPizzas = std::stoi(quantity);

        while (numPizzas > 0) {
            if (isBusy()) { createNewKitchen(); }

            int pizzasToCook = std::min(numPizzas, _cooksNumber * 2 - _currentNbPizza);

            // Cook the pizzas in separate threads
            for (int i = 0; i < pizzasToCook; ++i) {
                std::thread t(&Kitchen::cookPizza, this, message);
                t.detach();

                std::lock_guard<std::mutex> lock(_mutex);
                _currentNbPizza++;
                numPizzas--;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void Kitchen::run()
{
    startCooking();
}

void Kitchen::refill()
{
    _ingredients[ChiefLove]   += 1;
    _ingredients[Dough]       += 1;
    _ingredients[Eggplant]    += 1;
    _ingredients[GoatCheese]  += 1;
    _ingredients[Gruyere]     += 1;
    _ingredients[Ham]         += 1;
    _ingredients[Mushrooms]   += 1;
    _ingredients[Steak]       += 1;
    _ingredients[Tomato]      += 1;
}

void Kitchen::displayStock()
{
    std::cout <<
        "  Stock:\n"
        "  - ChiefLove:     " << _ingredients[ChiefLove]  << std::endl <<
        "  - Dough:         " << _ingredients[Dough]      << std::endl <<
        "  - Eggplant:      " << _ingredients[Eggplant]   << std::endl <<
        "  - GoatCheese:    " << _ingredients[GoatCheese] << std::endl <<
        "  - Gruyere:       " << _ingredients[Gruyere]    << std::endl <<
        "  - Ham:           " << _ingredients[Ham]        << std::endl <<
        "  - Mushrooms:     " << _ingredients[Mushrooms]  << std::endl <<
        "  - Steak:         " << _ingredients[Steak]      << std::endl <<
        "  - Tomato:        " << _ingredients[Tomato]     << std::endl;
}

int Kitchen::getCookingTime(std::string type)
{
    if (type == "regina")
        return 2 * _multiplier;
    else if (type == "margarita")
        return 1 * _multiplier;
    else if (type == "americana")
        return 2 * _multiplier;
    else if (type == "fantasia")
        return 4 * _multiplier;
    return 0;
}