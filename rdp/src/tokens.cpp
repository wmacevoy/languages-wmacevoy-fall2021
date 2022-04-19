#include <stdexcept>
#include "tokens.h"

std::string TokenTypeToJSON(enum TokenType tokenType) {
  switch(tokenType) {
  case identifier: return "identifier";
  case keyword: return "keyword";
  case number: return "number";
  case add: return "add";
  case sub: return "sub";
  case divide: return "divide";
  case times: return "times";
  case lparen: return "lparen";
  case rparen: return "rparen";
  case eof: return "eof";
  case unrecognized: return "unrecognized";
  default: throw std::range_error("invalid token type");
  }
}

enum TokenType JSONToTokenType(const std::string &jsonTokenType) {
  if (jsonTokenType == "identifier") return TokenType::identifier;
  if (jsonTokenType == "keyword") return TokenType::keyword;
  if (jsonTokenType == "number") return TokenType::number;
  if (jsonTokenType == "add") return TokenType::add;
  if (jsonTokenType == "sub") return TokenType::sub;
  if (jsonTokenType == "divide") return TokenType::divide;
  if (jsonTokenType == "times") return TokenType::times;
  if (jsonTokenType == "lparen") return TokenType::lparen;
  if (jsonTokenType == "rparen") return TokenType::rparen;
  if (jsonTokenType == "eof") return TokenType::eof;
  if (jsonTokenType == "unrecognized") return TokenType::unrecognized;
  throw std::range_error("invalid token string");
}

Token::Token() {}

Token::Token(const nlohmann::json &_obj) : obj(_obj) {}

const nlohmann::json& Token::toJSON() const {
  return obj;
}

TokenType Token::getType() const { return JSONToTokenType(obj["token-type"]); }
int Token::getLine() const { return int(obj["line"]); }
int Token::getCol() const { return int(obj["col"]); }
bool Token::operator==(const Token &to) const { return obj == to.obj; }
bool Token::operator!=(const Token &to) const { return obj != to.obj; }

Token Token::base(TokenType type, int line, int col) {
  nlohmann::json obj;
  obj["type"]="token";
  obj["token-type"]=TokenTypeToJSON(type);
  obj["line"]=line;
  obj["col"]=col;
  return Token(obj);
}

Token Token::identifier(const std::string &id, int line, int col) {
  Token ans = base(TokenType::identifier,line,col);
  ans.obj["id"]=id;
  return ans;
}

Token Token::keyword(const std::string &word, int line, int col) {
  Token ans = base(TokenType::keyword,line,col);
  ans.obj["word"]=word;
  return ans;
}

Token Token::number(double value, int line, int col) {
  Token ans = base(TokenType::number,line,col);
  ans.obj["value"]=value;
  return ans;
}

Token Token::add(int line, int col) {
  return base(TokenType::add,line,col);
}
Token Token::sub(int line, int col) {
  return base(TokenType::sub,line,col);
}

Token Token::times(int line, int col) {
  return base(TokenType::times,line,col);
}
Token Token::divide(int line, int col) {
  return base(TokenType::divide,line,col);
}

Token Token::lparen(int line, int col) {
  return base(TokenType::lparen,line,col);
}

Token Token::rparen(int line, int col) {
  return base(TokenType::rparen,line,col);
}

Token Token::eof(int line, int col) {
  return base(TokenType::eof,line,col);
}

Token Token::unrecognized(const std::string &what, int line, int col) {
  Token ans = base(TokenType::unrecognized,line,col);
  ans.obj["what"]=what;
  return ans;
}

double Token::getValue() const {
  if (getType() != TokenType::number) {
    throw std::range_error("not a number");
  }
  return double(obj["value"]);
}

std::string Token::getId() const {
  if (getType() != TokenType::identifier) {
    throw std::range_error("not an identifier");
  }
  return std::string(obj["id"]);
}

std::string Token::getWhat() const {
  if (getType() != TokenType::unrecognized) {
    throw std::range_error("known token");
  }
  return std::string(obj["what"]);
}

std::string Token::getWord() const {
  if (getType() != TokenType::keyword) {
    throw std::range_error("not a keyword");
  }
  return std::string(obj["word"]);
}





