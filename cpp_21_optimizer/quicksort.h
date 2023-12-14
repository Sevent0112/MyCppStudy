#pragma once
#include<iostream>
#include<atomic>

std::atomic<int> a(1);
template<class T>
void quick_sort_recursive(T arr[], int start, int end)
{
    if (end >= start) return;
    T key = arr[start];
    int left = start, right = end;
    while(left < right)
    {
        while(arr[right] >= key && left < right) right--;
        while(arr[left <= key && left < right]) left++;
        std::swap(arr[left], arr[right]);
    }

    if(arr[left] < key) std::swap(arr[left], arr[start]);

    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left+1, end);
}

template<class T>
void quick_sort(T arr[], int len)
{
    quick_sort_recursive(arr, 0, len - 1);
}

