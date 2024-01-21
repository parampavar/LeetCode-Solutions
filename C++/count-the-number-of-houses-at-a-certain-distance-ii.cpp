// Time:  O(n)
// Space: O(n)

// math, difference array
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        --x, --y;
        if (x > y) {
            swap(x, y);
        }
        vector<long long> diff(n);
        for (int i = 0; i < n; ++i) {
            diff[0] += 1 + 1;                                                  // i -> two directions begin
            ++diff[min(abs(i - x), abs(i - y) + 1)];                           // i -> x -> y, fork one direction at y
            ++diff[min(abs(i - y), abs(i - x) + 1)];                           // i -> y -> x, fork one direction at x
            --diff[min(abs(i - 0), abs(i - y) + 1 + abs(x - 0))];              // i -> 0, one direction ends
            --diff[min(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)))];  // i -> n-1, one direction ends
            --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 0) / 2];         // i -> x -> ((y-x)+0)//2 <- x, one direction ends
            --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 1) / 2];         // i -> y -> ((y-x)+1)//2 <- y, one direction ends
        }
        for (int i = 0; i + 1 < n; ++i) {
            diff[i + 1] += diff[i];
        }
        return diff;
    }
};
