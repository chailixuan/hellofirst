package com.example.asus.androidstudiounittest;

/**
 * Created by ASUS on 2018/3/31.
 */

public class MaxSum {
    public int get_maxSum(int arr[]){
        int len = arr.length;
        int thisSum = 0;
        int maxSum = 0;
        for(int i=0;i < len;i++){
            thisSum += arr[i];
            if(thisSum>maxSum) maxSum=thisSum;
            else if (thisSum<0)thisSum = 0;
        }
        return maxSum;
    }
}
