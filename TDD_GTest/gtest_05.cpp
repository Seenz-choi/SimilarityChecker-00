#include "pch.h"
#include "../TDD/test_05.cpp"

class SCFixture : public testing::Test
{
public:
	SimilarityChecker sc;
};

TEST_F(SCFixture, checkCharacterLines00) {
	EXPECT_EQ(60, sc.checkCharacterLines("AAA", "BBB"));
}

TEST_F(SCFixture, checkCharacterLines01) {
	EXPECT_EQ(40, sc.checkCharacterLines("AAA", "BBBB"));
	EXPECT_EQ(45, sc.checkCharacterLines("AAABB", "BBBB"));
}

TEST_F(SCFixture, checkCharacterLines02) {
	EXPECT_EQ(0, sc.checkCharacterLines("AA", "BBBB"));
}

TEST_F(SCFixture, checkAlphabetMatching00) {
	EXPECT_EQ(40, sc.checkAlphabetMatching("AAA", "AAA"));
	EXPECT_EQ(40, sc.checkAlphabetMatching("ABC", "CAB"));
}

TEST_F(SCFixture, checkAlphabetMatching01) {
	EXPECT_THROW(sc.checkAlphabetMatching("aaa", "AAA"),
	             std::invalid_argument);
}

TEST_F(SCFixture, checkAlphabetMatching02) {
	EXPECT_EQ(26, sc.checkAlphabetMatching("BBAA", "ABC"));
	EXPECT_EQ(0, sc.checkAlphabetMatching("DDEFG", "ABC"));
}