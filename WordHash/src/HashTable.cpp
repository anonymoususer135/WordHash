#include "Word.h"
#include "HashTable.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>

using namespace std;

//Thanks for the advice not to use a built in hash function, here is a custom
//hash function
unsigned long HashTable::hashFunc (Word w, int hashTableSize) {
        unsigned int h = w.getWord()[0];
        for (int i = 1; i < w.getWord().length(); i++)
         h = w.getWord()[i] * 61 + 19*i;      //My hash
 //              h+=w.getWord()[i]*61+73*i; //61, 19 are a prime number, I decide to use them to make my hash math equation
        return h % hashTableSize;
}


bool HashTable::insertWordIntoLinkedList(Word w) {
    unsigned long wordIndex=hashFunc(w, this->getSize());
//    if (w.getWord()=="aba")
//        cout << wordIndex << endl;


     try {
        Node *test = new Node;
 //        cout << "Test allocate memory seems OK, now rollback test " << endl;
        delete test;
         } catch(bad_alloc& exception) {
             cerr << " Out of memory!" << endl;
             return true;
         }
    Node *temp = new Node;
    temp=this->wor[wordIndex];

    try {
       Node *test = new Node;
 //      cout << "Test allocate memory seems OK, now rollback test " << endl;
       delete test;
        } catch(bad_alloc& exception) {
            cerr << " Out of memory!" << endl;
            return true;
        }

    Node *n = new Node;
    n->word=w.getWord();
    this->wor[wordIndex]=n;
    n->next=temp;
//    if (w.getWord()=="aba")
//    cout << wor[wordIndex]->word << endl;
    return false;
}

bool HashTable::search4Word(Word w) {
    unsigned long wordIndex=hashFunc(w, this->getSize());
//    cout << wordIndex << endl;
    Node *workNode=this->wor[wordIndex];
    if (!(workNode->word.compare(w.getWord())))
        return true;
    while (workNode->next!=NULL)
    {
        if (!(workNode->word.compare(w.getWord())))
            return true;
        workNode=workNode->next;
    }
    return false;
}



HashTable::HashTable() {
	size = 0;
}

HashTable::HashTable(unsigned int sz) {
    this->wor=new Node*[sz+1]; //this is the number of linked lists. i mean, the argument ;) it's not going to be a linked list, but it's going to be a node
    size=sz; //...yep

    for (unsigned long i=0;i<sz;i++)
    {
        Node *n=new Node;
        n->word="";
        n->next=NULL;
        this->wor[i]=n;
    }
}

int HashTable::getSize() {
    return size;
}

void HashTable::setSize(int sz)
{
    size=sz;
}

HashTable::~HashTable()
{
}





