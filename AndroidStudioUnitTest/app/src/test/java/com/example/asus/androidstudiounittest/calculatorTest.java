package com.example.asus.androidstudiounittest;

import org.junit.Test;
import org.junit.Before;

import static org.junit.Assert.*;

/**
 * Created by ASUS on 2018/3/19.
 */
public class calculatorTest {
    private calculator mcalculator;
    @Before
    public void setUp() throws Exception{
        mcalculator =new calculator();
    }
    @Test
    public void sum() throws Exception {
        assertEquals("1+5=6",6d,mcalculator.sum(1d,5d),0);
    }

    @Test
    public void divide() throws Exception {
        assertEquals("6/2=3",3d,mcalculator.divide(6d,2d),0);
    }

    @Test
    public void substract() throws Exception {
        assertEquals("6-2=4",4d,mcalculator.substract(6d,2d),0);
    }

    @Test
    public void multiply() throws Exception {
        assertEquals("6*2=12",12d,mcalculator.multiply(6d,2d),0);
    }

}