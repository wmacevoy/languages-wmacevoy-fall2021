#include "gtest/gtest.h"
#include "scanner.h"
#include "examples.h"


TEST(Scanner,Mock) {
  int n = Example::size();
  for (int k=0; k<n; ++k) {
    Example::Ptr ex = Example::example(k);
    
    Scanner::Ptr scanner=Scanner::mock();
    scanner->setString(ex->input);
    for (int i=0; i<ex->tokens.size(); ++i) {
      ASSERT_EQ(*scanner->next(),*ex->tokens[i]);
    }
  }
}

TEST(Scanner,Real) {
  int n = Example::size();
  for (int k=0; k<n; ++k) {
    Example::Ptr ex = Example::example(k);
    
    Scanner::Ptr scanner=Scanner::real();
    scanner->setString(ex->input);
    for (int i=0; i<ex->tokens.size(); ++i) {
      ASSERT_EQ(*scanner->next(),*ex->tokens[i]);
    }
  }
}


