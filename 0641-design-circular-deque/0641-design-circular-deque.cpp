class MyCircularDeque {
public:
    int size,front,rear,qsize;
    vector<int> nums;
    MyCircularDeque(int k) {
        nums.resize(k);
        size=k;
        qsize=0;
        front=-1;
        rear=-1;
    }
    
    bool insertFront(int value) {
        if(qsize==size) return false;
        if(front==-1 && rear==-1){
            front++;
            rear++;
            nums[front]=value;
        }
        else{
            front--;
            if(front==-1) front=size-1;
            nums[front]=value;
        }
        qsize++;
        return true;
    }
    
    bool insertLast(int value) {
        if(qsize==size) return false;
        if(front==-1 && rear==-1){
            front++;
            rear++;
            nums[rear]=value;
        }
        else{
            rear++;
            if(rear==size) rear=0;
            nums[rear]=value;
        }
        qsize++;
        return true;
    }
    
    bool deleteFront() {
        if(qsize==0) return false;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
            if(front==size) front=0;
        }
        qsize--;
        return true;
    }
    
    bool deleteLast() {
        if(qsize==0) return false;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            rear--;
            if(rear==-1) rear=size-1;
        }
        qsize--;
        return true;
    }
    
    int getFront() {
        if(qsize==0) return -1;
        return nums[front];
    }
    
    int getRear() {
        if(qsize==0) return -1;
        return nums[rear];
    }
    
    bool isEmpty() {
        return qsize==0;
    }
    
    bool isFull() {
        return qsize==size;
    }
};