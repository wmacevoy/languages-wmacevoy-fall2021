#pragma once

#include "json.hpp"
#include "ast.h"
#include "scanner.h"


class Parser {
  Scanner::Ptr scanner;
 public:
  typedef std::shared_ptr<Parser> Ptr;
  static Ptr mock();
  static Ptr real();
  virtual void setScanner(Scanner::Ptr _scanner);
  virtual Scanner::Ptr getScanner() const;
  virtual AST::Ptr parse();
};

#ifndef PARSER_CPP
extern const AST::Ptr PARSER_RESULT1;
extern const AST::Ptr PARSER_RESULT2;
#endif

