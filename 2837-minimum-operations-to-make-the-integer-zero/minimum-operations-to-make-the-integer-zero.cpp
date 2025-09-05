class Solution {
public:
    int makeTheIntegerZero(int a, int b) {
        int st = 1;
        while (true) {
            long long r = a - 1LL * b * st;

            if (r < st) {
                return -1; 
            }
            if (st >= __builtin_popcountll(r)) {
                return st;
            }
            st++;
        }
    }
};