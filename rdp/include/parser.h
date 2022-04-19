#pragma once

#include "json.hpp"
#include "scanner.h"

class Parser {
  SPScanner scanner;
 public:
  virtual void setScanner(SPScanner scanner);
  virtual nlohmann::json parse();
};
typedef std::shared_ptr<Parser> SPParser;

class MockParser : public Parser {
 public:
  nlohmann::json ast;
  virtual void setScanner(SPScanner scanner);
  virtual nlohmann::json parse();
};


