#include "function.h"

int main()
{
	std::ifstream input("input.txt");
	std::list<std::string> words;
	fillFromFile(words, input);
	/*for (std::string word : words)
		std::cout << word << "\n";
	std::cout << "-----------------------------------------\n";
	std::vector<std::string> word;
	words.sort();
	ListToVector(words, word);
	for (int i = 0; i < word.size(); i++)
		std::cout << word[i] << "\n";
	duplicateCount(input);*/
	keySort();
	return 0;
}