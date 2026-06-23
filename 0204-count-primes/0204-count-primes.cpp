// // 1.Brute
// class Solution {
// public:
//     int countPrimes(int n) {
//         int primecnt=0;
//         for(int i=2;i<n;i++)
//         {
//             int cnt=0;
//             for(int j=2;j<=i;j++)
//             {
//                 if(i%j==0)
//                 {
//                     cnt++;
//                 }
//             }
//             if(cnt==1)
//             {
//                 primecnt++;
//             }
//         }
//         return primecnt;
//     }
// };

// 2.Optimal
class Solution {
public:
    int countPrimes(int n) {

        if(n<=2) return 0;
        // Step 1 : Seive of Eratosthenes to find all primes upto n-1
        vector<bool> isprime(n, true);
        isprime[0] = isprime[1] = false;
        for (int p = 2; p * p < n; p++) {
            if (isprime[p]) {
                for (int j = p * p; j < n; j += p) {
                    isprime[j] = false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)
        {
            if(isprime[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// See Striver question, that one is different and complex from this version.