//Brute Approach : 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> mySet;

        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    if (nums[i] + nums[j] + nums[k] == 0 && i != j && i != k && j != k)
                    {
                        vector<int> temp_vec = {nums[i], nums[j], nums[k]};
                        sort(temp_vec.begin(), temp_vec.end());
                        mySet.insert(temp_vec);
                    }
                }
            }
        }

        vector<vector<int>> answer;

        for(auto vec : mySet)
        {
            answer.push_back(vec);
        }

        return answer;
    }
};

//Better Approach : 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> mySet;

        for(int i = 0; i < nums.size(); i++)
        {
            set<int> hash_set;
            for(int j = i + 1; j < nums.size(); j++)
            {
                int third = -1 * (nums[i] + nums[j]);
                if(hash_set.find(third) != hash_set.end())
                {
                    vector<int> temp_vec = {nums[i], nums[j], third};
                    sort(temp_vec.begin(), temp_vec.end());
                    mySet.insert(temp_vec);
                }
                else
                {
                    hash_set.insert(nums[j]);
                }
            }
        }

        vector<vector<int>> answer(mySet.begin(), mySet.end());

        return answer;
    }
};

//TC: O(N^2) + O(log N)
//SC: O(N^2) Worst Case

//Optimal Approach :

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
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

            int j = i + 1;
            int k = nums.size() - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if(sum > 0)
                {
                    k--;
                }
                else if(sum < 0)
                {
                    j++;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    answer.push_back(temp);
                    j++;
                    k--;
                    while(j < k && nums[j] == nums[j - 1])
                    {
                        j++;
                    }
                    while(j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
            }
        }

        return answer;  
    }
};

//TC: O(N log N) + O(N^2)
//SC: O(1)