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
	bitAdd(ab_carry, c, abc_sum, abc_carry);
	result = abc_sum;
	carry = ab_carry | abc_carry;
}

int add(int a, int b)
{
	int mask = 1;
	int result = 0, carry = 0;
	int final_result = 0;
	int a_bit = (a & mask) > 0;
	int b_bit = (b & mask) > 0;

	bitAdd(a_bit, b_bit, result, carry);
	final_result = final_result | 1;

	for (int i = 2; i < 32; i++)
	{
		mask = mask << 1;
		final_result = final_result << 1;
		a_bit = (a & mask) > 0;
		b_bit = (b & mask) > 0;
		bitAdd(a_bit, b_bit, carry, result, carry);
		final_result = final_result | result;
		cout << result;
		
	}
	return final_result;
}

int main(void)
{
	int result, carry;
	add(18, 5);
	return 0;
}