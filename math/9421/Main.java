//  Authored by : vswngjs
//  Co-authored by : -
//  Link : http://boj.kr/b9801e796f7547e890b0eb1231a9bce2
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String [] args) {
        FastReader rd = new FastReader();
        int value = rd.nextInt();
        boolean prime[] = new boolean[1000001];
        for (int i = 2; i <= 1000000; i++) {
            for (int j = i * 2; j <= 1000000; j +=i) {
                prime[j] = true;
            }
        }
        for (int i = 3; i <= value; i++) {
            if(!prime[i]) {
                Set<Integer> set = new HashSet<>();
                String str = Integer.toString(i);
                boolean flag = false;
                while(true) {
                    int sum = 0;
                    for (int j = 0; j < str.length(); j++) {
                        sum += Math.pow(str.charAt(j) -'0', 2);
                    }
                    if(sum == 1) {
                        flag = true;
                        break;
                    }
                    if(!set.contains(sum)){
                        set.add(sum);
                        str = String.valueOf(sum);
                    } else break;
                }
                if(flag) System.out.println(i);
            }
        }

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
