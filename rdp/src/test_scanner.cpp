#include "gtest/gtest.h"
#include "scanner.h"


std::string mockInput(int k) {
  if (k == 1) return SCANNER_INPUT1;
  if (k == 2) return SCANNER_INPUT2;
  throw std::range_error("invalid");
}

std::vector<Token> mockTokens(int k) {
  if (k == 1) return SCANNER_RESULT1;
  if (k == 2) return SCANNER_RESULT2;
  throw std::range_error("invalid");  
}

void stop() {}

TEST(Scanner,Mock) {
  stop();
  for (int k=1; k<=2; ++k) {
    MockScanner scanner(mockInput(k));
    std::vector<Token> expect = mockTokens(k);
    for (int i=0; i<expect.size(); ++i) {
      ASSERT_EQ(scanner.next(),expect[i]);
    }
  }
}
