#include"Verb.h"

Verb::Verb(string word, string definition) : Word(word, definition) {}

bool Verb::isVerb()
{
	return true;
}

string Verb::getDefinition()
{
	return "(v.) " + Word::getDefinition();
}