import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n2 = Integer.parseInt(br.readLine().trim());
    String[] input = br.readLine().trim().split(" ");

    int[] arr = new int[n2];
    for (int i = 0; i < n2; i++) {
      arr[i] = Integer.parseInt(input[i]);
    }

    Arrays.sort(arr);

    int sum = 0;
    for (int i = 0; i < n2; i += 2) {
      sum += arr[i];
    }

    System.out.println(sum);
  }
}