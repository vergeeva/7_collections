#pragma once
#include "Header.h"
#include "Function.h"

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

	public:



	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		List <dish^>^ food;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
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

		void View(List <dish^>^ m, System::Windows::Forms::ListBox^ LB)
		{
			LB->Items->Clear();
			for (int i = 0; i < m->Count; i++)
			{
				LB->Items->Add(m[i]->Name);
			}
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

		int Count_el(List <dish^>^ m, dish^ p)
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->dataGridView1->Location = System::Drawing::Point(13, 36);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(563, 208);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Меню::dataGridView1_CellClick);
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Меню::dataGridView1_CellContentClick);
			this->dataGridView1->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Меню::dataGridView1_CellDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 250;
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
			this->richTextBox1->Location = System::Drawing::Point(585, 59);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(327, 146);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// Описание
			// 
			this->Описание->AutoSize = true;
			this->Описание->Location = System::Drawing::Point(585, 36);
			this->Описание->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->Описание->Name = L"Описание";
			this->Описание->Size = System::Drawing::Size(213, 19);
			this->Описание->TabIndex = 2;
			this->Описание->Text = L"Описание выбранного блюда";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(584, 213);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(328, 31);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Помощь с заказом";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Меню::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 19);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Меню";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 248);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(85, 19);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Ваш заказ:";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 19;
			this->listBox1->Location = System::Drawing::Point(13, 270);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(353, 175);
			this->listBox1->TabIndex = 7;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Меню::listBox1_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(382, 260);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(245, 185);
			this->groupBox1->TabIndex = 8;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Информация по заказу";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(233, 35);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Сделать заказ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Меню::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(20, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(205, 27);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(83, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Вес заказа";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(17, 28);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 19);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Итоговая стоимость";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(20, 48);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(205, 27);
			this->textBox1->TabIndex = 0;
			// 
			// Меню
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(937, 458);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Описание);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dataGridView1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Меню";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Меню";
			this->Load += gcnew System::EventHandler(this, &Меню::Меню_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Меню_Load(System::Object^ sender, System::EventArgs^ e) {
		Load_food(food, "Menu.txt");
		View(food, dataGridView1);
		richTextBox1->Text = food[0]->About;

		textBox1->Text = Convert::ToString(sum_price(food_order));
		textBox2->Text = Convert::ToString(sum_w(food_order));
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
			View(food_order, listBox1);
			MessageBox::Show("Блюдо успешно добавлено в заказ", "Сообщение о добавлении");
			textBox1->Text = Convert::ToString(sum_price(food_order));
			textBox2->Text = Convert::ToString(sum_w(food_order));
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Чтобы добавить блюдо в заказ, нажмите дважды на название блюда\nЧтобы удалить блюдо из заказа, нажмите на него в вашем заказе", "Помощь");
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int i = listBox1->SelectedIndex;
	auto result = MessageBox::Show(
		"Вы действительно хотите удалить блюдо из списка?",
		"Подтвердите удаление",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		food_order->Remove(food_order[i]);
		View(food_order, listBox1);
		Infile(food_order, "Заказ текущего клиента.txt");
		textBox1->Text = Convert::ToString(sum_price(food_order));
		textBox2->Text = Convert::ToString(sum_w(food_order));
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	List <dish^>^ food = gcnew List <dish^>;
	Load_food(food, "Menu.txt");
	Dictionary <String^, int>^ temp = gcnew Dictionary <String^, int>;
	for (int i = 0; i < food_order->Count; i++)
	{
		int b = Count_el(food_order, food_order[i]);
		myPredicate predicate(food_order[i]->Name);
		int j = food->FindIndex(gcnew Predicate <dish^>(predicate, &myPredicate::isName));

		if (!temp->ContainsKey(food[j]->Name))
		{
			food[j]->C += b;
			temp->Add(food[j]->Name, food[j]->C);
		}
	}
	Infile(food, "Menu.txt");
	MessageBox::Show("Ваш заказ успешно сохранен", "Уведомление");
}
};
}
