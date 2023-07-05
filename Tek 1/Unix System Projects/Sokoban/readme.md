# My Sokoban
## Unix System

Sokoban (warehouse keeper in Japanese) is a type of transport puzzle, in which
the player pushes boxes or crates around in a warehouse, trying to get them to
storage locations.
The puzzle is usually implemented as a video game.
Sokoban was created in 1981 by Hiroyuki Imabayashi, and published in 1982 by
Thinking Rabbit, a software house based in Takarazuka, Japan.

The game is played on a board of squares, where each square is a floor or
a wall. Some floor squares contain boxes, and some floor squares are marked as
storage locations. The player is confined to the board, and may move
horizontally or vertically onto empty squares (never through walls or boxes).
The player can also move into a box, which pushes it into the square beyond.
Boxes may not be pushed into other boxes or walls, and they cannot be pulled.
The puzzle is solved when all boxes are at storage locations.

This project was done in C using the Ncurses library



## Statistics

| Category                                    | Percentages | Tests | Crash |
|---------------------------------------------|-------------|-------|-------|
| Usage and input check                       | 100%        | 4/4   | ❌     |
| Basic moves                                 | 100%        | 4/4   | ❌     |
| Basic collisions and box on targets         | 100%        | 4/4   | ❌     |
| Intermediate moves and collisions           | 100%        | 6/6   | ❌     |
| Intermediate maps tests                     | 100%        | 4/4   | ❌     |
| Intermediate Winning and losing condiitions | 50%         | 1/2   | ❌     |
| Final moves and collisions                  | 100%        | 6/6   | ❌     |
| Final maps tests                            | 100%        | 4/4   | ❌     |
| final winning and losing conditions         | 50%         | 1/2   | ❌     |
| Total                                       | **95%**         | **34/36** | ❌     |

## Usage

```bash
  make re
  ./sokoban maps/map1.txt
```
## Contributors

- [Lunnos](https://github.com/LunnosMp4)
