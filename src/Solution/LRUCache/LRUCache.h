#pragma once
#include <iostream>
#include <vector>

using namespace std;

class LRUCache
{

	private:
		unsigned int capacity;
		unsigned int size;
		vector<int> lru;

	public:
		/*
			* Constructor cu parametrul capacity
			*/
		LRUCache(int);
		/*
			* @param requestsNo vectorul ce contine id-urile ce corespund requesturilor
			* @return stadiul final al cache-ului
			*/
		vector<int> processRequests(vector<int> requestsNo);
		/*
			* @return capacitatea cache-ului
			*/
		int getCapacity();
		/*
			* @return dimensiunea cache-ului
			*/
		int getSize();
		/*
			* @return vectorul din spatele cache-ului
			*/
		vector<int> getLRU();
		/*
			* @return capacitatea vectorului din spatele cache-ului
			*/
		int getLRUCapacity();
		/*
			* @param seteaza capacitatea cache-ului
			*/
		void setCapacity(int capacity);
		/*
			* @param aux seteaza cache-ul folosind un vector de int
			*/
		void setLRU(vector<int> aux);
};