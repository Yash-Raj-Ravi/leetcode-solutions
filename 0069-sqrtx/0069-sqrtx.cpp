class Solution {
public:
    int mySqrt(int x) {
        int val = -1;
        if(x==0) return 0;
        if(x==1) return 1;
        for(int i=1;i<=x;i++){
            if(1LL*i*i > x) {val = i-1;break;}
        }
        return val;
    }
};