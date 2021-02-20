%{
#include<stdio.h>



extern FILE* yyin ;
extern int count ;
extern int line;
int yylex();
// bool recherche_syn(char * name);
//void wrap();
int yyerror(char * msg);
int num = 0;



%}

%token integer real car string mc_proc mc_prog mc_loop mc_arr mc_const mc_integer mc_real mc_car mc_string mc_read mc_write mc_while mc_execut mc_if mc_endif mc_else mc_arithOp mc_logiqOp mc_signeForma mc_sep mc_idf
%token var_sep
%token SEP_READ
%token mc_var
%left ADD_OP
%left MUL_OP


%start S
%%

S: header begin body End {printf("programme juste\n"); YYACCEPT;};
header: Bib_dec mc_prog mc_idf  | mc_prog mc_idf;

Bib_dec: '#''#' bib '$' Bib_dec | '#''#' bib '$';  
bib:mc_arr | mc_proc | mc_loop;

begin: '{'  var_dec | '{';

var_dec: mc_var type ':'':' list_var | mc_const type ':'':' constante_list_var ;
type: mc_string | mc_car | mc_integer | mc_real;
constante_list_var:  affectation '$' var_dec | affectation var_sep list_var | affectation '$' ;
list_var: mc_idf '$' var_dec | mc_idf var_sep list_var | mc_idf '$' ;

affectation: mc_idf mc_arithOp opera;
opera: constante | express | '('express')';
express: opera operand opera;
operand: ADD_OP | MUL_OP  ;
constante: '"'string'"' | integer | real | car | mc_idf ;



read: mc_read '(' '"' mc_signeForma '"' SEP_READ '@' mc_idf ')' '$' ;
write: mc_write '(' '"' write_string SEP_READ write_var ')' '$' { if(num != 0){printf("error signe de formatage is not equale to idf %d\n",num);}} ;
write_var: mc_idf {num--;}| mc_idf SEP_READ write_var {num--;};
write_string: string write_string | mc_signeForma write_string {num++;} | '"';

loop: mc_while '(' condition ')' '{' body '}';
condition: opera mc_logiqOp opera ;


if_statement: mc_execut body mc_if '(' condition ')' else_statement;
else_statement: mc_endif | mc_else mc_execut body mc_endif;

body: instruction | instruction body;
instruction: affectation '$' | read | write | loop | if_statement;

End: '}';




%%

int yyerror(char *msg)
{

printf("%s syntaxic error line %d cologne %d\n",msg,line,count);

return 1;
}


int main(int argc , char **argv)
{	
	if(argc != 2)
	{
		printf("Error need missing file argument");
	}
	else
	{
		yyin = fopen(argv[1],"r");
		yyparse();
	}
	//printf("Count = %d \n",count);
	
}

int yywrap(void)
{
}
