#pragma once

#include "token.h"
#include <vector>
#include <stack>
#include <iostream>
#include <memory>

class Scanner {
 public:
  typedef std::shared_ptr<std::istream> Stream;
  typedef std::shared_ptr<Scanner> Ptr;
private:
  Stream stream;
  std::stack<Token::Ptr> putBacks;
public:
  static Ptr mock();
  static Ptr real();
  virtual void setString(const std::string &str);
  virtual void setFile(const std::string &file);  
  virtual void setStream(Stream stream);
  virtual void setStdin();
  virtual Stream getStream() const;
  virtual void putBack(Token::Ptr token);
  virtual Token::Ptr next();
protected:
  virtual Token::Ptr nextFromStream();  
};

#ifndef SCANNER_CPP
extern const std::string SCANNER_INPUT1;
extern const std::vector<Token::Ptr> SCANNER_RESULT1;

extern const std::string SCANNER_INPUT2;
extern const std::vector<Token::Ptr> SCANNER_RESULT2;
#endif

