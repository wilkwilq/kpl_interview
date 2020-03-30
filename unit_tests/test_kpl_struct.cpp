extern "C" {
    #include "kpl_struct.h"
}
#include <gtest/gtest.h>

static void free_allocated_mem(kpl_struct_t* kpl_struct) 
{
    kpl_struct_t* temp_kpl_struct = NULL;
    if (kpl_struct != NULL) {
        do {
    	    if(kpl_struct->next != NULL) {
 	        temp_kpl_struct = kpl_struct->next; 
	    }
            free(kpl_struct);
            kpl_struct = temp_kpl_struct;
	    temp_kpl_struct = NULL;
        } while (kpl_struct != NULL);
    }
}

TEST(Add_function, NULL_structure) {
    kpl_struct_t* kpl_struct = NULL;
    
    kpl_struct = Add(NULL, 0, 1);

    EXPECT_EQ(0, kpl_struct->start);
    EXPECT_EQ(1, kpl_struct->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, not_NULL_structure) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* output = NULL;
    kpl_struct->start = 0;
    kpl_struct->end = 1;    
    kpl_struct->next = NULL;

    output = Add(kpl_struct, 0, 1);

    ASSERT_TRUE(output !=  NULL);
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
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
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, two_range_add_third_down) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = -3;
    int32_t end = -5;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 3, 5);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next ==  NULL);
    EXPECT_EQ(-3, output->start);
    EXPECT_EQ(-5, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, two_range_add_third_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 7;
    int32_t end = 9;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 3, 5);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next ==  NULL);
    EXPECT_EQ(7, output->next->next->start);
    EXPECT_EQ(9, output->next->next->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, three_range_add_fourth_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 13;
    int32_t end = 15;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 2;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 3, 5);
    output = Add(kpl_struct, 7, 9);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next !=  NULL);
    ASSERT_TRUE(output->next->next->next->next ==  NULL);
    EXPECT_EQ(13, output->next->next->next->start);
    EXPECT_EQ(15, output->next->next->next->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, two_range_one_merge) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 10;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 5;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 8, 12);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(12, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, three_range_one_merge) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 10;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 5;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 8, 12);
    output = Add(kpl_struct, 15, 20);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next->next ==  NULL);
    EXPECT_EQ(15, output->next->start);
    EXPECT_EQ(20, output->next->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, three_range_merge_to_one) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 23;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 5;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 8, 12);
    output = Add(kpl_struct, 15, 20);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(23, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, four_range_merge_to_one) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 4;
    int32_t end = 24;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 5;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 8, 12);
    output = Add(kpl_struct, 15, 20);
    output = Add(kpl_struct, 22, 33);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(33, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, three_range_one_merge_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 9;
    int32_t end = 18;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 5;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, 8, 12);
    output = Add(kpl_struct, 15, 20);
    output = Add(output, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next->next ==  NULL);
    EXPECT_EQ(8, output->next->start);
    EXPECT_EQ(20, output->next->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, one_range_one_overlapping) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    int32_t start = 3;
    int32_t end = 5;
    kpl_struct_t* output = NULL;
    kpl_struct->start = 1;
    kpl_struct->end = 4;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(1, output->start);
    EXPECT_EQ(5, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Add_function, create_new_struct) {
    kpl_struct_t* kpl_struct = NULL; 
    int32_t start = 0;
    int32_t end = 1;
    kpl_struct_t* output = NULL;

    output = Add(kpl_struct, start, end);

    ASSERT_TRUE(output->prev ==  NULL);
    ASSERT_TRUE(output->next ==  NULL);
    EXPECT_EQ(0, output->start);
    EXPECT_EQ(1, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, NULL_structure) {
    kpl_struct_t* kpl_struct = NULL;
    
    kpl_struct = Delete(NULL, 0, 1);

    ASSERT_TRUE(kpl_struct ==  NULL);
}

TEST(Delete_function, delete_the_same) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 4;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, 1, 4);
}

TEST(Delete_function, one_range_delete_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, 4, 10);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(4, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, one_range_delete_outside_up) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, 6, 10);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(6, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, one_range_delete_outside_down) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, -3, -1);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(6, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, one_range_delete_down) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, -3, 3);

    EXPECT_EQ(3, output->start);
    EXPECT_EQ(6, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, one_range_delete_down2) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 6;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, -3, 1);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(6, output->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, one_range_delete_middle) {
    kpl_struct_t* kpl_struct = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct->start = 1;
    kpl_struct->end = 10;    
    kpl_struct->next = NULL;    
    kpl_struct->prev = NULL;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct, 3, 6);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(3, output->end);
    EXPECT_EQ(6, output->next->start);
    EXPECT_EQ(10, output->next->end);
    free_allocated_mem(kpl_struct); 
}

TEST(Delete_function, two_range_delete_down) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = NULL;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, 3, 15);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(3, output->end);
    EXPECT_EQ(20, output->next->start);
    EXPECT_EQ(30, output->next->end);
    free_allocated_mem(kpl_struct_1); 
}

TEST(Delete_function, two_range_delete_up) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = NULL;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, 15, 25);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(10, output->end);
    EXPECT_EQ(25, output->next->start);
    EXPECT_EQ(30, output->next->end);
    free_allocated_mem(kpl_struct_1); 
}

TEST(Delete_function, two_range_middle_in_second) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = NULL;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, 23, 25);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(10, output->end);
    EXPECT_EQ(20, output->next->start);
    EXPECT_EQ(23, output->next->end);
    EXPECT_EQ(25, output->next->next->start);
    EXPECT_EQ(30, output->next->next->end);
    free_allocated_mem(kpl_struct_1); 
}

TEST(Delete_function, three_range_middle_in_second) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_3 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = kpl_struct_3;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_3->start = 40;
    kpl_struct_3->end = 50;    
    kpl_struct_3->next = NULL;    
    kpl_struct_3->prev = kpl_struct_2;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, 23, 25);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(10, output->end);
    EXPECT_EQ(20, output->next->start);
    EXPECT_EQ(23, output->next->end);
    EXPECT_EQ(25, output->next->next->start);
    EXPECT_EQ(30, output->next->next->end);
    EXPECT_EQ(40, output->next->next->next->start);
    EXPECT_EQ(50, output->next->next->next->end);
    free_allocated_mem(kpl_struct_1); 
}

TEST(Delete_function, three_range_middle_delete) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_3 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = kpl_struct_3;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_3->start = 40;
    kpl_struct_3->end = 50;    
    kpl_struct_3->next = NULL;    
    kpl_struct_3->prev = kpl_struct_2;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, 18, 33);

    EXPECT_EQ(1, output->start);
    EXPECT_EQ(10, output->end);
    EXPECT_EQ(40, output->next->start);
    EXPECT_EQ(50, output->next->end);
    free_allocated_mem(kpl_struct_1); 
}

TEST(Delete_function, three_range_delete_all) {
    kpl_struct_t* kpl_struct_1 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_2 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_t* kpl_struct_3 = (kpl_struct_t*)malloc(sizeof(kpl_struct_t));
    kpl_struct_1->start = 1;
    kpl_struct_1->end = 10;    
    kpl_struct_1->next = kpl_struct_2;    
    kpl_struct_1->prev = NULL;    
    kpl_struct_2->start = 20;
    kpl_struct_2->end = 30;    
    kpl_struct_2->next = kpl_struct_3;    
    kpl_struct_2->prev = kpl_struct_1;    
    kpl_struct_3->start = 40;
    kpl_struct_3->end = 50;    
    kpl_struct_3->next = NULL;    
    kpl_struct_3->prev = kpl_struct_2;    
    kpl_struct_t* output = NULL;
    
    output = Delete(kpl_struct_1, -18, 66);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
