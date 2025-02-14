class ProductOfNumbers {
    private:
        vector<int>product;
        int index = 0;
public:
    ProductOfNumbers() {
        index = 0;
        product.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            index = 0;
            product = {1};
        }
        else {
            product.push_back(product[index] * num);
            index++;
        }
    }
    
    int getProduct(int k) {
        if (k > index)
            return 0;
        if (k==index)
            return product.back();
        return product[index] / product[index - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */