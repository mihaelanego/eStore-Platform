#include "ReturnedProduct.h"

//Constructori
ReturnedProduct::ReturnedProduct() {
	this->reason = "";
}

ReturnedProduct::ReturnedProduct(const string& categorie, int id, const string& producator, const string& nume, float pret, int garantieAni, const string& motiv, int cantitate)
	: NonFoodProduct(categorie, id, producator, nume, pret, garantieAni, cantitate) {
	this->reason = motiv;
}

ReturnedProduct::ReturnedProduct(const ReturnedProduct& prodRet) : NonFoodProduct(prodRet) {
	this->reason = prodRet.reason;
}

//Operatori
const ReturnedProduct& ReturnedProduct::operator=(const ReturnedProduct& a) {
	NonFoodProduct::operator=(a);
	this->reason = a.reason;
	return*this;
}

//Get
string& ReturnedProduct::getReason() {
	return reason;
}

//Set
void ReturnedProduct::setReason(string& reason) {
	this->reason = reason;
}
	
//Metode auxiliare
string ReturnedProduct::getProductType() {
	return "ReturnedProduct";
}

//---
json ReturnedProduct::toJSON()
{
	return json(*this);
}

void ReturnedProduct::display()
{
	cout << "Product Returnat" << endl;
	cout << "Nume Product: " << this->name << endl;
	cout << "Producator: " << this->producer << endl;
	cout << "Categorie: " << this->category << endl;
	cout << "ID: " << this->id << endl;
	cout << "Cantitate: " << this->quantity << endl;
	cout << "Garantie: " << this->yearsOfWarranty << " ani" << endl;
	cout << "Pret: " << this->price << endl;
	cout << "Motiv : " << this->reason << endl
		 << endl;
}
