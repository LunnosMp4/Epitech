# 42sh

## Unix System

You must write a Unix SHELL.<br/>
The project consists of two sections:
- a mandatory section, which MUST be completed: display a prompt, parse and execute some commands (see below),
- an optional section, which will only be evaluated if the mandatory section is fully functionnal.
Authorized functions: all functions included in the libC or the ncurses library.

#### MANDATORY SECTION 
------------------

This section must be COMPLETELY FUNCTIONAL. Otherwise your grade will be 0.<br/>
Concerning command parsing and execution, you must handle:
    • spaces and tabs,<br/>
    • $PATH and environment,<br/>
    • errors and return value,<br/>
    • redirections (‘<’, ‘>’, ‘<<’ and ‘>>’),<br/>
    • pipes (‘|’),<br/>
    • builtins: cd, echo, exit, setenv, unsetenv,<br/>
    • separators: ‘;’, ‘&&’, ‘||’.<br/>
    For instance, you should be able to execute the following command

```bash
    ./42sh
    42sh> cd ; </etc/hosts od -c | grep xx | wc >> /tmp/z -l ; cd - && echo “OK”
```
#### OPTIONAL SECTION 
------------------

Here is a list of desired extras:<br/>
    • inhibitors (‘\’),<br/>
    • globbings (‘*’, ‘?’, ‘[’, ’]’),<br/>
    • job control (‘&’, fg),<br/>
    • backticks (“’),<br/>
    • parentheses (‘(’ and ‘)’),<br/>
    • variables (local and env),<br/>
    • special variables (term, precmd, cwdcmd, cwd, ignoreof for instance),<br/>
    • history (‘!’),<br/>
    • aliases,<br/>
    • line edition (multiline, dynamic rebinding, auto-completion dynamic,<br/>
    • scripting (a bit harsh though).<br/>
## Statistics

| Category                         | Percentages | Tests | Crash |
|----------------------------------|-------------|-------|-------|
| Basics tests                     | 100%        | 4/4   | ❌     |
| Path handling                    | 60%         | 3/5   | ❌     |
| Setenv and unsetenv              | 100%        | 2/2   | ❌     |
| Builtin cd                       | 66%         | 2/3   | ❌     |
| Line formatting (space and tabs) | 100%        | 8/8   | ❌     |
| Error handling                   | 66%         | 4/6   | ❌     |
| Separator                        | 100%        | 1/1   | ❌     |
| Simple pipe                      | 33%         | 1/3   | ❌     |
| Advanced pipe                    | 50%         | 3/6   | ❌     |
| Redirections                     | 80%         | 4/5   | ❌     |
| Advanced manipulations           | 33%         | 1/3   | ❌     |
| && and \|\| tests                | 0%          | 0/3   | ❌     |
| Globbing                         | 0%          | 0/1   | ❌     |
| Var interpreter                  | 0%          | 0/3   | ❌     |
| Inhibitor                        | 0%          | 0/2   | ❌     |
| Magic quote                      | 33%         | 1/3   | ❌     |
| Alias                            | 75%         | 3/4   | ❌     |
| Scripting                        | 0%          | 0/1   | ❌     |
| Foreach                          | 0%          | 0/1   | ❌     |
| Which                            | 0%          | 0/2   | ❌     |
| Where                            | 0%          | 0/2   | ❌     |
| If                               | 0%          | 0/2   | ❌     |
| Repeat                           | 0%          | 0/1   | ❌     |
| Parenthesis                      | 0%          | 0/1   | ❌     |
| **Total**                            | **51%**         | **37/72** | ❌     |

## Usage

```bash
  make re
  ./42sh
```
<br/>
With an animation at launch !

```bash
  make re
  ./42sh -g 
```

## Contributors

- [Lunnos](https://github.com/LunnosMp4)
- [0yco](https://github.com/0yco)
- [NickSpyker](https://github.com/NickSpyker)
- [Thorf1nn](https://github.com/Thorf1nn)
- [Alexia](https://github.com/alexia7)
