// // 1.Brute
// class Solution {
// public:
//     double myPow(double x, int n) {
//         long double val=1;
//         long long N=n; // To avoid integer overflow
//         if(N < 0)
//        {
//          x = 1/x;
//          N = -N;
//         }     
       
//         for(long long i=0;i<N;i++)
//         {
//             val*=x;
//         }
        
//         return val;
//     }
// };

// 2.Optimal
class Solution {
private:
 double power(double x,long n)
 {
   // Base case
   if(n==0) return 1;
   if(n==1) return x;

   if(n%2==0)
   {
    return power(x*x,n/2);
   }
   else
   {
    return x*power(x,n-1);
   }
 }
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0)
        {
            return 1.0/power(x,-N);
        }
        return power(x,N);
    }
};