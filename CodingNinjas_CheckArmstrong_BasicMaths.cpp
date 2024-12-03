bool checkArmstrong(int n)
{
    string s = to_string(n); 
    int size = s.size();            
    int count = 0;               

    for (int i = 0; i < size; i++)
    {
        int digit = s[i] - '0';      //Converts character to int. Ascii of '0' is 48, '1' is 49. '1' - '0' = 1 
        count += pow(digit, size); 
    }

    return count == n;
}