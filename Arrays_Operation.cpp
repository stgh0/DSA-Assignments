#include <iostream>
using namespace std;
int main() {
 int productID[100];
 int quantity[100];
 int n = 0;
 int choice;
 do {
 cout << "\n--- INVENTORY MANAGEMENT SYSTEM ---\n";
 cout << "1. Insert Product\n";
 cout << "2. Update Product Quantity\n";
 cout << "3. Delete Product\n";
 cout << "4. Display Products\n";
 cout << "5. Search Product\n";
 cout << "6. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 // INSERTION
 case 1:
 if (n >= 100) {
 cout << "Inventory is full!\n";
 }
 else {
 cout << "Enter Product ID: ";
 cin >> productID[n];
 cout << "Enter Quantity: ";
 cin >> quantity[n];
 n++;
 cout << "Product inserted successfully!\n";
 }
 break;
 // UPDATION
 case 2: {
 int id;
 bool found = false;
 cout << "Enter Product ID to update: ";
 cin >> id;
 for (int i = 0; i < n; i++) {
 if (productID[i] == id) {
 cout << "Current Quantity: " <<
quantity[i] << endl;
 cout << "Enter new quantity: ";
 cin >> quantity[i];
 cout << "Product updated
successfully!\n";
 found = true;
 break;
 }
 }
 if (found == false) {
 cout << "Product not found!\n";
 }
 break;
 }
 // DELETION
 case 3: {
 int id;
 bool found = false;
 cout << "Enter Product ID to delete: ";
 cin >> id;
 for (int i = 0; i < n; i++) {
 if (productID[i] == id) {
 // Shift elements to the left
 for (int j = i; j < n - 1; j++) {
 productID[j] = productID[j + 1];
 quantity[j] = quantity[j + 1];
 }
 n--;
 cout << "Product deleted
successfully!\n";
 found = true;
 break;
 }
 }
 if (found == false) {
 cout << "Product not found!\n";
 }
 break;
 }
 // DISPLAY
 case 4:
 if (n == 0) {
 cout << "Inventory is empty!\n";
 }
 else {
 cout << "\nProduct ID\tQuantity\n";
 for (int i = 0; i < n; i++) {
 cout << productID[i] << "\t\t"
 << quantity[i] << endl;
 }
 }
 break;
 // SEARCHING
 case 5: {
 int id;
 bool found = false;
 cout << "Enter Product ID to search: ";
 cin >> id;
 for (int i = 0; i < n; i++) {
 if (productID[i] == id) {
 cout << "Product Found!\n";
 cout << "Product ID: " << productID[i] <<
endl;
 cout << "Quantity: " << quantity[i] <<
endl;
 found = true;
 break;
 }
 }
 if (found == false) {
 cout << "Product not found!\n";
 }
 break;
 }
 case 6:
 cout << "Exiting program...\n";
 break;
 default:
 cout << "Invalid choice!\n";
 }
 } while (choice != 6);
 return 0;
}
