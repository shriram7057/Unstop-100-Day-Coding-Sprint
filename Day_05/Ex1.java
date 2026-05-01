import java.io.*;
import java.util.*;

class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int total = sc.nextInt(); // 2*n
    int n = total / 2;

    Map<Integer, Integer> freq = new HashMap<>();

    for (int i = 0; i < total; i++) {
      int x = sc.nextInt();
      freq.put(x, freq.getOrDefault(x, 0) + 1);

      if (freq.get(x) == n) {
        System.out.println(x);
        return;
      }
    }
  }
}