#include "NonFoodProduct.h"

//Constructori
NonFoodProduct::NonFoodProduct() {
	this->price = 0;
	this->producer = "";
	this->yearsOfWarranty = 0;
}

NonFoodProduct::NonFoodProduct(const string& category, int id, const string& producer, const string& name, float price, int yearsOfWarranty, int quantity)
	: Product(category, id, name, quantity) {
	this->price = price;
	this->producer = producer;
	this->yearsOfWarranty = yearsOfWarranty;
}

NonFoodProduct::NonFoodProduct(const NonFoodProduct& pn) : Product(pn) {
	this->price = pn.price;
	this->producer = pn.producer;
	this->yearsOfWarranty = pn.yearsOfWarranty;
}

//Set
void NonFoodProduct::setYearsOfWarranty(int yearsOfWarranty) {
	this->yearsOfWarranty = yearsOfWarranty;
}

void NonFoodProduct::setPrice(float price) {
	this->price = price;
}

void NonFoodProduct::setProducer(const string& producer) {
	this->producer = producer;
}

//Get
int NonFoodProduct::getYearsOfWarranty() {
	return this->yearsOfWarranty;
}

float NonFoodProduct::getPrice() {
	return this->price;
}

string& NonFoodProduct::getProducer() {
	return this->producer;
}

//Operatori
bool NonFoodProduct::operator==(const NonFoodProduct& obj) const {
	return (
		this->name == obj.name &&
		this->quantity == obj.quantity &&
		this->category == obj.category &&
		this->id == obj.id &&
		this->price == obj.price &&
		this->producer == obj.producer &&
		this->yearsOfWarranty == obj.yearsOfWarranty
	);
}

const NonFoodProduct& NonFoodProduct::operator=(const NonFoodProduct& a) {
	Product::operator=(a);
	this->price = a.price;
	this->producer = a.producer;
	this->yearsOfWarranty = a.yearsOfWarranty;
	return*this;
}

//Metode auxiliare
string NonFoodProduct::getProductType() {
	return "NonFoodProduct";
}

//---
json NonFoodProduct::toJSON()
{
	return json(*this);
}

void NonFoodProduct::display()
{
	cout << "Product Nealimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl
		 << endl;
}
