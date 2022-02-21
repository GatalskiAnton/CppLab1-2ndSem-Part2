#pragma once
#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream>
#include <algorithm>



void fillFromFile(std::list<std::string>& strings, std::ifstream& input);

void printList(std::list<std::string>& strings);

template <typename T>
void ListToVector(std::list<T>& list, std::vector<T>& vector)
{
	std::copy(list.begin(), list.end(), std::inserter(vector, vector.begin()));
}

int countWords(std::list<std::string>& words, char letter);

void printReverse(std::list<std::string>& strings);

std::list<std::string> findByFirstElementLambda(std::list<std::string>& strings, char letter);

std::list<std::string> findByFirstElementFunctor(std::list<std::string>& strings, char letter);

void deleteElements(std::list<std::string>& strings, char letter);

void printUniqueAlphabetically(std::ifstream& input);

void duplicateCount(std::ifstream& input);