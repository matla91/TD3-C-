#include <queue>
#include <stack>
#include <cctype>
#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(const string& input) {
    stack<char> s;
    queue<char> q;

    // Ajouter les caractères à la pile et à la file
    for (char c : input) {
        // Ignorer les espaces et transformer en minuscule pour que la vérification soit insensible à la casse
        if (isalpha(c)) {
            char lowercaseChar = tolower(c);
            s.push(lowercaseChar);
            q.push(lowercaseChar);
        }
    }

    // Comparer les caractères de la pile et de la file
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
