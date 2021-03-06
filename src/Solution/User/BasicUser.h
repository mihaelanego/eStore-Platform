#pragma once
#include "User.h"

class BasicUser : public User
{
protected:
  float costTransport;

public:
  /*
  * Constructor fara parametri
  */
  BasicUser();
  /*
  * Constructor cu parametri
  */
  BasicUser(const string &, const string &, const string &, int, const string &, int, const string &, const string &, const string &, int, const string &, int, int, const string &, const string &, const string &, float);
  /*
  * Constructor de copiere
  */
  BasicUser(const BasicUser &);
  /*
  * Operator =
  */
  BasicUser &operator=(const BasicUser &);
  /*
   * @param seteaza TransportCost (costul transportului)
   */
  void setCostTransport(int);
  /*
   * @return campul Transport Cost (costul transportului)
   */
  float getCostTransport();
  /*
   * @return UserType (string aferent tipului clasei - nu este un camp)
   */
  string getUserType();
  /*
   *     ADMINISTRATIV - NU MODIFICATI
   */
  json toJSON();
  void displayUser();
  NLOHMANN_DEFINE_TYPE_INTRUSIVE(BasicUser, billingData, deliveryData, lastName, firstName, email, UserID, costTransport)
};
