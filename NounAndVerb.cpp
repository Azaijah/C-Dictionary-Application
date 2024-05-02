#include"NounAndVerb.h"

VerbAndNoun::VerbAndNoun(string word, string definition) : Verb(word,definition), Noun(word, definition), Word(word, definition) {}


bool VerbAndNoun::isNoun()
{
	return true;
}
bool VerbAndNoun::isVerb()
{
	return true;
}

string VerbAndNoun::getDefinition()
{
	return "(n. v.) " + Word::getDefinition();
}