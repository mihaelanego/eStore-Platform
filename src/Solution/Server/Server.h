#pragma once
#include <string>
#include <list>
#include <map>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"
#include "../User/PremiumUser.h"
#include "../User/BasicUser.h"
#include "../ShoppingCart/ShoppingCart.h"
#include "../../utils/objectFactory/objectFactory.h"

using namespace std;

class Server
{
	private:
		static Server *instance;
		int usersCapacity;
		list<User *> usr;
		list<Product *> prod;
		/* UserID : ProductsCart */
		map<int, ShoppingCart *> __UserID__ProductsCart__;
		Server();

	public:
		/*
		* Instanta Singleton
		*/ 
		static Server *GetInstance();
		/*
		* Destructor
		*/
		~Server();
		/*
		* @return map __UserID__ProductsCart__; Cheie -> UserID, Valoare -> Pointer catre obiect ShoppingCart
		*/
		map<int, ShoppingCart *> get__UserID__ProductsCart__();
		/*
		* @param json - obiectul json din care va fi populata lista de produse
		*/
		void populateProducts(const json &);
		/*
		* @param json - obiectul json din care va fi populata lista de useri
		*/
		void populateUsers(const json &);
		/*
		* Creeaza map-ul usedId - shoppingCart pe baza listei de useri
		*/
		void set__UserID__ProductsCart__();
		/*
		* @return lista de produse
		*/
		list<Product *> &getProductsList();
		/*
		* @return lista de useri
		*/
		list<User *> &getUsersList();
		/*
		* @param userID id-ul userului pentru care se adauga produsul
		* @param productID id-ul produsului de adaugat
		* @param quantity cantiatatea de adaugat
		* @return true daca request-ul a fost efectuat cu succes, false daca nu
		*/
		bool requestAddProduct(int userID, int productID, int quantity);
		/*
		* @param userID id-ul userului pentru care se elimina produsul
		* @param productID id-ul produsului de eliminat
		* @param quantity cantiatatea de eliminat
		* @return true daca request-ul a fost efectuat cu succes, false daca nu
		*/
		bool requestDeleteProduct(int userID, int productID, int quantity);
};