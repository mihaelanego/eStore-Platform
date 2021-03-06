#include "PremiumUser.h"
using namespace std;

//Constructori
PremiumUser::PremiumUser() {
	this->premiumSubscriptionCost = 0;
}

PremiumUser::PremiumUser(const string& judetf, const string& localitatef, const string& stradaf, int nr_stradaf, const string& blocf, int apartamentf,
	const string& judetl, const string& localitatel, const string& stradal, int nr_stradal, const string& blocl, int apartamentl,
	int id, const string& nume, const string& prenume, const string& email, int premiumSubscriptionCost, const map<int, int>& discounts)
	: User(judetf, localitatef, stradaf, nr_stradaf, blocf, apartamentf, judetl, localitatel, stradal, nr_stradal, blocl, apartamentl, id, nume, prenume, email) {
	
	this->premiumSubscriptionCost = premiumSubscriptionCost;
	this->discounts = discounts;
}


PremiumUser::PremiumUser(const PremiumUser& up) : User(up) {
	this->premiumSubscriptionCost = up.premiumSubscriptionCost;
	this->discounts = up.discounts;
}

//Operatori
const PremiumUser& PremiumUser::operator=(const PremiumUser& up) {
	User::operator=(up);
	this->premiumSubscriptionCost = up.premiumSubscriptionCost;
	this->discounts = up.discounts;
	return*this;
}


//Display
void PremiumUser::displayUser() {
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email: " << email << endl;
	cout << "User ID: " << UserID << endl;
	cout << "Billing adress:\n" << billingData;
	cout << "Delivery adress:\n" << deliveryData;
	cout << "User type: " << getUserType() << endl;
}

//Get
string PremiumUser::getUserType() {
	return "PremiumUser";
}

int PremiumUser::getPremiumSubscriptionCost() {
	return premiumSubscriptionCost;
}

float PremiumUser::getCostTransport() {
	return 0.0;
}

map<int, int>& PremiumUser::getDiscounts() {
	return this->discounts;
}

//Set
void PremiumUser::setDiscounts(map<int, int> red) {
	this->discounts = red;
}

void PremiumUser::setPremiumSubscriptionCost(int cap) {
	this->premiumSubscriptionCost = cap;
}

//---
json PremiumUser::toJSON()
{
	return json(*this);
}