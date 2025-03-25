int find(int par[], int x)
{
    if(x == par[x])
    {
        return x;
    }
    else
    {
        return par[x] = find(par, par[x]);
    }
}

void unionSet(int par[], int x, int z)
{
    int ulp_x = find(par, x);
    int ulp_z = find(par, z);
    
    if(ulp_x != ulp_z)
    {
        par[ulp_x] = ulp_z;
    }
}