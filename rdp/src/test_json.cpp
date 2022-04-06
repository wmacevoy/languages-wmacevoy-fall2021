#include "gtest/gtest.h"

// https://github.com/nlohmann/json
#include "json.hpp"

using json = nlohmann::json;

TEST(json,string) {
  // https://pspdfkit.com/blog/2021/string-literals-character-encodings-and-multiplatform-cpp
  std::string s = u8R"-=-({ "happy": true, "pi": 3.141 })-=-";
  json j = json::parse(s);

  ASSERT_EQ(j["happy"],true);
  ASSERT_EQ(j["pi"],3.141);
}

TEST(json,object) {
  json j1;
  j1["answer"]["everything"] = 42;
  j1["fibonacci"]={1,1,2,3,5,8};

  json j2=u8R"-=-({ "answer": { "everything": 42 }, "fibonacci" : [1,1,2,3,5,8] })-=-"_json;

  ASSERT_EQ(j1,j2);

  for (auto& [key, value] : j1.items()) {
    std::ostringstream oss;
    oss << "j1[" << key << "]=" << value;
    std::string expect;
    if (key == "answer") expect=u8R"-=-(j1[answer]={"everything":42})-=-";
    if (key == "fibonacci") expect=u8R"-=-(j1[fibonacci]=[1,1,2,3,5,8])-=-";
    ASSERT_EQ(expect,oss.str());
  }
}
