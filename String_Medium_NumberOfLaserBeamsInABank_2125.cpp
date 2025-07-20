class Solution {
public:
    int numberOfBeams(vector<string>& bank)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        int curr_row_count = 0, next_row_count = 0, master_count = 0;
        bool prev_row_has_security_device = false;

        for(int i = 0; i < bank.size(); i++)
        {
            for(int j = 0; j < bank[i].size(); j++)
            {
                if(bank[i][j] == '1' && prev_row_has_security_device == false)
                {
                    curr_row_count++;
                }
                if(bank[i][j] == '1' && prev_row_has_security_device == true)
                {
                    next_row_count++;
                }
            }
            if(curr_row_count > 0)
            {
                prev_row_has_security_device = true;
            }
            if(next_row_count > 0)
            {
                master_count += (curr_row_count * next_row_count);
                curr_row_count = next_row_count;
                next_row_count = 0;
            }
        }

        return master_count;
    }
};