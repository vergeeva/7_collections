#pragma once
#include "Header.h"
#include "Статистика.h"


namespace My7collections {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Ред_меню
	/// </summary>
	public ref class Ред_меню : public System::Windows::Forms::Form
	{
	public:
		Ред_меню(void)
		{
			InitializeComponent();
			food = gcnew List <dish^>;
			//
			//TODO: добавьте код конструктора
			//
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	public:

	protected:
		List <dish^>^ food;
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Ред_меню()
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

		int find_name(List <dish^>^ m, String^ name)
		{
			for (int i = 0; i < m->Count; i++)
			{
				if (m[i]->Name == name)
				{
					return i;
				}
			}
				return 0;
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView1->Location = System::Drawing::Point(30, 55);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(501, 363);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Ред_меню::dataGridView1_CellContentDoubleClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Название";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 125;
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
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(566, 55);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(287, 187);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Режим редактирования";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(6, 36);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(253, 24);
			this->comboBox1->TabIndex = 17;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Ред_меню::comboBox1_SelectedIndexChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 63);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(106, 17);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Текущее цена:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Задайте новое значение:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(145, 156);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(123, 25);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Сохранить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Ред_меню::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 156);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 25);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Помощь";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Ред_меню::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(17, 128);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(174, 22);
			this->textBox2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(17, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(174, 22);
			this->textBox1->TabIndex = 0;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button3);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->richTextBox1);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->textBox3);
			this->groupBox2->Location = System::Drawing::Point(570, 258);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(406, 191);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Добавить блюдо";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(205, 145);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(182, 25);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Добавить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Ред_меню::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 128);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(43, 17);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Цена";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(13, 148);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(174, 22);
			this->textBox5->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(202, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(120, 17);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Описание блюда";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(205, 47);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(182, 82);
			this->richTextBox1->TabIndex = 12;
			this->richTextBox1->Text = L"";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(10, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 17);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Граммовка";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(13, 99);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(174, 22);
			this->textBox4->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(72, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Название";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(13, 47);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(174, 22);
			this->textBox3->TabIndex = 8;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(39, 424);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(217, 25);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Помощь с удалением";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Ред_меню::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(305, 424);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(217, 25);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Посмотреть статистику";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Ред_меню::button5_Click);
			// 
			// Ред_меню
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 485);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Ред_меню";
			this->Text = L"Режим редактирования";
			this->Load += gcnew System::EventHandler(this, &Ред_меню::Ред_меню_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ F = gcnew Статистика();
		F->ShowDialog();
	}
private: System::Void Ред_меню_Load(System::Object^ sender, System::EventArgs^ e) {
	Load_food(food, "Menu.txt");
	View(food, dataGridView1);

	comboBox1->Text = food[0]->Name;
	for (int i; i < food->Count; i++)
	{
		comboBox1->Items->Add(food[i]->Name);
	}
}
private: System::Void dataGridView1_CellContentDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int i = e->RowIndex;
	auto result = MessageBox::Show(
		"Вы действительно хотите удалить блюдо из меню?",
		"Подтвердите удаление",
		MessageBoxButtons::YesNo,
		MessageBoxIcon::Question);
	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		food->Remove(food[i]);
		View(food, dataGridView1);
		Infile(food, "Menu.txt");
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox3->Text != "" && textBox4->Text != "" && textBox5->Text != "" && richTextBox1->Text !="")
	{
		dish^ t = gcnew dish();
		t->Name = textBox3->Text;
		t->About = richTextBox1->Text;
		t->Price = Convert::ToDouble(textBox5->Text);
		t->W = Convert::ToInt32(textBox4->Text);
		food->Add(t);
		Infile(food, "Menu.txt");
		View(food, dataGridView1);
	}
	else {
		MessageBox::Show("Заполните необходимые поля!", "Предупреждение");
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Чтобы удалить элемент, щелкните по нему два раза", "Помощь");
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Чтобы отредактировать цену, выберите блюдо в списке и задайте новое значение в окне", "Помощь");
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = find_name(food, comboBox1->Text);
	food[i]->Price = Convert::ToDouble(textBox2->Text);
	View(food,dataGridView1);
	Infile(food, "Menu.txt");
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	int i = find_name(food, comboBox1->Text);
	textBox1->Text = Convert::ToString(food[i]->Price);
}
};
}
