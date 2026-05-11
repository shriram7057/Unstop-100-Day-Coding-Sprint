import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] first = br.readLine().split(" ");
    int n = Integer.parseInt(first[0]);
    int k = Integer.parseInt(first[1]);

    String s = br.readLine().trim();

    // kth character in reversed string = (n - k) index in original
    System.out.println(s.charAt(n - k));
  }
}