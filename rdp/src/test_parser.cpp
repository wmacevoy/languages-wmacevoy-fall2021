#include "gtest/gtest.h"

#include "ast.h"
#include "scanner.h"
#include "parser.h"

std::string mockInput(int k) {
  if (k == 1) return SCANNER_INPUT1;
  if (k == 2) return SCANNER_INPUT2;
  throw std::range_error("invalid");
}

AST::Ptr mockAST(int k) {
  if (k == 1) return PARSER_RESULT1;
  if (k == 2) return PARSER_RESULT2;
  throw std::range_error("invalid");  
}

TEST(Parser,Mock) {
  for (int k=1; k<=2; ++k) {
    Scanner::Ptr scanner = Scanner::Ptr(new MockScanner(mockInput(k)));
    Parser::Ptr parser = Parser::Ptr(new MockParser());

    parser->setScanner(scanner);

    AST::Ptr expect = mockAST(k);
    AST::Ptr result = parser->parse();

    ASSERT_EQ(expect,result);
  }
}
