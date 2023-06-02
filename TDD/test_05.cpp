#include <string>
#include <vector>
#include <stdexcept>
#include <bitset>

class SimilarityChecker
{
public:
	int checkCharacterLines(const std::string& str1, const std::string& str2)
	{
		int a = str1.length();
		int b = str2.length();
		if (needToSuffle(a, b)) std::swap(a, b);
		if (isZeroScore(a, b)) return 0;
		return getCharactorLinesScore(a, b);
	}

	int checkAlphabetMatching(const std::string& str1, const std::string& str2)
	{
		assertInvalidString(str1, str2);
		if (str1 == str2) return MAX_ALPH_SCORE;

		return getAlphabetMatchingScore(str1, str2);
	}
private:
	void assertInvalidString(const std::string& str1, const std::string& str2)
	{
		for (char ch : str1 + str2) {
			if (ch < 'A' || ch > 'Z') {
				throw std::invalid_argument("Allow UPPER case only ");
			}
		}
	}

	int getAlphabetMatchingScore(const std::string& str1, const std::string& str2)
	{
		uint32_t s1b = 0, s2b = 0;
		for (char ch : str1) s1b |= 1 << (ch - 'A');
		for (char ch : str2) s2b |= 1 << (ch - 'A');

		double totalCount = std::bitset<32>(s1b | s2b).count();
		double sameCount = std::bitset<32>(s1b & s2b).count();

		return (int)(sameCount / totalCount * MAX_ALPH_SCORE);
	}

	bool needToSuffle(const int& a, const int& b)
	{
		return a < b;
	}

	bool isZeroScore(const int& a, const int& b)
	{
		return a >= b * 2;
	}

	double getCharactorLinesScore(const int& a, const int& b)
	{
		double result = (1.f - (double)(a - b) / b) * MAX_CHAR_SCORE;
		return static_cast<int>(result);
	}
private:
	const double MAX_CHAR_SCORE = 60.f;
	const double MAX_ALPH_SCORE = 40.f;

};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif