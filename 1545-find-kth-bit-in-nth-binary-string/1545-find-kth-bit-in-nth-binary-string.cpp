class Solution {
private:
    string find_back(string s ) {
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') s[i] = '1';
            else if(s[i] == '1') s[i] = '0';
        }
        return s;
    }

    string solve(int n) {
        if(n == 1) return "0";

        string s = solve(n - 1);
        string front = s;
        string back = find_back(s);

        return front + "1" + back;
    }

public:
    char findKthBit(int n, int k) {
        string s = solve(n);
        return s[k - 1];
    }
};