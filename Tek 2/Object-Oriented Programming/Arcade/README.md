# 🕹️ Arcade

This project is a game engine that supports multiple games and graphical libraries.

This project will only work on Linux environments.

---

### 🚀 Getting Started

To build the project, run the following command:

```bash
make
```

This will compile the source code and generate the game binaries.
To launch the Arcade, run the following command:

```bash
./arcade lib/arcade_sdl2.so
```

The first argument is the graphical library to use per default.
You can change the graphical library at runtime by choosing one from the menu.

You can use any graphical library or game library (while ingame) that is located in the `lib` directory.

---

### 📘 How to create a new Library

You are free to create your own graphical or game library, as long as it follows the following rules:

- The library must be a shared object (`.so` file)
- The library must be located in the `lib` directory
- The library must implement the `IGraphical` or `IGame` interface
- The library must be compiled with the `-fPIC` flag

---

### 🎮 How to create a new Game Library
In order to create a new game library, you must implement the `IGame` interface.

The `IGame` interface is defined in the `IGame.hpp` file.

The `IGame` interface contains the following methods:

- `void init(IGraphical *graphical, std::string playerName);`
- `void update();`
- `void handleInput(Input input);`
- `void render() const;`
- `std::string getName() const;`
- `unsigned int getCurrentScore() const;`
- `unsigned int getHighScore() const;`
- `void setState(GameState state);`
- `GameState getState() const;`

The `init` method is called when the game is loaded.
It is used to initialize the game.

The `update` method is called every frame.
It is used to update the game state.

The `handleInput` method is called every frame.
It is used to handle the user input.

The `render` method is called every frame.
It is used to render the game.

The `getName` method is used to get the name of the game.

The `getCurrentScore` method is used to get the current score of the game.

The `getHighScore` method is used to get the high score of the game.

The `setState` method is used to set the state of the game.

The `getState` method is used to get the state of the game.

The `GameState` enum is defined in the `IGame.hpp` file.

The `GameState` enum contains the following values:

- `GameState::RUNNING`
- `GameState::PAUSED`
- `GameState::GAME_OVER`
- `GameState::WIN`

The `Input` enum is defined in the `Utils.hpp` file.

The `Input` enum contains the following values:

- `Input::UP`
- `Input::DOWN`
- `Input::LEFT`
- `Input::RIGHT`
- `Input::A`
- `Input::E`
- `Input::Q`
- `Input::S`
- `Input::Z`
- `Input::D`
- `Input::SPACE`
- `Input::ESCAPE`
- `Input::BACKSPACE`
- `Input::ENTER`

---

### 🎨 How to create a new Graphical Library

In order to create a new graphical library, you must implement the `IGraphical` interface.

The `IGraphical` interface is defined in the `IGraphical.hpp` file.

The `IGraphical` interface contains the following methods:

- `void createWindow(unsigned int width, unsigned int height, const std::string &title);`
- `void destroyWindow();`
- `void clear() const;`
- `void refresh() const;`
- `void display() const`
- `void drawRectangle(Vector2f pos, Vector2f size, Color color) const;`
- `void drawCircle(Vector2f pos, float radius, Color color) const;`
- `void drawText(Vector2f pos, const std::string &text, unsigned int size, Color color) const;`
- `void drawSprite(Vector2f pos, const std::string &path) const;`
- `bool isOpen() const;`
- `Input getInput() const;`

The `createWindow` method is used to create a window.

The `destroyWindow` method is used to destroy a window.

The `clear` method is used to clear the window.

The `refresh` method is used to refresh the window.

The `display` method is used to display the window.

The `drawRectangle` method is used to draw a rectangle.

The `drawCircle` method is used to draw a circle.

The `drawText` method is used to draw text.

The `drawSprite` method is used to draw a sprite.

The `isOpen` method is used to check if the window is open.

The `getInput` method is used to get the user input.

The `Vector2f` struct is defined in the `Utils.hpp` file.

The `Vector2f` struct contains the following attributes:

- `float x`
- `float y`

The `Color` enum is defined in the `Utils.hpp` file.

The `Color` enum contains the following values:

- `Color::BLACK`
- `Color::RED`
- `Color::GREEN`
- `Color::YELLOW`
- `Color::BLUE`
- `Color::MAGENTA`
- `Color::CYAN`
- `Color::WHITE`
- `Color::TRANSPARENT`

Its highly recommended to create an Exception class that inherits from the `std::runtime_error` class.

This class will be used to throw exceptions when an error occurs.

### Authors

- Loïc Tisseyre (loic.tisseyre@epitech.eu)
- Enzo Daumalle (enzo.daumalle@epitech.eu)
- William Andreo (william.andreo@epitech.eu)

Pair group :

- Edgar Falcou (edgar.falcou@epitech.eu)
- Maxime Santos (maxime.santos@epitech.eu)
- Nicolas Lefèvre (nicolas.lefevre@epitech.eu)
- Lysandra Manuguerra (lysandra.manuguerra@epitech.eu)