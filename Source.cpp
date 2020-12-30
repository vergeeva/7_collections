#include "Header.h"
dish::dish()
{
	name = gcnew String("Названия блюда");
	about = gcnew String("Описание блюда");
	weight = 1;
	price = 1;
}

dish::dish(dish^ t)
{
	this->About = t->About;
	this->Name = t->Name;
	this->Price = t->Price;
	this->W = t->W;
}

dish::~dish()
{
	delete name;
}

bool dish::operator==(dish^ ot)
{
	return this->Name == ot->Name && this->About == ot->About && this->Price == ot->Price && this->W == ot->W;
}

feedback::feedback()
{
	name = gcnew String("");
	text = gcnew String("");
	mark = 0;
}

feedback::~feedback()
{
	delete name;
	delete text;
}
