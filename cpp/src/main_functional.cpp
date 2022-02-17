
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <regex>

using namespace std;

// const x = { "a" : 4, "b" : 7 };
// x = { "a" : 7, "b" : 3 }; // illegal in js.
// x["a"] =333;
class WebTemplate {
   public: map<string,string> dictionary; // dictionary["who"]="bob"
   public: string component;  /// ex <p>hello ${who}</p>
   public: string substitute(string in, string from, string to) const {
       const regex pattern(from);
       return  regex_replace( in,pattern, to);
   }

   public: void add(string message) {
       component += message;
   }
   public: string translate() const {
       string ans = component;
       for (auto keyValue : dictionary) {
           auto key = keyValue.first;
           auto value = keyValue.second;
           ans = substitute(ans, "${" + key + "}",value);
       }
       return "";
   }
};


const string hello(const string &who) {
    return "hello " + who;
}

const string b(const string &text) {
    return "<b>" + text + "</b>";
}
const string p(const string &text) {
    return "<p>" + text  + "</p>";
}

string ps(const vector<string> &texts, int from = 0) {
   if (texts.size() <= from) return "";
   else return texts[from] + ps(texts,from+1);  
   
   // if the last thing you do is call yourself, you might
   // as well replace your stack frame with the recursed version.

   // Upshot: tail recursion can be really efficient.
}

string ps_nonfunctional_impl(vector<string> texts) {
    // philosphically bad -- modifying a value...
    string ans = "";
    for (auto text : texts) {
        ans += p(text);
    }
    return ans;
}

int main() {
    cout << p("hello world") << endl;
   //  page(header(),title(),body(vector([p("hi)"),p("there")]))));
}