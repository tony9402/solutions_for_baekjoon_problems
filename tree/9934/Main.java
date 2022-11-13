//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/259bd9ce8c2b4c01b68d5b54783d3eff

import java.util.*;
import java.io.*;
public class Main {
    static int depth;
    static int[] arr;
    static StringBuffer[] result;
    public static void main(String [] args) throws IOException {
            FastReader br = new FastReader();
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

            depth = br.nextInt();
            String[] slist = br.nextLine().split(" ");

            arr = new int[(int) Math.pow(2, depth) - 1];

            for (int i = 0; i < arr.length; i++) {
                arr[i] = Integer.parseInt(slist[i]);
            }

            result = new StringBuffer[depth];

            for (int i = 0; i < depth; i++) {
                result[i] = new StringBuffer();
            }

            solve(0, arr.length - 1, 0);

            for (int i = 0; i < depth; i++) {
                bw.write(result[i].toString() + "\n");
            }
            bw.flush();

    }
    static void solve(int s, int e, int dep) {
        if (dep == depth) {
            return;
        }
        int m = (s + e) / 2;
        result[dep].append(arr[m] + " ");

        solve(s, m - 1, dep + 1);
        solve(m + 1, e , dep + 1);
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

