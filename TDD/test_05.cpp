#include <string>
#include <vector>
#include <stdexcept>

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

	void assertInvalidString(const std::string& str1, const std::string& str2)
	{
		for(char ch : str1 + str2)
		{
			if (ch < 'A' || ch > 'Z') {
				throw std::invalid_argument("Allow UPPER case only ");
			}
		}
	}

	int getAlphabetMatchingScore(const std::string& str1, const std::string& str2)
	{
		std::vector<int> str_map1 = { 0, };
		str_map1.resize(32);
		for (char ch : str1) {
			str_map1[ch - 'A'] = 1;
		}
		std::vector<int> str_map2 = { 0, };
		str_map2.resize(32);
		for (char ch : str2) {
			str_map2[ch - 'A'] = 1;
		}
		if (std::equal(str_map1.begin(),
		               str_map1.end(), str_map2.begin()))
		{
			return 40;
		}
		return 0;
	}

	int checkAlphabetMatching(const std::string& str1, const std::string& str2)
	{
		assertInvalidString(str1, str2);
		if (str1 == str2) return 40;

		return getAlphabetMatchingScore(str1, str2);
	}
private:
	bool needToSuffle(int a, int b)
	{
		return a < b;
	}

	bool isZeroScore(int a, int b)
	{
		return a >= b * 2;
	}

	double getCharactorLinesScore(int a, int b)
	{
		double result = (1.f - (double)(a - b) / b) * 60.f;
		return static_cast<int>(result);
	}
};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif