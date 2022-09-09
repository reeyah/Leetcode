class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]>b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int weak=0, maxDef = INT_MIN;
        sort(properties.begin(), properties.end(), compare);
        for(int i=0; i<properties.size(); i++){
            if(properties[i][1] < maxDef)
                weak++;
            maxDef = max(maxDef, properties[i][1]);
        }
        return weak;
    }
};