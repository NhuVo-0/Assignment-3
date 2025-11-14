#include "Queue.h"
#include <vector>
#include <list>

int linear_search_last(const vector<int> &items, int target, int pos_first) //modified function of linear search to return the last value
{
    if (pos_first < 0)
        return -1;
    if (items[pos_first] == target) //this condition was changed to checking  in the vector for the last occurrence instead of checking for the first occurrence and stopping
        return pos_first;

    return linear_search_last(items, target, pos_first - 1);
}

void insertion_sort_list(list<int> &num) //modified function of insortion to work with a list of int
{
    vector<int> tempV;
    tempV.reserve(num.size()); //double the size of the vector of int

    for (int u : num) //read integers and pushing them into the temp vector
    {
        tempV.push_back(u);
    }

    bool insertionNeeded = false; //condition for insertion

    for (size_t j = 1; j < tempV.size(); j++)
    {
        int key = tempV[j]; //the key gradually increases as the for loop run
        insertionNeeded = false;

        int i = static_cast<int>(j) - 1; //static cast the int i to be j-1

        for (; i >= 0; i--) //checking if there is still insertion needed
        {
            if (key < tempV[i])
            {
                tempV[i + 1] = tempV[i];
                insertionNeeded = true; //if insertion is done
            }
            else
                break;
        }
        if (insertionNeeded)
            tempV[i + 1] = key; //update the key
    }

    auto iter = num.begin(); //auto iterator to run through the list

    for (size_t l = 0; l < tempV.size(); l++, ++iter)
    {
        *iter = tempV[l]; //dereferencing the iterator to get the data and adding it to the temp vector
    }
}

int main()
{
    Queue<int> qs; //initializing the queue of integers

    for ( int i = 1; i <= 10; ++i) { //reading numbers up to 10
        qs.push(i); //push the integers into the queue
    }

    cout << "OG Queue: ";
    qs.printQ(); //display original queue
    cout << "OG Queue's front: " << qs.front() << endl; //front of OG queue
    qs.move_rear(); //call moving to rear functoion to move the front to the end

    cout << "After moving to rear function: ";
    qs.printQ(); //print queue after moving
    cout << "OG Queue's front after moving: " << qs.front() << endl; //front of queue after
    cout << endl;

    vector<int> vector1{3, 4, 5, 6, 7, 8, 9, 5}; //vector of unsorted integers
    cout << "OG vector: "; //print original vector
    for (auto i : vector1) {
        cout << i << ' ';
    }
    cout << endl;
    int index = linear_search_last(vector1, 5, vector1.size() - 1); //call linear search to search for the last occurrence of 5
    cout << "Last occurrencce of 5: " << index << endl; //display the last occurrence
    cout << endl;


    list<int> numbers{1,10,5,7,4, 2}; //list of integers
    cout << "OG list: "; //displace OG list before sorted
    for (int m : numbers) {
        cout << m << " ";
    }
    insertion_sort_list(numbers); //sort the list w/ function
    cout << endl;
    cout << "Sorted OG list: ";
    for (int n : numbers) { //print sorted list
        cout << n << " ";
    }
    
    return 0;
}