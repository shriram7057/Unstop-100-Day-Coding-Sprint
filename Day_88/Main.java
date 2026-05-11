import java.util.*;

public class Main {
  public static int findMisplacedFile(int n, int[] file_numbers) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans ^= file_numbers[i];
    }
    return ans;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    int[] file_numbers = new int[n];
    for (int i = 0; i < n; i++) {
      file_numbers[i] = scanner.nextInt();
    }
    int result = findMisplacedFile(n, file_numbers);
    System.out.println(result);
  }
}