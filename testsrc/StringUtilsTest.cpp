#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    EXPECT_EQ(Slice("hello", 1, 4), "ell");
}

TEST(StringUtilsTest, Capitalize){
    EXPECT_EQ(Capitalize("hELLo"), "Hello");
}

TEST(StringUtilsTest, Upper){
    EXPECT_EQ(Upper("abc"), "ABC");
}

TEST(StringUtilsTest, Lower){
    EXPECT_EQ(Lower("AbC123"), "abc123");
}

TEST(StringUtilsTest, LStrip){
    EXPECT_EQ(LStrip("   hi"), "hi");
}

TEST(StringUtilsTest, RStrip){
    EXPECT_EQ(RStrip("hi   "), "hi");
}

TEST(StringUtilsTest, Strip){
    EXPECT_EQ(Strip("  hi  "), "hi");
}

TEST(StringUtilsTest, Center){
    EXPECT_EQ(Center("hi", 4, '.'), ".hi.");
}

TEST(StringUtilsTest, LJust){
    EXPECT_EQ(LJust("hi", 4, '.'), "hi..");
}

TEST(StringUtilsTest, RJust){
    EXPECT_EQ(RJust("hi", 4, '.'), "..hi");
}

TEST(StringUtilsTest, Replace){
    EXPECT_EQ(Replace("a-b-c", "-", "+"), "a+b+c");
}

TEST(StringUtilsTest, Split){
    auto v = Split("a,b,c", ",");
    EXPECT_EQ(v.size(), 3);
}

TEST(StringUtilsTest, Join){
    std::vector<std::string> v = {"a","b","c"};
    EXPECT_EQ(Join("-", v), "a-b-c");
}

TEST(StringUtilsTest, ExpandTabs){
    EXPECT_EQ(ExpandTabs("a\tb", 4), "a   b");
}

TEST(StringUtilsTest, EditDistance){
    EXPECT_EQ(EditDistance("kitten", "sitting"), 3);
}
