#include "examples.h"

Example::Example(const std::string &_input,
		 const std::vector<Token::Ptr> &_tokens,
		 const AST::Ptr &_ast, const double &_ans)
  : input(_input), tokens(_tokens), ast(_ast), ans(_ans) {}

// SCANNER_INPUT1="(4+5)S*R";
// PARSER_RESULT1=
//       *
//      / \
//     S   R
//     |
//     +
//    / \
//   4   5



// SCANNER_INPUT1="(4+5)S*R";
// PARSER_RESULT1=
//       *
//      / \
//     S   R
//     |
//     +
//    / \
//   4   5

Token::Ptr append(std::vector<Token::Ptr> &tokens, Token::Ptr token) {
  tokens.push_back(token);
  return token;
}


Example::Ptr ex0() {
  int line=0, col=0;
  std::string input = "(4+5)S*R";
  
  std::vector<Token::Ptr> tokens;
  Token::Ptr tkLparen0 = append(tokens,Token::lparen(line,col++));
  Token::Ptr tkFour1 = append(tokens,Token::number(4,line,col++));
  Token::Ptr tkAdd2 = append(tokens,Token::add(line,col++));
  Token::Ptr tkFive3 = append(tokens,Token::number(5,line,col++));
  Token::Ptr tkRparen4 = append(tokens,Token::rparen(line,col++));
  Token::Ptr tkStore5 = append(tokens,Token::keyword("S",line,col++));
  Token::Ptr tkTimes6 = append(tokens,Token::times(line,col++));
  Token::Ptr tkRecall7 = append(tokens,Token::keyword("R",line,col++));
  Token::Ptr tkEof8 = append(tokens,Token::eof(line,col++));

  AST::Ptr ast =
    AST::times(tkTimes6,
	       AST::store(tkStore5,
			  AST::add(tkAdd2,
				   AST::number(tkFour1),
				   AST::number(tkFive3))),
	       AST::recall(tkRecall7));

  double ans = 81;  

  return Example::Ptr(new Example(input,tokens,ast,ans));
}

Example::Ptr ex1() {
  int line=0, col=0;
  std::string input = "3S+R";
  
  std::vector<Token::Ptr> tokens;
  Token::Ptr tkThree0 = append(tokens,Token::number(3,line,col++));
  Token::Ptr tkStore1 = append(tokens,Token::keyword("S",line,col++));
  Token::Ptr tkAdd2 = append(tokens,Token::add(line,col++));
  Token::Ptr tkRecall3 = append(tokens,Token::keyword("R",line,col++));
  Token::Ptr tkEof4 = append(tokens,Token::eof(line,col++));

  AST::Ptr ast =
    AST::add(tkAdd2,
	     AST::store(tkStore1,
			AST::number(tkThree0)),
	     AST::recall(tkRecall3));

  double ans = 6;

  return Example::Ptr(new Example(input,tokens,ast,ans));
}

std::size_t Example::size() { return 2; }
Example::Ptr Example::example(int k) {
  switch(k) {
  case 0: return ex0();
  case 1: return ex1();
  default: return NULL;
  }
}
