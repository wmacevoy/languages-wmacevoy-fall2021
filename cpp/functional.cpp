
#include <string>
#include <vector>
#include <map>

using namespace std;

const string apply(const map<string,string> dictionary, const string tmpl) {

}

const string hello(const string &who) {
    return "hello " + who;
}

const string b(const string text) {
    return "<b>" + text + "</b>";
}
const string p(const string text) {
    return "<p>" + text  + "</p>";
}

string ps(vector<string> texts, int from = 0) {
   if (texts.size() <= from) return "";
   else return texts[from] + ps(texts,from+1);
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
   //  page(header(),title(),body(vector([p("hi)"),p("there")]))));
}