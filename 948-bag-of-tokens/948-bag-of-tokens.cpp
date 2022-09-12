class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int score=0;
        for(int i=0, j=tokens.size()-1; i<=j;){
            // cout<<i<<","<<j<<" ";
            if(power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else{
                if(i!=j && score>0 && power+tokens[j] >= tokens[i]){
                    power+= tokens[j];
                    score--;
                    j--;
                }
                else break;
            }
        }
        return score;
    }
};