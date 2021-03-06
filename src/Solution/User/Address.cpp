#include "Address.h"

using namespace std;

//Constructori
Address::Address() {
	this->county = "";
	this->locality = "";
	this->street = "";
	this->number = 0;
	this->block = "";
	this->apartment = 0;
}

Address::Address(const Address& address) {
	this->county = address.county;
	this->locality = address.locality;
	this->street = address.street;
	this->number = address.number;
	this->block = address.block;
	this->apartment = address.apartment;
}

Address::Address(const string& jud, const string& loc, const string& str, int nr, const string& bl, int ap) {
	this->county = jud;
	this->locality = loc;
	this->street = str;
	this->number = nr;
	this->block = bl;
	this->apartment = ap;
}

//Set
void Address::setStrada(const string& str) {
	this->street = str;
}

void Address::setNumber(int nr) {
	this->number = nr;
}

void Address::setBlock(const string &bl) {
	this->block = bl;
}

void Address::setApartment(int ap) {
	this->apartment = ap;
}

void Address::setCounty(const string& jud) {
	this->county = jud;
}

void Address::setLocality(const string& loc) {
	this->locality = loc;
}

//Get
string& Address::getStreet() {
	return street;
}

int Address::getNumber() {
	return number;
}

string& Address::getBlock() {
	return block;
}

int Address::getApartment() {
	return apartment;
}

string& Address::getCounty() {
	return county;
}

string& Address::getLocality() {
	return locality;
}

//Operatori
const Address& Address::operator=(const Address& adr) {
	this->county = adr.county;
	this->locality = adr.locality;
	this->street = adr.street;
	this->number = adr.number;
	this->block = adr.block;
	this->apartment = adr.apartment;
	return*this;
}

bool Address::operator==(const Address& address) {
	return (
		this->county == address.county &&
		this->locality == address.locality &&
		this->street == address.street &&
		this->number == address.number &&
		this->block == address.block &&
		this->apartment == address.apartment
	);
}

bool Address::operator!=(const Address& address) {
	return (
		this->county != address.county &&
		this->locality != address.locality &&
		this->street != address.street &&
		this->number != address.number &&
		this->block != address.block &&
		this->apartment != address.apartment
	);
}

ostream& operator<<(ostream& OUTPUT, const Address& a) {
	OUTPUT << "County: " << a.county << endl;
	OUTPUT << "Locality: " << a.locality << endl;
	OUTPUT << "Street: " << a.street << endl;
	OUTPUT << "Number: " << a.number << endl;
	OUTPUT << "Block: " << a.block << endl;
	OUTPUT << "Apartment: " << a.apartment << endl << endl;
	return OUTPUT;
}

//---
json Address::toJSON()
{
	return json(*this);
}