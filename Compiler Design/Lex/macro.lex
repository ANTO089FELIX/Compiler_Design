%{
int m=0,h=0;
%}

%%
[#define][][a-z 0-9]+ {m++;}
[#include][<][a-z]+[>] {h++;}
%%

int yywrap()
{}

int main(){
printf("Enter the statement:");
yylex();
printf("No of headers:%d",h);
printf("No of macro:%d",m);
}
