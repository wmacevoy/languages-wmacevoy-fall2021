#include "vm.h"
#include "parser.h"

#include "gtest/gtest.h"

TEST(VM,Ex1) { // (4+5)S*R
  VM vm;
  nlohmann::json store = 9;
  nlohmann::json expect = 81;
  auto result = vm.run(PARSER_RESULT1);
  ASSERT_EQ(result,expect);
  ASSERT_EQ(vm.heap["store"],store);
}

TEST(VM,Ex2) { // 3S+R
  VM vm;
  nlohmann::json store = 3;
  nlohmann::json expect = 6;
  auto result = vm.run(PARSER_RESULT2);
  ASSERT_EQ(result,expect);
  ASSERT_EQ(vm.heap["store"],store);
}
