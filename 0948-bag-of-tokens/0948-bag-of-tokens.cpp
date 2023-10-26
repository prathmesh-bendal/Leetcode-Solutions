class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int score=0;
        
        sort(tokens.begin(),tokens.end());
        
        int i=0,j=tokens.size()-1;
        
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i];
                i++;
            }
            else
            {
                if(power+tokens[j]>=tokens[i] && score>0 && i!=j)
                {
                    power+=tokens[j];
                    j--;
                    score--;
                }
                else
                    break;
            }
        }
        return score;
        
    }
};