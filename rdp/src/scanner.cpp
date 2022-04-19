#define SCANNER_CPP
#include "scanner.h"

Token Scanner::next() { return Token::eof(0,0); }
extern const std::string SCANNER_INPUT0="4";

extern const std::string SCANNER_INPUT1="(4+5)S*R";
extern const std::vector<Token> SCANNER_RESULT1 =
  {
   Token::lparen(0,0),
   Token::number(4,0,1),
   Token::add(0,2),
   Token::number(5,0,3),
   Token::rparen(0,4),
   Token::keyword("S",0,5),
   Token::times(0,6),
   Token::keyword("R",0,6),
   Token::eof(0,7)
  };

extern const std::string SCANNER_INPUT2="3S+R";
extern const std::vector<Token> SCANNER_RESULT2 =
  {
   Token::number(3,0,0),
   Token::keyword("S",0,1),
   Token::add(0,2),
   Token::keyword("R",0,3),
   Token::eof(0,4)
  };

// 3. R+3S
// 4. 2S*4+R

MockScanner::MockScanner(const std::string &input) {
  if (input == SCANNER_INPUT1) {
    tokens = SCANNER_RESULT1;
  } else if (input == SCANNER_INPUT2) {
    tokens = SCANNER_RESULT2;
  } else {
    tokens.push_back(Token::unrecognized(input,0,0));
  }
  at=0;
}

MockScanner::MockScanner(const std::vector<Token> &_tokens)
  : tokens(_tokens),at(0)
{
}

Token MockScanner::next() {
  int current = at;  
  if (at < tokens.size()) {
    ++at;
  }
  return tokens.at(current);
}
