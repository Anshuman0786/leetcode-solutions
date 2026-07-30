class ProductOfNumbers {
public:
    vector<int> prefix; // prefix[i] = product of first i numbers (prefix[0] = 1)

    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            // reset: any product including this 0 is 0, 
            // so start fresh after it
            prefix.clear();
            prefix.push_back(1);
        } else {
            prefix.push_back(prefix.back() * num);
        }
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        if (k >= n) {
            // not enough numbers since last zero
            return 0;
        }
        return prefix[n - 1] / prefix[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */