#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(Upper("abc"), "ABC");
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(Upper("AbC123"), "ABC123");
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(Lower("ABC"),"abc");
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(Lower("AbC123"),"abc123");
}

TEST(StringUtilsTest, LStrip){
    
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
