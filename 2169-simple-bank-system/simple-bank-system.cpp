class Bank {
private: 
    unordered_map<int, int> accounts;
    vector<long long> balance;
public:
    Bank(vector<long long>& balance) {
        int n = balance.size(); //0->1, 1->2, and so on, to assign balances to accounts
        for (int i = 0; i < n; i++) {
            accounts[i + 1] = i; //balance of each account, remember accounts start from 1
        }
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (!(accounts.contains(account1) && accounts.contains(account2))) {
            return false; //both account should exists!!
        }

        int ac1Idx = accounts[account1];
        int ac2Idx = accounts[account2];

        long long ac1Balance = balance[ac1Idx];
        long long ac2Balance = balance[ac2Idx];
        if (ac1Balance - money < 0) {
            return false;
        } else {
            balance[ac1Idx] -= money;
            balance[ac2Idx] += money;
        }

        return true;
    }
    
    bool deposit(int account, long long money) {
        if (!accounts.contains(account)) return false;

        int idx = accounts[account];
        balance[idx] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (!accounts.contains(account)) {
            return false;
        }

        int idx = accounts[account];
        long long acBalance = balance[idx];

        if (acBalance - money < 0) {
            return false;
        }

        balance[idx] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 
 mp = {
    1 : 0
 }
        i = 0
 balance = [2]

 
 */

