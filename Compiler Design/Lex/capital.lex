
%{
%}

%%
[A-Z] {printf("It is a capital letter");}
.+ {printf("It is not a capital letter");}

%%
int yywrap(){}
int main()
{
  printf("Enter a letter");
  yylex();
}
