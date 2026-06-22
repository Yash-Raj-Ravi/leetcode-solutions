class Solution {
public:

 int countSetbits(int result)
 {
    int setcount=0;
    while(result>0)
    {
        result&=result-1;
        setcount++;
    }
    return setcount;
 }
    int minBitFlips(int start, int goal) {
        // int bigger_num=max(start,goal);
        // int count=0; // count bits of bigger number
        // while(bigger_num>0)
        // {
        //     count++;
        //     bigger_num>>=1;   
        // }
        int result=start ^ goal;
        return countSetbits(result);
    }
};