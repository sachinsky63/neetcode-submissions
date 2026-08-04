class Solution {
public:

    int SumOfSquares(int n){
        int product = 0;
        while(n > 0){
            int digit = n % 10;
            digit = digit * digit;
            product += digit;
            n /= 10;
        }
        return product;
    }

    bool isHappy(int n) {
        unordered_set<int>visit;
        while(visit.find(n) ==visit.end()){
            visit.insert(n);
            n = SumOfSquares(n);
            if( n== 1){
                return true;
            }
        }
        return false;

    }
};
