#include <gtest.h>
#include "queue.h"
//TQueue

TEST(TQueue, throws_when_create_stack_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> a(-5));
}
TEST(TQueue, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> m(5));
}

TEST(TQueue, can_create_copied_stack)
{
	TQueue<int> m(5);
	ASSERT_NO_THROW(TQueue<int> m1(m));
}

TEST(TQueue, copied_stack_is_equal_to_source_one)
{
	TQueue<int> v(4);
	v.Push(7);
	TQueue<int> v2(v);
	EXPECT_EQ(v, v2);
}

TEST(TQueue, can_get_size)
{
	TQueue<int> v(4);
	EXPECT_EQ(4, v.GetSize());
}

TEST(TQueue, can_get_top)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(2, v.Get());
}

TEST(TQueue, can_get_top_view)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(2, v.Get());
}

TEST(TQueue, can_push)
{
	TQueue<int> v(4);
	v.Push(1);
	EXPECT_EQ(1, v.Get());
}

TEST(TQueue, can_get)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	int m = v.Pop();
	if (m != 2) ADD_FAILURE();
	else EXPECT_EQ(1, v.Get());
}


TEST(TQueue, throw_when_empty)
{
	TQueue<int> v(4);
	ASSERT_ANY_THROW(v.Get());
}

TEST(TStack, throw_when_full)
{
	TQueue<int> v(1);
	v.Push(5);
	ASSERT_ANY_THROW(v.Push(4));
}

