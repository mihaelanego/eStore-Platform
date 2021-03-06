/*
* Administrativ - NU MODIFICATI
*/
#include "TestHelper.h"

const json failJson = json::parse("{\"result\": \"fail\"}");
const json successJson = json::parse("{\"result\": \"success\"}");

TestHelper::TestHelper(const string &inFile)
{
	ifstream inStream(inFile);

	inStream >> input;

	inStream.close();

	server = Server::GetInstance();
}

void TestHelper::Init()
{
	server->populateProducts(input);
	server->populateUsers(input);
	server->set__UserID__ProductsCart__();
}

TestHelper::~TestHelper()
{
	if (server != nullptr)
	{
		server = nullptr;
	}
}

json TestHelper::TestProductClass()
{	
	string str = "check";

	// Test Constructori FoodProduct
	FoodProduct *pa = new FoodProduct();
	FoodProduct *pa2 = new FoodProduct(str, 78, str, 7.89, str, 200);

	if (pa2 == NULL)
	{
		return failJson;
	}

	// Test Set FoodProduct
	float val = 9.27;
	string taraOrigine = "Spania";

	pa->setLeiPerKg(val);
	pa->setCountryOfOrigin(taraOrigine);

	// Test Get FoodProduct
	if (pa->getLeiPerKg() != val)
	{
		return failJson;
	}
	if (pa->getCountryOfOrigin() != taraOrigine)
	{
		return failJson;
	}

	// OPERATORI FoodProduct ???

	// Test Construcori NonFoodProduct
	NonFoodProduct *pn = new NonFoodProduct();
	NonFoodProduct *pn2 = new NonFoodProduct(str, 20, str, str, 4.78, 30, 40);

	if (pn2 == NULL)
	{
		return failJson;
	}

	// Test Set NonFoodProduct
	int garantie = 5;
	float pret = 5.79;
	string producator = "Adibas";

	pn->setYearsOfWarranty(garantie);
	pn->setPrice(pret);
	pn->setProducer(producator);

	// Test Get NonFoodProduct
	if (garantie != pn->getYearsOfWarranty())
	{
		return failJson;
	}

	if (pret != pn->getPrice())
	{
		return failJson;
	}

	if (producator != pn->getProducer())
	{
		return failJson;
	}

	// Test Constructori DiscountedProduct
	DiscountedProduct *pr = new DiscountedProduct();
	DiscountedProduct *pr_ref = new DiscountedProduct(str, 69, str, str, 4.20, 2, 60, 100);

	if (pr_ref == NULL)
	{
		return NULL;
	}

	int procentReducere = 60;
	// Test Set DiscountedProduct
	pr->setPrice(pret);
	pr->setDiscountPercentage(procentReducere);

	// Test Get DiscountedProduct
	if (pr->getPrice() != pret)
	{
		return failJson;
	}

	if (pr->getDiscountPercentage() != procentReducere)
	{
		return failJson;
	}

	if (pr->priceAfterDiscount() != pret - ( pret * procentReducere ) / 100) 
	{
		return failJson;
	}

	// Test Constructori ReturnedProduct
	ReturnedProduct *prt = new ReturnedProduct();
	ReturnedProduct *prt_ref = new ReturnedProduct(str, 69, str, str, 4.20, 5, str, 51);

	if (prt_ref == NULL)
	{
		return NULL;
	}

	string motiv = "aiurea";
	// Test Set ReturnedProduct
	prt->setReason(motiv);

	// Test Get ReturnedProduct
	if (prt->getReason() != motiv)
	{
		return failJson;
	}

	// Test Constructori ResealedProduct
	ResealedProduct *pr_res = new ResealedProduct();
	ResealedProduct *pr_res2 = new ResealedProduct(str, 5, str, str, 6.89, 25, 28, str, 29, 30);

	if (pr_res2 == NULL)
	{
		return failJson;
	}

	// Test Set ResealedProduct
	int procent = 6;
	pr_res->setWearPercentage(procent);

	// Test Get ResealedProduct
	if (procent != pr_res->getWearPercentage())
	{
		return failJson;
	}

	return successJson;
}

