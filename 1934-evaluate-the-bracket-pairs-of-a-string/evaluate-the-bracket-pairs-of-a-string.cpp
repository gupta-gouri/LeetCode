class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> lookup;
        for (const auto& pair : knowledge) {
            lookup[pair[0]] = pair[1];
        }
        
        string result = "";
        string current_key = "";
        bool in_brackets = false;
        
        for (char ch : s) {
            if (ch == '(') {
                in_brackets = true;
            } else if (ch == ')') {
                in_brackets = false;
                if (lookup.count(current_key)) {
                    result += lookup[current_key];
                } else {
                    result += "?";
                }
                current_key = "";
            } else if (in_brackets) {
                current_key += ch;
            } else {
                result += ch;
            }
        }
        return result;
    }
};
