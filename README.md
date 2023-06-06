# 42sh

This project consists in creating a zsh-like in C language considered UNIX (and POSIX) standard.

# Usage
```
make re
./42sh
```

# Features
---
- [x] Builtins
	- [x] cd [directory]
	- [x] echo [str...]
	- [x] exit [n]
	- [x] env
	- [x] setenv [name] [value]
	- [x] unsetenv
	- [x] unset [-fv] name...
	- [x] history
	- [x] ![n | str]
- [x] Execution
	- [x] Execution of commands with their parameters and PATH management.
	- [x] Management of errors and the return value of commands.
	- [x] The following redirects: ">", "<<", ">>", "<".
	- [x] Pipes “|”.
	- [x] The logical operators "&&" and "||".
	- [x] The ";" separator.
- [x] Signals
	- [x] ctrl+D
	- [x] ctrl+C
- [x] Bonuses
	- [x] The "<<" heredoc.
	- [x] Colours.
	- [x] Variables.
	- [x] Aliases.
	- [x] History.
