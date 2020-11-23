#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace std;
using namespace System::IO;
//Задача 19. Кафешка: есть меню блюд, в нем указано, что умеет готовить повар.Есть
//информация о спросе : что люди берут.Эта разница поможет узнать, как обновлять
//ассортимент.Каждое блюда можно удалить, если не пользуется спросом, или снизить
//цену, если дорого.Выясняя причину, почему не берут, можно ограничиться критериями :
//невкусно, дорого, калорийно.

//Примерная реализация:
//класс блюдо: название, описание, граммовка, цена
//массив List блюд, функции прописать в хедере формы
//Изначальное окно: для клиента, для управленца
//Для клиента: меню для ознакомления, оформить заказ, оставить отзыв
//Для управленца: посмотреть статистику блюд, редактировать меню
//Меню: список блюд, добавление в заказ через двойной щелчок мыши по блюду
//Когда блюдо добавляется, то мы считаем(плюсуем) их количество
//оформить заказ: список заказанных блюд, возможность удаление по 2 щелчку
//по нажатию кнопки заказать, количество заказанных блюд обновляется
//оставить отзыв: можно выбрать блюдо и поставить оценку. Можно оформить как словарь
//посмотреть статистику: показан список блюд и рядом количество покупок, 
//так же средняя оценка блюда
//редактировать меню: можно удалять блюда по двойному нажатию, редактировать цену
//Совет: лучше объединить это все в одно окно

public ref class dish //блюдо
{
private:
	String^ name; //Название блюда
	String^ about; //Описание блюда
	int weight; //граммовка
	double price; //цена
	int count;//Сколько уже заказано

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
	String^ name; //название блюда, по которому составлен отзыв
	String^ text; //Содержание отзыва
	int mark; //оценка, которую поставил пользователь с текущим отзывом
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


