//  Authored by : vswngjs
//  Co-authored by : -
//  Link : http://boj.kr/fa6233ec1d9c4fd482068da8461e4a03
import java.io.*;
import java.util.*;
public class Main {
    public static void main(String [] args) {
        // 최대일 경우 : M이 K를 만날때까지 상태를 유지, M이 연속 될 경우 1로 상태 변화
        // 최소일 경우 : K는 바로 5로 변화, M이 연속 될 시 제곱으로 변화
        FastReader rd = new FastReader();
        String s = rd.nextLine();
        int size = s.length();

        System.out.println(return_max(s, size));
        System.out.println(return_min(s, size));

    }
    private static String return_min(String str, int size) {
        int idx = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i< size; i++) {
            if(str.charAt(i) == 'M'){
                idx = i;
                while (idx < str.length() && str.charAt(idx) == 'M') {
                    idx++;
                }
                sb.append(1);
                for(; i + 1 < idx; i++) {
                    sb.append(0);       // 제곱 + 1 만큼의 M이 있으므로 0은 1개 더 적어야함.
                }
                i = idx - 1;
            } else {
                sb.append(5);
            }
        }
        return sb.toString();
    }
    private static String return_max(String str, int size) {
        int idx = 0;
        StringBuilder sb= new StringBuilder();
        for (int i = 0; i < size; i++) {
            if (str.charAt(i) == 'M') {
                idx = i;
                while (idx < size && str.charAt(idx) == 'M') {
                    idx++;
                }
                if (idx == size) {
                    for(; i < idx; i++) {
                        sb.append(1);
                    }
                }
                else {
                    sb.append(5);
                    for(; i < idx; i++) {
                        sb.append(0);
                    }
                }
                i = idx;
            } else {
                sb.append(5);
            }
        }
        return sb.toString();
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
