#include "scanner.h"
#include "parser.h"
#include "vm.h"

class Calc {
public:
  VM vm;
  AST::Ptr prog;  
  nlohmann::json ans;
  
  Scanner::Ptr scanner;
  void setScanner(Scanner::Ptr _scanner) {
    scanner=_scanner;
  }
  Scanner::Ptr getScanner() {
    if (!scanner) {
      scanner=Scanner::real();
    }
    if (!scanner->getStream()) {
      scanner->setStdin();
    }
    return scanner;
  }

  Parser::Ptr parser;
  void setParser(Parser::Ptr _parser) {
    parser=_parser;
  }
  
  Parser::Ptr getParser() {
    if (!parser) {
      parser=Parser::real();
    }
    if (!parser->getScanner()) {
      parser->setScanner(getScanner());
    }
    return parser;
  }

  void setString(const std::string &str) {
    getScanner()->setString(str);
  }

  void setFile(const std::string &file) {
    getScanner()->setFile(file);
  }

  void setStream(std::shared_ptr<std::istream> stream) {
    getScanner()->setStream(stream);
  }


  bool parse() {
    prog = getParser()->parse();
    if (!prog || prog->getType() == ASTType::unrecognized) return false;
    return true;
  }
  
  void run() {
    ans = vm.run(prog);
  }
};

int main(int argc, const char *argv[]) {
  Calc calc;

  for (int argi=1; argi<argc; ++argi) {
    std::string arg=argv[argi];
    if (arg=="--mockScanner") {
      calc.setScanner(Scanner::mock());
      continue;
    }
    
    if (arg=="--mockParser") {
      calc.setParser(Parser::mock());
      continue;
    }

    if (arg=="--file") {
      ++argi;
      calc.setFile(argv[argi]);
      continue;
    }

    if (arg=="--string") {
      ++argi;
      calc.setString(argv[argi]);
      continue;
    }

    std::cerr << "uknown arg: " << arg << std::endl;
    exit(1);
  }

  if (!calc.parse()) {
    std::cerr << "syntax error: " << calc.prog->toJSON() << std::endl;
    return 1;
  }

  calc.run();
  
  std::cout << "ans=" << calc.ans << std::endl;
  return 0;
}
