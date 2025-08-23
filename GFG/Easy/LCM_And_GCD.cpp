class Solution {
  public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    vector<int> lcmAndGcd(int a, int b) {
        int gcd_val = gcd(a, b);
        long long lcm_val = (1LL * a * b) / gcd_val;
        
        vector<int> ans;
        ans.push_back((int)lcm_val);
        ans.push_back(gcd_val);
        return ans;
    }
};
