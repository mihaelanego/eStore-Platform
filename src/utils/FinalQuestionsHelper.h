/*
* Administrativ - NU MODIFICATI
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "../json.hpp"

using namespace std;
using json = nlohmann::json;
typedef struct lrubluprint{
    int capacity;
    vector<int> allLRUOperations;
}LRU_blueprint;
typedef struct query{
    int productID;
    int userID;
    string operation;
    int quantity;
}Query;

LRU_blueprint getLruBlueprint(json&);

json writeLruFinalState(vector<int>&);

vector<Query> getQuery(json&);

json writeFinalState(vector<Query>&, vector<int>&);

json queryToJson(Query&);