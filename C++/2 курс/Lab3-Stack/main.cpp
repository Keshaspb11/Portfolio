// ����, ���, ���� "������ ����������������-2", �++, ���
//
// Copyright (c) ������� �.�. 28.07.2000
//   ������������ ��� Microsoft Visual Studio 2008 �������� �.�. (21.04.2015)
//
// ������������ ��������� ������ - ������������ �����
#pragma once
#include <iostream>
#include "tstack.h"

using namespace std;

int main()
{
	TStack st(2);
	int temp;
	setlocale(LC_ALL, "Russian");
	cout << "������������ �������� ��������� ��������� ���� �����" << endl;
	for (int i = 0; i < 35; i++)
	{
	st.Put(i);
	cout << "�������� �������� " << i << " ��� " << st.GetRetCode() << endl;
	}
	while (!st.IsEmpty())
	{
	temp = st.Get();
	cout << "����� �������� " << temp << " ��� " << st.GetRetCode() << endl;
	}
	system("pause");
	return 1;
}
