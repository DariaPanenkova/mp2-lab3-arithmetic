#include <gtest.h>
#include "arithmetic.h"

TEST(Arithmetic, check_parenthesis)
{
	string str="a+5*(b+2)";
	Arithmetic a(str);
	
	EXPECT_TRUE(a.CheckParenthesis());
}

TEST(Arithmetic, check_parenthesis_1)
{
	string str="((a+b";
	Arithmetic a(str);
	
	EXPECT_FALSE(a.CheckParenthesis());
}

TEST(Arithmetic, check_postfix_not)
{
	string str="(2+3.4)*a";
	Arithmetic a(str);

	string post="3.4 2+a*";

	a.GetPostfixNot();
	str=a.GetPostNot();

	EXPECT_EQ(post,str);
}



