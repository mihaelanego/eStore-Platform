/*
* Administrativ - NU MODIFICATI
*/
#pragma once
#include <iostream>
#include <map>
#include <string>
#include "../json.hpp"
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/User/PremiumUser.h"
#include "../Solution/User/BasicUser.h"
#include "../Solution/ShoppingCart/ShoppingCart.h"

using namespace std;
using json = nlohmann::json;
class JSONSerializer 
{
    public:
        static json fromProductMap(const map<int, Product*> products)
        {
            json result;

            for (auto& it: products)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }

        static json FromUserMap(const map<int, ShoppingCart*>& cartsOfProducts)
        {
            json result;

            for (auto& it : cartsOfProducts)
            {
                result[to_string(it.first)] = it.second->toJSON();
            }

            return result;
        }
};