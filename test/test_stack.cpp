#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack) 
{
	ASSERT_NO_THROW(TStack<int> a);
}

TEST(TStack, can_add_element)
{
	TStack<int> s(4);

	ASSERT_NO_THROW(s.PutElem(2));

}

TEST(TStack, can_not_add_element_in_full_stack)
{
	TStack<int> s(4);

	for(int i = 0; i < 4; i++)
		s.PutElem(1);

	ASSERT_ANY_THROW(s.PutElem(3));


}

TEST(TStack, can_get_elem)
{
	TStack<int> s(4);

	for(int i = 0; i < 4; i++)
		s.PutElem(1);
	ASSERT_NO_THROW(s.GetElem());

}
TEST(TStack, can_not_get_element_in_empty_stack)
{
	TStack<int> s(4);

	ASSERT_ANY_THROW(s.GetElem());
}

TEST(TStack,can_chek_stack_empty_true)
{
	TStack<int> s(4);

	EXPECT_TRUE(s.StEmpty());
}
TEST(TStack,can_chek_stack_empty_false)
{
	TStack<int> s(4);

	for(int i = 0; i < 4; i++)
		s.PutElem(1);

	EXPECT_FALSE(s.StEmpty());
}
TEST(TStack,can_chek_stack_full_false)
{
	TStack<int> s(4);

	EXPECT_FALSE(s.StFull());
}
TEST(TStack,can_chek_stack_full_true)
{
	TStack<int> s(4);

	for(int i = 0; i < 4; i++)
		s.PutElem(1);

	EXPECT_TRUE(s.StFull());
}