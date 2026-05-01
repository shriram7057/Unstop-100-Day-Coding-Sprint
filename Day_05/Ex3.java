import java.io.*;
import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int q = sc.nextInt();

    Map<Integer, Integer> map = new HashMap<>();

    // Step 1: aggregate frequencies
    for (int i = 0; i < q; i++) {
      int freq = sc.nextInt();
      int num = sc.nextInt();
      map.put(num, map.getOrDefault(num, 0) + freq);
    }

    if (map.size() <= 1) {
      System.out.println(0);
      return;
    }

    int minFreq = Integer.MAX_VALUE;
    int maxFreq = Integer.MIN_VALUE;

    int minNum = Integer.MAX_VALUE;
    int maxNum = Integer.MIN_VALUE;

    // Step 2: process final frequencies
    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
      int num = entry.getKey();
      int freq = entry.getValue();

      // minimum frequency
      if (freq < minFreq) {
        minFreq = freq;
        minNum = num;
      } else if (freq == minFreq) {
        minNum = Math.min(minNum, num);
      }

      // maximum frequency
      if (freq > maxFreq) {
        maxFreq = freq;
        maxNum = num;
      } else if (freq == maxFreq) {
        maxNum = Math.max(maxNum, num);
      }
    }

    if (minFreq == maxFreq) {
      System.out.println(0);
    } else {
      System.out.println(Math.abs(maxNum - minNum));
    }
  }
}