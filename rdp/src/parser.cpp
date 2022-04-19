
//
//  <e>:=<lit>|<e>+<e>|(<e>)|...
//  4
//
//  <e>-><lit>
//     ->  4
//
//     4  {"type":"ast","ast-type":"number","value":4}
//     5  {"type":"ast","ast-type":"number","value":5}
//
//
//     a+b  {"type":"ast","ast-type":"add","args":[<a>,<b>]}
//
//
//    "4+5"
//
//    {"type":"ast","ast-type":"add","args":[{"type":"ast","ast-type":"number","value":4},{"type":"ast","ast-type":"number","value":5}]}
//
//
//   <e>-> <e> + <e> 
//          v     v
//        <lit> <lit>
//          v     v
//          4     5
//
//            +
//           / \
//          4   5
//
//
//    "<what>S"
//    {"type":"ast","ast-type":"store","args":[<what>]}
//
//    (4+5)S
//
//    {"type":"ast","ast-type":"store","args":[{"type":"ast","ast-type":"add","args":[{"type":"ast","ast-type":"number","value":4},{"type":"ast","ast-type":"number","value":5}]}]}
//
//
//     a*b  {"type":"ast","ast-type":"times","args":[<a>,<b>]}
//     
//      R   {"type":"ast","ast-type":"recall"}
//
//     (4+5)S*R
//
//     

//extern const std::string SCANNER_INPUT1="(4+5)S*R";
extern const nlohmann::json PARSER_RESULT1=u8R"-=-({"type":"ast","ast-type":"times","args":[{"type":"ast","ast-type":"store","args":[{"type":"ast","ast-type":"add","args":[{"type":"ast","ast-type":"number","value":4},{"type":"ast","ast-type":"number","value":5}]}]},{"type":"ast","ast-type":"recall"}]})-=-"_json;

//extern const std::string SCANNER_INPUT2="3S+R";
extern const nlohmann::json PARSER_RESULT2=u8R"-=-(???)-=-"_json;


