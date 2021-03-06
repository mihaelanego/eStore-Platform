#include "Product.h"
using namespace std;

//Destructor
Product::~Product() {}

//Constructori
Product::Product() {
	this->name = "";
	this->quantity = 0;
	this->category = "";
	this->id = 0;
}

Product::Product(const string& category, int id, const string& name, int quantity) {
	this->name = name;
	this->quantity = quantity;
	this->category = category;
	this->id = id;
}

Product::Product(const Product& p) {
	this->name = p.name;
	this->quantity = p.quantity;
	this->category = p.category;
	this->id = p.id;
}

//Set
void Product::setCategory(const string& category) {
	this->category = category;
}

void Product::setId(int id) {
	this->id = id;
}

void Product::setQuantity(int quantity) {
	this->quantity = quantity;
}

void Product::setName(const string&) {
	this->name = name;
}

//Get
string& Product::getCategory() {
	return this->category;
}

int Product::getQuantity() {
	return this->quantity;
}

int Product::getId() {
	return this->id;
}

string& Product::getName() {
	return this->name;
}

//Operatori
const Product& Product::operator=(const Product& a) {
	this->name = a.name;
	this->quantity = a.quantity;
	this->category = a.category;
	this->id = a.id;
	return*this;
}

//Modificare/verificare cantitate
bool Product::checkQuantity(int requestedQuantity) {
	return (this->quantity >= requestedQuantity);
}

void Product::decreaseQuantity(int requestedQuantity) {
	if (this->quantity >= requestedQuantity) {
		this->quantity -= requestedQuantity;
	}
	else {
		this->quantity = 0;
	}
}

void Product::increaseQuantity(int requestedQuantity) {
	this->quantity += requestedQuantity;
}

//------

json Product::toJSON() {
	return json(*this);
}
