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
	/// Сводка для Статистика
	/// </summary>
	public ref class Статистика : public System::Windows::Forms::Form
	{
	public:
		Статистика(void)
		{
			food = gcnew List <dish^>;
			fb = gcnew List <feedback^>;
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		List <dish^>^ food;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
		List<feedback^>^ fb;
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Статистика()
		{
			if (components)
			{
				delete components;
			}
		}
		void Load_fb(List <feedback^>^ m, String^ fileName)
		{
			StreamReader^ SR = gcnew StreamReader(fileName);
			String^ str = gcnew String("");
			while (str = SR->ReadLine()) {
				feedback^ p = gcnew feedback();
				p->Name = str->Substring(0, str->IndexOf("$"));
				p->Text = str->Substring(str->IndexOf("$") + 1, str->IndexOf("!") - str->IndexOf("$") - 1);
				p->Mark = Convert::ToInt32(str->Substring(str->IndexOf("!") + 1));
				m->Add(p);
			}
			SR->Close();
		}
		double find_and_average(List <feedback^>^ m, String^name)
		{
			double sum = 0;
			int count = 0;
			for (int i = 0; i < m->Count; i++)
			{
				if (m[i]->Name == name)
				{
					sum += m[i]->Mark;
					count++;
				}
			}
			if (count != 0) return sum / count;
			else return 0;
		}
		void View(List <dish^>^ m, System::Windows::Forms::DataGridView^ DGV)
		{
			if (m->Count == 0)
			{
				DGV->Rows[0]->Cells[0]->Value = "";
				DGV->Rows[0]->Cells[1]->Value = "";
				//DGV->Rows[0]->Cells[2]->Value = "";
			}
			else
			{
				DGV->RowCount = m->Count;
				for (int i = 0; i < m->Count; i++)
				{
					DGV->Rows[i]->Cells[0]->Value = m[i]->Name;
					DGV->Rows[i]->Cells[1]->Value = m[i]->C;
					//DGV->Rows[i]->Cells[2]->Value = m[i]->Price;
				}
			}
		}
		void View_fb(List <feedback^>^ m, String^n, System::Windows::Forms::ListBox^lb)
		{
			lb->Items->Clear();
			for (int i; i < fb->Count; i++)
			{
				if (m[i]->Name == n)
				{
					lb->Items->Add(m[i]->Text);
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

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:


	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::Button^ Закрыть;

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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Закрыть = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Column1,
					this->Column2
			});
			this->dataGridView1->Location = System::Drawing::Point(24, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(537, 301);
			this->dataGridView1->TabIndex = 0;
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
			this->Column2->HeaderText = L"Сколько взяли за все время(шт)";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 150;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(16, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(291, 24);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Статистика::comboBox1_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Location = System::Drawing::Point(591, 37);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(340, 267);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Просмотр отзывов";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(6, 128);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(328, 132);
			this->listBox1->TabIndex = 6;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 17);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Отзывы:";
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(175, 72);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(106, 22);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(35, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Средняя оценка:";
			// 
			// Закрыть
			// 
			this->Закрыть->Location = System::Drawing::Point(701, 310);
			this->Закрыть->Name = L"Закрыть";
			this->Закрыть->Size = System::Drawing::Size(197, 28);
			this->Закрыть->TabIndex = 3;
			this->Закрыть->Text = L"Закрыть";
			this->Закрыть->UseVisualStyleBackColor = true;
			this->Закрыть->Click += gcnew System::EventHandler(this, &Статистика::Закрыть_Click);
			// 
			// Статистика
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 374);
			this->Controls->Add(this->Закрыть);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"Статистика";
			this->Text = L"Статистика";
			this->Load += gcnew System::EventHandler(this, &Статистика::Статистика_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Статистика_Load(System::Object^ sender, System::EventArgs^ e) {
		Load_food(food, "Menu.txt");
		Load_fb(fb, "Отзывы и оценки.txt");
		View(food, dataGridView1);
		comboBox1->Text = food[0]->Name;
		for (int i; i < food->Count; i++)
		{
			comboBox1->Items->Add(food[i]->Name);
		}
		textBox1->Text = Convert::ToString(find_and_average(fb, comboBox1->Text));
		View_fb(fb, comboBox1->Text,listBox1);
	}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Text = Convert::ToString(find_and_average(fb, comboBox1->Text));
	View_fb(fb, comboBox1->Text, listBox1);
}
private: System::Void Закрыть_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