json TestHelper::TestUserClass()
{

	// Variabile ajutatoare Address
	string check = "check";
	string judet = "Constanta";
	string oras = "SatulDeVacanta";
	string strada = "Strada Bogatanilor";
	int numar = 20;
	string bloc = "Cel Mai Tare Bloc";
	int apartament = 1000;

	// Test Constructor Address
	Address *adr = new Address();
	Address *adr2 = new Address(check, check, check, 70, check, 20);

	// Test Set Address
	adr->setCounty(judet);
	adr->setLocality(oras);
	adr->setStrada(strada);
	adr->setNumber(numar);
	adr->setBlock(bloc);
	adr->setApartment(apartament);

	// Test Get Address
	if (adr->getCounty() != judet)
	{
		return failJson;
	}
	if (adr->getLocality() != oras)
	{
		return failJson;
	}
	if (adr->getStreet() != strada)
	{
		return failJson;
	}
	if (adr->getBlock() != bloc)
	{
		return failJson;
	}
	if (adr->getApartment() != apartament)
	{
		return failJson;
	}

	// OPERATOR << ????

	// Test Constructori PremiumUser
	map<int, int> reduceri_test;
	reduceri_test[1] = 5;
	reduceri_test[3] = 10;
	PremiumUser *up = new PremiumUser();
	PremiumUser *up2 = new PremiumUser(check, check, check, 20, check, 200, check, check, check, 20, check, 30, 200, check, check, check, 20, reduceri_test);

	if (up2 == NULL)
	{
		return failJson;
	}

	// Variabile ajutatoare User
	string nume = "Salam";
	string prenume = "Florin";
	string email = "capitanulromaniei@gmail.com";
	int idUser = 1000;
	int cap = 10;

	// Test Set PremiumUser (implicit si User)
	up->setLastName(nume);
	up->setFirstName(prenume);
	up->setEmail(email);
	up->setUserID(idUser);
	up->setBillingData(*adr);
	up->setDeliveryData(*adr2);
	up->setDiscounts(reduceri_test);
	up->setPremiumSubscriptionCost(cap);

	// Test Get PremiumUser
	if (up->getLastName() != nume)
	{
		return failJson;
	}

	if (up->getFirstName() != prenume)
	{
		return failJson;
	}

	if (up->getEmail() != email)
	{
		return failJson;
	}

	if (up->getUserID() != idUser)
	{
		return failJson;
	}

	if (up->getBillingData() != *adr)
	{
		return failJson;
	}

	if (up->getDeliveryData() != *adr2)
	{
		return failJson;
	}
	if (up->getDiscounts() != reduceri_test)
	{
		return failJson;
	}
	if (up->getPremiumSubscriptionCost() != cap)
	{
		return failJson;
	}

	// Variabile ajutatoare BasicUser
	int costTransport = 20;

	// Test Constructor BasicUser
	BasicUser *unp = new BasicUser();
	BasicUser *unp2 = new BasicUser(check, check, check, 40, check, 60, check, check, check, 20, check, 50, 200, check, check, check, 3.40);

	if (unp2 == NULL)
	{
		return failJson;
	}

	// Test Set UserNonpremium
	unp->setCostTransport(costTransport);

	// Test Get UserNonpremium
	if (unp->getCostTransport() != costTransport)
	{
		return failJson;
	}

	return successJson;
}

json TestHelper::TestCartClass()
{
	// Test Constructori Cos Produse
	string check = "check";
	ShoppingCart *cp = new ShoppingCart();
	ShoppingCart *cp2 = new ShoppingCart(check);

	if (cp2 == NULL)
	{
		return failJson;
	}

	// Test Set + Metode ShoppingCart
	string metodaPlata = "Card";

	cp->setPayMethod(metodaPlata);
	cp->addProduct(5, 3);

	// Test Get + Metode ShoppingCart
	if (cp->getQuantity(5) != 3)
	{
		return failJson;
	}

	cp->lowerQuantity(5, 2);

	if (cp->getQuantity(5) != 1)
	{
		return failJson;
	}

	cp->raiseQuantity(5, 4);

	if (cp->getQuantity(5) != 5)
	{
		return failJson;
	}

	// Map ajutator pentru verificarea operatiilor
	map<int, int> TestCos;
	TestCos[5] = 5;

	if (cp->getShoppingCart() != TestCos)
	{
		return failJson;
	}

	cp->deleteProduct(5);
	TestCos.clear();

	if (cp->getShoppingCart() != TestCos)
	{
		return failJson;
	}

	int res = cp->getQuantity(5);

	if (res != -1)
	{
		return failJson;
	}

	return successJson;
}

json TestHelper::Test_2()
{
	Init();
	json output;

	output["productList"] = ObjectFactory::getProductJson(server->getProductsList());
	output["useri"] = JSONSerializer::FromUserMap(server->get__UserID__ProductsCart__());

	return output;
}

json TestHelper::Test_3a()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3a();

	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3b()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3b();

	output = ObjectFactory::getUserJson(result);

	return output;
}

json TestHelper::Test_3c()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3c();

	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3d()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3d();

	output = ObjectFactory::getProductJson(result);

	return output;
}

json TestHelper::Test_3e()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3e();

	output = ObjectFactory::getUserJson(result);

	return output;
}

json TestHelper::Test_3f()
{
	Init();
	json output;

	auto result = rezolvatorul.Query_3f();

	output = ObjectFactory::getUserJson(result);

	return output;
}

json TestHelper::Test_4()
{
	vector<int> lruTest = {1, 2, 3, 2, 5, 3, 4, 5, 8, 9};
	LRUCache obj(4);
	// check processRequests
	vector<int> ans = obj.processRequests(lruTest);
	vector<int> test = {9, 8, 5, 4};

	if (ans != test)
	{
		return failJson;
	}

	// check set-get LRU
	test = {0, 1, 2, 3};
	obj.setLRU(test);
	vector<int> aux = obj.getLRU();

	if (test != aux)
	{
		return failJson;
	}

	// check set-get cap
	obj.setCapacity(20);
	int cap = obj.getCapacity();

	if (cap != 20 && obj.getLRUCapacity() != 20)
	{
		return failJson;
	}

	return successJson;
}

json TestHelper::Test_5(const string &inFile)
{
	Init();
	ifstream in(inFile);
	json jin;
	in >> jin;
	LRUCache lru(5);
	vector<int> buff;
	json output;
	vector<Query> vec = getQuery(jin["queries"]);
	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		if ((*i).operation == "ADD")
		{
			bool doUpdate = server->requestAddProduct((*i).userID, (*i).productID, (*i).quantity);
			if (doUpdate)
				buff.push_back((*i).productID);
		}
		else
		{
			server->requestDeleteProduct((*i).userID, (*i).productID, (*i).quantity);
		}
	}
	map<int, ShoppingCart *> res = server->get__UserID__ProductsCart__();
	output.push_back(JSONSerializer::FromUserMap(res));
	output.push_back(json(lru.processRequests(buff)));

	return output;
}
