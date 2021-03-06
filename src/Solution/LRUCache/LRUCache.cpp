#include "LRUCache.h"
#include <algorithm>

using namespace std;

//Constructori
LRUCache::LRUCache(int capacity) {
	this->capacity = capacity;
	// this->lru.reserve(capacity);
}

//Metode auxiliare
vector<int> LRUCache::processRequests(vector<int> requestsNo) {
	lru.insert(lru.begin(), requestsNo[0]);
	for (int i = 1; i < requestsNo.capacity(); i++){
		for (int k = 0; k < this->capacity; k++) {
			if (lru[k] == requestsNo[i]) {
				lru.erase(lru.begin() + k);
			} 
		}
		
		if (lru.capacity() > capacity - 1) {
			lru.erase(lru.begin() + capacity - 1 , lru.end());
		}

		lru.insert(lru.begin(), requestsNo[i]);
	}
	return lru;
}

//Get
int LRUCache::getCapacity() {
	return this->capacity;
}

int LRUCache::getSize() {
	return this->size;
}

vector<int> LRUCache::getLRU() {
	return this->lru;
}

int LRUCache::getLRUCapacity() {
	return this->lru.capacity();
}

//Set
void LRUCache::setCapacity(int capacity) {
	this->capacity = capacity;
}

void LRUCache::setLRU(vector<int> aux) {
	this->lru = aux;
}
