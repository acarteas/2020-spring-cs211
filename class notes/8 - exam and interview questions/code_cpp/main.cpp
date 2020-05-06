#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unordered_map>
#include <functional>
#include <chrono>

using namespace std::chrono;
using namespace std;

void bitAdd(int a, int b, int& result, int& carry)
{
	result = a ^ b;
	carry = a & b;
}

void bitAdd(int a, int b, int c, int& result, int& carry)
{
	int ab_sum, ab_carry;
	bitAdd(a, b, ab_sum, ab_carry);

	int abc_sum, abc_carry;
	bitAdd(ab_sum, c, abc_sum, abc_carry);
	result = abc_sum;
	carry = ab_carry | abc_carry;
}

int toBit(int number)
{
	return number & 1;
}

void shift(int &number)
{
	number = number >> 1;
}

int add(int a, int b)
{
	int results[32], carries[32];

	//peform add
	bitAdd(toBit(a), toBit(b), results[0], carries[0]);
	for (int i = 1; i < 32; i++)
	{
		shift(a);
		shift(b);
		bitAdd(toBit(a), toBit(b), carries[i - 1], results[i], carries[i]);
	}

	//convert to int
	int result = 0;
	for (int i = 31; i > -1; i--)
	{
		result = result << 1;
		result = result | results[i];
		
	}
	return result;
}

int main(void)
{
	int result, carry;
	add(123, 456);
	return 0;
}