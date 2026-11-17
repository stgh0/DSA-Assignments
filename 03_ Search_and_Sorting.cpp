#include <iostream>
#include <string>
using namespace std;
struct Friend {
 string name;
 string mobile;
};
int sentinelSearch(Friend phoneBook[], int n, string key) {
 // Store the last element temporarily
 Friend last = phoneBook[n];
 // Place the search key as a sentinel
 phoneBook[n].name = key;
 int i = 0;
 // Search until the name is found
 while (phoneBook[i].name != key) {
 i++;
 }
 // Restore the last element
 phoneBook[n] = last;
 // If found within original array
 if (i < n)
 return i;
 return -1;
}
void insertFriend(Friend phoneBook[], int &n, string name, string
mobile) {
 int pos = 0;
 // Find correct alphabetical position
 while (pos < n && phoneBook[pos].name < name) {
 pos++;
 }
 // Shift elements to the right
 for (int i = n; i > pos; i--) {
 phoneBook[i] = phoneBook[i - 1];
 }
 // Insert new friend
 phoneBook[pos].name = name;
 phoneBook[pos].mobile = mobile;
 n++;
 cout << "Friend added successfully.\n";
}
void display(Friend phoneBook[], int n) {
 cout << "\n--- Phone Book ---\n";
 for (int i = 0; i < n; i++) {
 cout << phoneBook[i].name << " : "
 << phoneBook[i].mobile << endl;
 }
}
int main() {
 Friend phoneBook[100];
 int n;
 cout << "Enter number of friends: ";
 cin >> n;
 cout << "\nEnter names and mobile numbers in sorted order:\n";
 for (int i = 0; i < n; i++) {
 cout << "Name: ";
 cin >> phoneBook[i].name;
 cout << "Mobile: ";
 cin >> phoneBook[i].mobile;
 }
 string searchName;
 cout << "\nEnter friend name to search: ";
 cin >> searchName;
 int index = sentinelSearch(phoneBook, n, searchName);
 if (index != -1) {
 cout << "\nFriend found!\n";
 cout << "Name : " << phoneBook[index].name << endl;
 cout << "Mobile : " << phoneBook[index].mobile << endl;
 }
 else {
 cout << "\nFriend not found.\n";
 char choice;
 cout << "Do you want to add this friend? (y/n): ";
 cin >> choice;
 if (choice == 'y' || choice == 'Y') {
 string mobile;
 cout << "Enter mobile number: ";
 cin >> mobile;
 insertFriend(phoneBook, n, searchName, mobile);
 }
 }
 display(phoneBook, n);
 return 0;
}
