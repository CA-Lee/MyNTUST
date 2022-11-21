#include <iostream>

using namespace std;

void sort(int nums[], int n)
{
    if (n == 1 || (n == 2 && nums[0] <= nums[1]))
        return;
    if (n == 2)
    {
        int temp = nums[0];
        nums[0] = nums[1];
        nums[1] = temp;
        return;
    }
    int half = n / 2 + (n & 1);
    sort(nums, half);
    sort(nums + half, n - half);
    int nums2[n], l = 0, r = half;
    for (int i = 0; i < n; i++)
    {
        if (l < half && r < n)
        {
            nums2[i] = nums[l] <= nums[r] ? nums[l++] : nums[r++];
        }
        else if (l < half)
        {
            nums2[i] = nums[l++];
        }
        else
        {
            nums2[i] = nums[r++];
        }
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums2[i];
    }
    return;
}

int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n;
        cin >> n;
        int nums[n];
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        sort(nums, n);
        for (int i = 0; i < n; i++)
        {
            cout << (i == 0 ? "" : " ") << nums[i];
        }
        cout << endl;
    }
}