%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// extern YYSTYPE yylval;
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
real {Integer}+"."(0)*{Integer}+
new_line [\n]
comments ("/*"(.|\n)*"*/")  // doesnt work well since .* is a greedy operator
character ['].[']
chaine ["][^"]*["]
sign [-|+]
signed_int "("+{sign}+{Integer}+")"
signed_float "("+{sign}+{real}+")"
operateur_arithmetique ([-+/*]|":=")
operateur_logique ("EG"|"SUP"|"SUPE"|"INF"|"INFE"|"DIFF")
signe_formatage [:%?&]
separateur ("["|"]"|"|"|"("|")"|"##"|"{"|"}"|"$"|"@"|"//")



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

{signed_int} {
	lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a signed int  line = %d\n",yytext,line);
}
{signed_float} {
	lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a signed float line = %d\n",yytext,line);
}
{character} {lenght = strlen(yytext);count+=strlen(yytext);
	printf("%s is a char line = %d\n",yytext,line);
	
}

{chaine} { 
	lenght = strlen(yytext);
	count+=strlen(yytext);
	printf("%s is a string line = %d\n",yytext,line);
	
}
{real} {
	count+=strlen(yytext);
	printf("%s is a float line = %d\n",yytext,line); 
		
}
{Integer} {
	count+=strlen(yytext);
	printf("%s is aN int line = %d\n",yytext,line);
}

PROCESS { count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);
	
}
LOOP {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
ARRAY {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}

Programme {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}

CONST {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
INTEGER {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
REAL {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
CHAR {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
STRING {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}

READ {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
WRITE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}

WHILE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
EXECUT {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
IF {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
END_IF {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}
ELSE {count+=strlen(yytext);
printf("%s is a key word  line = %d\n",yytext,line);}

{operateur_arithmetique} {count+=strlen(yytext);
printf("%s is an arithmetique operator  line = %d\n",yytext,line);

}
{operateur_logique} {count+=strlen(yytext);
printf("%s is an loqique operator  line = %d\n",yytext,line);

}
{signe_formatage} {count+=strlen(yytext);
printf("%s is a formate signe  line = %d\n",yytext,line);

}
{separateur} {count+=strlen(yytext);
printf("%s is a separator  line = %d\n",yytext,line);

}


{IDF} { printf("%s is an idf at line %d collum %d\n",yytext,line,count); count+=strlen(yytext);}


{new_line} { line++; count = 1;
}


[ \t] { count+=strlen(yytext);}
. 	{printf("Erreur %s code %d line %d collone %d\n",yytext,yytext[0],line,count); count+=strlen(yytext);}


%%

int main(int argc , char **argv)
{	
	if(argc != 2)
	{
		printf("Error need missing file argument");
	}
	else
	{
		yyin = fopen(argv[1],"r");
		yylex();
	}
	//printf("Count = %d \n",count);
	
}
