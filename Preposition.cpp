#include"Preposition.h"

Preposition::Preposition(string word, string definition) : MiscWord(word, definition) {}

string Preposition::getDefinition()
{
	return "(prep.) " + Word::getDefinition();
}