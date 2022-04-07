#include "gtest/gtest.h"

// https://github.com/nlohmann/json
#include "json.hpp"

using json = nlohmann::json;

// camera = {"targets" : ["ukraine","Севасто́поль"], 
//             "target":"Севасто́поль", 
//             "lookAt="${target}"}

// <string> := (<sub>? <char>*)*
// <sub> := ${ <exp> }
// <exp> := <string>

TEST(ParseTree,AsJSON) {
  json camera = u8R"-=-({"targets" : ["ukraine","Севасто́поль"], 
             "target":"Севасто́поль", 
             "lookAt="${target}"})-=-"_json

  json lookAtParseTree = u8R"-=-([ {"sub":"target", "chars":"" } ])-=-"_json

}