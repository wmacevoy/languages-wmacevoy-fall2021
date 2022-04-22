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
protected:
  Stream stream;
  std::vector<Token::Ptr> putBacks;
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
