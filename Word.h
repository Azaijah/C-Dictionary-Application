#pragma once
#include <iostream>
#include<string>

using namespace std;

//This class is used as a template storing common code for all the different word types.
class Word {
private:
	string word;
	string definition;


public:
	Word(string word, string definition);

	//Getters
	virtual string getWord(); //Get the word stored by the word object.
	virtual string getDefinition(); //Get the definition stored by the word object.
	void printDefinition(); //Print the definition stored by the word object.


	//Checker functions
	bool isPalindrome(); //Tests to see if the word stored by the word object is a palindrome.
	virtual bool isVerb(); //Tests to see if the word stored by the word object is a verb.
	virtual bool isNoun(); //Tests to see if the word stored by the word object is a noun.

};