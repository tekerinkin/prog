//
// Created by Дима Шестаков on 14.02.2021.
//

#ifndef C___QUICKSORT_H
#define C___QUICKSORT_H

#endif //C___QUICKSORT_H

#include<functional>
#include<algorithm>
#include<vector>

template<typename T>
void quicksort(std::vector<T>& arr)
{
    if(arr.size() < 2)
        return;
    std::vector<T> less_v;
    std::vector<T> great_v;
    int pivot = arr[0];
    for(size_t i = 1; i < arr.size(); ++i)
    {
        if(arr[i] > pivot)
            great_v.push_back(arr[i]);
        else
            less_v.push_back(arr[i]);
    }
    quicksort(less_v);
    quicksort(great_v);
    arr.resize(0);
    for(auto& i : less_v)
        arr.push_back(i);
    arr.push_back(pivot);
    for(auto& i : great_v)
        arr.push_back(i);
}