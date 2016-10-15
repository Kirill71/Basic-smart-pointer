#include<iostream>
#include"SmartPointer.h"

int main() {

	SmartPointer<int> arr(new int[10]);
	for (auto i = 0; i < 10; ++i)
		arr[i] = i;
	std::cout << arr << " " << std::endl;
	//arr[-1];
	std::cout <<"preincrement "<< *(++arr) << " " << std::endl;
	std::cout <<"postincrement "<< *(arr++) << " " << std::endl;
	std::cout << "operator [] " << *(arr) << " " << std::endl;
	std::cout << "predeccrement " << *(--arr) << " " << std::endl;
	std::cout << "postdeccrement " << *(arr--) << " " << std::endl;

	for (int i = 0; i < 10; ++i)
		std::cout << arr[i] << " ";


	system("pause");
}