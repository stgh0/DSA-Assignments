// Shivtej Ghorpade | PRN: 202501110185 | AIML B3
#include <iostream>
#include <string>
#include <deque>
bool isPalindrome(const std::string& text) {
    std::deque<char> characters(text.begin(), text.end());
    while (characters.size() > 1) {
        char left = characters.front(), right = characters.back();
        characters.pop_front(); characters.pop_back();
        if (left != right) return false;
    }
    return true;
}
#ifndef DSA_NO_MAIN
int main() {
    std::string text;
    std::cout << "Enter a string: ";
    if (!std::getline(std::cin, text)) { std::cerr << "Input unavailable\n"; return 1; }
    std::cout << (isPalindrome(text) ? "Palindrome" : "Not a palindrome") << '\n';
}
#endif
