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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

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

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->next !=  NULL);
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
    output = Add(kpl_struct_1, 3, 5);
    output = Add(output, start, end);

    EXPECT_EQ(7, output->next->next->start);
    EXPECT_EQ(9, output->next->next->end);
    free(kpl_struct_1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
