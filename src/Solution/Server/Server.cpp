#include "Server.h"

using namespace std;

/* NU MODIFICATI */
Server::Server(){}

/* NU MODIFICATI */
Server *Server::GetInstance()
{
	if (!instance)
	{
		instance = new Server;
	}

	return instance;
}

/* NU MODIFICATI */
Server::~Server()
{
	if (instance != NULL)
		instance = NULL;

	if (!__UserID__ProductsCart__.empty())
		__UserID__ProductsCart__.clear();
}

void Server::set__UserID__ProductsCart__() {
	list<User *> :: iterator it;
	for (it = usr.begin(); it != usr.end(); ++it) {
		User* aux = *it;
		__UserID__ProductsCart__[aux->getUserID()] =  new ShoppingCart; 
	}
}

list<Product *> &Server::getProductsList() {
	return prod;
}

list<User *> &Server::getUsersList() {
	return usr;
}

map<int, ShoppingCart *> Server::get__UserID__ProductsCart__() {
	return __UserID__ProductsCart__;
}

//metode auxiliare
bool Server::requestAddProduct(int userID, int productID, int quantity) {
	list<User*> :: iterator it;
	list<Product*> :: iterator itr; 
	if (quantity <= 0) {
		return false;
	}

	for (it = usr.begin(); it != usr.end(); ++it) {
		User* aux_usr = *it;
		if (aux_usr->getUserID() == userID) {
			for (itr = prod.begin(); itr != prod.end(); ++itr) {
				Product* aux_prod = *itr;
				if (aux_prod->getId() == productID) {
					if (aux_prod->checkQuantity(quantity)) {
						ShoppingCart* cart = __UserID__ProductsCart__[aux_usr->getUserID()];
						cart->addProduct(productID, quantity);
						aux_prod->decreaseQuantity(quantity);

						return true;
					}
				}
			}
		}
	}
}

bool Server::requestDeleteProduct(int userID, int productID, int quantity) {
	list<User*> :: iterator it;
	list<Product*> :: iterator itr; 
	
	if (quantity <= 0) {
		return false;
	}

	for (it = usr.begin(); it != usr.end(); ++it) {
		User* aux_usr = *it;
		if (aux_usr->getUserID() == userID) {
			for (itr = prod.begin(); itr != prod.end(); ++itr) {
				Product* aux_prod = *itr;
				if (aux_prod->getId() == productID) {				
					ShoppingCart* cart = __UserID__ProductsCart__[aux_usr->getUserID()];
					if (cart->getQuantity(productID) != -1) {
						cart->lowerQuantity(productID, quantity);
						aux_prod->increaseQuantity(quantity);

						return true;
					}
				}
			}
		}
	}
}

/* NU MODIFICATI */
void Server::populateProducts(const json &input)
{
	prod = ObjectFactory::getProductList(input["shoppingCart"]);
}

/* NU MODIFICATI */
void Server::populateUsers(const json &input)
{
	usr = ObjectFactory::getUserList(input["useri"]);
}