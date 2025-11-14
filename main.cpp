#include "Queue.h"
#include <vector>
#include <list>

int linear_search_last(const vector<int> &items, int target, int pos_first)
{
    if (pos_first < 0)
        return -1;
    if (items[pos_first] == target)
        return pos_first;

    return linear_search_last(items, target, pos_first - 1);
}

void insertion_sort_list(list<int> &num)
{
    vector<int> tempV;
    tempV.reserve(num.size());

    for (int u : num)
    {
        tempV.push_back(u);
    }

    bool insertionNeeded = false;

    for (size_t j = 1; j < tempV.size(); j++)
    {
        int key = tempV[j];
        insertionNeeded = false;

        int i = static_cast<int>(j) - 1;

        for (; i >= 0; i--)
        {
            if (key < tempV[i])
            {
                tempV[i + 1] = tempV[i];
                insertionNeeded = true;
            }
            else
                break;
        }
        if (insertionNeeded)
            tempV[i + 1] = key;
    }

    auto iter = num.begin();

    for (size_t l = 0; l < tempV.size(); l++, ++iter)
    {
        *iter = tempV[l];
    }
}

int main()
{
    Queue<int> qs;

    for ( int i = 1; i <= 10; ++i) {
        qs.push(i);
    }

    cout << "OG Queue: ";
    qs.printQ();

    qs.move_rear();

    cout << "After moving to rear function: ";
    qs.printQ();

    vector<int> vector1{3, 4, 5, 6, 7, 8, 9, 5};
    int index = linear_search_last(vector1, 5, vector1.size() - 1);
    cout << "Last occurrencce of 5: " << index << endl;

    list<int> numbers{1,10,5,7,4, 2};

    insertion_sort_list(numbers);

    for (int n : numbers) {
        cout << n << " ";
    }
    
    return 0;
}