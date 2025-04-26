class Solution {
  public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        vector<int> given_den = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        
        int n = given_den.size();
        sort(given_den.begin(), given_den.end(), greater<int>());
        
        while(N > 0)
        {
            for(int i = 0; i < given_den.size(); i++)
            {
                if((N - given_den[i]) < 0)
                {
                    continue;
                }
                N -= given_den[i];
                ans.push_back(given_den[i]);
                break;
            }
        }
        
        return ans;
    }
};