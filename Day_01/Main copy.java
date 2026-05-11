import java.util.*;

public class Main {
  public static void find_youngest_member(int n, int m, int[][] gifts) {
    int[] given = new int[n + 1];
    int[] received = new int[n + 1];

    for (int i = 0; i < m; i++) {
      int a = gifts[i][0];
      int b = gifts[i][1];
      given[a]++;
      received[b]++;
    }

    for (int i = 1; i <= n; i++) {
      if (given[i] == 0 && received[i] == n - 1) {
        System.out.println(i);
        return;
      }
    }

    System.out.println(-1);
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int m = scanner.nextInt();
    int[][] gifts = new int[m][2];
    for (int i = 0; i < m; i++) {
      gifts[i][0] = scanner.nextInt();
      gifts[i][1] = scanner.nextInt();
    }
    find_youngest_member(n, m, gifts);
  }
}