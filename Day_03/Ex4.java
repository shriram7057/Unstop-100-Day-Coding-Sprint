import java.util.Scanner;

public class Main {
  public static long compareBits(String a, String b) {
    int n = a.length();
    int m = b.length();

    int[] prefixOnes = new int[m + 1];

    // Build prefix sum of ones in b
    for (int i = 0; i < m; i++) {
      prefixOnes[i + 1] = prefixOnes[i] + (b.charAt(i) - '0');
    }

    long totalDiff = 0;

    // For each position in a
    for (int i = 0; i < n; i++) {
      int left = i;
      int right = m - n + i;

      int ones = prefixOnes[right + 1] - prefixOnes[left];
      int total = (right - left + 1);

      if (a.charAt(i) == '0') {
        totalDiff += ones; // differing where b has 1
      } else {
        totalDiff += (total - ones); // differing where b has 0
      }
    }

    return totalDiff;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String a = scanner.next();
    String b = scanner.next();
    System.out.println(compareBits(a, b));
  }
}