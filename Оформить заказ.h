#pragma once
#include "Header.h"
using namespace System::IO;

namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Оформитьзаказ
	/// </summary>
	public ref class Оформитьзаказ : public System::Windows::Forms::Form
	{
	public:
		Оформитьзаказ(void)
		{
			food_order = gcnew List <dish^>;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		List <dish^>^ food_order;
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>

		~Оформитьзаказ()
		{
			if (components)
			{
				delete components;
			}
		}

		int find_and_count(List <dish^>^m, dish^ p)
		{
			int count = 0;
			for (int i; i < m->Count; i++)
			{
				if (m[i]->operator==(p))
				{
					count++;
				}
			}
			return count;
		}

		int find(List <dish^>^ m, dish^ p)
		{
			for (int i; i < m->Count; i++)
			{
				if (m[i] == p)
				{
					return i;
				}
			}
			return -1;
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
				p->Price = Convert::ToDouble(str->Substring(str->IndexOf("#") + 1, str->IndexOf("@") - str->IndexOf("#") - 1));
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
		double sum_price(List <dish^>^ m)
		{
			double sum;
			for (int i; i < m->Count; i++)
			{
				sum += m[i]->Price;
			}
			return sum;
		}

		double sum_w(List <dish^>^ m)
		{
			double sum;
			for (int i; i < m->Count; i++)
			{
				sum += m[i]->W;
			}
			return sum;
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(34, 35);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(633, 254);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Оформитьзаказ::dataGridView1_CellDoubleClick);
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(34, 305);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(251, 35);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Помощь";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Оформитьзаказ::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(416, 305);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(251, 35);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Сделать заказ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Оформитьзаказ::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(687, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(245, 176);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Информация по заказу";
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(20, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(205, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Вес заказа";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(17, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Итоговая стоимость";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(20, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(205, 22);
			this->textBox1->TabIndex = 0;
			// 
			// Оформитьзаказ
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 389);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Оформитьзаказ";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Оформить заказ";
			this->Load += gcnew System::EventHandler(this, &Оформитьзаказ::Оформитьзаказ_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Оформитьзаказ_Load(System::Object^ sender, System::EventArgs^ e) {
		Load_food(food_order, "Заказ текущего клиента.txt");
		View(food_order, dataGridView1);
		textBox1->Text = Convert::ToString(sum_price(food_order));
		textBox2->Text = Convert::ToString(sum_w(food_order));
	}
private: System::Void dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int i = e->RowIndex;
	auto result = MessageBox::Show(
		"Вы действительно хотите удалить блюдо из списка?",
		"Подтвердите удаление",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		food_order->Remove(food_order[i]);
		View(food_order, dataGridView1);
		Infile(food_order, "Заказ текущего клиента.txt");
		textBox1->Text = Convert::ToString(sum_price(food_order));
		textBox2->Text = Convert::ToString(sum_w(food_order));
	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Чтобы удалить что-то из заказа, нажмите два раза на элемент в списке", "Помощь");
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	List <dish^>^ food = gcnew List <dish^>;
	Load_food(food, "Menu.txt");

	for (int i = 0; i < food_order->Count; i++)
	{
		int b = find_and_count(food_order, food_order[i]);
		int j = find(food, food_order[i]);
		food[j]->C += b;
	}
	Infile(food, "Menu.txt");
	MessageBox::Show("Ваш заказ успешно сохранен", "Уведомление");
}
};
}
