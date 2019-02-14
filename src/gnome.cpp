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

int gnome_sort(vector<int> &vec){
    int i = 0;
    while (i + 1 < vec.size()){
        if (vec.at(i) < vec.at(i + 1)){
            ++i;
        }
        else{
            swap(vec.at(i), vec.at(i + 1));
            --i;
            if (i == -1) ++i;
        }
    }
    return 0;
}

int main(){
    vector<int> vec(100);
    init_vec(vec);
    
    gnome_sort(vec);
    
    for (int &i : vec){
        cout << i << endl;
    }
    return 0;
}
