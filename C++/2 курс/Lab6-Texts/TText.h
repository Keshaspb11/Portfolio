#ifndef _TEXT_
#define _TEXT_

#include "tdatacom.h"
#include "TTextLink.h"
#include <stack>
#include <string>
#include <fstream>

class TText;
typedef TText *PTText;

class TText : public TDataCom
{
protected:
    PTTextLink pFirst;                                    // ��������� ����� ������
    PTTextLink pCurrent;                                  // ��������� ������� ������
    stack< PTTextLink > Path;                             // ���� ���������� �������� �� ������
    stack< PTTextLink > St;                               // ���� ��� ���������
    PTTextLink GetFirstAtom(PTTextLink pl);              // ����� ������� �����
    void PrintText(PTTextLink ptl);                      // ������ ������ �� ����� ptl
    void PrintTextFile(PTTextLink ptl, ofstream& TxtFile);
    PTTextLink ReadText(ifstream& TxtFile);               // ������ ������ �� �����
    static int TextLevel;
public:
    TText(PTTextLink pl = nullptr);
    ~TText() { pFirst = nullptr; }
    // ���������
    int GoFirstLink(void);            // ������� � ������ ������
    int GoDownLink(void);             // ������� � ��������� ������ �� Down
    int GoNextLink(void);             // ������� � ��������� ������ �� Next
    int GoPrevLink(void);             // ������� � ���������� ������� � ������
                                       // ������
    string GetLine(void);               // ������ ������� ������
    void SetLine(string str);         // ������ ������� ������ 
                                      // �����������
    void InsDownLine(string str);      // ������� ������ � ����������
    void InsDownSection(string str);   // ������� ������� � ����������
    void InsNextLine(string str);      // ������� ������ � ��� �� ������
    void InsNextSection(string str);   // ������� ������� � ��� �� ������
    void DelDownLine(void);            // �������� ������ � ���������
    void DelDownSection(void);         // �������� ������� � ���������
    void DelNextLine(void);            // �������� ������ � ��� �� ������
    void DelNextSection(void);         // �������� ������� � ��� �� ������
                                       // ��������
    int Reset(void);                  // ���������� �� ������ ������
    bool IsTextEnded(void) const;      // ����� ��������?
    bool GoNext(void);                 // ������� � ��������� ������
                                       //������ � �������
    void Read(char* pFileName);        // ���� ������ �� �����
    void Write(char* pFileName);       // ����� ������ � ����
                                       //������
    void Print(void);                  // ������ ������
};

#endif 