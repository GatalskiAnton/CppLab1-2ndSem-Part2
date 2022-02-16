#pragma once
#include <vector>
#include <list>
#include <iostream>

using std::vector;
using std::list;
using std::cout;
using std::string;

template <typename T>
vector<T> ListToVector(list<T> list)
{
	vector<T> ListCopy;
	for (T elements : list)
		ListCopy.push_back(elements);
	return ListCopy;
}

int countWords(list<string> words , char letter);

void reverse(list<string> strings);

void deleteElements(list<string> &strings, char letter);