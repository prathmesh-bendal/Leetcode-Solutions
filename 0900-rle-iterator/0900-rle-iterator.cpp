class RLEIterator {
public:
    vector<int> encoding;
    int curr=0;
    RLEIterator(vector<int>& encoding) {
        this->encoding=encoding;
        curr=0;
    }
    
    int next(int n) {
        if(curr>=encoding.size())
            return -1;
        if(encoding[curr]>=n)
        {
            encoding[curr]=encoding[curr]-n;
            return encoding[curr+1];
        }
        else
        {
            n=n-encoding[curr];
            encoding[curr]=0;
            curr+=2;
            return next(n);
        }
        
        
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */