class Solution {
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word) {
        // represent characters like :
        // a -> 001, b -> 010, c -> 100
        unordered_map<ll, ll> mp;
        mp[0] = 1;  // initially we have seen xor = 0
        int cum_xor = 0;

        ll result = 0;

        for(char &ch : word){    // O(n)
            int shift = ch - 'a';
            // shift 1 by above shift no. to get respective char representation

            cum_xor ^= (1 << shift);

            result += mp[cum_xor];  // all chars are even counted

            for(char ch1='a'; ch1<='j'; ch1++){   // a to j      // O(1)
                shift = ch1 - 'a';

                ll check_xor = (cum_xor ^ (1 << shift));

                result += mp[check_xor];  // only max 1 char is odd in count
            }

            mp[cum_xor] ++ ;
        }

        return result;
    }
};
