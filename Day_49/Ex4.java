import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

class Main {

  public static void main(String[] args) {
    /*
     * Enter your code here. Read input from STDIN. Print output to STDOUT. Your
     * class should be named Solution.
     */
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    String arr[] = new String[n];
    for (int i = 0; i < n; i++) {
      arr[i] = sc.next();
    }
    Map<String, Integer> map = new HashMap<>();
    for (int i = 0; i < n; i++) {
      map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
    }
    List<String> l = new ArrayList<>();
    for (Map.Entry<String, Integer> en : map.entrySet()) {
      if (en.getValue() % 2 != 0) {
        l.add(en.getKey());
      }
    }
    System.out.println(l);
  }
}