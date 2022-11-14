//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/095123c8145c4bb988e87a75cd4fc2f7
import java.util.*;
import java.io.*;
public class Main {
    static class Node {
        int num;
        Node left, right;

        Node(int num) {
            this.num = num;
        }

        Node(int num, Node left, Node right) {
            this.num = num;
            this.left = left;
            this.right = right;
        }

        void insert(int n) {
            if (n < this.num) {
                if (this.left == null) {
                    this.left = new Node(n);
                }
                else {
                    this.left.insert(n);
                }
            }
            else {
                if (this.right == null) {
                    this.right = new Node(n);
                }
                else {
                    this.right.insert(n);
                }
            }
        }
    }
    public static void main(String [] args) throws IOException {
            FastReader br = new FastReader();
            Node root = new Node(Integer.parseInt(br.nextLine()));
            String input;
            while (true) {
                input = br.nextLine();
                if (input == null || input.equals("")) {
                    break;
                }
                root.insert(Integer.parseInt(input));
            }
            postorder(root);


    }
    static void postorder(Node node) {
        if (node == null) {
            return;
        }
        postorder(node.left);
        postorder(node.right);
        System.out.println(node.num);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while(st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}

