extern "C" {
    #include "kpl_struct.h"
}
#include <gtest/gtest.h>
 
TEST(Add_function, NULL_structure) {
    ASSERT_TRUE(Add(NULL, 0, 0) ==  NULL);
}

TEST(Add_function, not_NULL_structure) {
    kpl_struct_t kpl_struct = {0};
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 1;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, 0, 1);

    ASSERT_TRUE(output !=  NULL);
}

TEST(Add_function, one_range_add_the_same) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 0;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 1;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(0, output->start);
    EXPECT_EQ(1, output->end);
}

TEST(Add_function, one_range_add_one_more) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 0;
    int32_t end = 2;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 1;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(0, output->start);
    EXPECT_EQ(2, output->end);
}
 
TEST(Add_function, one_range_add_one_more_smaller_at_end) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 0;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 2;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(0, output->start);
    EXPECT_EQ(2, output->end);
}

TEST(Add_function, one_range_add_one_more_at_start) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = -1;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 2;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(-1, output->start);
    EXPECT_EQ(2, output->end);
}

TEST(Add_function, one_range_add_one_smaller_start_one_bigger_end) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = -1;
    int32_t end = 3;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 0;
    kpl_struct.end = 2;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(-1, output->start);
    EXPECT_EQ(3, output->end);
}

TEST(Add_function, one_range_add_one_bigger_start_one_smaller_end) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 1;
    kpl_struct.end = 6;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(6, output->end);
}

TEST(Add_function, one_range_add_the_same_start) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = -5;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 1;
    kpl_struct.end = 6;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(-5, output->start);
    EXPECT_EQ(6, output->end);
}

TEST(Add_function, one_range_add_the_same_end) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 6;
    int32_t end = 8;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 1;
    kpl_struct.end = 6;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(8, output->end);
}

TEST(Add_function, one_range_add_second_up) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 1;
    kpl_struct.end = 2;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(2, output->end);
}

TEST(Add_function, one_range_add_second_down) {
    kpl_struct_t kpl_struct = {0};
    int32_t start = -3;
    int32_t end = 0;
    kpl_struct_t* output = NULL;
    kpl_struct.start = 1;
    kpl_struct.end = 2;    
    kpl_struct.next = NULL;

    output = Add(&kpl_struct, start, end);

    EXPECT_EQ(-3, output->start);
    EXPECT_EQ(0, output->end);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
