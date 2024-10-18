#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for(int i = 0; i < numbers.size(); i++){
        int frequency = 0;
        for(int j = 0; j < numbers.size(); j++){
            if( numbers[j] == numbers[i] ){
                frequency ++;
            }
        }
        cout << numbers[i] << " est " << frequency << "fois." << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;

    for(int i = 0; i < numbers.size(); i++){
        frequencyMap[numbers[i]]++;
    }
    return frequencyMap;
}

//On a 2 boucles dans countFrequencyBruteForce donc complexité O(n²)
//On a 1 boucle dans countFrequencyOptimal donc complexité 0(n)


int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force) :" << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal) :" << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }

    return 0;
}
