

import java.util.*;

/**
 * @ClassName: leet995
 * @Description:
 * @Author: wzt
 * @Create: 2024-01-12 11:56
 **/

public class leet995 {
    public int minKBitFlips(int[] nums, int k) {
        int res = 0;
        Queue<Integer> q = new LinkedList<>();
        //队列的写法细节，本质是模拟，但是要模拟的好，可以先出队，后入队，同时注意if不是并列关系
        for(int i = 0; i < nums.length; i++){
            if(!q.isEmpty() && q.peek() + k <= i)q.remove();

            if(q.size() % 2 == nums[i]){
                q.add(i);
                res++;
                if(i + k > nums.length)return -1;
            }
        }
        return res;
    }
}