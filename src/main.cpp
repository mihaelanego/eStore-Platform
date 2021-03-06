/*
* Administrativ - NU MODIFICATI
*/
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Solution/QuerySolver.h"
#include "Solution/Product/ResealedProduct.h"
#include "Solution/Product/FoodProduct.h"
#include "Solution/Server/Server.h"
#include "Solution/User/PremiumUser.h"
#include "Solution/User/BasicUser.h"
#include "Solution/LRUCache/LRUCache.h"
#include "utils/objectFactory/objectFactory.h"
#include "utils/TestHelper.h"
#include "utils/FinalQuestionsHelper.h"

using namespace std;

Server *Server::instance = 0;

int main(int argc, char **argv)
{
	json result;
	TestHelper p(argv[1]);
	QuerySolver rez;

	try
	{
		if (argc != 4)
		{
			throw "Error: Executable requires precisely 4 arguments!";
		}

		ofstream oStream(argv[2]);
		int testIndex = atoi(argv[3]);

		switch (testIndex)
		{
		case 1:
			result = p.TestProductClass();
			break;
		case 2:
			result = p.TestUserClass();
			break;
		case 3:
			result = p.TestCartClass();
			break;
		case 4:
		    result = p.Test_2();
			break;
		case 5:
			result = p.Test_3a();
			break;
		case 6:
			result = p.Test_3b();
			break;
		case 7:
			result = p.Test_3c();
			break;
		case 8:
			result = p.Test_3d();
			break;
		case 9:
			result = p.Test_3e();
			break;
		case 10:
			result = p.Test_3f();
			break;
		case 11:
			result = p.Test_4();
			break;
		case 12:
			result = p.Test_5(argv[1]);
			break;
		default:
			break;
		}

		oStream << result;

		return 0;
	}
	catch (const char *ex)
	{
		cout << ex;
	}

	return 0;
}