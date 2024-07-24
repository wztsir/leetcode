#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int romanToInt(string s) {// "IVI"
    int n = s.size();
    unordered_map<string, int> mp{{"I", 1}, {"V",5}, {"X", 10}, {"L", 50}, {"C", 100},
       {"D", 500}, {"M", 1000}, {"IV", 4},{"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
    int ans = 0;
    string c;
    for(int i = 0; i < n; i++){
        // s.substr(pos, len) position
        if(i+1 < n){
            c = s.substr(i, 2);// string 
            // c = s[i] + s[i+1];
            if(mp.find(c) != mp.end()){// 处理两个位置
                ans += mp[c];
                i++;
            }else{//处理一个位置
            // s[i] -> 'I' -> char
                c = s[i];
                ans += mp[c];
            }
        }else{// 最末尾情况，肯定是处理一个
            c = s[i];
            ans += mp[c];
        }
        
    }
    
    return ans;
}
int main(){
    // "wzt" -> "178"
    // "llz" -> "180"
    // key -> value
    //{key, value}
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
    // //增删改查
    // unordered_map<string, int> mp;
    // //增加
    // mp["wzt"] = 178; // "wzt" -> 178
    // mp.insert({"llz", 180});
    // mp["llz"] = 198;
    // //删除
    // mp.erase("wzt");
    // mp.erase(mp.begin());
    // //修改
    // mp["llz"] = 198;
    // //查找
    // string c = " wzt";
    // if(mp.find(c) != mp.end())mp[c];

    // mp[c]

    // vector<int> arr;
    // arr[0] = 10;
    //  unordered_map<string, int> mp{{"I", 1}, {"V",5}, {"X", 10}, {"L", 50}, {"C", 100},
    //   {"D", 500}, {"M", 1000}, {"IV", 4},{"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
     
    // string c = s[0] + s[1];//"III"  -> "II"
    // int total = 0;
    // total += mp[c]; // +1
    // if(mp.find("II") != mp.end())mp["II"];
    
    // mp["XL"]  -> 40
    // 数组 arr
    // 下标(int) -> value
    
}