class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        ios::sync_with_stdio(false);

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int player_pointer = 0, trainer_pointer = 0, count = 0;

        while(player_pointer < players.size() && trainer_pointer < trainers.size())
        {
            if(players[player_pointer] <= trainers[trainer_pointer])
            {
                player_pointer++;
                trainer_pointer++;
                count++;
            }
            else
            {
                trainer_pointer++;
            }
        }

        return count;
    }
};