%{
#include<stdio.h>
#include<stdbool.h>
#include "T.h"



extern FILE* yyin ;
extern int count ;
extern int line;
int yylex();
// bool recherche_syn(char * name);
//void wrap();
int yyerror(char * msg);
int num = 0;

char current_type[10];
char current_entity[10];

tableau * pointer;
tableau * tab = NULL;

bool process = false;
bool loops = false;
bool arrays = false;
bool division = false;


typedef struct tab_type{

	char ptr[10];
	struct tableau * next;

}tab_type;

tab_type * tableau_type = NULL;
tab_type *tmp_type_pointer;
char tmp_type[10];
char tmp_value[10];

%}

%union{
	int  entier;
	char * chaine;
	float real ;
	char chars[10];
}

%token  mc_proc mc_prog mc_loop mc_arr mc_const mc_integer mc_real mc_car mc_string mc_read mc_write mc_while mc_execut mc_if mc_endif mc_else mc_arithOp mc_logiqOp  mc_sep 
%token <chaine>mc_idf
%token <chaine>mc_signeForma
%token var_sep
%token SEP_READ
%token mc_var
%token <chaine>integer <chaine>real <chaine>string <chaine>car
%left ADD_OP
%left <chaine>MUL_OP


%start S
%%

S: header begin body End {printf("programme juste\n");affich(); YYACCEPT;};
header: Bib_dec mc_prog mc_idf  | mc_prog mc_idf;

Bib_dec: '#''#' bib '$' Bib_dec | '#''#' bib '$';  
bib:mc_arr {if(loops){printf("\033[31m warning \033[0m array already included\n");}else{arrays = true;}}
| mc_proc {if(loops){printf("\033[31m warning \033[0m process already included\n");}else{process = true;}}
| mc_loop {if(loops){printf("\033[31m warning \033[0m loop already included\n");}else{loops = true;}};

begin: '{'  var_dec | '{';

var_dec: variable_type type ':'':' list_var | variable_type type ':'':' constante_list_var ;

variable_type: mc_var {strcpy(current_entity,"IDF");} |
 mc_const {strcpy(current_entity,"CONST");};

type: mc_string {strcpy(current_type,"STRING");}|
 mc_car {strcpy(current_type,"CHAR");}
| mc_integer {strcpy(current_type,"INT");}
| mc_real{strcpy(current_type,"FLOAT");};

constante_list_var:  constante_affectation '$' var_dec | constante_affectation var_sep constante_list_var | constante_affectation '$' ;
list_var: variable '$' var_dec | variable var_sep list_var | variable '$' ;

constante_affectation: mc_idf mc_arithOp direct_value 
{
	if(recherche_syn($1)){printf("\033[31m Error \033[0m double declaration for %s",$1);affich();YYACCEPT;}else{insert($1,current_type,current_entity);}

	if(strcmp(tableau_type->ptr,current_type) != 0){printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,current_type);}

	tableau_type = NULL;
	update($1,tmp_value);
}
| mc_idf mc_arithOp opera 
{
if(recherche_syn($1)){printf("\033[31m Error \033[0m double declaration for %s",$1);affich();YYACCEPT;}else{insert($1,current_type,current_entity);}

if(strcmp(tableau_type->ptr,current_type) != 0){printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,current_type);}

tableau_type = NULL;
} ;

direct_value: integer {if(atoi($1)<-32768 & atoi($1)> 32767){printf("\033[31m Error \033[0m integer either bigger than 32767 or lower than (-32768)\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,$1);

} 

| real {if(division && (atoi($1) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}
tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,$1);
}

| car {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,$1);
}

| '"'string'"' {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
strcpy(tmp_value,$2);
};

variable: mc_idf 
{
	if(recherche_syn($1)){printf("\033[31m Error \033[0m double declaration for %s\n",$1);affich();YYACCEPT;}
	else{insert($1,current_type,current_entity);}}

| mc_idf '[' integer ']' 
{
	if(!arrays){printf("\033[31m Error \033[0m library arrays wasn't included\n");affich();YYACCEPT;}
	
	if(atoi($3)<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}

	if(recherche_syn($1)){printf("\033[31m Error \033[0m double declaration for %s\n",$1);affich();YYACCEPT;}
	else{insert_tab($1,current_type,"TAB",atoi($3));}

	
};


affectation: mc_idf '[' integer ']' mc_arithOp opera 
{
	if(!recherche_syn($1)){printf("\033[31m Error \033[0m not declared %s\n",$1);affich();YYACCEPT;}  
	if(strcmp(tableau_type->ptr,recherche_type($1)) != 0)
	{printf("\033[31m Error \033[0m type non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,recherche_type($1));affich();YYACCEPT;}

	tableau_type = NULL;
	if(atoi($3)<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}

	if(atoi($3) > recherche_max_index($1)) {printf("\033[31m Error \033[0m index > max_index for this array\n");affich();YYACCEPT;}
	

}

|mc_idf mc_arithOp opera {if(!recherche_syn($1)){printf("\033[31m Error \033[0m not declared %s\n",$1);affich();YYACCEPT;}  
if(strcmp(tableau_type->ptr,recherche_type($1)) != 0){printf("\033[31m Error \033[0mtype non compatible!!last type was %s while idf type is %s\n",tableau_type->ptr,recherche_type($1));affich();YYACCEPT;}
tableau_type = NULL;
}
;

opera: constante | express | '('express')';
express: opera operand opera {strcpy(tmp_type,tableau_type->ptr); tableau_type = tableau_type->next; 
if(strcmp(tableau_type->ptr,tmp_type) != 0){printf("type non compatible!!first type was %s while second type is %s\n",tmp_type,tableau_type->ptr);affich();YYACCEPT;}

 };
//pop the last type and add the new one 

operand: ADD_OP {if(!process){printf("\033[31m Error \033[0m library process for arithmetique operation wasn't included\n");affich();YYACCEPT;}  division = false;}
| MUL_OP 
{
	if(!process){printf("\033[31m Error \033[0m library process for arithmetique operation wasn't included\n");affich();YYACCEPT;}
	if($1[0]== '/'){division = true;}else{division = false;}
};

constante: '"'string'"' {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}

 | integer {if(atoi($1)<-32768 & atoi($1)> 32767){printf("\033[31m Error \033[0m integer either bigger than 32767 or lower than (-32768)\n");affich();YYACCEPT;}

	if(division && (atoi($1) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}

| real {if(division && (atoi($1) == 0)){printf("\033[31m Error \033[0m devision per 0\n");affich();YYACCEPT;}

tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}

| car {tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;}

| mc_idf '[' integer ']' {
	
	if(!recherche_syn($1)){printf("\033[31m Error \033[0m not declared %s",$1);affich();YYACCEPT;}
	if(atoi($3)<0){printf("\033[31m Error \033[0m Can't have a negative interger as index for an array\n");affich();YYACCEPT;}
	tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,recherche_type($1)); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
	if(atoi($3) > recherche_max_index($1)) {printf("\033[31m Error \033[0m index > max_index for this array\n");affich();YYACCEPT;}

}

| mc_idf { 
	if(!recherche_syn($1)){printf("not declared %s",$1);affich();YYACCEPT;}
	tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,recherche_type($1)); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;};



read: mc_read '(' '"' mc_signeForma '"' SEP_READ '@' mc_idf ')' '$' 
{
	switch($4[0])
	{
		case ';':
		strcpy(tmp_type,"INT");
		break;
		case '%':
		strcpy(tmp_type,"FLOAT");
		break;
		case '?':
		strcpy(tmp_type,"STRING");
		break;
		case '&':
		strcpy(tmp_type,"CHAR");
		break;

		default:
		printf("Erreur signe formatage non reconnue\n");YYACCEPT;
		break;
	}
	if(!recherche_syn($8))  {printf("not declared %s",$8);affich();YYACCEPT;}  

	if(strcmp(tmp_type,recherche_type($8)) != 0)   {printf("type non compatible!! signe type is %s while idf type is %s\n",tmp_type,recherche_type($8));affich();YYACCEPT;}
	
	
};



write: mc_write '(' '"' write_string SEP_READ write_var ')' '$' { if(num != 0){printf("error signe de formatage is not equale to idf %d\n",num);}} ;

write_var: mc_idf 
{
	if(!recherche_syn($1))  {printf("not declared %s",$1);affich();YYACCEPT;} 
	if(strcmp(tableau_type->ptr,recherche_type($1)) != 0)   {printf("type non compatible!! signe type is %s while idf %s type is %s\n",tableau_type->ptr,$1,recherche_type($1));affich();YYACCEPT;}
	tableau_type = tableau_type->next;
}

| mc_idf SEP_READ write_var 
{
	if(!recherche_syn($1))  {printf("not declared %s",$1);affich();YYACCEPT;} 
	if(strcmp(tableau_type->ptr,recherche_type($1)) != 0)   {printf("type non compatible!! signe type is %s while idf %s type is %s\n",tableau_type->ptr,$1,recherche_type($1));affich();YYACCEPT;}
	tableau_type = tableau_type->next;
};


write_string: string write_string 
| '"'

| forma write_string ;


forma: mc_signeForma
{
	switch($1[0])
	{
		case ';':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"INT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '%':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"FLOAT"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '?':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"STRING"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;
		case '&':
		tmp_type_pointer = malloc(sizeof(tab_type)); strcpy(tmp_type_pointer->ptr,"CHAR"); tmp_type_pointer->next = tableau_type  ; tableau_type = tmp_type_pointer ;
		break;

		default:
		printf("Erreur signe formatage non reconnue\n");YYACCEPT;
		break;
	}
	

};

loop: loop_keyword '(' condition ')' '{' body '}';
loop_keyword: mc_while {if(!loops){printf("\033[31m Error \033[0m library loop wasn't included\n");affich();YYACCEPT;} };
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
