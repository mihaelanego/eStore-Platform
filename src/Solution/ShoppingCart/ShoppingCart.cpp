#include "ShoppingCart.h"

//Constructori
ShoppingCart::ShoppingCart() {
	this->payMethod = "-";
}

ShoppingCart::ShoppingCart(const string& payMethod) {
	this->payMethod = payMethod;
}

//Get
string& ShoppingCart::getPayMethod() {
	return payMethod;
}

map<int, int>& ShoppingCart::getShoppingCart() {
	return shoppingCart;
}

int ShoppingCart::getQuantity(int productID) {
	if (shoppingCart.count(productID) != 0){
		return shoppingCart[productID];
	} 
	else {
		return -1;
	}
}

//Set
void ShoppingCart::setPayMethod(const string& payMethod) {
	this->payMethod = payMethod;
}

//Modificari
void ShoppingCart::addProduct(int id, int quantity) {
	if (shoppingCart.count(id) == 0){
		this->shoppingCart[id] = quantity;
	} 
	else {
		this->shoppingCart[id] += quantity;
	}
}

void ShoppingCart::raiseQuantity(int id, int quantity) {
	int pr = shoppingCart[id];
	this->shoppingCart[id] = pr + quantity;
}

void ShoppingCart::lowerQuantity(int id, int quantity) {
	

	if (shoppingCart[id] > quantity) {
		this->shoppingCart[id] -= quantity;
	}
	else {
		// this->shoppingCart[id] = 0;
		deleteProduct(id);
	}
}

//Delete
void ShoppingCart::deleteProduct(int productID) {
	shoppingCart.erase(productID);
}

//Display
void ShoppingCart::displayShoppingCart()
{
	throw("undefined");
}

//---
json ShoppingCart::toJSON()
{
  return json(*this);
}