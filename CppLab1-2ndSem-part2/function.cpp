#include "function.h"
#include "Complex.h"
#include "Human.h"
class Initial
{
private:
	char letter_;
public:
	Initial(char letter) : letter_(letter) {};
	bool operator()(std::string word)
	{
		return word[0] == letter_;
	}
};

void fillFromFile(std::list<std::string>& strings, std::ifstream& input)
{
	std::copy(std::istream_iterator<std::string>(input), std::istream_iterator<std::string>(), std::back_inserter(strings));
}

void printList(std::list<std::string>& strings)
{
	for (std::string string : strings)
		std::cout << string << "\n";
}

int countWords(std::list<std::string>& words, char letter)
{
	int countWords = 0;
	for (std::string word : words)
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

void printReverse(std::list<std::string>& strings)
{
	std::list<std::string>::iterator it = strings.end();
	it--;
	for (; it != strings.begin(); --it)
		std::cout << *it << "\n";
	std::cout << strings.front();
}

std::list<std::string> findByFirstElementLambda(std::list<std::string>& strings, char letter)
{
	std::list<std::string> result;
	for_each(strings.begin(), strings.end(), [&result, letter](std::string word)
		{
			if (word[0] == letter)
				result.push_back(word);
		});
	return result;
}

std::list<std::string> findByFirstElementFunctor(std::list<std::string>& strings, char letter)
{
	std::list < std::string > result;
	strings.sort();
	std::list<std::string>::iterator it1 = std::find_if(strings.begin(), strings.end(), Initial(letter));
	std::list<std::string>::iterator it2 = std::find_if_not(strings.begin(), strings.end(), Initial(letter));
	std::for_each(it1, it2, [&result](std::string word)
		{
			result.push_back(word);
		});
	return result;
}

void deleteElements(std::list<std::string>& strings, char letter)
{
	std::list<std::string> resultStrings;
	for (std::string string : strings)
	{
		if (string[0] != letter);
		resultStrings.push_front(string);
	}
	strings = resultStrings;
}

void printUniqueAlphabetically(std::ifstream& input)
{
	std::list<std::string> unique_words;
	std::copy(std::istream_iterator<std::string>(input), std::istream_iterator<std::string>(), std::back_inserter(unique_words));
	unique_words.unique();
	unique_words.sort();
	for (std::string word : unique_words)
		std::cout << word << "\n";
}

void duplicateCount(std::ifstream& input)
{
	std::list<std::string> strings_list;
	std::copy(std::istream_iterator<std::string>(input), std::istream_iterator<std::string>(), std::back_inserter(strings_list));
	strings_list.sort();
	std::vector<std::string> strings_vector;
	ListToVector(strings_list, strings_vector);
	int first_pos = 0;
	std::vector<int> count;
	for (int i = 0; i < strings_vector.size(); i++)
	{
		if (strings_vector[i] != strings_vector[first_pos] || i == strings_vector.size() - 1)
		{
			count.push_back(i - first_pos);
			first_pos = i;
		}
	}
	strings_list.unique();
	int i = 0;
	for (std::string string : strings_list)
	{
		if (i != count.size() - 1)
		{
			std::cout << string << " - " << count[i] << "\n";
		}
		else
		{
			std::cout << string << " - " << count[i] + 1 << "\n";
		}
		++i;
	}
}

void sortContainer()
{
	Complex A(3, 5);
	Complex B(2, 4);
	Complex C(1, 3);
	std::list<Complex> complex{ A,B,C };
	complex.sort();//default
	complex.sort([](Complex c1, Complex c2)//using lambda
		{
			return c1.getiPart() < c1.getiPart();
		});
}

void keySort()
{
	Human people1(25, 12, 26);
	Human people2(13, 15, 60);
	Human people3(54, 1, 13);
	std::vector<Human> people {people1, people2, people3};
	std::sort(people.begin(),people.end(),[](Human h1, Human h2)//one key
		{
			return h1.getStrength() < h2.getStrength();
		});
	std::sort(people.begin(), people.end(),[](Human h1, Human h2)//two keys
		{
			return h1.getStrength() + h1.getAgility() < h2.getStrength() + h2.getAgility();
		});
	std::sort(people.begin(), people.end(),[](Human h1, Human h2)//thee keys
		{
			return h1.getStrength() + h1.getAgility() + h1.getIntelligence() < h2.getStrength() + h2.getAgility() + h2.getIntelligence();
		});
}