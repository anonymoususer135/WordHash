#include "Word.h"
#include <string>

using namespace std;

Word::Word() {
	word = "";
}

string Word::getWord() const {
	return word;
}

void Word::setWord(string w) {
	word=w;
}

