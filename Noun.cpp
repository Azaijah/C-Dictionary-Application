#include"Noun.h"

Noun::Noun(string word, string definition) : Word(word, definition) {}

bool Noun::isNoun()
{
	return true;
}

string Noun::getDefinition()
{
	return "(n.) " + Word::getDefinition();
}