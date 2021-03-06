#pragma once
#include "NonFoodProduct.h"

class ReturnedProduct : virtual public NonFoodProduct
{
    protected:
        string reason;

    public:
        /*
        * Constructor fara parametri
        */
        ReturnedProduct();
        /*
        * Constructor cu parametri
        */
        ReturnedProduct(const string &, int, const string &, const string &, float, int, const string &, int);
        /*
        * Constructor de copiere
        */
        ReturnedProduct(const ReturnedProduct &);
        /*
        * Operator =
        */
        const ReturnedProduct &operator=(const ReturnedProduct &);
        /*
        * @return campul reason (motiv)
        */
        string &getReason();
        /*
        * @param seteaza campul reason (motivul returnarii)
        */
        void setReason(string &);
        /*
        * @return tipul produsului (nu este camp)
        */
        string getProductType();
        /*
        *     ADMINISTRATIV - NU MODIFICATI
        */
        json toJSON();
        void display();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ReturnedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, reason)
};
