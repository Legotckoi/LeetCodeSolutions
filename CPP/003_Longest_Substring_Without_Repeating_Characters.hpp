class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string candidate_str = "";
        string checking_str = "";
        size_t position = std::string::npos;
        for (auto& ch : s)
        {
            position = checking_str.find(ch);
            if (position == std::string::npos)
            {
                checking_str += ch;
            }
            else
            {
                if (candidate_str.size() < checking_str.size())
                {
                    candidate_str = checking_str;
                }
                
                checking_str = checking_str.substr(position + 1);
                checking_str += ch;
            }
        }
        
        if (candidate_str.size() < checking_str.size())
        {
            candidate_str = checking_str;
        }
        return candidate_str.size();
    }
};
