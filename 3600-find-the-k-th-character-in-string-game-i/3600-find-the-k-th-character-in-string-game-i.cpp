class Solution {
public:
    char kthCharacter(int k) {
        return 'a' + __builtin_popcount(k - 1);
    }
};

// a b bc bccd bccdcdde bccdcddecddedeef bccdcddecddedeefcddedeefdeefeffg