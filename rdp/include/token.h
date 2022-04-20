
#pragma once

#include <string>
#include <memory>

#include "json.hpp"

enum class TokenType { 
    identifier,keyword,number,
    add,sub,times,divide, 
    lparen, rparen,eof,unrecognized 
};

std::string TokenTypeToJSON(enum TokenType tokenType);
enum TokenType JSONToTokenType(const std::string &jsonTokenType);

class Token { 
public:
  typedef std::shared_ptr<Token> Ptr;
  friend int operator<=>(const Ptr &a, const Ptr &b);
  friend bool operator==(const Ptr &a, const Ptr &b);
  friend bool operator!=(const Ptr &a, const Ptr &b);
  friend bool operator<=(const Ptr &a, const Ptr &b);
  friend bool operator>=(const Ptr &a, const Ptr &b);
  friend bool operator<(const Ptr &a, const Ptr &b);
  friend bool operator>(const Ptr &a, const Ptr &b);

  static Ptr base(TokenType type, int line, int col);
  static Ptr identifier(const std::string &id, int line, int col);
  static Ptr keyword(const std::string &word, int line, int col);
  static Ptr number(double value, int line, int col);
  static Ptr add(int line, int col);
  static Ptr sub(int line, int col);  
  static Ptr times(int line, int col);
  static Ptr divide(int line, int col);  
  static Ptr lparen(int line, int col);
  static Ptr rparen(int line, int col);

  static Ptr eof(int line, int col);
  static Ptr unrecognized(const std::string &what, int line, int col);
  
  Token();
  Token(const nlohmann::json &_obj);
  
  const nlohmann::json &toJSON() const;
  TokenType getType() const;

  int getLine() const; 
  int getCol() const;
  double getValue() const;
  std::string getId() const;
  std::string getWhat() const;
  std::string getWord() const;
  int operator<=>(const Token&) const;
private:
  nlohmann::json obj;
};


