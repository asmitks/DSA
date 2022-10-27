import java.util.*;
import java.io.*;
 
/*
Problem FrogJump or Minimum Jump - many names but same approach
Given an array of integers where each element represents the max 
number of steps that can be made forward from that element. 
Write a function to return the minimum number of jumps to reach 
the end of the array (starting from the first element). 
If an element is 0, they cannot move through that element. If the end isn’t reachable, return -1.
 */
class FrogJump {
    static int minJumps(int arr[], int l, int h)
    {
        if (h == l)
            return 0;
        if (arr[l] == 0)
            return Integer.MAX_VALUE;
        int min = Integer.MAX_VALUE;
        for (int i = l + 1; i <= h
                            && i <= l + arr[l];
             i++) {
            int jumps = minJumps(arr, i, h);
            if (jumps != Integer.MAX_VALUE && jumps + 1 < min)
                min = jumps + 1;
        }
        return min;
    }
    public static void main(String args[])
    {
        int arr[] = { 1, 3, 6, 5, 7, 3, 6, 3, 9, 9, 1, 5, 2, 4, 3 };
        int n = arr.length;
        System.out.print("Minimum number of jumps to reach end is "
                         + minJumps(arr, 0, n - 1));
    }
}