#include <gtest/gtest.h>
#include "../core/trie.h"
#include "../core/utils.h"

// test trie insertion and exact search
TEST(TrieTest, InsertAndSearch) {
    Trie T;
    T.ins("hello");
    T.ins("oxygen");

    EXPECT_TRUE(T.search_exact("hello"));
    EXPECT_TRUE(T.search_exact("oxygen"));
    EXPECT_FALSE(T.search_exact("oxy"));
}

// prefix search test
TEST(TrieTest, PrefixSearch) {
    Trie T;
    T.ins("oxygen");
    T.ins("oxide");
    T.ins("oxford");

    auto results = T.search_pre("ox");
    EXPECT_EQ(results.size(), 3);
    EXPECT_NE(std::find(results.begin(), results.end(), "oxide"), results.end());  
    EXPECT_NE(std::find(results.begin(), results.end(), "oxygen"), results.end());
    EXPECT_NE(std::find(results.begin(), results.end(), "oxford"), results.end());
}

// test data loading
TEST(utilsTest, LoadData) {
    std::vector<std::string> data = get_array("test_data.txt");
    EXPECT_GT(data.size(), 0);
    EXPECT_EQ(data[0], "hello");
}