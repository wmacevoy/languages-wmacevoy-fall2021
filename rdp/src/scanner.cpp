#define SCANNER_CPP
#include "scanner.h"

#include <fstream>
#include <sstream>


void Scanner::setString(const std::string &str) {
  setStream(Stream(new std::istringstream(str)));
}

void Scanner::setFile(const std::string &str) {
  setStream(Stream(new std::ifstream(str)));
}

void Scanner::setStdin() {
  // don't delete cin
  Stream shim(&std::cin, [](auto p) {});
  setStream(shim);
}

void Scanner::setStream(Stream _stream) {
  stream = _stream;
}

Scanner::Stream Scanner::getStream() const {

  return stream;
}

void Scanner::putBack(Token::Ptr token) { putBacks.push(token); }

Token::Ptr Scanner::next() {
  if (!putBacks.empty()) {
    Token::Ptr ans = putBacks.top();
    putBacks.pop();
    return ans;
  }
  return nextFromStream();
}

Token::Ptr Scanner::nextFromStream() {
  return Token::eof(0,0);
}


extern const std::string SCANNER_INPUT1="(4+5)S*R";
extern const std::vector<Token::Ptr> SCANNER_RESULT1 =
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
extern const std::vector<Token::Ptr> SCANNER_RESULT2 =
  {
   Token::number(3,0,0),
   Token::keyword("S",0,1),
   Token::add(0,2),
   Token::keyword("R",0,3),
   Token::eof(0,4)
  };

// 3. R+3S
// 4. 2S*4+R


class MockScanner : public Scanner {
 public:
  std::vector < Token::Ptr > tokens;
  int at;
  MockScanner();
  virtual Token::Ptr nextFromStream();  
};

MockScanner::MockScanner() {
  at=-1;
}

std::string readall(std::shared_ptr<std::istream> streamptr) {
  if (!streamptr) return "";
  
  std::istream &stream=*streamptr;
  
  std::string all;
  for (;;) {
    int ch = stream.get();
    if (ch < 0) break;
    all.push_back(ch);
  }
  return all;
}

Token::Ptr MockScanner::nextFromStream() {
  if (at == -1) {
    std::string input=readall(getStream());
    
    if (input == SCANNER_INPUT1) {
      tokens = SCANNER_RESULT1;
    } else if (input == SCANNER_INPUT2) {
      tokens = SCANNER_RESULT2;
    } else {
      tokens.push_back(Token::unrecognized(input,0,0));
      tokens.push_back(Token::eof(0,0));
    }
    at=0;
  }
  
  int current = at;  
  if (at < tokens.size()) {
    ++at;
  }
  return tokens.at(current);
}


Scanner::Ptr Scanner::mock() { return Ptr(new MockScanner()); }
Scanner::Ptr Scanner::real() { throw std::range_error("todo"); }
