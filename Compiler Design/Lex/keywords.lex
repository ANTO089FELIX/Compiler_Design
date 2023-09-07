%{ 
#include <stdio.h>
int n = 0 ;  
%} 
%% 
"while"|"if"|"else"|"int"|"float"|"main"  {n++;printf("\t keywords : %s", yytext);}   
[a-zA-Z]+ {n++;printf("\t identifier : %s", yytext);} 

%% 
int yywrap(){
return 1;
}
int main() 
{ 
printf("enter the string:\n");
yylex();
}
