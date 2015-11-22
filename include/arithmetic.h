#ifndef _ARITHMETIC__H_
#define _ARITHMETIC__H_

#include <iostream>
#include "stack.h"

using namespace std; 

class Arithmetic
{
	char* inputline;  //входна€ строка
	char* postfixnot;  //постификсна€ запись 

public:

	//bool CheckParenthesis(char* str); 	//ѕроверка корректности открывающих и закрывающих скобок
	//bool CheckOperator(char *s) ;	//ѕроверка наличи€ операндов между операторами

bool CheckParenthesis(char* str)
{
	TStack<int> s(100);

	int s_str=strlen(str);

	for(int i=0; i < s_str; i++)
	{
		if(str[i]=='(')
			s.PutElem(i);
		else 
			if(str[i]==')')
				if (s.StEmpty())
					throw("excess close parenthesis");
				else
					s.ExcludeElem();		
	}

	if (s.StEmpty())
		return true;
	else 
	{
		cout<<"Uncorectly close and open parenthesis"<<endl;
		return false;
	}


}

bool CheckOperator(char *s) 
{
	int s_str=strlen(s);

	char operators[]="+-*/";

	for(int i = 0; i < s_str-1;i++)
	{
		for(int j = 0; j < 4; j++)
			if ( s[i]==operators[j] )
				for(int k = 0; k < 4; k++)
					if (s[i+1]==operators[k])
					{
						cout<<"No operand between operators"<<endl;
						return false;

					}
	}


	return true;
}

int Priority(char c)
{
		if ( c=='(' )
			return 1;
		if ( c=='+' || c=='-' )
			return 2;
		if ( c=='*' || c=='/' )
			return 2;

}

bool IsOperation(char c)
{
	if ( c=='+' || c=='-' || c=='*' || c=='/')
		return true;
	else 
		return false;
}
void GetPostfixNot(char *inputline)
{
	TStack<char> oper;
	int len_s=strlen(inputline);
	int ind=0;

	for(int i=0; i<len_s; i++)
		{
			if( isdigit(inputline[i])||isalpha(inputline[i])) //если число или операнд, добавл€ем в выходную сроку
				{
					postfixnot[ind]=inputline[i];
					ind++;
					continue; 
				}

			if ( inputline[i]=='(' )
				{
					oper.PutElem( '(');
					continue;
				}

			if( IsOperation(inputline[i]))
				{
					int p=Priority((inputline[i]));

					
					if( (p > Priority(oper.CheckElem()) ) || oper.StEmpty() )
						oper.PutElem(inputline[i]);
					else 
						{
							while (p <= Priority(oper.CheckElem()))
								{
									postfixnot[ind]=oper.GetElem();
									ind++;
								}
							if( (p > Priority(oper.CheckElem()) ) || oper.StEmpty() )
								oper.PutElem(inputline[i]);
								
						}
				}

			if( inputline[i]==')')
				while ( oper.CheckElem()!='(' )
					{
									postfixnot[ind]=oper.GetElem();
									ind++;
					}


			
		}
		
}
};

#endif