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

int comb_sort(vector<int> &vec)
{
    int h = vec.size() / 1.3;
    bool swapped;
    while (true)
    {
        swapped = false;
        for (int i = 0; i + h < vec.size(); ++i)
        {
            if (vec.at(i) > vec.at(i + h))
            {
                swap(vec.at(i), vec.at(i + h));
                swapped = true;
            }
        }
        if (!swapped && h == 1)
            break;
        if (h != 1)
            h /= 1.3;
        if (h == 9 || h == 10)
            h = 11;
    }
    return 0;
}

int main()
{
    vector<int> vec(100);
    init_vec(vec);

    comb_sort(vec);

    for (int &i : vec)
    {
        cout << i << endl;
    }
    return 0;
}
