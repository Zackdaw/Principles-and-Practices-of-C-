/*
This question does not actually have a coding solution. It is instead just a grammar map.

The grammar for logical bitwise functions is as follows:

Operators: ~, !, &, ^, |.

Expression
	STerm
	Expression '|' Pterm

PTerm:
	STerm
	PTerm '^' STerm

STerm:
	Unary
	STerm '&' Unary

Unary:
	Primary
	'!' Primary
	'~' Primary

Primary:
	Number
	'(' Expression ')'

Number:
	An Integer


*/