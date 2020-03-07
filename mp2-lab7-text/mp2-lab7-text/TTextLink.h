#pragma once
#include <string>
#include "../../../mp2-lab3-calculator/mp2-lab3-calculator/TStack.h"
class TTextLink{
public:
	TTextLink* pNext, *pDown;
	char str[81];
	TTextLink(const char _str[]) {
		strcpy(str, _str);
	}
};

class TText {
	TTextLink* pFirst, * pCur;
	TStack<TTextLink*> stack;
public:
	TText();
	~TText();
	void GoFirstLink();
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void SetLine(std::string str);
	std::string GetLine();
	void InsNextLine(std::string str);
	void InsNextSection(std::string str);
	void InsDownLine(std::string str);
	void InsDownSection(std::string str);
	void DelNext();
	void DelDown();
};
