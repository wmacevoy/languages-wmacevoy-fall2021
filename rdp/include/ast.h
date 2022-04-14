#pragma once

#include <string>
#include <function>
#include "json.hpp"

#include "token.h"
#include "vm.h"

enum ASTType { literal,store,recall,binary,unary };

std::string ASTTypeToJSON(enum ASTType astType);
enum ASTType JSONToASTType(const std::string &jsonASTType);

class AST;
std::shared_ptr<AST> ASTP;

class AST { 
public:
  std::function<void(VM &vm, ASTP &node)> eval;
  static ASTP base(ASTType type, int line, int col);
  static ASTP literal(const Token &literal);
  static ASTP store(const Token &store);
  static ASTP recall(const Token &recall);
  static ASTP add(const Token &recall);
  AST();
  AST(const nlohmann::json &json);
  const nlohmann::json &toJSON() const;
  ASTType getType() const;
private:
  nlohmann::json obj;
};


