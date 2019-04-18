
package com.gooyuan;

import java.util.*;

class Solution{

    public int minimumTotal(List<List<Integer>> triangle){
        int n = triangle.size();
        if(n == 0 || triangle.get(0).size() == 0) return 0;
        if(n<1) return triangle.get(0).get(0);
        print(triangle);
        for(int i=1; i<n; i++){
           for(int j=0; j<=i; j++){
               int cur = triangle.get(i).get(j);
               if(j==0){
                   triangle.get(i).set(j, cur + triangle.get(i-1).get(j));
               }else if(j<i){
                   triangle.get(i).set(j, Math.min(cur + triangle.get(i-1).get(j-1), cur + triangle.get(i-1).get(j)));
               }else{
                   triangle.get(i).set(j, cur + triangle.get(i-1).get(j-1));
               }
           }
        }
        print(triangle);
        int minimum = Integer.MAX_VALUE;
        for(int i=0, size = triangle.get(n-1).size(); i<size; i++){
           minimum = Math.min(minimum, triangle.get(n-1).get(i));
        }
        return minimum;
    }

    void print(List<List<Integer>> arrays){
        for(int i=0, s1 = arrays.size(); i<s1; i++){
            for(int j=0; j<=i; j++){
                System.out.print(arrays.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args){
        List<List<Integer>> triangle = new ArrayList<>();
        List<Integer> l1 = new ArrayList<>();
        l1.add(2);
        List<Integer> l2 = new ArrayList<>();
        l2.add(3);
        l2.add(4);
        List<Integer> l3 = new ArrayList<>();
        l3.add(6);
        l3.add(5);
        l3.add(7);
        List<Integer> l4 = new ArrayList<>();
        l4.add(4);
        l4.add(1);
        l4.add(8);
        l4.add(3);
        triangle.add(l1);
        triangle.add(l2);
        triangle.add(l3);
        triangle.add(l4);
        System.out.println(new Solution().minimumTotal(triangle));
    }
}
