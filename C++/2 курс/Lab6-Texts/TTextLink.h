#define _CRT_SECURE_NO_WARNINGS

#ifndef _LINK_
#define _LINK_

#include "tdatvalue.h"
#include <cstring>
#include <iostream>

using namespace std;

const int TextLineLength = 40;

class TText;
class TTextLink;

typedef TTextLink* PTTextLink;
typedef char TStr[TextLineLength];

class TTextMem
{
    PTTextLink pFirst;                       // ��������� �� ������ �����
    PTTextLink pLast;                        // ��������� �� ��������� �����
    PTTextLink pFree;                        // ��������� �� ������ ��������� �����
    TTextMem() : pFirst(nullptr), pLast(nullptr), pFree(nullptr) {};
    friend class TTextLink;
};
typedef TTextMem *PTTextMem;

class TTextLink : public TDatValue
{
protected:
    TStr Str;                                 // ���� ��� �������� ������ ������
    PTTextLink pNext, pDown;                  // ��������� �� ���. ������� � �� ����������
    static TTextMem MemHeader;                // ������� ���������� �������
public:
    static void InitMemSystem(int size);     // ������������� ������
    static void PrintFreeLink(void);         // ������ ��������� �������
    void * operator new (size_t size);        // ��������� �����
    void operator delete (void *pM);          // ������������ �����
    static void MemCleaner(TText &txt);      // ������ ������
	TTextLink(TStr s = nullptr, PTTextLink pn = nullptr, PTTextLink pd = nullptr);
	TTextLink(string s);
    ~TTextLink() {}
    int IsAtom() { return pDown == nullptr; }   // �������� ����������� �����
    PTTextLink GetNext() { return pNext; }       // ������� � ���������� �����
    PTTextLink GetDown() { return pDown; }       // ������� �� ����������
    PTDatValue GetCopy() { return new TTextLink(Str, pNext, pDown); }
    friend class TText;
};

#endif 
