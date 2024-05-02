#include "Word.h"

//Constructor: used to intialize a Word object's word and defintion variables on creation.

Word::Word (string word, string definition)
{
	this->word = word;
	this->definition = definition;

}

//Getter methods for word, definition and type variables.
string Word::getWord() 
{
	return word;
}
string Word::getDefinition()
{
	return definition;
}


//Predicate functions (Checking functions). 
bool Word::isPalindrome()
{
	if(word == string(word.rbegin(), word.rend()))
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool Word::isVerb()
{
	return false;
}
bool Word::isNoun()
{
	return false;
}


//When called this function prints the variables word and definition to the users console.
void Word::printDefinition ()
{
	cout << word << endl << getDefinition();
 
}



