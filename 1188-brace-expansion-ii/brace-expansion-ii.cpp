class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        stack<pair<set<string>, set<string>>> st;
        set<string> union_set;
        set<string> prod = {""};
        
        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            
            if (isalpha(c)) {
                string word = "";
                while (i < expression.length() && isalpha(expression[i])) {
                    word += expression[i++];
                }
                i--;
                
                set<string> next_prod;
                for (const auto& p : prod) {
                    next_prod.insert(p + word);
                }
                prod = move(next_prod);
                
            } else if (c == '{') {
                st.push({union_set, prod});
                union_set.clear();
                prod = {""};
                
            } else if (c == '}') {
                for (const auto& p : prod) {
                    union_set.insert(p);
                }
                
                auto [prev_union, prev_prod] = st.top();
                st.pop();
                
                set<string> next_prod;
                for (const auto& p : prev_prod) {
                    for (const auto& u : union_set) {
                        next_prod.insert(p + u);
                    }
                }
                
                prod = move(next_prod);
                union_set = move(prev_union);
                
            } else if (c == ',') {
                for (const auto& p : prod) {
                    union_set.insert(p);
                }
                prod = {""};
            }
        }
        
        for (const auto& p : prod) {
            union_set.insert(p);
        }
        
        return vector<string>(union_set.begin(), union_set.end());
    }
};
