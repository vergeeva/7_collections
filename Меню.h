#pragma once
#include "Header.h"

namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Меню
	/// </summary>
	public ref class Меню : public System::Windows::Forms::Form
	{
	public:
		Меню(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			food = gcnew List <dish^>;
			food_order = gcnew List <dish^>;
		}
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	public:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		List <dish^>^ food;
	private: System::Windows::Forms::Button^ button1;
	protected:
		List <dish^>^ food_order;
		~Меню()
		{
			if (components)
			{
				delete components;
			}
		}

		void View(List <dish^>^ m, System::Windows::Forms::DataGridView^ DGV)
		{
			if (m->Count == 0)
			{
				DGV->Rows[0]->Cells[0]->Value = "";
				DGV->Rows[0]->Cells[1]->Value = "";
				DGV->Rows[0]->Cells[2]->Value = "";
			}
			else
			{
				DGV->RowCount = m->Count;
				for (int i = 0; i < m->Count; i++)
				{
					DGV->Rows[i]->Cells[0]->Value = m[i]->Name;
					DGV->Rows[i]->Cells[1]->Value = m[i]->W;
					DGV->Rows[i]->Cells[2]->Value = m[i]->Price;
				}
			}
		}

		void Load_food(List <dish^>^ m, String^ fileName)
		{
			StreamReader^ SR = gcnew StreamReader(fileName);
			String^ str = gcnew String("");
			while (str = SR->ReadLine()) {
				dish^ p = gcnew dish();
				p->Name = str->Substring(0, str->IndexOf("$"));
				p->W = Convert::ToInt32(str->Substring(str->IndexOf("$") + 1, str->IndexOf("!") - str->IndexOf("$") - 1));
				p->About = str->Substring(str->IndexOf("!") + 1, str->IndexOf("#") - str->IndexOf("!") - 1);
				p->Price = Convert::ToDouble(str->Substring(str->IndexOf("#") + 1, str->IndexOf("@")- str->IndexOf("#")-1));
				p->C = Convert::ToInt32(str->Substring(str->IndexOf("@") + 1));
				m->Add(p);
			}
			SR->Close();
		}

		void Infile(List <dish^>^ m, String^ fileName)
		{
			StreamWriter^ My_SW = gcnew StreamWriter(fileName);
			for (int i = 0; i < m->Count; i++)
			{
				String^ Line = gcnew String("");
				Line = m[i]->Name + "$" + m[i]->W + "!" + m[i]->About + "#" + m[i]->Price + "@" + m[i]->C + "\n";
				My_SW->Write(Line);
			}
			My_SW->Close();
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:



	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ Описание;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Описание = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(28, 22);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(649, 305);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Меню::dataGridView1_CellClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Меню::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 200;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Граммовка";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Цена";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(686, 41);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(291, 123);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// Описание
			// 
			this->Описание->AutoSize = true;
			this->Описание->Location = System::Drawing::Point(683, 21);
			this->Описание->Name = L"Описание";
			this->Описание->Size = System::Drawing::Size(74, 17);
			this->Описание->TabIndex = 2;
			this->Описание->Text = L"Описание";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(686, 180);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(291, 27);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Помощь с заказом";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Меню::button1_Click);
			// 
			// Меню
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1059, 386);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Описание);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Меню";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню";
			this->Load += gcnew System::EventHandler(this, &Меню::Меню_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Меню_Load(System::Object^ sender, System::EventArgs^ e) {
		Load_food(food, "Menu.txt");
		View(food, dataGridView1);
		richTextBox1->Text = food[0]->About;
	}
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = e->RowIndex;
		richTextBox1->Text = food[i]->About;
	}
	private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		int i = e->RowIndex;
		auto result = MessageBox::Show(
			"Вы действительно хотите добавить блюдо в список?",
			"Подтвердите добавление",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question);

		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			food_order->Add(food[i]);
			Infile(food_order, "Заказ текущего клиента.txt");
			MessageBox::Show("Блюдо успешно добавлено в заказ", "Сообщение о добавлении");
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Чтобы добавить блюдо в заказ, нажмите дважды на название блюда", "Помощь");
	}
};
}
