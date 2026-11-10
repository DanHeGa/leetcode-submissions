class TrieNode {
    private:
        vector<TrieNode*> children;
        bool isEnd;
    public:
        TrieNode() {
            children.resize(27, nullptr); //assign 26 place to ' ' (space char)
            isEnd = false;
        }

        void insert(string sentence) {
            TrieNode* curr = this;
            for (int i = 0; i < sentence.length(); i++){ 
                int cIdx;
                if (sentence[i] == ' ') {
                    cIdx = 26;
                } else {
                    cIdx = sentence[i] - 'a';
                }

                if (!curr->children[cIdx]) {
                    curr->children[cIdx] = new TrieNode();
                }

                curr = curr->children[cIdx];
            }

            curr->isEnd = true;
        }

        vector<string> getRecommendations(string prefix) {
            //get to prefix and then find all possible recommendations
            TrieNode* curr = this;
            for (int i = 0; i < prefix.size(); i++) {
                int cIdx = prefix[i] == ' ' ? 26 : prefix[i] - 'a';

                if (!curr->children[cIdx]) {
                    return {};
                }

                curr = curr->children[cIdx];
            }
            vector<string> results;
            findAllRecommendations(curr, prefix, results);
            return results;
        }

        void findAllRecommendations(TrieNode* curr, string candidate, vector<string> &results) {
            if (curr->isEnd) {
                results.push_back(candidate);
            }

            for (int i = 0; i < 27; i++) {
                if (curr->children[i]) {
                    char nextChar = (i == 26) ? ' ' : ('a' + i);
                    findAllRecommendations(curr->children[i], candidate + nextChar, results);
                }
            }

            return;
        }
};

class AutocompleteSystem {
    //have a class prefix, only reset when user inputs '#', and add it to the vocabulary to consider it for future searches.
    string prefix;
    TrieNode* trie;
    unordered_map<string, int> hotMp;
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        this->trie = new TrieNode();
        this->prefix = "";

        for(int i = 0; i < sentences.size(); i++) {
            hotMp[sentences[i]] = times[i];
            trie->insert(sentences[i]);
        }
    }
    
    vector<string> input(char c) {
        /*
        Return top three hot sentences, if less than three return all.
        Sorted by hot sentence, if equals, sort by ascii value.
        End of a sentence is defined with '#'
        */
        if (c == '#') {
            trie->insert(prefix);
            hotMp[prefix]++;
            prefix = "";
            return {};
        }

        this->prefix += c;
        vector<string> allRecommendations = this->trie->getRecommendations(prefix);
        //sort by hot level, if equal, by lexicographical order
        sort(allRecommendations.begin(), allRecommendations.end(), [&](string &s1, string &s2){
            //by hot desc
            if (hotMp[s1] != hotMp[s2]) {
                return hotMp[s1] > hotMp[s2];
            } else {
                //by ascii asc
                return s1 < s2;
            }
        });

        if (allRecommendations.size() > 3) allRecommendations.resize(3);

        return allRecommendations;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */