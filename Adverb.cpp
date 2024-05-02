#include"Adverb.h"

Adverb::Adverb(string word, string definition) : Word(word, definition) {}

string Adverb::getDefinition()
{
	return "(adv.) " + Word::getDefinition();
}
