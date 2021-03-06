#pragma once
#include "User.h"
#include <string>

using namespace std;

class PremiumUser : public User
{
protected:
  map<int, int> discounts;
  int premiumSubscriptionCost;

public:
  /*
   * Constructor fara parametri
   */
  PremiumUser();
  /*
   * Constructor cu parametri
   */
  PremiumUser(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, int, const map<int, int> &);
  /*
   * Constructor de copiere
   */
  PremiumUser(const PremiumUser &);
  /*
   * Operator =
   */
  const PremiumUser &operator=(const PremiumUser &);
  /*
   * @param seteaza campul Discounts (reduceri) cu 
   */
  void setDiscounts(map<int, int>);
  /*
   * @param seteaza campul PremiumSubscriptionCost
   */
  void setPremiumSubscriptionCost(int);
  /*
   * @return campul TransportCost (cost transport)
   */
  float getCostTransport();
  /*
   * @return campul Discounts (reduceri)
   */
  map<int, int> &getDiscounts();
  /*
   * @return campul PremiumSubscriptionCost (cost abonament premium)
   */
  int getPremiumSubscriptionCost();
  /*
   * @return UserType (tipul userului - nu este camp)
   */
  string getUserType();
  /*
   *     ADMINISTRATIV - NU MODIFICATI
   */
  json toJSON();
  void displayUser();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(PremiumUser, billingData, deliveryData, lastName, firstName, email, UserID, premiumSubscriptionCost, discounts)
};