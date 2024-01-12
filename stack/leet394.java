package 字符串;

import java.util.Stack;

/**
 * @ClassName: leet394
 * @Description:
 * @Author: wzt
 * @Create: 2024-01-12 23:33
 **/

public class leet394 {
    public String decodeString(String s) {
        StringBuilder res = new StringBuilder();
        int num = 0;
        Stack<String> st_string = new Stack<>();
        Stack<Integer> st_num = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '[') {
                st_string.add(res.toString());
                st_num.add(num);
                res = new StringBuilder();
                num = 0;
            } else if (c == ']') {
                Integer n = st_num.peek();
                st_num.pop();
                String out = st_string.peek();
                st_string.pop();
                StringBuilder tmp = new StringBuilder();
                for (int i = 0; i < n; i++) tmp.append(res);
                res = new StringBuilder(out + tmp);

            } else if (c >= '0' && c <= '9') num = num * 10 + c - '0';
            else res.append(c);
        }
        return res.toString();
    }

}
