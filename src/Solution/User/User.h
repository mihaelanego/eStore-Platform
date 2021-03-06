#pragma once
#include <string>
#include <map>

#include "Address.h"
#include "../Product/ResealedProduct.h"
#include "../Product/FoodProduct.h"

using namespace std;

class User
{
	protected:
		Address billingData;
		Address deliveryData;
		string lastName;
		string firstName;
		string email;
		int UserID;

	public:
		/*
		 * @return tipul userului (nu este camp)
		 */
		virtual string getUserType() = 0;
		/*
		 * @return campul TransportCost (costul transportului)
		 */
		virtual float getCostTransport() = 0;
		/*
		 * destructor User
		 */
		virtual ~User() = 0;
		/*
		 * Constructor fara parametri
		 */
		User();
		/*
		 * Constructor cu parametri
		 */
		User(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &);
		/*
		 * Constructor de copiere
		 */
		User(const User &);
		/*
		 * Operator =
		 */
		const User &operator=(const User &);
		/*
		 * @param seteaza campul lastName (nume de familie)
		 */
		void setLastName(const string &);
		/*
		 * @param seteaza campul firstName (prenume)
		 */
		void setFirstName(const string &);
		/*
		 * @param seteaza campul email
		 */
		void setEmail(const string &);
		/*
		 * @param seteaza campul id
		 */
		void setUserID(int);
		/*
		 * @param seteaza campul billingData (adresa de facturare)
		 */
		void setBillingData(const Address &billingData);
		/*
		 * @param seteaza campul deliveryData (adresa de livrare)
		 */
		void setDeliveryData(const Address &deliveryData);
		/*
		 * @return campul lastName (nume de familie)
		 */
		string &getLastName();
		/*
		 * @return campul firstName (prenume)
		 */
		string &getFirstName();
		/*
		 * @return campul email
		 */
		string &getEmail();
		/*
		 * @return campul UserID
		 */
		int getUserID() const;
		/*
		 * @return campul billingData (adresa de facturare)
		 */
		Address &getBillingData();
		/*
		 * @return campul deliveryData (adresa de livrare)
		 */
		Address &getDeliveryData();
		/*
		*     ADMINISTRATIV - NU MODIFICATI
		*/
		virtual void displayUser() = 0;
		virtual json toJSON();
		NLOHMANN_DEFINE_TYPE_INTRUSIVE(User, billingData, deliveryData, lastName, firstName, email, UserID)
};
