import java.io.*;
import java.util.*;

class Main {
  static class Point {
    int x, y;
    int dist;

    Point(int x, int y) {
      this.x = x;
      this.y = y;
      this.dist = x * x + y * y;
    }
  }

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine().trim());

    Point[] arr = new Point[N];
    for (int i = 0; i < N; i++) {
      String[] parts = br.readLine().split(" ");
      int x = Integer.parseInt(parts[0]);
      int y = Integer.parseInt(parts[1]);
      arr[i] = new Point(x, y);
    }

    int K = Integer.parseInt(br.readLine().trim());

    Arrays.sort(arr, (a, b) -> a.dist - b.dist);

    for (int i = 0; i < K; i++) {
      System.out.println(arr[i].x + " " + arr[i].y);
    }
  }
}