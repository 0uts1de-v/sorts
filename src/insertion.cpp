#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int init_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        vec.at(i) = i;
    }
    random_device rd;
    mt19937 shuffle_engine(rd());
    shuffle(vec.begin(), vec.end(), shuffle_engine);
    return 0;
}

int insertion_sort(vector<int> &vec)
{
    int j, tmp;
    for (int i = 0; i < vec.size(); ++i)
    {
        j = i - 1;
        tmp = vec.at(i);
        while (j >= 0 && vec.at(j) > tmp)
        {
            vec.at(j + 1) = vec.at(j);
            --j;
        }
        vec.at(j + 1) = tmp;
    }
    return 0;
}

int main()
{
    vector<int> vec(100);
    init_vec(vec);

    insertion_sort(vec);

    for (int &i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
