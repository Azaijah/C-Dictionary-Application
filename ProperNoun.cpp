#include"ProperNoun.h"

ProperNoun::ProperNoun(string word, string definition) : Noun(word, definition), Word(word, definition) {}

string ProperNoun::getWord()
{
	string properNoun = Word::getWord();
	properNoun[0] = toupper(properNoun[0]);
	return properNoun;
}

string ProperNoun::getDefinition()
{
	return "(pn.) " + Word::getDefinition();
}