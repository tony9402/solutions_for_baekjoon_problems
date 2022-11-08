//  Authored by : vswngjs
//  Co-authored by : -
//  Link : http://boj.kr/c57554b97d364cb1b50c3f599f5d1bf4
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) {
        FastReader rd = new FastReader();
        String [] line = rd.nextLine().split(" ");
        long A = Long.parseLong(line[0]);
        long B = Long.parseLong(line[1]);

        int maxValue = 10000000;
        boolean prime[] = new boolean[maxValue + 1];

        for (int i = 2; i <= maxValue; i++) {
            for (int j = 2 * i; j <= maxValue; j += i) {                // 소수 판별
                prime[j] = true;
            }
        }

        ArrayList<Long> list = new ArrayList<>();
        for (int i = 2; i <= maxValue; i++) {
            if (B <= i) break;
            if (!prime[i]) {
                for (int j = 2; true; j++) {
                    if((long)Math.pow(i, j) > B) break;                 // B 범위 확인
                    list.add((long)Math.pow(i, j));
                }
            }
        }
        Collections.sort(list);
        int min_index = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) >= A) {
                min_index = i;                                          // A 범위 확인
                break;
            }
        }
        System.out.println(list.size() - min_index);
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
