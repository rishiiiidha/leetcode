class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        int v = 0;
        int c = 0;
        if (n >= 3) {

            for (int i = 0; i < n; i++) {
                if (isalnum(word[i])) {
                    if (isalpha(word[i])) {
                        char ch = tolower(word[i]);
                        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                            ch == 'u')
                            v++;
                        else
                            c++;
                    }
                }
                else return false;
            }
        }
        else return false;
        if(v>=1 && c>=1) return true;
        return false;
    }
};