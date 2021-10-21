inline string to_bin(int val)
{
    long long pos_val = (1LL << 31) + val;
    
    string bin = "";
    for (long long i = 31; i >= 0; i--)
    {
        bin.push_back((pos_val >> i & 1) ? '1' : '0');
    }
    
    return bin;
}
