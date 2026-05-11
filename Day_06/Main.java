import java.util.*;

public class Main {
  public static List<Integer> modifyArray(int n, List<Integer> arr) {
    List<Integer> result = new ArrayList<>();

    int maxSoFar = 0;

    for (int i = 0; i < n; i++) {
      maxSoFar = Math.max(maxSoFar, arr.get(i));
      result.add(arr.get(i) + maxSoFar);
    }

    return result;
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int n = scanner.nextInt();
    List<Integer> arr = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      arr.add(scanner.nextInt());
    }

    List<Integer> modifiedArr = modifyArray(n, arr);

    for (int num : modifiedArr) {
      System.out.print(num + " ");
    }
  }
}