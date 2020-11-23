#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace System::IO;
//������ 19. �������: ���� ���� ����, � ��� �������, ��� ����� �������� �����.����
//���������� � ������ : ��� ���� �����.��� ������� ������� ������, ��� ���������
//�����������.������ ����� ����� �������, ���� �� ���������� �������, ��� �������
//����, ���� ������.������� �������, ������ �� �����, ����� ������������ ���������� :
//��������, ������, ���������.

//��������� ����������:
//����� �����: ��������, ��������, ���������, ����
//������ List ����, ������� ��������� � ������ �����
//����������� ����: ��� �������, ��� ����������
//��� �������: ���� ��� ������������, �������� �����, �������� �����
//��� ����������: ���������� ���������� ����, ������������� ����
//����: ������ ����, ���������� � ����� ����� ������� ������ ���� �� �����
//����� ����� �����������, �� �� �������(�������) �� ����������
//�������� �����: ������ ���������� ����, ����������� �������� �� 2 ������
//�� ������� ������ ��������, ���������� ���������� ���� �����������
//�������� �����: ����� ������� ����� � ��������� ������. ����� �������� ��� �������
//���������� ����������: ������� ������ ���� � ����� ���������� �������, 
//��� �� ������� ������ �����
//������������� ����: ����� ������� ����� �� �������� �������, ������������� ����
//�����: ����� ���������� ��� ��� � ���� ����

public ref class dish //�����
{
private:
	String^ name; //�������� �����
	String^ about; //�������� �����
	int weight; //���������
	double price; //����
	int count;//������� ��� ��������

public:
	dish();
	dish(dish^);
	~dish();
	bool operator ==(dish^ ot);
	property String^ Name
	{
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = gcnew String(Name);
		}
	}
	property String^ About
	{
		String^ get() {
			return about;
		}
		void set(String^ About) {
			about = gcnew String(About);
		}
	}

	property int W
	{
		int get() {
			return weight;
		}
		void set(int Cal) {
			weight = Cal;
		}
	}

	property int C
	{
		int get() {
			return count;
		}
		void set(int C) {
			count = C;
		}
	}

	property double Price
	{
		double get() {
			return price;
		}
		void set(double price) {
			this->price = price;
		}
	}
};

public ref class feedback
{
private:
	String^ name; //�������� �����, �� �������� ��������� �����
	String^ text; //���������� ������
	int mark; //������, ������� �������� ������������ � ������� �������
public:
	feedback();
	property String^ Name
	{
		String^ get() {
			return name;
		}
		void set(String^ Name) {
			name = gcnew String(Name);
		}
	}
	property String^ Text
	{
		String^ get() {
			return text;
		}
		void set(String^ Text) {
			text = gcnew String(Text);
		}
	}

	property int Mark
	{
		int get() {
			return mark;
		}
		void set(int Mark) {
			mark = Mark;
		}
	}


};


