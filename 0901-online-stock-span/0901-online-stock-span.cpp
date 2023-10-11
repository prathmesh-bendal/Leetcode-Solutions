class StockSpanner {
public:
    stack<pair<int,int>> s;
    int index=-1;
    StockSpanner() {
        index=-1;
        while(s.size()>0)
            s.pop();
        
    }
    
    int next(int price) {
        index++;
        int ans=index+1;
        while(s.size()>0 && s.top().first<=price)
            s.pop();
        
        if(s.size()>0)
            ans=index-s.top().second;
        
        s.push({price,index});
        
        return ans;
        
        
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */