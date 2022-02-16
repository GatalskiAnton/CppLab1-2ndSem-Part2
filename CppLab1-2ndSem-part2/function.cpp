#include "function.h"

int countWords(list<string> words, char letter)
{
	int countWords = 0;
	for (string word : words)
	{
		bool insertion = false;
		for (int i = 0; i < word.size(); i++)
		{
			if (word[i] == letter)
				insertion = true;
		}
		if (insertion == true)
		{
			++countWords;
		}
	}
	return countWords;
}

void reverse(list<string> strings)
{
	list<string>::iterator it = strings.end();
	it--;
	for (; it != strings.begin(); --it)
		cout << *it << "\n";
	cout << strings.front();
}

void deleteElements(list<string> &strings, char letter)
{

	list<string> resultStrings;
	for (string string : strings)
	{
		if (string[0] != letter);
			resultStrings.push_front(string);
	}
	strings = resultStrings;
}