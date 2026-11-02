class Vector2D {
    private:
        int i;
        int j;
        vector<vector<int>> vec;
    public:
        Vector2D(vector<vector<int>>& vec) {
            this->vec = vec;
            this->i = 0;
            this->j = 0;
            checkIncrement();
        }

        void checkIncrement() {
            while(i < vec.size() && j == vec[i].size()) {
                j = 0;
                i++;
            }
        }
        
        int next() {
            cout << i << ", " << j << endl;
            int res = vec[i][j];
            j++;
            checkIncrement();

            return res;
        }
        
        bool hasNext() {
            return i < vec.size();
        }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */