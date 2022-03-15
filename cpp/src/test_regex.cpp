// Goal - match C++ decimal (base 10) integer strings.

// Digit = r(0|..|9)
// PositiveDigit=r(1|..|9)
// Decimal = r(0|(PositiveDigit((|')Digit)*))

#include "gtest/gtest.h"
#include <regex>
#include <string>

using namespace std;

bool IsDecimal(const std::string &candidate) {
    regex matcher("(-?(0|([1-9]('?[0-9])*))|\\((0|([1-9]('?[0-9])*))\\))");
    return regex_match(candidate,matcher);
}

bool IsDouble(const std::string &candidate) {
    return true;
}

bool IsIdentifier(const std::string &candidate) {
    return true;
}

TEST(RegEx,DecimalInteger) {
   ASSERT_TRUE(IsDecimal("0"));
   ASSERT_TRUE(IsDecimal("1"));
   ASSERT_TRUE(IsDecimal("1'2'3"));
   ASSERT_TRUE(IsDecimal("1'000'000"));

   ASSERT_TRUE(IsDecimal("-0"));
   ASSERT_TRUE(IsDecimal("-1"));
   ASSERT_TRUE(IsDecimal("-1'2'3"));
   ASSERT_TRUE(IsDecimal("-1'000'000"));

   ASSERT_FALSE(IsDecimal("-"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("00"));
   ASSERT_FALSE(IsDecimal("0001"));
   ASSERT_FALSE(IsDecimal("1''000''000"));
   ASSERT_FALSE(IsDecimal(".20"));
   ASSERT_FALSE(IsDecimal("20."));
}

TEST(RegEx,Double) {


}

TEST(RegEx,Identifier) {

}
