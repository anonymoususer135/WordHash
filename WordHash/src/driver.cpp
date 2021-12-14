#include "Word.h"
#include "HashTable.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
 //   Word *wor;
    string line;
    int choice;
    HashTable h;
    Word wordToBeInserted;
    string wordToBeSearched;
    Word toBeSearched;
//    cout << "Enter the size of the table" << endl;
//    cin >> tableSize;


//    ifstream words("c:/tmp/words.txt");
    int tableSize;
    cout << "Enter the size of table" << endl;
    cin >> tableSize;//prompting the user to enter a size

    h=HashTable(tableSize);//and then the size becomes the number of linked lists
 //Now read words and added into dynamic array of linked list
    ifstream words("c:/temp/words.txt");
    unsigned int wordCount=0;
    if (words.is_open()) {

        while (getline (words, line)) {
            //remove new line \r from line
        	if (line.size()==0)
        		continue;
            line=line.erase(line.size() - 1);
//            if (!line.compare("aba"
//            cout << line << " " << line.size() << endl;
            wordToBeInserted.setWord(line);
            h.insertWordIntoLinkedList(wordToBeInserted);
            wordCount++;
        }
    }
    cout << "number of the words read " << wordCount <<endl;

    cout << "MENU" << endl;
    cout << "1. Search for a word" << endl;
    cout << "2. Quit" << endl;
    cin >> choice;
    while (choice != 2) {
        switch (choice) {
        case 1:
            {
            cout << "Enter word to be searched"<<endl;
            cin >> wordToBeSearched;
            toBeSearched.setWord(wordToBeSearched);
   //             cout << "hello" << endl;
   //             cout << toBeSearched.getWord() << endl;
   //             cout << "world" << endl;
            auto start =  std::chrono::high_resolution_clock::now();

            bool searchResult=h.search4Word(toBeSearched);
 //           system("sleep 1");
            system("ping 127.0.0.1 -n 2 > nul"); //sleep 1 mili second, later will substract 1000 microseconds
            //this ping will delay 1 second, later subtract 1 million.
            if (searchResult)
            {
                cout << "found" << endl;

            }
            else
            {
                cout << "not found" << endl;

            }
            auto stop =  std::chrono::high_resolution_clock::now();
            auto durationInMS = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            long durationFinal=durationInMS.count()-1000000; //Minus sleep 1 mili second, left over is the compute duration
            cout << "Duration in MicroSecond " << durationFinal << endl;
 //           if (h.search4Word(toBeSearched) == true) {
 //               cout << "Time taken to search: " << duration.count() << " microseconds" << endl;
 //           }
 //           else {
 //               cout << "Word not found";
 //           }
            cout << "MENU" << endl;
            cout << "1. Search for a word" << endl;
            cout << "2. Quit" << endl;
            cin >> choice;
            }
            break;
        case 2:
            return 0;
        default:
            cout << "Invalid input" << endl;
            cout << "MENU" << endl;
            cout << "1. Search for a word" << endl;
            cout << "2. Quit" << endl;
            cin >> choice;
    }
    }
    return 0;
}

