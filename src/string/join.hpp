inline string join(vector<string> words, char delimiter = ' ')
{
    string s = "";
    
    for (auto &word : words)
    {
        if (s.length() > 0)
        {
            s.push_back(delimiter);
        }
        
        s.append(word.begin(), word.end());
    }
    
    return s;
}
