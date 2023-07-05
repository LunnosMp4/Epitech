THE PLAZZA

Usage:
    $> ./plazza cookingTime nCooks refillTime

    cookingTime:    Multiplier for the actual cooking time
    nCooks:         Amount of cooks per kitchen
    refillTime:     Time required for the kitchen to replace their ingredient stock, in milliseconds

ARCHITECTURE

    The projet is devided into different parts that are independant.

    The Core class, is meant to manage each part of the project together.

    The Kitchens, which contain their own ingredient stock and a fixed amount of cooks.

    The Cooks, whose job is to prepare the pizzas with the available ingredients of the kitchen.


CORE


KITCHENS

    Each kitchen runs on its own process.
    The amount of cooks they contain is defined by the nCooks parameter

    Kitchens should be automatically opened and closed by the core according to the needs of the Plazza in real time.

    The kitchen defines a macro for each ingredient, in order to manage them in a smooth way, and make a clean and readable code.
    (see ./src/Kitchen.hpp)

COOKS

    Each cook runs on their own thread

INGREDIENTS

    The ingredient class is defined by the IIngredients interface (located in ./src/ingredients)

    Each ingredient containts a 'std::string _type' constant reachable through the getType() public method.
    Each ingredient object actually represent a certain amount of ingredients of its type, represented by the 'int _units' variable.

    This _units variable can be decremented when an ingredient is consumed through the consumeUnit() public method.
    It can also be refilled to 5 units, when the kitchen calls the refill() public method.