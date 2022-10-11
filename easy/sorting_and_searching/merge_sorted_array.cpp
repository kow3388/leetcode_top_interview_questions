#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//從大的開始看, array的屁股開始
//time O(m+n) , space O(1)
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if(m == 0)
        for(int i = 0; i < n; i++)
            nums1[i] = nums2[i];
    else if(n == 0)
        return;
    else
    {
        int i = m-1, j = n-1;
        while(i >= 0 and j >= 0)
            if(nums1[i] >= nums2[j])
            {
                nums1[i+j+1] = nums1[i];
                i--;
            }
            else
            {
                nums1[i+j+1] = nums2[j];
                j--;
            }
        
        while(j >= 0)
        {
            nums1[j] = nums2[j];
            j--;
        }
    }

    for(int i = 0; i < (m+n); i++)
        cout << nums1[i] << " ";
    cout << endl;
}

//time O(m+n) , space O(m+n)
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if(m == 0)
        for(int i = 0; i < n; i++)
            nums1[i] = nums2[i];
    else if(n == 0)
        return;
    else
    {
        vector<int> tmp;
        int i = 0, j = 0;
        while(i < m and j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                tmp.push_back(nums1[i]);
                i++;
            }
            else
            {
                tmp.push_back(nums2[j]);
                j++;
            }
        }
        
        while(i < m)
        {
            tmp.push_back(nums1[i]);
            i++;
        }

        while(j < n)
        {
            tmp.push_back(nums2[j]);
            j++;
        }
        nums1.swap(tmp);
        tmp.clear();
    }

    for(int i = 0; i < (m+n); i++)
        cout << nums1[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums2 = {1,2,3};
    int m = 3, n = 3;

    merge2(nums1, m, nums2, n);

    return 0;
}