import java.io.*;
import java.util.*;

public class Main {
  public static int countConsistentCars(String components, int n, List<String> models) {
    Set<Character> allowed = new HashSet<>();

    for (char c : components.toCharArray()) {
      allowed.add(c);
    }

    int count = 0;

    for (String model : models) {
      boolean isValid = true;

      for (char c : model.toCharArray()) {
        if (!allowed.contains(c)) {
          isValid = false;
          break;
        }
      }

      if (isValid) {
        count++;
      }
    }

    return count;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    String components = reader.readLine().trim();
    int n = Integer.parseInt(reader.readLine().trim());
    List<String> models = new ArrayList<>();

    for (int i = 0; i < n; ++i) {
      models.add(reader.readLine().trim());
    }

    int result = countConsistentCars(components, n, models);
    System.out.println(result);
  }
}