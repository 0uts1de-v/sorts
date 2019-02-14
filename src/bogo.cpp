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

int bogo_sort(vector<int> &vec){
    random_device rd;
    mt19937 shuffle_engine(rd());
    while (!is_sorted(vec.begin(), vec.end())){
        shuffle(vec.begin(), vec.end(), shuffle_engine);
    }
    return 0;
}

int main(){
    vector<int> vec(10);
    init_vec(vec);
    
    bogo_sort(vec);
    
    for (int &i : vec){
        cout << i << endl;
    }
    return 0;
}
