/*
* Administrativ - NU MODIFICATI NIMIC
*/
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "../Solution/Product/ResealedProduct.h"
#include "../Solution/Product/FoodProduct.h"
#include "../Solution/LRUCache/LRUCache.h"
#include "../json.hpp"
#include "../Solution/QuerySolver.h"
#include "JSONSerializer.h"
#include "FinalQuestionsHelper.h"

using json = nlohmann::json;
class TestHelper 
{
	Server *server;
	QuerySolver rezolvatorul;
	json input;
  	
	public:
		TestHelper(const string&);
		~TestHelper();
		void Init();
		json TestProductClass(); 
		json TestUserClass();   
		json TestCartClass();     
		json Test_2();
		json Test_3a();
		json Test_3b();
		json Test_3c();          
		json Test_3d();           
		json Test_3e();
		json Test_3f();
		json Test_4();      
		json Test_5(const string&);
};