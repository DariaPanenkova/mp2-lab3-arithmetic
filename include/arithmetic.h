#ifndef _ARITHMETIC__H_
#define _ARITHMETIC__H_

#include <iostream>
#include "stack.h"

using namespace std; 

class Arithmetic
{
	string inputline;  //входна€ строка
	string postfixnot;  //постификсна€ запись 

	TStack<string> st_post;

public:

Arithmetic(string s)
{
		inputline=s;

}


	//bool CheckParenthesis(char* str); 	//ѕроверка корректности открывающих и закрывающих скобок
	//bool CheckOperator(char *s) ;	//ѕроверка наличи€ операндов между операторами

bool CheckParenthesis()
{
	TStack<int> s(100);

	int s_str=inputline.size();

	for(int i=0; i < s_str; i++)
	{
		if(inputline[i]=='(')
			s.PutElem(i);
		else 
			if(inputline[i]==')')
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

bool CheckOperator() 
{
	int s_str=inputline.size();

	char operators[]="+-*/";

	for(int i = 0; i < s_str-1;i++)
	{
		for(int j = 0; j < 4; j++)
			if ( inputline[i]==operators[j] )
				for(int k = 0; k < 4; k++)
					if (inputline[i+1]==operators[k])
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
			return 3;

}

bool IsOperation(char c)
{
	if ( c=='+' || c=='-' || c=='*' || c=='/')
		return true;
	else 
		return false;
}

bool IsDigit(char c)
{
	if( isdigit(c) || (c=='.') )
		return true;
	else
		return false;

}
void GetPostfixNot()
{
	TStack<char> oper;
	int len_s=inputline.size();
	postfixnot = "";

	for(int i = 0; i < len_s; i++)
		{
			if( IsDigit(inputline[i])) {
				
					postfixnot+=inputline[i];
					while ( IsDigit(inputline[i+1]) )
						{
							i++;
							postfixnot+=inputline[i];
							
						}
					postfixnot+=' ';
					continue; 
				}

			if(isalpha(inputline[i])) 
				{
					postfixnot+=inputline[i];
					postfixnot+=' ';
					
					continue; 
				}

			if ( inputline[i]=='(' )
				{
					oper.PutElem( '(' );
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
									postfixnot+=oper.GetElem();
									postfixnot+=' ';

								}
							if( (p > Priority(oper.CheckElem()) ) || oper.StEmpty() )
								oper.PutElem(inputline[i]);
								
						}
				}

			if( inputline[i]==')')
				while ( oper.CheckElem() != '(' )
					{
						postfixnot+=oper.GetElem();
						postfixnot+=' ';
									
					}
	
		}
	while ( !(oper.StEmpty())  && (oper.CheckElem() != '(' ))  //
		{
			postfixnot+=oper.GetElem();
			postfixnot+=' ';
	    }
}

string GetPostNot()
{
		return postfixnot;
}


//стек дл€ вычислени€ польской записи 
void PostfixSt()
{
	TStack<string> inv_st_post;
	for( int i=0; i < postfixnot.size()-1; i++)
		{
			if (IsDigit(postfixnot[i])) 
				{
					string digit;
					while ( postfixnot[i]!= ' ' )
						{
							digit += postfixnot[i];
							i++;
						}
					inv_st_post.PutElem(digit);
					continue;
				}
		
			if ( postfixnot[i]== ' ' )
				i++;

			else
			{
				string str;
				str +=postfixnot[i];
				inv_st_post.PutElem(str);
			}
		}
	while( !(inv_st_post.StEmpty()) )
		st_post.PutElem(inv_st_post.GetElem());
}




};

#endif