#include "ast.h"
#include "parser.h"
#include "examples.h"

void Parser::setScanner(Scanner::Ptr _scanner) {
  scanner=_scanner;
}

Scanner::Ptr Parser::getScanner() const {
  return scanner;
}

AST::Ptr Parser::parse() { return AST::unrecognized(Token::eof(0,0)); }

class MockParser : public Parser {
 public:
  virtual AST::Ptr parse();
};

AST::Ptr MockParser::parse() {
  Scanner::Ptr scanner = getScanner();
  std::vector<Token::Ptr> tokens;
  for (int i=0; i<1000; ++i) {
    Token::Ptr token = scanner->next();
    tokens.push_back(token);
    if (token->getType() == TokenType::eof) break;
  }
  int n = Example::size();
  for (int k=0; k<n; ++k) {
    Example::Ptr ex = Example::example(k);
    if (tokens == ex->tokens) {
      return ex->ast;
    }
  }

  for (auto token : tokens) {
    std::cout << token->toJSON() << std::endl;
  }
  
  return AST::unrecognized(Token::eof(0,0));
}

Parser::Ptr Parser::mock() { return Ptr(new MockParser()); }
Parser::Ptr Parser::real() { throw std::range_error("todo"); }
