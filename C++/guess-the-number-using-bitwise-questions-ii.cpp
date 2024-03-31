// Time:  O(logr)
// Space: O(1)

// bit manipulation
class Solution {
public:
    int findNumber() {
        static const int BIT_COUNT = 30;

        int result = 0;
        for (int i = 0; i < BIT_COUNT; ++i) {
            if (commonBits(1 << i) - commonBits(1 << i) == 1) {
                result |= 1 << i;
            }
        }
        return result;
    }
};
