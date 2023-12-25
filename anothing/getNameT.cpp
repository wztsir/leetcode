#include <iostream>  
#include <unordered_map>  
#include <sstream>  
  
int main() {  
    std::string input = "陈浩明 徐若航 徐若航 徐晖炫 王立勤 陈润欢 陈润欢\n\  
                         王立勤 陈润欢 吴超为 徐若航 杨帅 张君扬\n\  
                         张家健 张家健 李伟祺 张家健 陈润欢 陈树楷 周林\n\  
                         周林 余绵杰 陈浩明 尹亚鹏 张君扬 张荣浩\n\  
                         杨帅 张君扬 赖乔伟 冯业津 尹亚鹏 杨帅\n\  
                         王子通 孔伟珩 刘树林 冯业津\n\  
                         张君扬 杨帅 朱泓穗\n\  
                         黄世运 陈浩明\n\  
                         杨世彪 张君扬\n\  
                         余绵杰 张家健\n\  
                         杨志邦\n\  
                         王子通\n\  
                         鲍悦\n\  
                         朱颖琪\n\  
                         白佳业\n\  
                         苏琎韬\n\  
                         王立勤\n\  
                         黄彦林";  
  
    std::unordered_map<std::string, int> nameCount;  
    std::istringstream iss(input);  
    std::string line;  
    int t = 0;
    while (std::getline(iss, line)) {  
        std::istringstream ss(line);  
        std::string name;  
  
        while (std::getline(ss, name, ' ')) {  
            t++;
            nameCount[name]++;  
        }  
    }  
  
    for (const auto& pair : nameCount) {  
        std::cout << pair.first << ": " << pair.second << std::endl;  
        // std::cout << t;
    }  
  
    return 0;  
}