#include<iostream>
int main()
{
	short things[] = { 1,5,3,8 };
	int num_elements = sizeof things / sizeof(short);
	std::cout << num_elements << "\n";
	std::cout << sizeof things << "\n";
	std::cout << sizeof(short);
	std::cin.get();
}