class Solution {
public:
    vector<string> split(string& tran, char separator){
        vector<string> parts;
        stringstream ss(tran);
        string part;

        while(getline(ss, part, separator)) {
            parts.push_back(part);
        }
        
        return parts;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> registered_trans;
        vector<string> res;
        set<int> res_idx;

        int n = transactions.size();
        for (int i = 0; i < n; i++) {
            vector<string> parts = split(transactions[i], ','); //split transaction details
            string curr_name = parts[0];
            int curr_time = stoi(parts[1]);
            int curr_amount = stoi(parts[2]);
            string curr_city = parts[3];

            if(curr_amount > 1000) {
                res_idx.insert(i);
            }

            if (registered_trans.find(curr_name) != registered_trans.end()) {
                for (auto [time, city, idx] : registered_trans[curr_name]) {
                    if (abs(curr_time - time) <= 60 && curr_city != city) {
                        res_idx.insert(i);
                        res_idx.insert(idx);
                    }
                }
            }

            tuple<int, string, int> new_registry = make_tuple(curr_time, curr_city, i);
            registered_trans[curr_name].push_back(new_registry);
        }


        for (int ele : res_idx) {
            res.push_back(transactions[ele]);
        }

        return res;
    }
};