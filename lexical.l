%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "synt.tab.h"


 extern YYSTYPE yylval;
int i = 0;

char *tmp;
int count = 1;
int line = 1;
int lenght;
//tableau * pointer;
//tableau * tab;






%}
DIGIT [0-9]
letter [a-zA-Z]
IDF [A-Z]({letter}|{DIGIT})*
Integer (([1-9]{DIGIT}*)|(0))
real {Integer}+"."(0)*{Integer}
new_line [\n]
comments ("/*"(.|\n)*"*/")  // doesnt work well since .* is a greedy operator
character ['].[']
chaine [a-zA-Z0-9,.=!]*
sign [-|+]
signed_int "("{sign}{Integer}")"
signed_float "("{sign}{real}")"
operateur_arithmetique ":="
multi [*/]
operateur_logique ("EG"|"SUP"|"SUPE"|"INF"|"INFE"|"DIFF")
signe_formatage [;%?&]
separateur ("["|"]"|"|"|"("|")"|"#"|"{"|"}"|"$"|"@"|":"|["])



%%


"/*" { // non greedy version of comments still doesn't work well if the the comment is not closed with */
	register int c;
	for (;;){
		printf("/*");
		while((c=input()) != '*' && c != '\0' && c != EOF  ){
			if(c == '\n'){line++;count =1;}
			printf("%c",c);		
		}
		if (c == '*'){
			printf("%c",c);
			if ((c = input()) == '/'){
				printf("%c",c);	
				break;
			}
				
		}
		if (c == '\0' || c == EOF){
			printf("error in line %d comment doesnt close",line);
			break;		
		}
	}
	lenght = strlen(yytext);count+=strlen(yytext);
	printf(" is a comment line = %d\n",line);

}

[|] return SEP_READ;

{signed_int} {
	lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a signed int  line = %d\n",yytext,line);
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
        strcpy(tmp,&yytext[1]); tmp[strlen(tmp)-1] = '\0' ; yylval.chaine = tmp ; 
	return integer;
}
{signed_float} {
	lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a signed float line = %d\n",yytext,line);
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
        strcpy(tmp,&yytext[1]); tmp[strlen(tmp)-1] = '\0' ; yylval.chaine = tmp ; 
	return real;
}
{character} {lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a char line = %d\n",yytext,line);
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
        strcpy(tmp,yytext);yylval.chaine = tmp ; 
	return car;
	
}


{real} {
	count+=strlen(yytext);
	printf("%s is a float line = %d\n",yytext,line);
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
        strcpy(tmp,yytext);yylval.chaine = tmp ;  
	return real;
}
{Integer} {
	count+=strlen(yytext);
	printf("%s is aN int line = %d\n",yytext,line);
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
        strcpy(tmp,yytext);yylval.chaine = tmp ; 
	return integer;
}

PROCESS { count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);
	return mc_proc;
	
}
LOOP {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_loop;}
ARRAY {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_arr;}

Programme {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_prog;}

VAR {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_var;}

CONST {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_const;}
INTEGER {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_integer;}
REAL {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_real;}
CHAR {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_car;}
STRING {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_string;}

READ {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_read;}
WRITE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_write;}

WHILE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_while;}
EXECUT {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_execut;}
IF {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_if;}
END_IF {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_endif;}
ELSE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);return mc_else;}

{operateur_arithmetique} {count+=strlen(yytext);
printf("%s is an arithmetique operator  line = %d\n",yytext,line);
return mc_arithOp;
}
{operateur_logique} {count+=strlen(yytext);
printf("%s is an loqique operator  line = %d\n",yytext,line);
return mc_logiqOp;
}

"//" {count+=strlen(yytext);
printf("%s is a separator  line = %d\n",yytext,line);
return var_sep;

}
{sign} {count+=strlen(yytext);
printf("%s is a ADD OP  line = %d\n",yytext,line);
return ADD_OP;
}
{multi} {count+=strlen(yytext);
printf("%s is a MUL OP line = %d\n",yytext,line);
tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
strcpy(tmp,yytext);yylval.chaine = tmp ; 
return MUL_OP;
}

{separateur} {count+=strlen(yytext);
printf("%s is a separator  line = %d\n",yytext,line);
return yytext[0];
}

{signe_formatage} {count+=strlen(yytext);
printf("%s is a formate signe  line = %d\n",yytext,line);
tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
strcpy(tmp,yytext);yylval.chaine = tmp ; 
return mc_signeForma;
}
{IDF} { printf("%s is an idf at line %d collum %d\n",yytext,line,count); count+=strlen(yytext);
	//insert(yytext,"","IDF");
	tmp = malloc(sizeof(char)*(strlen(yytext)+1)); 
	strcpy(tmp,yytext);yylval.chaine = tmp ; return mc_idf;}

{chaine} { 
	lenght = strlen(yytext);
	count+=strlen(yytext);
	printf("%s is a string line = %d\n",yytext,line);
	return string;
	
}




{new_line} { line++; count = 1;
}


[ \t] { count+=strlen(yytext);}
. 	{printf("Erreur %s code %d line %d collone %d\n",yytext,yytext[0],line,count); count+=strlen(yytext);}


%%
