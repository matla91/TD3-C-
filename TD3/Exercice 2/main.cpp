#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    vector<int> indicesBruteForce;
    for( int i = 0; i < nums.size(); i++){
        for( int j = 0; j < nums.size(); j++){
            int somme = nums[i] + nums[j];
            if(somme == target){
                indicesBruteForce.push_back(i);
                indicesBruteForce.push_back(j);
                return indicesBruteForce;
            }
        }
    }
    return indicesBruteForce;
}


vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> indicesOptimal;
    for(int i = 0; i < nums.size(); i++){
        int soustraction = target - nums[i];
        // Vérifier si la soustraction est déjà présent dans la map
        if(indicesOptimal.find(soustraction) != indicesOptimal.end()){
                // Si on trouve la soustraction, retourner les indices
                return {indicesOptimal[soustraction], i};
        }
        // Si la soustraction n'est pas trouvée, ajouter l'élément courant et son indice dans la map
        indicesOptimal[nums[i]] = i;
    }
    return {};
}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: ["<< indicesBruteForce[0]<< ", "<< indicesBruteForce[1]<< "]"<< endl;
    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: [" << indicesOptimal[0] << ", " << indicesOptimal[1] << "]" << endl;
    return 0;
}
