class MyCircularQueue {
    vector<int>data;
    int head=0, tail=-1, len=0;
public:
    MyCircularQueue(int k) {
        data.resize(k);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        tail=(tail+1)%data.size();
        data[tail]=value;
        len++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        head = (head+1)%data.size();
        len--;
        return true;
    }
    
    int Front() {
        return isEmpty()? -1 : data[head];
    }
    
    int Rear() {
        return isEmpty()? -1 : data[tail];
    }
    
    bool isEmpty() {
        return len==0;
    }
    
    bool isFull() {
        return len==data.size();
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */