#include <string>
#include <vector>

class SimilarityChecker
{
public:
	int checkCharacterLines(const std::string& str1, const std::string& str2)
	{
		int a = str1.length();
		int b = str2.length();
		if (a < b) std::swap(a, b);

		int gap = a - b;
		if (gap == 0) return 60;
		if (a >= b * 2) return 0;

		double result = (1.f - (double)gap / b) * 60.f;
		return (int)result;
	}
};

#ifndef GTEST_INCLUDE_GTEST_GTEST_H_
int main(int argc, char* argv[])
{
	return 0;
}
#endif