inline int from_bin(string bin)
{
    long long pos_val = 0;
    
    for (long long i = 0; i < 32; i++)
    {
        if (bin[i] == '1')
        {
            pos_val += 1LL << (31 - i);
        }
    }
    
    return pos_val - (1LL << 31);
}
