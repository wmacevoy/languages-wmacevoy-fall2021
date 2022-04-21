# rdp

This is the infrastructure (thinking about how interepreters/compilers
are put together generally).  For a simple calculator with a store/recall
feature.

## structure

- token lexical tokens
- ast abstract syntax tree
- vm virtual machine
- scanner
- - mock scanner
- - real scanner
- parser
- - mock parser
- - real parser
- calc (in main_calc)

## references

JSON data is stored this way
https://github.com/nlohmann/json