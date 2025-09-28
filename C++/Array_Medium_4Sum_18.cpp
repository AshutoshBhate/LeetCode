//Better : 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        set<vector<int>> answer_set;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                set<int> hash_set;
                for(int k = j + 1; k < nums.size(); k++)
                {
                    int fourth = target - (nums[i] + nums[j] + nums[k]);

                    if(hash_set.find(fourth) != hash_set.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                        sort(temp.begin(), temp.end());
                        answer_set.insert(temp);
                    }
                    else
                    {
                        hash_set.insert(nums[k]);
                    }
                }
            }
        }

        vector<vector<int>> answer_vector(answer_set.begin(), answer_set.end());

        return answer_vector;
    }
};

//TC: O(N^3) + O(log N)

//Optimal : 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(nums.begin(), nums.end());

        vector<vector<int>> answer;

        for(int i = 0; i < nums.size(); i++)
        {   
            if(i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for(int j = i + 1; j < nums.size(); j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int k = j + 1;
                int l = nums.size() - 1;

                while(k < l)
                {
                    long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum > target)
                    {
                        l--;
                    }
                    else if(sum < target)
                    {
                        k++;
                    }
                    else
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        answer.push_back(temp);
                        k++;
                        l--;
                        while(k < l && nums[k] == nums[k - 1])
                        {
                            k++;
                        }
                        while(k < l && nums[l] == nums[l + 1])
                        {
                            l--;
                        }
                    }
                }
            }
        }

        return answer;    
    }
};

