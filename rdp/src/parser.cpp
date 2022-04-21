#include "ast.h"
#define PARSER_CPP
#include "parser.h"

//
//  <e>:=<lit>|<e>+<e>|(<e>)|...
//  4
//
//  <e>-><lit>
//     ->  4
//
//     4  {"type":"ast","ast-type":"number","value":4}
//     5  {"type":"ast","ast-type":"number","value":5}
//
//     a+b  {"type":"ast","ast-type":"add","args":[<a>,<b>]}
//
//    "4+5"
//
//    {"type":"ast","ast-type":"add","args":[{"type":"ast","ast-type":"number","value":4},{"type":"ast","ast-type":"number","value":5}]}
//
//
//   <e>-> <e> + <e> 
//          v     v
//        <lit> <lit>
//          v     v
//          4     5
//
//            +
//           / \
//          4   5
//
//    "<what>S"
//    {"type":"ast","ast-type":"store","args":[<what>]}
//
//    (4+5)S
//      store
//        +
//       / \
//      4   5
//
//    {"type":"ast","ast-type":"store","args":[{"type":"ast","ast-type":"add","args":[{"type":"ast","ast-type":"number","value":4},{"type":"ast","ast-type":"number","value":5}]}]}
//
//
//     a*b  {"type":"ast","ast-type":"times","args":[<a>,<b>]}
//     
//      R   {"type":"ast","ast-type":"recall"}
//
//     (4+5)S*R
//
//

extern const AST::Ptr PARSER_RESULT1=
  AST::times(SCANNER_RESULT1[6],
	     AST::store(SCANNER_RESULT1[5],
			AST::add(SCANNER_RESULT1[2],
				 AST::number(SCANNER_RESULT1[1]),
				 AST::number(SCANNER_RESULT1[3]))),
	     AST::recall(SCANNER_RESULT1[7]));


extern const AST::Ptr PARSER_RESULT2=AST::unrecognized(Token::eof(0,0));

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
  for (int i=0; i<100; ++i) {
    Token::Ptr token = scanner->next();
    tokens.push_back(token);
    if (token->getType() == TokenType::eof) break;
  }
  if (tokens == SCANNER_RESULT1) {
    return PARSER_RESULT1;
  }
  if (tokens == SCANNER_RESULT2) {
    return PARSER_RESULT2;
  }
  return AST::unrecognized(Token::eof(0,0));
}

Parser::Ptr Parser::mock() { return Ptr(new MockParser()); }
Parser::Ptr Parser::real() { throw std::range_error("todo"); }
