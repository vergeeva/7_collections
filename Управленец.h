#pragma once
#include "����������.h"
#include "���_����.h"

namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� ����������
	/// </summary>
	public ref class ���������� : public System::Windows::Forms::Form
	{
	public:
		����������(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~����������()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;

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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 41);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(234, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"����������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &����������::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(32, 98);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(234, 41);
			this->button2->TabIndex = 1;
			this->button2->Text = L"������������� ����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &����������::button2_Click);
			// 
			// ����������
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(305, 182);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"����������";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"����������";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ F = gcnew ���_����();
		F->ShowDialog();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ F = gcnew ����������();
		F->ShowDialog();
	}
	};
}
