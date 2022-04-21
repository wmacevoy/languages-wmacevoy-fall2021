#include "gtest/gtest.h"
#include "scanner.h"


std::string mockInput(int k) {
  if (k == 1) return SCANNER_INPUT1;
  if (k == 2) return SCANNER_INPUT2;
  throw std::range_error("invalid");
}

std::vector<Token::Ptr> mockTokens(int k) {
  if (k == 1) return SCANNER_RESULT1;
  if (k == 2) return SCANNER_RESULT2;
  throw std::range_error("invalid");  
}

TEST(Scanner,Mock) {
  for (int k=1; k<=2; ++k) {
    Scanner::Ptr scanner=Scanner::mock();
    scanner->setString(mockInput(k));
    std::vector<Token::Ptr> expect = mockTokens(k);
    for (int i=0; i<expect.size(); ++i) {
      ASSERT_EQ(*scanner->next(),*expect[i]);
    }
  }
}

TEST(Scanner,Real) {
  for (int k=1; k<=2; ++k) {
    Scanner::Ptr scanner=Scanner::real();
    scanner->setString(mockInput(k));
    std::vector<Token::Ptr> expect = mockTokens(k);
    for (int i=0; i<expect.size(); ++i) {
      ASSERT_EQ(*scanner->next(),*expect[i]);
    }
  }
}


