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

int selection_sort(vector<int> &vec)
{
    int min;
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        min = i;
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec.at(j) < vec.at(min))
                min = j;
        }
        swap(vec.at(i), vec.at(min));
    }
    return 0;
}

int main()
{
    vector<int> vec(100);
    init_vec(vec);

    selection_sort(vec);

    for (int &i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
