#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>
#include<vector>
#include<deque>


bool isPalindrome(const std::string& word)
{
	std::deque<char> myDeque;
	for (const char& letter : word)//add all the characters that are alpha to the back of the deque in uppercase
		if (std::isalpha(letter))//only alpha characters allowed
			myDeque.push_back(std::toupper(letter));
	char c1{}, c2{};

	//while there are more than 1 character in the deque keep:
	//	removing and comparing the front char with the back char
	//	if they are not the same then return false.

	while (myDeque.size() > 1)
	{
		c1 = myDeque.front();
		c2 = myDeque.back();
		myDeque.pop_back();
		myDeque.pop_front();
		if (c1 != c2)
			return false;
	}


	return true;
}


int main()
{
	std::vector<std::string> myWords
	{ "Mom", "bob", "avid diva","Palindrome" ,"a santa at NASA", "Hello" };

	std::cout << std::boolalpha;
	std::cout << std::setw(30) << std::left << "Result" << "String" <<std::right<< std::endl
		<< "-------------------------------------" <<std::endl ;
	for (const auto& word : myWords)
	{
		std::cout << std::setw(30) << std::left << word<<isPalindrome(word) <<std::right <<std::endl;
	}


	system("pause");
	return 0;
}