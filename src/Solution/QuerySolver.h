#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "../utils/utility.h"
#include "Product/ResealedProduct.h"
#include "Product/FoodProduct.h"
#include "Server/Server.h"
#include "User/PremiumUser.h"
#include "User/BasicUser.h"
#include "LRUCache/LRUCache.h"
#include "../utils/objectFactory/objectFactory.h"

/*
 * Clasa ce contine metodele in care vor fi scrise rezolvarile
 * aferente cerintelor cu query-uri (Cerinta 3)
 */
class QuerySolver
{
  	private:
		Server *server;
		LRUCache *lru;
  	public:
		QuerySolver();
		~QuerySolver();
		list<Product*> Query_3a();
		list<User*> Query_3b();
		list<Product*> Query_3c();
		list<Product*> Query_3d();
		list<User*> Query_3e();
		list<User*> Query_3f();
};