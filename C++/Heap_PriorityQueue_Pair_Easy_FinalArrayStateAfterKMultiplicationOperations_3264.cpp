class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier)
    {
        using pii = pair<int, int>; // pair of (value, index)

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        vector<pii> modifiedElements;
        vector<int> answers;

        // Push initial values and indices into the priority queue
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({nums[i], i});
        }

        // Process the smallest element k times
        for (int j = 0; j < k; j++)
        {
            auto [val, idx] = pq.top();
            pq.pop();
            val = val * multiplier;
            pq.push({val, idx});
        }

        // Collect final state from the priority queue
        for(int i = 0; i < nums.size(); i++)
        {
            modifiedElements.push_back(pq.top());
            pq.pop();
        }

        // Sort modified elements based on their original indices
        sort(modifiedElements.begin(), modifiedElements.end(), [](const pii& a, const pii& b)
                {
                    return a.second < b.second;
                }
            );

        // Extract the values in the correct order
        for (int i = 0; i < modifiedElements.size(); i++)
        {
            answers.push_back(modifiedElements[i].first);
        }

        return answers;
    }
};
