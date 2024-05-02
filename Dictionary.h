#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include<vector>
#include<algorithm>
#include <random>

#include"Word.h"
#include"Verb.h"
#include"Noun.h"
#include"Adverb.h"
#include"Adjective.h"
#include"Preposition.h"
#include"ProperNoun.h"
#include"NounAndVerb.h"
#include"MiscWord.h"

using namespace std;

//This class is responsible for maintaining a collection of word objects. 
class Dictionary
{

private:
	vector<Word*> collectionOfWords; //Used to store word objects.
	bool loaded = false;

public:
	void loadDictionary(string filename); //Used to load a dictionary in .txt format into the collectionOfWords vector.
	bool getLoaded();
	void findDefinition(); //Used to find the definition of a word based on the string passed in.
	void findWordWithMoreThanThreeZ(); //Finds words with more than 3 z's and prints them to the screen.
	void findWordWithQandNoTrailingU(); //Finds words with a q but no trailig u.
	void findWordsThatArePalindrome(); //Finds words that are palindromes
	Word *findWord(string); //Returns a word object if the passed in string matches the word of the word object.
	void findWordsThatAreVerbsAndNouns(); //Finds words that are both nouns and verbs.
	void findAnagramsOfWord(string); //Finds anagrams of the word/string passed into the function.
	void nounGuessingGame(); //This function displays a definition of a noun to the user and gives them 3 attempts to guess the word of the definition.

	
};
