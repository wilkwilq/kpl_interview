extern "C" {
    #include "kpl_struct.h"
}
#include <gtest/gtest.h>
 
TEST(Add_function, NULL_structure) {
    ASSERT_TRUE(Add(NULL, 0, 0) ==  NULL);
}

TEST(Add_function, not_NULL_structure) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 1;    
    kpl_struct->next = NULL;

    output = Add(kpl_struct, 0, 1);

    ASSERT_TRUE(output !=  NULL);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_the_same) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 0;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 1;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(0, output->start);
    EXPECT_EQ(1, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_one_more) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 0;
    int32_t end = 2;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 1;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(0, output->start);
    EXPECT_EQ(2, output->end);
    free(kpl_struct);
}
 
TEST(Add_function, one_range_add_one_more_smaller_at_end) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 0;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(0, output->start);
    EXPECT_EQ(2, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_one_more_at_start) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -1;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(-1, output->start);
    EXPECT_EQ(2, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_one_smaller_start_one_bigger_end) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -1;
    int32_t end = 3;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(-1, output->start);
    EXPECT_EQ(3, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_one_bigger_start_one_smaller_end) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(6, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_the_same_start) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -5;
    int32_t end = 1;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(-5, output->start);
    EXPECT_EQ(6, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_the_same_end) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 6;
    int32_t end = 8;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next ==  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(8, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_second_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(2, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_second_down) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -3;
    int32_t end = 0;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->prev ==  NULL);
    EXPECT_EQ(-3, output->start);
    EXPECT_EQ(0, output->end);
    free(kpl_struct);
}

TEST(Add_function, one_range_add_second_up_check_second) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;
    kpl_struct->prev = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next ==  NULL);
    EXPECT_EQ(3, output->next->start);
    EXPECT_EQ(5, output->next->end);
    free(kpl_struct);
}

TEST(Add_function, two_range_add_third_down) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -3;
    int32_t end = -5;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 2;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 3, 5);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next ==  NULL);
    EXPECT_EQ(-3, output->start);
    EXPECT_EQ(-5, output->end);
    free(kpl_struct_1);
}

TEST(Add_function, two_range_add_third_up) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 7;
    int32_t end = 9;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 2;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 3, 5);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next ==  NULL);
    EXPECT_EQ(7, output->next->next->start);
    EXPECT_EQ(9, output->next->next->end);
    free(kpl_struct_1);
}

TEST(Add_function, three_range_add_fourth_up) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 13;
    int32_t end = 15;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 2;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 3, 5);
    output = Add(kpl_struct_1, 7, 9);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next->next ==  NULL);
    EXPECT_EQ(13, output->next->next->next->start);
    EXPECT_EQ(15, output->next->next->next->end);
    free(kpl_struct_1);
}

TEST(Add_function, two_range_one_merge) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 10;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 5;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 8, 12);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(12, output->end);
    free(kpl_struct_1);
}

TEST(Add_function, three_range_one_merge) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 10;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 5;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 8, 12);
    output = Add(kpl_struct_1, 15, 20);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next->next ==  NULL);
    EXPECT_EQ(15, output->next->start);
    EXPECT_EQ(20, output->next->end);
    free(kpl_struct_1);
}

TEST(Add_function, three_range_merge_to_one) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 23;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 5;    
    kpl_struct_1->next = NULL;    
    kpl_struct_1->prev = NULL;    
    output = Add(kpl_struct_1, 8, 12);
    output = Add(kpl_struct_1, 15, 20);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(23, output->end);
    free(kpl_struct_1);
}

TEST(Add_function, four_range_merge_to_one) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 24;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 5;    
    kpl_struct_1->next = NULL;    
    output = Add(kpl_struct_1, 8, 12);
    output = Add(kpl_struct_1, 15, 20);
    output = Add(kpl_struct_1, 22, 33);
    output = Add(output, start, end);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(33, output->end);
    free(kpl_struct_1);
}

TEST(Add_function, three_range_one_merge_up) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 9;
    int32_t end = 18;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 5;    
    kpl_struct_1->next = NULL;    
    output = Add(kpl_struct_1, 8, 12);
    output = Add(kpl_struct_1, 15, 20);
    output = Add(output, start, end);

    EXPECT_EQ(8, output->next->start);
    EXPECT_EQ(20, output->next->end);
    free(kpl_struct_1);
}

TEST(Add_function, one_range_one_overlapping) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 4;    
    kpl_struct_1->next = NULL;    
    output = Add(kpl_struct_1, start, end);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(5, output->end);
    free(kpl_struct_1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
