// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

class PrefixSum {
private:
    int* prefix;

public:
    // 前缀和数组
    PrefixSum(vector<int>& nums) {
        prefix = new int[nums.size() + 1];
        // 计算 nums 的累加和
        for (int i = 1; i < nums.size() + 1; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
    }

    // 查询闭区间 [i, j] 的累加和
    int query(int i, int j) {
        return prefix[j + 1] - prefix[i];
    }
};
