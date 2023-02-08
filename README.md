# Project 1: Mini Unix Utilities
Vivian Duong, Emily Lim, Robert Panerio

## my-cat
Reads input file(s) and prints its contents.

### How to run:
- cd into project folder
- run `make my-cat`
- run `./my-cat [file] ...`


## my-sed
Finds and replaces a word with another word and prints the result. Will only replace the first instance of the word in each line. If no file is given, the program finds and replaces using words read from standard input.

### How to run:
- cd into project folder
- run `make my-sed`
- run `./my-sed find_term replace_term [file ...]`


## my-uniq
Finds adjacent duplicate lines in the input file(s) and prints them.

### How to run:
- cd into project folder
- run `make my-uniq`
- run `./my-uniq [file] ...`