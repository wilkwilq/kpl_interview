extern "C" {
    #include "kpl_struct.h"
}
#include <gtest/gtest.h>
 
TEST(Add_function, NULL_structure) {
    ASSERT_TRUE(Add(NULL, 0, 0) ==  NULL);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
