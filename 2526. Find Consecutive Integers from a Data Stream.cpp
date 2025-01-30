class DataStream {
public:
    int val, K, cnt;
    DataStream(int value, int k) {
        val = value;
        K = k;
        cnt = 0;
    }
    
    bool consec(int num) {
        if(val == num)
            cnt++;
        else
            cnt = 0;
        return cnt >= K;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */