//Classic Solution with multimaps and reverse_iterators

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> answer;
        multimap<int, int> myMap;
        multimap<int, int> :: iterator iter;
        multimap<int, int> :: reverse_iterator reviter;

        for(int i = 0; i < nums.size(); i++)
        {
            myMap.emplace(nums[i], i);
        }

        for(iter = myMap.begin(); iter != myMap.end(); iter++)
        {
            if((*iter).first == target)
            {
                answer.push_back((*iter).second);
                break;
            }
        }

        for(reviter = myMap.rbegin(); reviter != myMap.rend(); reviter--)
        {
            if((*reviter).first == target)
            {
                answer.push_back((*reviter).second);
                break;
            }
        }
        if(answer.empty())
        {
            vector<int> fail = {-1, -1};
            return fail;
        }
        else
        {
            return answer;
        }
    }
};


//Optimal Solution

