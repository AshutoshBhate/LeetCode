class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> counts(26, 0);
        for(int i = 0; i < tasks.size(); i++)
        {
            counts[tasks[i] - 'A']++;
        }

        priority_queue<int> pq;
        for(int count : counts)
        {
            if(count > 0)
            {
                pq.push(count);
            }
        }

        int total_time = 0;

        while(!pq.empty())
        {
            vector<int> waitlist;
            int cycle_size = n + 1;
            int tasks_done_this_cycle = 0;

            while(cycle_size > 0 && !pq.empty())
            {
                int current_task_count = pq.top();
                pq.pop();

                current_task_count--;
                waitlist.push_back(current_task_count);

                tasks_done_this_cycle++;
                cycle_size--;
            }

            for(int remaining_count : waitlist)
            {
                if(remaining_count > 0)
                {
                    pq.push(remaining_count);
                }
            }

            if(pq.empty())
            {
                total_time += tasks_done_this_cycle;
            }
            else
            {
                total_time += (n + 1);
            }
        }

        return total_time;
    }
};