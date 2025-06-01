class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int>clipEnd(time+1, 0);
        for(int i=0; i<clips.size(); i++) {
            int start = clips[i][0];
            int end = clips[i][1];
            if(start>time)
                continue;
            clipEnd[start] = min(max(clipEnd[start], end),time);
        }

        int maxFar=0, currEnd=0, clipCount=0;

        for(int t=0; t<=time; t++) {
            //cout<<clipEnd[t]<<" ";
            if(currEnd == time)
                return clipCount;
            
            if(t>currEnd)
                return -1;
            
            maxFar = max(maxFar, clipEnd[t]);
            if (t==currEnd) {
                clipCount++;
                currEnd = maxFar;
            }
        }
        return clipCount;
    }
};