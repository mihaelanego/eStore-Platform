/*
* Administrativ - NU MODIFICATI
*/
#include "FinalQuestionsHelper.h"

vector<Query> getQuery(json &j){
    vector<Query> rez;
    for(json::iterator it = j.begin(); it != j.end(); it++){
        Query q{
            (*it)["productID"].get<int>(),
            (*it)["userID"].get<int>(),
            (*it)["operation"].get<string>(),
            (*it)["quantity"].get<int>()
        };
        rez.push_back(q);
    }
    return rez;
}

