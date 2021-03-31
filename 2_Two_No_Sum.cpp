// AlgoExpert 100 Days of Code Solutions
// Code is Written By Krishna
// &copy 2021 Krishna

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Using 2 For Loops
// Time Complexity : O(N^2)
// Space Complexity: O(1)

pair<int, int> two_sum(vector<int> arr, int target)
{
    pair<int, int> ans;
    ans = make_pair(-1, -1);
    for (int i = 0; i < arr.size(); i++)
    {
        int val1 = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] == (target - val1))
            {
                ans.first = val1;
                ans.second = arr[j];
            }
            else
            {
                continue;
            }
        }
    }
    return ans;
}

//Approach 2 : Using HashTable
// Time Complexity : O(N)
// Space Complexity: O(N)
pair<int, int> two_sum_hashtable(vector<int> arr, int target)
{
    unordered_set<int> hash;
    for (auto val : arr)
    {
        int potential_match = target - val;
        if (hash.find(potential_match) != hash.end())
        {
            return pair<int, int>(val, potential_match);
        }
        else
        {
            hash.insert(val);
        }
    }
    return pair<int, int>(-1, -1);
}

//Approach 3 : Using Two Pointer + Sorting
// Time Complexity : O(NlogN)
// Space Complexity: O(1)
pair<int, int> two_sum_sorting(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int left_ptr = 0;
    int right_ptr = arr.size() - 1;
    while (left_ptr < right_ptr)
    {
        if ((arr[left_ptr] + arr[right_ptr]) == target)
        {
            return pair<int, int>(arr[left_ptr], arr[right_ptr]);
        }
        else if ((arr[left_ptr] + arr[right_ptr]) > target)
        {
            right_ptr--;
        }
        else
        {
            left_ptr++;
        }
    }
    return pair<int, int>(-1, -1);
}

int main()
{
    vector<int> v{-4, -1, 1, 3, 5, 6, 8, 11};
    cout << "Approach 1(nested loop): \n";
    int target = 10;
    pair<int, int> ans = two_sum(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;
    target = 15;
    ans = two_sum(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;

    cout << "Approach 2(hash table): \n";
    target = 10;
    ans = two_sum_hashtable(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;
    target = 15;
    ans = two_sum_hashtable(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;

    cout << "Approach 3(Sorting+Pointer Technique): \n";
    target = 10;
    ans = two_sum_sorting(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;
    target = 15;
    ans = two_sum_sorting(v, target);
    cout << "Pairs: " << ans.first << " " << ans.second << endl;
    return 0;
}