// Authored by : vswngjs
// Co-authored by : tony9402
// Link : http://boj.kr/997461ea2c784c50952cf2c2fea3f797
import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        FastReader rd = new FastReader();
        
        int N = rd.nextInt();
        int[] prefix_sum = new int[N + 1];

        for(int i = 1; i <= N; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + rd.nextInt();
        }

        int testcase = rd.nextInt();

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < testcase; ++i) {
            int s = rd.nextInt();
            int e = rd.nextInt();
            sb.append(prefix_sum[e] - prefix_sum[s - 1]);
            sb.append('\n');
        }
        System.out.println(sb);
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
