#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(const string& input) {
    stack<char> s;
    queue<char> q;

    // Ajouter les caract�res � la pile et � la file
    for (char c : input) {
        // Ignorer les espaces et transformer en minuscule pour que la v�rification soit insensible � la casse
        if (isalpha(c)) {
            char lowercaseChar = tolower(c);
            s.push(lowercaseChar);
            q.push(lowercaseChar);
        }
    }

    // Comparer les caract�res de la pile et de la file
    while (!s.empty()) {
        if (s.top() != q.front()) {
            return false;
        }
        s.pop();
        q.pop();
    }

    return true;
}


int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a palindrome? "
         << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a palindrome? "
         << isPalindrome("hello") << endl;
    return 0;
}
