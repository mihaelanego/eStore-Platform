#pragma once
#include "Product.h"
#include <string>

class FoodProduct : public Product
{
	protected:
		float leiPerKg;
		string countryOfOrigin;

	public:
		/*
		* Constructor fara parametri
		*/
		FoodProduct();
		/*
		* Constructor cu parametri
		*/
		FoodProduct(const string &, int, const string &, float, const string &, int);
		/*
		* Constructor de copiere
		*/
		FoodProduct(const FoodProduct &);
		/*
		* Operator =
		*/
		const FoodProduct &operator=(const FoodProduct &);
		/*
		* @param seteaza campul leiPerKg
		*/
		void setLeiPerKg(float);
		/*
		* @param seteaza campul countryOfOrigin 
		*/
		void setCountryOfOrigin(const string &countryOfOrigin);
		/*
		* @return campul leiPerKg
		*/
		float getLeiPerKg();
		/*
		* @return campul countryOfOrigin
		*/
		string &getCountryOfOrigin();
		/*
		* @return tipul produsului (nu este camp)
		*/
		string getProductType();
		/*
		*     ADMINISTRATIV - NU MODIFICATI
		*/
		json toJSON();
		void display();
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(FoodProduct, name, quantity, category, id, leiPerKg, countryOfOrigin)
};
