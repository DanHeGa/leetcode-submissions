class Vector2D {
    private:
        vector<int> vec1D; //dynamically changing size
        int vecSize;
        int it;
    public:
        Vector2D(vector<vector<int>>& vec) {
            for (vector<int> subVec : vec) {
                for (int ele : subVec) {
                    vec1D.push_back(ele);
                }
            }
            vecSize = vec1D.size();
            it = 0;
        }
        
        int next() {
            int res = vec1D[it];
            it++;
            return res;
        }
        
        bool hasNext() {
            return it < vecSize;
        }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */