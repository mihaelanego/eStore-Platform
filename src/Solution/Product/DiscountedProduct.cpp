#include "DiscountedProduct.h"
using namespace std;

//Constructori
DiscountedProduct::DiscountedProduct() : NonFoodProduct() {
	this->discountPercentage = 0;
}

DiscountedProduct::DiscountedProduct(const string& category, int id, const string& producer, const string& name, float price, int yearsOfWarranty, int discountPercentage, int quantity)
	: NonFoodProduct(category, id, producer, name, price, yearsOfWarranty, quantity) {
	this->discountPercentage = discountPercentage;
}


DiscountedProduct::DiscountedProduct(const DiscountedProduct& discountedProduct) : NonFoodProduct(discountedProduct) {
	this->discountPercentage = discountedProduct.discountPercentage;
}

//Get
float DiscountedProduct::getDiscountPercentage() {
	return this->discountPercentage;
}

string DiscountedProduct::getProductType() {
	return "DiscountedProduct";
}

//Set
void DiscountedProduct::setDiscountPercentage(int discountPercentage) {
	this->discountPercentage = discountPercentage;
}

//Operatori
const DiscountedProduct& DiscountedProduct::operator=(const DiscountedProduct& a) {
	NonFoodProduct::operator = (a);
	this->discountPercentage = a.discountPercentage;
	return*this;
}

//Metode auxiliare
float DiscountedProduct::priceAfterDiscount() const {
	float newPrice = price - ( price * discountPercentage ) / 100;
	return newPrice;
}

//---
json DiscountedProduct::toJSON()
{
	return json(*this);
}

void DiscountedProduct::display()
{
	cout << "Product Redus" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Procent reducere : " << this->discountPercentage << endl
		 << endl;
}