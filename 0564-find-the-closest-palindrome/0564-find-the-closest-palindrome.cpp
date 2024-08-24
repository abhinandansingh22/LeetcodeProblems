class Solution {
public:
    string nearestPalindromic(string n) {

        // base cases

        if (n == "1")
            return "0";

        // number is of the form 99999..
        bool allNine = true;
        for (auto i : n) {
            if (i != '9') {
                allNine = false;
            }
        }

        if (allNine) {
            if (n == "9")
                return "8";
            else {
                int len = n.size();
                string ans = "1";
                while (--len) {
                    ans += "0";
                }
                ans += "1";
                return ans;
            }
        }

        // number is of the form 1 [0]*  1
        bool is101 = true;
        for (int i = 1; i < n.size() - 1; i++) {
            if (n[i] != '0') {
                is101 = false;
                break;
            }
        }

        if (is101 && n.front() == '1' && (n.back() == '1' || n.back() == '0')) {
            string ans;
            for (int i = 0; i < n.size() - 1; i++)
                ans += '9';
            return ans;
        }

        // Now, after the base cases, answer always exists in the same number of
        // digits as n
        int N = n.size();
        string cur;
        function<void(int, bool, bool, bool, string&)> makePalindrome =
            [&](int index, bool isZero, bool isLimit, bool isLesser,
                string& ans) {
                if (ans.size()) {
                    return;
                }

                if (index >= (N + 1) / 2) {

                    int i = 0;
                    string secondHalf;
                    while (secondHalf.size() + cur.size() < N) {
                        secondHalf.push_back(cur[i++]);
                    }
                    reverse(secondHalf.begin(), secondHalf.end());
                    string candidate = cur + secondHalf;

                    if (isLesser && candidate >= n ||
                        !isLesser && candidate <= n)
                        return;
                    ans = candidate;
                    return;
                }

                if (isLesser) {
                    int start = 0;
                    int end = (isLimit) ? (n[index] - '0') : 9;

                    for (int num = end; num >= start; num--) {
                        if (!isZero || num != 0) {
                            cur += to_string(num);

                            makePalindrome(index + 1, isZero && num == 0,
                                           isLimit && num == (n[index] - '0'),
                                           isLesser, ans);
                            if (ans.size())
                                break;

                            cur.pop_back();
                        }
                    }
                } else {
                    int start = (isLimit) ? (n[index] - '0') : 0;
                    int end = 9;

                    for (int num = start; num <= end; num++) {
                        if (!isZero || num != 0) {
                            cur += to_string(num);

                            makePalindrome(index + 1, isZero && num == 0,
                                           isLimit && num == (n[index] - '0'),
                                           isLesser, ans);
                            if (ans.size())
                                break;

                            cur.pop_back();
                        }
                    }
                }
            };

        string lesser, greater;
        makePalindrome(0, 1, 1, 1, lesser);
        cur.clear();
        makePalindrome(0, 1, 1, 0, greater);

        if (abs(stoll(lesser) - stoll(n)) <= abs(stoll(greater) - stoll(n))) {
            return lesser;
        } else
            return greater;
    }
};