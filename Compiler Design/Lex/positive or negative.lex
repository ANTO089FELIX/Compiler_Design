
%{
int positive_no = 0, negative_no = 0;
%}

%%
[-][0-9]+ {negative_no++;}
		

[0-9]+ {positive_no++;} 	
%%


int yywrap(){}
int main()											
{

yylex();
printf ("number of positive numbers = %d,"
		"number of negative numbers = %d\n",
				positive_no, negative_no);

return 0;
}
