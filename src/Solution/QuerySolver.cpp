#include "QuerySolver.h"
#include <algorithm>

using namespace std;

/* NU MODIFICATI */
QuerySolver::QuerySolver()
{
  server = Server::GetInstance();
}

/* NU MODIFICATI */
QuerySolver::~QuerySolver()
{
  if (server != nullptr)
  {
    server = nullptr;
  }
}

list<Product *> QuerySolver::Query_3a() {
    list<Product*> query_3a;
    list<Product*> prod_3a = server->getProductsList();
    list<Product*> :: iterator it;

    for (it = prod_3a.begin(); it != prod_3a.end(); ++it) {
        Product *aux = *it;
        if (aux->getCategory() == "espressor" && aux->getProductType() == "DiscountedProduct") {
          query_3a.push_back(aux);
        }
    }

    return query_3a;
}

list<User *> QuerySolver::Query_3b() {
    list<User*> query3b;
    list<User*> users_3b = server->getUsersList();
    list<User*> :: iterator it;

    for (it = users_3b.begin(); it != users_3b.end(); ++it) {
        User* aux = *it;
        if (aux->getUserType() == "BasicUser" && aux->getCostTransport() <= 11.5) {
            query3b.push_back(aux);
        }
    }

    return query3b;
}

list<Product *> QuerySolver::Query_3c() {
    list<Product*> query3c;
    list<Product*> prod_3c = server->getProductsList();
    list<Product*> :: iterator it;

    for (it = prod_3c.begin(); it != prod_3c.end(); ++it) {
        Product* aux = *it;
        ResealedProduct *x = dynamic_cast<ResealedProduct*>(aux);
        if (x != nullptr && x->getReason() == "lipsa_accesorii") {
            query3c.push_back(x);
        }
    }
    
      query3c.sort([](Product *y, Product *z) {
        ResealedProduct* casted_y = dynamic_cast<ResealedProduct*>(y);
        ResealedProduct* casted_z = dynamic_cast<ResealedProduct*>(z);

        return casted_y->getPrice() < casted_z->getPrice();
      });
    
    return query3c;
}

list<Product *> QuerySolver::Query_3d() {
    list<Product*> query3d;
    list<Product*> prod_3d = server->getProductsList();
    list<Product*> :: iterator it;

    for (it = prod_3d.begin(); it != prod_3d.end(); ++it) {
        Product* aux = *it;
        if (aux->getProductType() == "FoodProduct") {
            query3d.push_back(aux);
        }
    }

    query3d.sort([] (Product* a, Product* b) {
        FoodProduct* x = dynamic_cast<FoodProduct*>(a);
        FoodProduct* y = dynamic_cast<FoodProduct*>(b);
        
        if (x->getName() != y->getName()) {
            return x->getName() < y->getName();
        } 
        else {
            if (x->getCountryOfOrigin() != y->getCountryOfOrigin()) {
                return x->getCountryOfOrigin() < y->getCountryOfOrigin();
            }
            else {
                return x->getLeiPerKg() < y->getLeiPerKg();
            }
        }
    });

    return query3d;
}

list<User *> QuerySolver::Query_3e() {
    list<User*> query3e;
    list<User*> users_3e = server->getUsersList();
    list<User*> :: iterator it;
    map<string, int> countys;
    int max = 0;
    string max_county = "";

    for (it = users_3e.begin(); it != users_3e.end(); ++it) {
        User* aux = *it;
        if (countys.count(aux->getDeliveryData().getCounty()) == 0) {
            countys[aux->getDeliveryData().getCounty()] = 1;
        }
        else {
            countys[aux->getDeliveryData().getCounty()] += 1;
            if (countys[aux->getDeliveryData().getCounty()] > max) {
                max = countys[aux->getDeliveryData().getCounty()];
                max_county = aux->getDeliveryData().getCounty();
            }
        }
    }

    for (it = users_3e.begin(); it != users_3e.end(); ++it) {
        User* aux = *it;
        if (aux->getDeliveryData().getCounty() == max_county && 
            aux->getDeliveryData().getBlock() == "-" && 
            aux->getDeliveryData().getApartment() == 0) {
                query3e.push_back(aux);
            }
    }

    query3e.sort([](User* x, User* y) {
        return x->getUserID() < y->getUserID();
    });
    
    return query3e;
}


list<User *> QuerySolver::Query_3f() {
    list<User*> query3f;
    list<User*> users_3f = server->getUsersList();
    list<Product*> prod_3f = server->getProductsList();
    vector<int> id_prod;

    list<User*> :: iterator it;
    list<Product*> :: iterator ite;
    map<int, int> :: iterator itr;
    
    for (ite = prod_3f.begin(); ite != prod_3f.end(); ++ite) {
        Product* aux = *ite;
        if (aux->getCategory() == "telefon" || aux->getCategory() == "imprimanta") {
            id_prod.push_back(aux->getId());
        }
    }

    for (it = users_3f.begin(); it != users_3f.end(); ++it) {
        User* aux = *it;
        [&] {
            if (aux->getUserType() == "PremiumUser") {
                PremiumUser* x = dynamic_cast<PremiumUser*>(aux);
                for (itr = x->getDiscounts().begin(); itr != x->getDiscounts().end(); ++itr) {
                    int id = itr->first;
                    for (int i = 0; i < id_prod.size(); i++){
                        if (id == id_prod[i]) {
                            query3f.push_back(aux);
                            return;
                        }
                    }
                }
            }
        }();
    }

    return query3f;
}
