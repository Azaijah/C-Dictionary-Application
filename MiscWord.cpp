#include"MiscWord.h"

MiscWord::MiscWord(string word, string definition) : Word(word, definition) {}

string MiscWord::getDefinition()
{
	return "(misc.) " + Word::getDefinition();
}
