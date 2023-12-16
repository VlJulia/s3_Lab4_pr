#include <gtest.h>
#include "queue.h"
//TQueue

TEST(TQueue, throws_when_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> a(-5));
}
TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> m(5));
}

TEST(TQueue, can_create_copied_queue)
{
	TQueue<int> m(5);
	ASSERT_NO_THROW(TQueue<int> m1(m));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
	TQueue<int> v(4);
	v.Push(7);
	TQueue<int> v2(v);
	EXPECT_EQ(v, v2);
}
TEST(TQueue, copied_queue_has_own_memory)
{
	TQueue<int> v(4);
	TQueue<int> v2(v);
	v.Push(7);
	EXPECT_NE(v, v2);
}
TEST(TQueue, can_get_size)
{
	TQueue<int> v(4);
	EXPECT_EQ(4, v.GetSize());
}

TEST(TQueue, can_get)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(1, v.Get());
}

TEST(TQueue, can_get_start)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	EXPECT_EQ(0, v.GetStart());
}

TEST(TQueue, can_push)
{
	TQueue<int> v(4);
	v.Push(1);
	EXPECT_EQ(1, v.Get());
}

TEST(TQueue, can_pop)
{
	TQueue<int> v(4);
	v.Push(1);
	v.Push(2);
	int m = v.Pop();
	if (m != 1) ADD_FAILURE();
	else EXPECT_EQ(2, v.Get());
}


TEST(TQueue, throw_when_empty)
{
	TQueue<int> v(4);
	ASSERT_ANY_THROW(v.Get());
}

TEST(TQueue, throw_when_full)
{
	TQueue<int> v(1);
	v.Push(5);
	ASSERT_ANY_THROW(v.Push(4));
}

