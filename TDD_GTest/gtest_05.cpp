#include "pch.h"
#include "../TDD/test_05.cpp"

TEST(SimilarityCheckerTC, checkCharacterLines00) {
	int score = SimilarityChecker().checkCharacterLines("AAA", "BBB");
	EXPECT_EQ(60, score);
}

TEST(SimilarityCheckerTC, checkCharacterLines01) {
	int score = SimilarityChecker().checkCharacterLines("AAA", "BBBB");
	EXPECT_EQ(40, score);
	score = SimilarityChecker().checkCharacterLines("AAABB", "BBBB");
	EXPECT_EQ(45, score);
}