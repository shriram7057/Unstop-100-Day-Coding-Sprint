package Day_03;

public

import java.util.*;

public class Main {
    public static int userLogic(String[] ops) {
        Stack<Integer> stack = new Stack<>();

        for (String op : ops) {
            if (op.equals("+")) {
                int last = stack.pop();
                int newTop = last + stack.peek();
                stack.push(last);
                stack.push(newTop);
            } else if (op.equals("D")) {
                stack.push(2 * stack.peek());
            } else if (op.equals("C")) {
                stack.pop();
            } else {
                stack.push(Integer.parseInt(op));
            }
        }

        int sum = 0;
        for (int score : stack) {
            sum += score;
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String[] ops = new String[n];

        for (int i = 0; i < n; ++i) {
            ops[i] = scanner.next();
        }

        int result = userLogic(ops);
        System.out.println(result);
    }
}{

}
