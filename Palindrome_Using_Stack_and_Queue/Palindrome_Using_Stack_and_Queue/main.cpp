#include<iostream>
#include<iomanip>
#include<cctype>
#include<string>
#include<vector>
#include<queue>
#include<stack>

bool isPalindrome(const std::string& word)
{
	std::stack<char> myStack;
	std::queue<char> myQueue;

	//add only alpha characters
	for (char letter : word)
		if (std::isalpha(letter))
		{
			letter = std::toupper(letter);
			myQueue.push(letter);
			myStack.push(letter);
		}

	char c1{}; char c2{};

	//while the queue is not empty
	//	compare and remove the character at the top of the stack
	//	and the character at the front of the queue
	//	f they are not the same return false

	while (!myQueue.empty())
	{
		c1 = myQueue.front();
		c2 = myStack.top();
		myQueue.pop();
		myStack.pop();
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
	std::cout << std::setw(30) << std::left << "Result" << "String" << std::right << std::endl
		<< "-------------------------------------" << std::endl;
	for (const auto& word : myWords)
	{
		std::cout << std::setw(30) << std::left << word << isPalindrome(word) << std::right << std::endl;
	}


	system("pause");
	return 0;
}