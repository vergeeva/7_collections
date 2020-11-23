#pragma once
using namespace System::Collections::Generic;
#include "Header.h"
#include "Меню.h"
#include "Оставить отзыв.h"
#include "Оформить заказ.h"
namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Клиент
	/// </summary>
	public ref class Клиент : public System::Windows::Forms::Form
	{
	public:
		Клиент(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			List <dish^>^ My_List;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Клиент()
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
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
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
			this->button1->Text = L"Меню";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Клиент::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(33, 115);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(210, 34);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Оформить заказ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Клиент::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(33, 164);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(210, 34);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Оставить отзыв";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Клиент::button3_Click);
			// 
			// Клиент
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(293, 290);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Клиент";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Клиент";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew Меню();
		Frm->ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew Оформитьзаказ();
		Frm->ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ Frm = gcnew Оставитьотзыв();
		Frm->ShowDialog();
	}
	};
}
