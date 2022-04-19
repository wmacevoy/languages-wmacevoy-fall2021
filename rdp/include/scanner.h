#pragma once

#include "tokens.h"
#include <vector>
#include <iostream>
#include <memory>

class Scanner {
 public:
  virtual Token next();
};
typedef std::shared_ptr<Scanner> SPScanner;

class MockScanner : public Scanner {
 public:
  std::vector < Token > tokens;
  int at;
  MockScanner();
  MockScanner(const std::string &input);  
  MockScanner(const std::vector<Token> &_tokens);
  virtual Token next();  
};

#ifndef SCANNER_CPP
extern const std::string SCANNER_INPUT1;
extern const std::vector<Token> SCANNER_RESULT1;

extern const std::string SCANNER_INPUT2;
extern const std::vector<Token> SCANNER_RESULT2;
#endif



