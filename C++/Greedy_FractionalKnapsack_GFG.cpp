// class implemented
struct Item{
    int value;
    int weight;
};

bool static comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    
    return r1 > r2;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        int n = val.size();
        Item arr[n];
        
        for(int i = 0; i < n; i++)
        {
            arr[i].value = val[i];
            arr[i].weight = wt[i];
        }
        
        sort(arr, arr + n, comp);
        
        int currWeight = 0;
        double finalvalue = 0.0;
        
        for(int i = 0; i < n; i++)
        {
            if(arr[i].weight + currWeight <= capacity)
            {
                currWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = capacity - currWeight;
                finalvalue += ((double)remain / (double)arr[i].weight) * arr[i].value;
                break; 
            }
        }
        
        return finalvalue;
    }
};