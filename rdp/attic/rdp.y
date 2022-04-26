%name LemonParse

%token_prefix {TokenType::}
%token_type {Token::Ptr}
%default_type {AST::Ptr}

%include {
#include "port.h"
#include "token.h"
#include "ast.h"
}

%left ADD SUB.
%left TIMES DIVIDE.
%right NOT STORE.
%extra_argument { AST::Ptr &ast }

all ::= exp(e) EOL. { $$=e; }
exp ::= LPAREN exp(e) RPAREN. { $$ = e;  }
exp ::= exp(a) ADD(tkAdd) exp(b). { $$=AST::add(tkAdd,a,b); }
exp ::= exp(a) STORE(tkStore). { $$=AST::store(tkStore,a); }
exp ::= NUMBER(tkNumber). { $$=AST::number(tkNumber); }
exp ::= RECALL(tkRecall). { $$=AST::number(tkRecall); }  
   
%parse_accept {
  printf("yay!\n");
}
