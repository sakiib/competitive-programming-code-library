#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

const int N = 1e6 + 100;

struct simplehash{
    int len = 0;
    long long base, mod;
    vector <long long> P, H, R;
    string str;

    simplehash(){}
    simplehash(long long b, long long m){
        base = b, mod = m;
        P.resize(N, 1), H.resize(N, 0), R.resize(N, 0);
        for (int i = 1; i < N; i++) P[i] = (P[i - 1] * base) % mod;
    }

    void add(char ch) {
        ++len;
        str.push_back(ch);
        int i = len;
        H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

};

struct stringhash{
    simplehash sh1, sh2;
    stringhash(){
        sh1 = simplehash(1949313259, 2091573227);
        sh2 = simplehash(1997293877, 2117566807);
    }
    void add(char ch) {
        sh1.add(ch);
        sh2.add(ch);
    }
    inline long long range_hash(int l, int r){
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }
}Hash;


struct Simplehash{
    int len;
    long long base, mod;
    vector <long long> P, H, R;

    Simplehash(){}
    Simplehash(string &str, long long b, long long m){
        base = b, mod = m, len = str.size();
        P.resize(len + 3, 1), H.resize(len + 3, 0), R.resize(len + 3, 0);

        for (int i = 1; i <= len; i++) P[i] = (P[i - 1] * base) % mod;
        for (int i = 1; i <= len; i++) H[i] = (H[i - 1] * base + str[i - 1] + 1007) % mod;
        for (int i = len; i >= 1; i--) R[i] = (R[i + 1] * base + str[i - 1] + 1007) % mod;
    }

    inline int range_hash(int l, int r){
        int hashval = H[r + 1] - ((long long)P[r - l + 1] * H[l] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }

    inline int reverse_hash(int l, int r){;
        int hashval = R[l + 1] - ((long long)P[r - l + 1] * R[r + 2] % mod);
        return (hashval < 0 ? hashval + mod : hashval);
    }
};

struct Stringhash{
    Simplehash sh1, sh2;
    Stringhash(){}
    Stringhash(string &str){
        sh1 = Simplehash(str, 1949313259, 2091573227);
        sh2 = Simplehash(str, 1997293877, 2117566807);
    }

    inline long long range_hash(int l, int r){
        return ((long long)sh1.range_hash(l, r) << 32) ^ sh2.range_hash(l, r);
    }

    inline long long reverse_hash(int l, int r){
        return ((long long)sh1.reverse_hash(l, r) << 32) ^ sh2.reverse_hash(l, r);
    }
};


int main(){
    int n;
    cin >> n;
    string str = "";
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        Stringhash H(s);
        if(i == 1) {
            for(int j = 0; j < s.size(); j++) {
                Hash.add(s[j]);
            }
            str = s;
        }
        else {
            bool flag = 0;
            for(int j = min(s.size(),str.size()); j >= 1; j--) {
                if(Hash.range_hash(str.size()-j,str.size()-1) == H.range_hash(0,j-1)) {
                    flag = 1;
                    for(int k = j; k < s.size(); k++) {
                        str.push_back(s[k]);
                        Hash.add(s[k]);
                    }
                    break;
                }
            }
            if(flag == 0) {
                str += s;
                for(int j = 0; j < s.size(); j++) {
                    Hash.add(s[j]);
                }
            }
        }
    }
    cout << str << endl;
    return 0;
}
