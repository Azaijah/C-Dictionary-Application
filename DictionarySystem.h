#pragma once

#include "Dictionary.h"
#include "Word.h"


using namespace std;

class DictionarySystem
{
private:
	Dictionary dictionary;
public:
	//Function declarations
	void displayOptions(); //Used to display menu options to the user.
	int getSelection(); //Used to get a seletion for a menu option.
	void executeOption(int selection);
	void run(); //Used to run the dictionary system core features.
};
