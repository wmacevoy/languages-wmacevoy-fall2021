#pragma once

#include "token.h"
#include <vector>
#include <iostream>
#include <memory>

class Scanner {
 public:
  typedef std::shared_ptr<Scanner> Ptr;
  virtual Token::Ptr next();
};

class MockScanner : public Scanner {
 public:
  std::vector < Token::Ptr > tokens;
  int at;
  MockScanner();
  MockScanner(const std::string &input);  
  virtual Token::Ptr next();  
};

#ifndef SCANNER_CPP
extern const std::string SCANNER_INPUT1;
extern const std::vector<Token::Ptr> SCANNER_RESULT1;

extern const std::string SCANNER_INPUT2;
extern const std::vector<Token::Ptr> SCANNER_RESULT2;
#endif

