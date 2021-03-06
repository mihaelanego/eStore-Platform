#pragma once
#include "NonFoodProduct.h"

class DiscountedProduct : virtual public NonFoodProduct
{
    protected:
        int discountPercentage;

    public:
        /*
        * Constructor fara parametri
        */
        DiscountedProduct();
        /*
        * Constructor cu parametri
        */
        DiscountedProduct(const string &, int, const string &, const string &, float, int, int, int);
        /*
        * Constructor de copiere
        */
        DiscountedProduct(const DiscountedProduct &);
        /*
        * Operator =
        */
        const DiscountedProduct &operator=(const DiscountedProduct &);
        /*
        * @param seteaza procentajul de reducere
        */
        void setDiscountPercentage(int);
        /*
        * @return campul discountPercentage
        */
        float getDiscountPercentage();
        /*
        * @return tipul produsului (nu este camp)
        */
        string getProductType();
        /*
        * @return pretul dupa reducerea aplicata
        */
        float priceAfterDiscount() const;
        /*
        *     ADMINISTRATIV - NU MODIFICATI
        */
        void display();
        json toJSON();
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(DiscountedProduct, name, quantity, category, id, producer, yearsOfWarranty, price, discountPercentage)
};
