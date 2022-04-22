#include <string>
#include <version>

#include "json.hpp"

typedef nlohmann::json JSON;

#if !defined(__cpp_char8_t)
using char8_t = char;
namespace std {
  using u8string = string;
}
#endif

std::string operator"" _string(const char8_t* str, std::size_t n);
JSON operator"" _JSON(const char8_t* str, std::size_t n);
