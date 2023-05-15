// lab 4, variant 18
#include <iostream>

#define MAX_SIZ 100

extern "C" {
int32_t product_asm(int32_t* arr,
		    int32_t arr_siz,
		    int32_t lower,
		    int32_t upper);
}

/*
 * product_cpp
 * @arr: a pointer to the first element in an array of integers
 * @arr_siz: its size
 * @lower: the lowest allowed multiplier
 * @upper: the biggest allowed multiplier
 *
 * Returns the product of all the elements in the array.
 * If arr pointer is invalid or wrong size specified,
 * the function's behaviour is undefined.
 */
int32_t product_cpp(int32_t* arr,
		    int32_t arr_siz,
		    int32_t lower,
		    int32_t upper)
{
	int32_t res = 1;

	for (int i = 0; i < arr_siz; i++)
		if ((lower <= arr[i]) && (arr[i] <= upper))
			res *= arr[i];
	return res;
}

int main(void)
{
	int32_t lower, upper;
	int32_t arr[MAX_SIZ];
	int32_t arr_siz = 0;

	std::cout << "lower and upper bound: " << std::endl;
	std::cin >> lower >> upper;
	if (!std::cin.good())
		return 1;

	std::cout << "array: " << std::endl;
	for (auto& el: arr) {
		if (std::cin >> el)
			arr_siz++;
		else
			//cin is bad now
			break;
	}

	std::cout << "product:\n";
	std::cout	<< "in c++: "
			<< product_cpp(arr, arr_siz, lower, upper)
			<< std::endl;
	std::cout	<< "in asm: "
			<< product_asm(arr, arr_siz, lower, upper)
			<< std::endl;
	return 0;
}
