import java.util.*;

public class Main {
  public static void processQueries(int q, List<String[]> queries) {
    Map<String, Long> stock = new HashMap<>();

    for (String[] query : queries) {
      int type = Integer.parseInt(query[0]);

      if (type == 1) {
        String name = query[1];
        long qty = Long.parseLong(query[2]);
        stock.put(name, stock.getOrDefault(name, 0L) + qty);
      } else {
        String name = query[1];
        long qty = Long.parseLong(query[2]);

        long available = stock.getOrDefault(name, 0L);
        long sold = Math.min(available, qty);

        System.out.println(sold);

        stock.put(name, available - sold);
      }
    }
  }

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int q = scanner.nextInt();
    scanner.nextLine();

    List<String[]> queries = new ArrayList<>();
    for (int i = 0; i < q; ++i) {
      String[] parts = scanner.nextLine().split(" ");
      queries.add(parts);
    }

    processQueries(q, queries);
  }
}