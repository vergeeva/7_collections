#pragma once
#include "Header.h"
using namespace System::Collections::Generic;
public value class myPredicate
{
	String^ Name;
	String^ About;
	double price;
	int c;
	int w;

public:
	myPredicate(String^ Name)
	{
		this->Name = gcnew String(Name);
	}

	myPredicate(dish ^S)
	{
		this->Name = gcnew String(S->Name);
		this->About = gcnew String(S->About);
		this->price = S->Price;
		this->w = S->W;
		this->c = S->C;
	}

	myPredicate(double price)
	{
		this->price = price;
	}

	bool isName(dish ^S)
	{
		return this->Name == S->Name;
	}

	bool isName(feedback^ S)
	{
		return this->Name == S->Name;
	}

	bool isDish(dish^ S)
	{
		return S->Name == Name && S->About == About && S->Price == price&&S->C == c && S->W == w;
	}
};

//void View_(List <dish^>^ m, System::Windows::Forms::DataGridView^ DGV)
//{
//	if (m->Count == 0)
//	{
//		DGV->Rows[0]->Cells[0]->Value = "";
//		DGV->Rows[0]->Cells[1]->Value = "";
//		DGV->Rows[0]->Cells[2]->Value = "";
//	}
//	else
//	{
//		DGV->RowCount = m->Count;
//		for (int i = 0; i < m->Count; i++)
//		{
//			DGV->Rows[i]->Cells[0]->Value = m[i]->Name;
//			DGV->Rows[i]->Cells[1]->Value = m[i]->W;
//			DGV->Rows[i]->Cells[2]->Value = m[i]->Price;
//		}
//	}
//}
//
//void Load_food(List <dish^>^ m, String^ fileName)
//{
//	StreamReader^ SR = gcnew StreamReader(fileName);
//	String^ str = gcnew String("");
//	while (str = SR->ReadLine()) {
//		dish^ p = gcnew dish();
//		p->Name = str->Substring(0, str->IndexOf("$"));
//		p->W = Convert::ToInt32(str->Substring(str->IndexOf("$") + 1, str->IndexOf("!") - str->IndexOf("$") - 1));
//		p->About = str->Substring(str->IndexOf("!") + 1, str->IndexOf("#") - str->IndexOf("!") - 1);
//		p->Price = Convert::ToDouble(str->Substring(str->IndexOf("#") + 1, str->IndexOf("@") - str->IndexOf("#") - 1));
//		p->C = Convert::ToInt32(str->Substring(str->IndexOf("@") + 1));
//		m->Add(p);
//	}
//	SR->Close();
//}
//
//void Infile(List <dish^>^ m, String^ fileName)
//{
//	StreamWriter^ My_SW = gcnew StreamWriter(fileName);
//	for (int i = 0; i < m->Count; i++)
//	{
//		String^ Line = gcnew String("");
//		Line = m[i]->Name + "$" + m[i]->W + "!" + m[i]->About + "#" + m[i]->Price + "@" + m[i]->C + "\n";
//		My_SW->Write(Line);
//	}
//	My_SW->Close();
//}