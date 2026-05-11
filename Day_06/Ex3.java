import java.util.*;

public class Main {
  public static long maxBottleCost(int n, int x, int[] costs) {
    Arrays.sort(costs);

    long totalBottles = 0;
    long prefixSum = 0;

    for (int i = 0; i < n; i++) {
      prefixSum += costs[i];

      if (prefixSum > x)
        break;

      long days = (x - prefixSum) / (i + 1) + 1;
      totalBottles += days;
    }

    return totalBottles;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();
    int[] costs = new int[n];

    for (int i = 0; i < n; i++) {
      costs[i] = sc.nextInt();
    }

    long result = maxBottleCost(n, x, costs);
    System.out.println(result);
  }
}