#pragma once
using namespace System::Collections::Generic;
#include "Header.h"
#include "����.h"
#include "�������� �����.h"
#include "�������� �����.h"
namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� ������
	/// </summary>
	public ref class ������ : public System::Windows::Forms::Form
	{
	public:
		������(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			List <dish^>^ My_List;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~������()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(33, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(210, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &������::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 115);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(210, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"�������� �����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &������::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 164);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(210, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"�������� �����";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &������::button3_Click);
			// 
			// ������
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 290);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"������";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"������";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew ����();
		Frm->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew �������������();
		Frm->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew �������������();
		Frm->ShowDialog();
	}
	};
}
