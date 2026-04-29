import java.io.*;
import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int n = sc.nextInt();
    sc.nextLine();

    String[] arr = new String[n];
    Map<String, Integer> freq = new LinkedHashMap<>();

    for (int i = 0; i < n; i++) {
      arr[i] = sc.nextLine();
      freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
    }

    int k = sc.nextInt();

    int count = 0;
    for (String s : freq.keySet()) {
      if (freq.get(s) == 1) {
        count++;
        if (count == k) {
          System.out.println(s);
          return;
        }
      }
    }

    System.out.println(-1);
  }
}