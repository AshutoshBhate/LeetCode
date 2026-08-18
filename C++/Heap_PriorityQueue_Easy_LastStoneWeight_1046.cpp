class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int> pq;

        for(int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }    

        while(pq.size() > 1)
        {
            int max_1 = pq.top();
            pq.pop();
            int max_2 = pq.top();
            pq.pop();

            if(max_1 == max_2)
            {
                continue;
            }
            else
            {
                pq.push(abs(max_1 - max_2));
            }
        }

        if(pq.empty())
        {
            return 0;
        }
        else
        {
            return pq.top();
        }
        
    }
};