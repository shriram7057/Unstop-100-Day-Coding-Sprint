import java.io.*;
import java.util.*;

class Main {
  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine().trim());
    String[] input = br.readLine().trim().split(" ");

    Queue<Integer> q = new LinkedList<>();
    int maxSize = 0;

    for (int i = 0; i < N; i++) {
      int t = Integer.parseInt(input[i]);

      while (!q.isEmpty() && t - q.peek() >= 5000) {
        q.poll();
      }

      q.offer(t);
      maxSize = Math.max(maxSize, q.size());
    }

    System.out.println(maxSize);
  }
}