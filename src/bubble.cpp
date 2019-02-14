#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int init_vec(vector<int> &vec){
    for (int i = 0; i < vec.size(); ++i){
        vec.at(i) = i;
    }
    random_device rd;
    mt19937 shuffle_engine(rd());
    shuffle(vec.begin(), vec.end(), shuffle_engine);
    return 0;
}

int bubble_sort(vector<int> &vec){
    bool swapped;
    while (true){
        swapped = false;
        for (int i = 0; i < vec.size() - 1; ++i){
            if (vec.at(i) > vec.at(i + 1)){
                swap(vec.at(i), vec.at(i + 1));
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return 0;
}

int main(){
    vector<int> vec(100);
    init_vec(vec);
    
    bubble_sort(vec);
    
    for (int &i : vec){
        cout << i << endl;
    }
    return 0;
}
