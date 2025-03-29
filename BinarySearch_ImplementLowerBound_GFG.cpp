int LowerBound(vector<int>& arr, int n, int x)
{
    int  left = 0, right = n - 1, mid, ans;

    while(left <= right)
    {
        mid = (left + right)/2;
        if(arr[mid] >= x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}