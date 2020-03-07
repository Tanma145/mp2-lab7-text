#include "TTextLink.h"

TText::TText(){
	pFirst = 0;
	pCur = 0;
	stack.Clear();
}

TText::~TText(){
}

void TText::GoFirstLink(){
	pCur = pFirst;
	stack.Clear();
}

void TText::GoNextLink(){
	if (!pCur) throw - 1;
	if (pCur->pNext) {
		stack.Push(pCur);
		pCur = pCur->pNext;
	}
}

void TText::GoDownLink(){
	if (!pCur) throw - 1;
	if (pCur->pDown) {
		stack.Push(pCur);
		pCur = pCur->pDown;
	}
}

void TText::GoPrevLink(){
	if (!pCur) throw - 1;
	if (!stack.IsEmpty())
		pCur = stack.Pop();
}

void TText::SetLine(std::string str){
	if (!pCur) throw - 1;
	strcpy(pCur->str, str.c_str());
}

std::string TText::GetLine()
{
	if (!pCur) throw - 1;
	return std::string(pCur->str);
}

void TText::InsNextLine(std::string str){
	if (!pCur) throw - 1;
	TTextLink* tmp = new TTextLink(str.c_str());
	tmp->pNext = pCur->pNext;
	pCur->pNext = tmp;
}

void TText::InsNextSection(std::string str){
	if (!pCur) throw - 1;
	TTextLink* tmp = new TTextLink(str.c_str());
	tmp->pDown = pCur->pNext;
	pCur->pNext = tmp;
}

void TText::InsDownLine(std::string str){
	if (!pCur) throw - 1;
	TTextLink* tmp = new TTextLink(str.c_str());
	tmp->pNext = pCur->pDown;
	pCur->pDown = tmp;
}

void TText::InsDownSection(std::string str){
	if (!pCur) throw - 1;
	TTextLink* tmp = new TTextLink(str.c_str());
	tmp->pDown = pCur->pDown;
	pCur->pDown = tmp;
}

void TText::DelNext(){
	if (!pCur) throw - 1;
	if (!pCur->pNext) throw - 1;
	TTextLink* tmp = pCur->pNext;
	pCur->pNext = tmp->pNext;
	delete tmp;
}

void TText::DelDown(){
if (!pCur) throw - 1;
if (!pCur->pDown) throw - 1;
TTextLink* tmp = pCur->pDown;
pCur->pDown = tmp->pNext;
delete tmp;
}
