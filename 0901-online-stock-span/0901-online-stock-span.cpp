// class StockSpanner {
// public:
//     // StockSpanner is a constructor here which signifies a fresh start and it will contain an empty array to begin with.
//     vector<int> arr;

//     StockSpanner() {
//     }
    
//     int next(int price) {
//         arr.push_back(price);
//         int cnt = 1;
//         for(int i = arr.size()-2;i>=0;i--){
//             if(arr[i]<=price) cnt++;
//             else break;
//         }
//         return cnt;
//     }
// };

// We find pge index for each price then push (current price index) - (pge index) to ans array.
class StockSpanner {
public:

    int idx = -1;
    stack<pair<int,int>> st;

    StockSpanner() {
        idx = -1; 
    }
    
    
    int next(int price) {
        idx = idx + 1;
        int ans = -1;

        while(!st.empty() && st.top().first <= price){
            st.pop();
        }
        ans = idx - (st.empty()?-1:st.top().second);
        st.push({price,idx});

    return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */