class KthLargest {
private:
    int heapLimit;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:

    KthLargest(int k, vector<int>& nums) 
    {
        heapLimit = k;

        for(int i = 0; i < nums.size(); i++)
        {
            minHeap.push(nums[i]);
        }
    }
    
    int add(int val) 
    {
        minHeap.push(val);

        if(minHeap.size() < heapLimit)
        {
            return -1;
        }
        else 
        {
            while(minHeap.size() > heapLimit)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */