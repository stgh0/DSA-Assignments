#include <iostream>
#include <string>
using namespace std;
const int SIZE = 10;
class Book {
public:
 long long isbn;
 string title;
 bool occupied;
 Book() {
 occupied = false;
 }
};
int main() {
 Book hashTable[SIZE];
 int choice;
 do {
 cout << "\n--- LIBRARY HASHING SYSTEM ---\n";
 cout << "1. Insert Book\n";
 cout << "2. Search Book\n";
 cout << "3. Delete Book\n";
 cout << "4. Display Hash Table\n";
 cout << "5. Exit\n";
 cout << "Enter choice: ";
 cin >> choice;
 switch (choice) {
 case 1: {
 long long isbn;
 string title;
 cout << "Enter ISBN: ";
 cin >> isbn;
 cout << "Enter Book Title: ";
 cin.ignore();
 getline(cin, title);
 int index = isbn % SIZE;
 int originalIndex = index;
 while (hashTable[index].occupied) {
 index = (index + 1) % SIZE;
 if (index == originalIndex) {
 cout << "Hash Table is full!\n";
 break;
 }
 }
 if (!hashTable[index].occupied) {
 hashTable[index].isbn = isbn;
 hashTable[index].title = title;
 hashTable[index].occupied = true;
 cout << "Book inserted at index: " <<
index << endl;
 }
 break;
 }
 case 2: {
 long long isbn;
 cout << "Enter ISBN to search: ";
 cin >> isbn;
 int index = isbn % SIZE;
 int originalIndex = index;
 bool found = false;
 while (hashTable[index].occupied) {
 if (hashTable[index].isbn == isbn) {
 cout << "\nBook Found!\n";
 cout << "ISBN: " <<
hashTable[index].isbn << endl;
 cout << "Title: " <<
hashTable[index].title << endl;
 cout << "Index: " << index << endl;
 found = true;
 break;
 }
 index = (index + 1) % SIZE;
 if (index == originalIndex) break;
 }
 if (!found) cout << "Book not found!\n";
 break;
 }
 case 3: {
 long long isbn;
 cout << "Enter ISBN to delete: ";
 cin >> isbn;
 int index = isbn % SIZE;
 int originalIndex = index;
 bool found = false;
 while (hashTable[index].occupied) {
 if (hashTable[index].isbn == isbn) {
 hashTable[index].occupied = false;
 cout << "Book deleted
successfully!\n";
 found = true;
 break;
 }
 index = (index + 1) % SIZE;
 if (index == originalIndex) break;
 }
 if (!found) cout << "Book not found!\n";
 break;
 }
 case 4:
 cout << "\n--- HASH TABLE ---\n";
 for (int i = 0; i < SIZE; i++) {
 cout << "Index " << i << ": ";
 if (hashTable[i].occupied) {
 cout << "ISBN = " << hashTable[i].isbn
<< ", Title = " << hashTable[i].title;
 } else {
 cout << "Empty";
 }
 cout << endl;
None
 }
 break;
 case 5:
 cout << "Exiting program...\n";
 break;
 default:
 cout << "Invalid choice!\n";
 }
 } while (choice != 5);
 return 0;
}
