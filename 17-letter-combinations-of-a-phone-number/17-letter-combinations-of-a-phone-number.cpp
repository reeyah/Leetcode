class Solution {
public:
//     void rec(string digits, string proc, int i, vector<string>&letters, const vector<string>&chars){
//         if(i==digits.length()){
//             letters.push_back(proc);
//             return;
//         }
            
//         int d = digits[i] - '0'; 
//         for(char c: chars[d-2])
//             rec(digits, proc+c, i+1, letters, chars);
//     }
    
    vector<string> letterCombinations(string digits) {
//         if(digits.empty())
//             return {};
//         vector<string>chars = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string>letters;
//         string proc;

//         rec(digits, proc, 0, letters, chars);
        
        vector<string> pad = {"abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
    
        if (digits.empty()) return {};
		vector<string> letters;
        letters.push_back("");
        
        for(auto digit: digits) {
            vector<string> tmp; //re-initialize
            for(auto c: pad[digit - '0' - 2]) {
                for(auto s: letters) {
                    tmp.push_back(s + c); //add the new c to every string s in letter
                }
            }
            letters.swap(tmp);
        }
        
        return letters;
    }
};