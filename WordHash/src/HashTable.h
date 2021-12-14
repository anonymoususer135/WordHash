
#include <string>
#include "Word.h"
#include <vector>
#ifndef HASHTABLE_H_
#define HASHTABLE_H_


using namespace std;
struct Node {
    string word;
    Node * next;
};
class HashTable {
private:
    int size;
    Node **wor;
	unsigned long hashFunc(Word w, int size);

public:
	HashTable();
    void setSize(int sz);
    ~HashTable();
    int getSize();
//	HashTable(Word *w);
    HashTable(vector <string> v);
    HashTable(unsigned int sz);
	bool insertWordIntoLinkedList(Word wToInsert);
	bool search4Word(Word wToSearch);
	bool isFull() const;
//	struct collisions {
//		string data;
//		collisions *next;
//	};
};



#endif /* HASHTABLE_H_ */


