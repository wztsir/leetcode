import java.util.Collections;
import java.util.NavigableMap;
import java.util.TreeMap;

/**
 * @ClassName: leet2182
 * @Description:
 * @Author: wzt
 * @Create: 2024-01-13 10:20
 **/

public class leet2182 {
    public String repeatLimitedString(String s, int repeatLimit) {
        int[] hash = new int[26];
        for (char c : s.toCharArray()) {
            hash[c-'a']++;
        }
        StringBuilder str = new StringBuilder();
        // i指向最大的， j指向次大的
        // 还有一个参数 repeat// 重点是i,j 什么时候移动
        int m = 0;
        for(int i = 25, j = 24; i >=0 && j >= 0;){
            if(hash[i] == 0){
                i--;
                m = 0;
            }
            else if(m < repeatLimit){
                str.append((char)('a' + i));
                hash[i]--;
                m++;
            }else if(hash[j] == 0 || i <= j){//考虑j的移动, 遗漏一个关键 i>j
                j--;
            }else if(m == repeatLimit){
                str.append((char)('a' + j));
                hash[j]--;
                m = 0;
            }
        }

        return str.toString();
    }
}
