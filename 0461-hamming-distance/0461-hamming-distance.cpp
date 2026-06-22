class Solution {
public:

int countsetbits(int result)
{
    int count=0;
    while(result>0)
    {
        count++;
        result&=result-1;  
    }
    return count;
}
    int hammingDistance(int x, int y) {
        int result = x^y;
        return countsetbits(result);
    }
};