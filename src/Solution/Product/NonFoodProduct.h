#pragma once
#include "Product.h"

class NonFoodProduct : public Product
{
	protected:
  		string producer;
  		int yearsOfWarranty;
  		float price;

	public:
		/*
		* Constructor fara parametri
		*/
		NonFoodProduct();
		/*
		* Constructor cu parametri
		*/
		NonFoodProduct(const string &, int, const string &, const string &, float, int, int);
		/*
		* Constructor de copiere
		*/
		NonFoodProduct(const NonFoodProduct &pn);
		/*
		* Operator =
		*/
		const NonFoodProduct &operator=(const NonFoodProduct &);
		/* 
		* Operator ==
		*/
		bool operator==(const NonFoodProduct &) const;
		/*
		* @param seteaza campul yearsOfWarranty
		*/
		void setYearsOfWarranty(int);
		/*
		* @param seteaza campul price (pret)
		*/
		void setPrice(float);
		/*
		* @param seteaza campul producer (producator)
		*/
		void setProducer(const string &);
		/*
		* @return warranty (garantie)
		*/
		int getYearsOfWarranty();
		/*
		* @return campul price (pret)
		*/
		float getPrice();
		/*
		* @return campul producer (producator)
		*/
		string &getProducer();
		/*
		* @return tipul produsului (nu este un camp)
		*/
		string getProductType();
		/*
		*     ADMINISTRATIV - NU MODIFICATI
		*/
		json toJSON();
		void display();
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(NonFoodProduct, name, quantity, category, id, producer, yearsOfWarranty, price)
};
