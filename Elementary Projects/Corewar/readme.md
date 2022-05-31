# Corewar
## Elementary Programming

*Good luck understanding the subject! 🥲*

Corewar is a game. A very special game.<br/>
It consists of pitting little programs against one another in a virtual
machine.<br/>
The goal of the game is to prevent the other programs from functioning correctly by using all available
means.<br/>
The game will, therefore, create a virtual machine in which the programs (written by the players) will face
off. Each program’s objective is to “survive”, that is to say executing a special instruction ("live") that means
I’m still alive. These programs simultaneously execute in the virtual machine and in the same memory zone,
which enables them to write on one another.
The winner of the game is the last one to have executed the "live" instruction.

- **The Virtual Machine**<br/>
    It houses the fighting binary programs (called champions), and provides them with a standard execution environment. It offers all kind of features that are useful to the champions’ fights. It must
    obviously be able to execute several programs at once.. .
- **The Assembler**<br/>
    It enables you to write programs designed to fight (the champions). It therefore understands the assembly language and generates binary programs that the virtual machine can execute.
- **Champions**<br/>
    This is your personal handiwork. They must be able to fight and to victoriously leave the virtual machine arena. They are written in the assembly language specific to our virtual machine (described
    further on).

# Part I - ASM
## Statistics

| Category                  | Percentages | Tests | Crash |
|---------------------------|-------------|-------|-------|
| ASM, Header               | 0%          | 0/3   | ✅     |
| ASM, Full header          | 0%          | 0/5   | ✅     |
| ASM, valid bytecode cases | 0%          | 0/18  | ❌     |
| ASM, invalid cases        | 100%        | 35/35 | ❌     |
| ASM, real champion        | 0%          | 0/5   | ❌     |
| **Total**                     | **53%**         | **35/66** | ✅     |

## Usage

```bash
  make re
  ./asm/asm <champion.s>
```
# Part II - Virtual Machine

*⚠️ The virtual machine part is corrected manually and is therefore not noted below*

## Usage

Battle up to 4 champions !

```bash
  make re
  ./corewar/corewar <champion.cor> <champion.cor> <champion.cor> <champion.cor>
```

### Bonus - Graphical Window

```bash
  cd bonus/
  make re
  ./bonus_corewar -g <champion.cor> <champion.cor> <champion.cor> <champion.cor>
```

<a href="https://zupimages.net/viewer.php?id=22/22/xd5k.png"><img src="https://zupimages.net/up/22/22/xd5k.png" alt="" /></a>
# Contributors

- [Lunnos](https://github.com/LunnosMp4) (Virtual Machine)
- [Hugo Eschlimann](https://github.com/HugoEschlimann) (ASM)
- [Doud Irow](https://github.com/0yco) (Virtual Machine)
- [Nico-coder-ui](https://github.com/Nico-coder-ui) (ASM)
