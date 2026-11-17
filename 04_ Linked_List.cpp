#include <iostream>
#include <string>
using namespace std;
class Node {
public:
 string song;
 Node* next;
 Node(string s) {
 song = s;
 next = nullptr;
 }
};
class Playlist {
private:
 Node* last;
public:
 Playlist() {
 last = nullptr;
 }
 // Add a song
 void addSong(string song) {
 Node* newNode = new Node(song);
 if (last == nullptr) {
 last = newNode;
 last->next = last;
 }
 else {
 newNode->next = last->next;
 last->next = newNode;
 last = newNode;
 }
 cout << "Song added successfully.\n";
 }
 // Delete a song
 void deleteSong(string song) {
 if (last == nullptr) {
 cout << "Playlist is empty.\n";
 return;
 }
 Node* current = last->next;
 Node* previous = last;
 do {
 if (current->song == song) {
 // Only one song
 if (current == last && current->next == last) {
 last = nullptr;
 }
 else {
 previous->next = current->next;
 if (current == last)
 last = previous;
 }
 delete current;
 cout << "Song deleted successfully.\n";
 return;
 }
 previous = current;
 current = current->next;
 } while (current != last->next);
 cout << "Song not found.\n";
 }
 // Display playlist
 void display() {
 if (last == nullptr) {
 cout << "Playlist is empty.\n";
 return;
 }
 Node* current = last->next;
 cout << "\nMusic Playlist:\n";
 do {
 cout << current->song << " -> ";
 current = current->next;
 } while (current != last->next);
 cout << "(Back to first song)\n";
 }
 // Play songs
 void playSongs(int count) {
 if (last == nullptr) {
 cout << "Playlist is empty.\n";
 return;
 }
 Node* current = last->next;
 cout << "\nPlaying songs:\n";
 for (int i = 0; i < count; i++) {
 cout << "Playing: " << current->song << endl;
 current = current->next;
 }
 }
};
int main() {
 Playlist playlist;
 int choice;
 string song;
 int count;
 do {
 cout << "\n===== MUSIC PLAYLIST =====\n";
 cout << "1. Add Song\n";
 cout << "2. Delete Song\n";
 cout << "3. Display Playlist\n";
 cout << "4. Play Songs\n";
 cout << "5. Exit\n";
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 cout << "Enter song name: ";
 cin.ignore();
 getline(cin, song);
 playlist.addSong(song);
 break;
 case 2:
 cout << "Enter song to delete: ";
 cin.ignore();
 getline(cin, song);
 playlist.deleteSong(song);
 break;
 case 3:
 playlist.display();
 break;
 case 4:
 cout << "How many songs do you want to play? ";
 cin >> count;
 playlist.playSongs(count);
 break;
 case 5:
 cout << "Exiting playlist...\n";
 break;
 default:
 cout << "Invalid choice.\n";
 }
 } while (choice != 5);
 return 0;
}
