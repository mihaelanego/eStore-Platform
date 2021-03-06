#include "FoodProduct.h"

//Constructori
FoodProduct::FoodProduct() {
	this->leiPerKg = 0;
	this->countryOfOrigin = "";
}


FoodProduct::FoodProduct(const string& categorie, int id, const string& nume, float leiPerKg, const string& countryOfOrigin, int cantitate) 
	: Product(categorie, id, nume, cantitate) {
	this->leiPerKg = leiPerKg;
	this->countryOfOrigin = countryOfOrigin;
}

FoodProduct::FoodProduct(const FoodProduct& pa) : Product(pa) {
	this->leiPerKg = pa.leiPerKg;
	this->countryOfOrigin = pa.countryOfOrigin;
}

//Set
void FoodProduct::setLeiPerKg(float leiPerKg) {
	this->leiPerKg = leiPerKg;
}

void FoodProduct::setCountryOfOrigin(const string& countryOfOrigin) {
	this->countryOfOrigin = countryOfOrigin;
}

//Get
float FoodProduct::getLeiPerKg() {
	return this->leiPerKg;
}

string& FoodProduct::getCountryOfOrigin() {
	return this->countryOfOrigin;
}

//Operator
const FoodProduct& FoodProduct::operator=(const FoodProduct& a) {
	Product::operator=(a);
	this->leiPerKg = a.leiPerKg;
	this->countryOfOrigin = a.countryOfOrigin;
	return*this;
}

string FoodProduct::getProductType() {
	return "FoodProduct";
}

//------
json FoodProduct::toJSON()
{
	return json(*this);
}

void FoodProduct::display()
{
	cout << "Product alimentar" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Categorie : " << this->category << endl;
	cout << "ID : " << this->id << endl;
	cout << "Cantitate (stoc): " << this->quantity << endl;
	cout << "Lei per KG : " << this->leiPerKg << endl;
	cout << "Tara de Origine : " << this->countryOfOrigin << endl
		 << endl;
}