/*
* Administrativ - NU MODIFICATI
*/
#pragma once
#include <iostream>
#include <list>
#include "json.hpp"
#include "../../Solution/Product/FoodProduct.h"
#include "../../Solution/Product/ResealedProduct.h"
#include "../../Solution/User/BasicUser.h"
#include "../../Solution/User/PremiumUser.h"
#include <fstream>

using namespace std;
using json = nlohmann::json;

#define TYPE_KEY "type"

class ObjectFactory
{

	public:
		static Product *createProduct(string, json::iterator);

		static list<Product *> getProductList(json j);

		static json getProductJson(list<Product *> &);

		static User *createUser(string, json::iterator);

		static list<User *> getUserList(json j);

		static json getUserJson(list<User *> &);
};