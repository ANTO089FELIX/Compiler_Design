%{
%}

%%

[0-3][0-9]\/[0-1][0-9]\/[2][0][0-9][0-9] {printf("Valid Date of Birth");}
.+ {printf("Invalid Date of Birth");}

%%

int yywrap()
{}

int main(){
printf("Enter your Date of Birth: ");
yylex();
}
