#include <string>
#include <vector>

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