// // 1.Brute
// class Solution {
// public:
//     int mySqrt(int x) {
//         int val = -1;
//         if(x==0) return 0;
//         if(x==1) return 1;
//         for(int i=1;i<=x;i++){
//             if(1LL*i*i > x) {val = i-1;break;}
//         }
//         return val;
//     }
// };

// 2.Using BS
class Solution {
public:
    int mySqrt(int x) {
        int low = 0;
        int high = x;
        int ans = 0;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(mid * mid <= x) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};