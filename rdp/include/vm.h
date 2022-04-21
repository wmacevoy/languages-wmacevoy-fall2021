#pragma once

#include <stack>
#include <map>
#include "json.hpp"
#include "ast.h"

class VM {
 public:
  typedef std::map<std::string,nlohmann::json> Heap;
  typedef std::stack < nlohmann::json > Stack;
  

  Heap heap;
  VM();
  nlohmann::json run(AST::Ptr prog);
 private:
  void exec(AST::Ptr prog, Stack &stack);
};
