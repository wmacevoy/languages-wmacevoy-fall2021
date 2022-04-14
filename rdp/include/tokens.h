
#pragma once

#include <string>
#include "json.hpp"

enum TokenType { 
    identifier,keyword,number,
    add,sub,times,divide, 
    lparen, rparen,eof,unrecognized 
};

std::string TokenTypeToJSON(enum TokenType tokenType);
enum TokenType JSONToTokenType(const std::string &jsonTokenType);

class Token { 
public:
  static Token base(TokenType type, int line, int col);
  static Token identifier(const std::string &id, int line, int col);
  static Token keyword(const std::string &word, int line, int col);
  static Token number(double value, int line, int col);
  static Token add(int line, int col);
  static Token sub(int line, int col);  
  static Token times(int line, int col);
  static Token divide(int line, int col);  
  static Token lparen(int line, int col);
  static Token rparen(int line, int col);
  static Token eof(int line, int col);
  static Token unrecognized(const std::string &what, int line, int col);
  Token();
  Token(const nlohmann::json &json);
  const nlohmann::json &toJSON() const;
  TokenType getType() const;
  int getLine() const; 
  int getCol() const;
private:
  nlohmann::json obj;
};


