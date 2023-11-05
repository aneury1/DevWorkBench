#include <gtest/gtest.h>

namespace {
    int get(){
        return 128;
    }
}

TEST(topic,  test128){
    EXPECT_EQ(get(), 128);
}
TEST(topic,  ftest128){
    ASSERT_EQ(get(), 128) <<"this fAIL";
}

