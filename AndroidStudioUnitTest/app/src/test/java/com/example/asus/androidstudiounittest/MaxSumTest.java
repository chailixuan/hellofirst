package com.example.asus.androidstudiounittest;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.Parameterized;

import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Collection;
import java.util.Objects;

import static org.junit.Assert.*;

/**
 * Created by ASUS on 2018/3/31.
 */
@RunWith(Parameterized.class)//必须
public class MaxSumTest {
    private int expected;
    private int[] input;
    public MaxSumTest(int expected,int [] input){
        this.expected = expected;
        this.input = input;
    }
    @Parameterized.Parameters//用此语句去修饰一个public static Collection xxx()
    public static Collection data(){
        return Arrays.asList(new Object[][]{
            {11,new int[]{-6,10,-5,6,-7,-1,-1}},
            {10, new int[]{10,-2,-1,-8}},
        });
    }
    @Test
    public void get_maxSum() throws Exception {
        assertEquals(expected,new MaxSum().get_maxSum(input));
    }

}