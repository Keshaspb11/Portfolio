// ����, ���, ���� "������ ����������������-2", �++, ���
//
// tset.cpp - Copyright (c) ������� �.�. 04.10.2001
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (19.04.2015)
//
// ��������� - ���������� ����� ������� ����

#include "tset.h"

TSet::TSet(int mp) : BitField(mp)
{
	if (mp < 0)
		throw NegativeIndex();
	MaxPower = mp;
}

// ����������� �����������
TSet::TSet(const TSet &s) : BitField(s.BitField)
{
	MaxPower = s.MaxPower;
}

// ����������� �������������� ����
TSet::TSet(const TBitField &bf) : BitField(bf)
{
	MaxPower = bf.GetLength();
}

TSet::operator TBitField()
{
	return BitField;
}

int TSet::GetMaxPower(void) const // �������� ����. �-�� ��-���
{
	return MaxPower;
}

int TSet::IsMember(const int Elem) const // ������� ���������?
{
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // ��������� �������� ���������
{
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // ���������� �������� ���������
{
	BitField.ClrBit(Elem);
}

// ���������-������������� ��������

TSet& TSet::operator=(const TSet &s) // ������������
{
	MaxPower = s.MaxPower;
	BitField = s.BitField;
	return *this;
}

int TSet::operator==(const TSet &s) const // ���������
{
	if (MaxPower != s.MaxPower)
		return 0;
	int thisCount = 0, otherCount = 0;
	for (int i = 0; i < MaxPower; i++)
	{
		if (BitField.GetBit(i) != s.BitField.GetBit(i))
			return 0;
	}
	return 1;
}

int TSet::operator!=(const TSet &s) const // ���������
{
	if (*this == s)
		return 0;
	return 1;
}

TSet TSet::operator+(const TSet &s) // �����������
{
	int size;
	if (MaxPower > s.MaxPower)
		size = MaxPower;
	else
		size = s.MaxPower;
	TSet *set = new TSet(size);
	set->BitField = BitField | s.BitField;
	return *set;
}

TSet TSet::operator+(const int Elem) // ����������� � ���������
{
	if (Elem > MaxPower)
		throw BigIndex();
	TSet *set = new TSet(*this);
	if (set->IsMember(Elem) == 0)
		set->InsElem(Elem);
	return *set;
}
TSet TSet::operator-(const int Elem) // �������� � ���������
{
	TSet *set = new TSet(*this);
	if (set->IsMember(Elem))
		set->DelElem(Elem);
	return *set;
}

TSet TSet::operator*(const TSet &s) // �����������
{
	int size;
	if (MaxPower > s.MaxPower)
		size = MaxPower;
	else
		size = s.MaxPower;
	TSet *set = new TSet(size);
	set->BitField = BitField & s.BitField;
	return *set;
}

TSet TSet::operator~(void) // ����������
{
	TSet *set = new TSet(MaxPower);
	set->BitField = ~BitField;
	return *set;
}

// ���������� �����/������

istream &operator>>(istream &input, TSet &s) // ����
{
	string buf;
	input >> buf;
	TBitField *field;
	int count = 0;
	for (unsigned i = 0; i < buf.size(); i++)
	{
		if (buf[i] >= '0' || buf[i] <= '9')
		{
			count++;
		}
	}
	field = new TBitField(count);
	s.MaxPower = count;
	count = 0;
	for (unsigned i = 0; i < buf.size(); i++)
	{
		if (buf[i] == '0' || buf[i] == '1')
		{
			if (buf[i] == '0')
			{
				field->ClrBit(count);
			}
			else if (buf[i] == '1')
			{
				field->SetBit(count);
			}
			count++;
		}
	}
	s.BitField = *field;
	return input;
}

ostream& operator<<(ostream &output, const TSet &s) // �����
{
	output << "Max Power :" << s.MaxPower << endl;
	for (int i = 0; i < s.BitField.GetLength(); i++)
	{
		output << s.BitField.GetBit(i);
	}
	output << endl;
	return output;
}
