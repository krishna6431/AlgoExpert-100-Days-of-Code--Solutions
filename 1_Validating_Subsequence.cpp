// AlgoExpert 100 Days of Code Solutions
// Code is Written By Krishna
// &copy 2021 Krishna

// Time Complexity---> O(N)
// Space Complexity---> O(1)

#include <bits/stdc++.h>
using namespace std;
// using while loop
bool isValidSubsequence(vector<int> arr, vector<int> seq)
{
    int arr_idx = 0;
    int seq_idx = 0;
    while (arr_idx < arr.size() and seq_idx < seq.size())
    {
        if (arr[arr_idx] == seq[seq_idx])
        {
            seq_idx++;
        }
        else
        {
            arr_idx++;
        }
    }
    return seq_idx == seq.size();
}
// using for loop
bool isValidSubsequence2(vector<int> arr, vector<int> seq)
{
    int seq_idx = 0;
    for (auto itr : arr)
    {
        if (seq_idx == seq.size())
        {
            break;
        }
        if (seq[seq_idx] == itr)
        {
            seq_idx++;
        }
    }
    return seq_idx == seq.size();
}
int main()
{
    vector<int> arr, seq;
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i + 13);
    }
    seq.push_back(14);
    seq.push_back(17);
    seq.push_back(19);
    seq.push_back(21);
    cout << "Using First Function(While Loop): ";
    isValidSubsequence(arr, seq) ? cout << "Valid Subsequence\n" : cout << "Invalid Subsequence\n"
                                                                        << endl;
    cout << "Using Second Function(For Loop): ";
    isValidSubsequence2(arr, seq) ? cout << "Valid Subsequence\n" : cout << "Invalid Subsequence\n"
                                                                         << endl;
    return 0;
}