#include<vector>
#include<string>
using namespace std;
//编程有很多细节，这道题是一道细节题
//细节一，字符加上空格大于max
//细节二，文本的最后一行应为左对齐，且单词之间不插入额外的空格
//细节三，每种情况的区间没有想明白

//犯错：写的很乱，初始状态没有像明白，没有考虑清楚
//网友锐评：代码又臭又长，很像公司的需求

//主要考察的点就是代码的简洁与优美性
vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int length = 0, l = 0;
    vector<string> res;
    for(int i = 0; i < words.size(); ++i){
        length += words[i].size() + 1;
        if(length-1 == maxWidth){
            string s = "";
            for(int j = l; j <= i; ++j){
                s += words[j];
                if(j < i)s+=" ";
            }
            res.push_back(s);
            length = 0, l = i+1;
        }
        else if(length == maxWidth){//遗漏i==l只有一个元素, 遗漏可能为最后一行
            string s = "";
            for(int j = l; j <= i; ++j){
                s += words[j];
                if(i == words.size()-1 && j < i)s+=" ";
                else if(j ==l && j == i)s +=" ";
                else if(j == l)s += "  ";
                else if(j < i)s+=" ";
            }
            s.append(maxWidth - s.size(), ' ');
            res.push_back(s);
            length = 0, l = i+1;
        }
        else if(length > maxWidth){ 
            string s ="";
            int k = maxWidth - length + words[i].size() + 2;
            int c1 = i - l - 1;//空格数，要考虑==0
            if(c1 == 0){
                s += words[l];
                s.append(maxWidth - s.size(), ' ');
            }else{
                int p = (k / c1) + 1;//空格长度
                int c = k % c1;
                string t = string(p, ' ');
                for(int j = l; j < i; ++j){
                    s += words[j];
                    if(j -l < c1)s += t;//负数也可以true
                    if(j - l < c)s += ' ';
                }
            }
            res.push_back(s);
            length = 0, l = i;
            i--;
        }
        else if(length < maxWidth && i == words.size()-1){
            string s = "";
            for(int j = l; j < words.size(); ++j){
                s += words[j];//细节，末尾不能添加空格，防止长度越界
                if(j < words.size()-1)s += " ";
            }
            s.append(maxWidth - s.size(), ' ');
            res.push_back(s);
        }
    }
    return res;
}
int main(){
    vector<string> words = {"Listen","to","many,","speak","to","a","few."};
    int m = 6;
    fullJustify(words, m);
}
class Solution {
    // blank 返回长度为 n 的由空格组成的字符串
    string blank(int n) {
        return string(n, ' ');
    }

    // join 返回用 sep 拼接 [left, right) 范围内的 words 组成的字符串
    string join(vector<string> &words, int left, int right, string sep) {
        string s = words[left];
        for (int i = left + 1; i < right; ++i) {
            s += sep + words[i];
        }
        return s;
    }

public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> ans;
        int right = 0, n = words.size();
        while (true) {
            int left = right; // 当前行的第一个单词在 words 的位置
            int sumLen = 0; // 统计这一行单词长度之和
            // 循环确定当前行可以放多少单词，注意单词之间应至少有一个空格
            while (right < n && sumLen + words[right].length() + right - left <= maxWidth) {
                sumLen += words[right++].length();
            }

            // 当前行是最后一行：单词左对齐，且单词之间应只有一个空格，在行末填充剩余空格
            if (right == n) {
                string s = join(words, left, n, " ");
                ans.emplace_back(s + blank(maxWidth - s.length()));
                return ans;
            }

            int numWords = right - left;
            int numSpaces = maxWidth - sumLen;

            // 当前行只有一个单词：该单词左对齐，在行末填充剩余空格
            if (numWords == 1) {
                ans.emplace_back(words[left] + blank(numSpaces));
                continue;
            }

            // 当前行不只一个单词
            int avgSpaces = numSpaces / (numWords - 1);
            int extraSpaces = numSpaces % (numWords - 1);
            string s1 = join(words, left, left + extraSpaces + 1, blank(avgSpaces + 1)); // 拼接额外加一个空格的单词
            string s2 = join(words, left + extraSpaces + 1, right, blank(avgSpaces)); // 拼接其余单词
            ans.emplace_back(s1 + blank(avgSpaces) + s2);
        }
    }
};
