#pragma once
#include <iostream>
#include <string>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

#define placeHolder "?"
class Product
{
    protected:
        string name;
        int quantity;
        string category;
        int id;

    public:
        /*
        * Destructor
        */
        virtual ~Product() = 0;
        /*
        * Constructor fara parametri
        */
        Product();
        /*
        * Constructor cu parametri
        */
        Product(const string &, int, const string &, int);
        /*
        * Constructor de copiere
        */
        Product(const Product &p);
        /*
        * Operator =
        */
        const Product &operator=(const Product &);
        /*
        * @param seteaza campul Category (categorie) 
        */
        void setCategory(const string &category);
        /*
        * @param seteaza campul id 
        */
        void setId(int);
        /*
        * @param seteaza campul Quantity (cantitate)
        */
        void setQuantity(int);
        /*
        * @param seteaza campul Name (nume)
        */
        void setName(const string &);
        /*
        * @return campul Category (categorie)
        */
        string &getCategory();
        /*
        * @return campul quantity (cantitate)
        */
        int getQuantity();
        /*
        * @return campul id
        */
        int getId();
        /*
        * @return campul Name (nume)
        */
        string &getName();
        /*
        * @return tipul produsului 
        */
        virtual string getProductType() = 0;
        /*
        * @return 
        * @param
        */
        bool checkQuantity(int);
        /*
        * @param 
        */
        void decreaseQuantity(int);
        /*
        * @param
        */
        void increaseQuantity(int);
        /*
        *     ADMINISTRATIV - NU MODIFICATI
        */
        virtual void display() = 0;
        virtual json toJSON();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Product, name, quantity, category, id)
};
