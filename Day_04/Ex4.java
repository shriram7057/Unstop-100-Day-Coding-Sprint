import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();

    long val = 1;
    for (int i = 0; i <= n; i++) {
      System.out.print(val + " ");
      val = val * (n - i) / (i + 1);
    }
  }
}