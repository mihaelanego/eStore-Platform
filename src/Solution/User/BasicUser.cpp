#include "BasicUser.h"
using namespace std;

//Constructori
BasicUser::BasicUser() {
	this->costTransport = 0;
}

BasicUser::BasicUser(const string& judetf, const string& localitatef, const string& stradaf, int nr_stradaf, const string& blocf, int apartamentf, const string& judetl, const string& localitatel, const string& stradal, int nr_stradal, const string& blocl, int apartamentl, int id, const string& nume, const string& prenume, const string& email, float _costTransport)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email), costTransport(_costTransport) {
}


BasicUser::BasicUser(const BasicUser& unp) : User(unp) {
	this->costTransport = unp.costTransport;
}

//Operatori
BasicUser& BasicUser::operator=(const BasicUser& unp) {
	User::operator=(unp);
	this->costTransport = unp.costTransport;
	return*this;
}

//Set
void BasicUser::setCostTransport(int cost) {
	this->costTransport = cost;
}

//Get
float BasicUser::getCostTransport() {
	return costTransport;
}

string BasicUser::getUserType() {
	return "BasicUser";
}

//Display
void BasicUser::displayUser() {
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email: " << email << endl;
	cout << "User ID: " << UserID << endl;
	cout << "Billing adress:\n" << billingData;
	cout << "Delivery adress:\n" << deliveryData;
	cout << "User type: " << getUserType() << endl;
}

//---
json BasicUser::toJSON()
{
	return json(*this);
}
