
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;
class WebTemplate {
   map<string,string> dictionary; // dictionary["who"]="bob"
   string component;  /// ex <p>hello ${who}</p>
   string translate() const {
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