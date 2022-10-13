// Authored by : vswngjs
// Co-authored by : -
// Link : http://boj.kr/ed9212b6595d4e678366d326ab71c304
import java.util.*;
import java.io.*;
public class Main {
    public static void main(String [] args) {
        FastReader rd = new FastReader();

        int N = rd.nextInt();
        String s = rd.nextLine();
        int [] dp = new int[N];    // 필요한 에너지 양의 최솟값을 담는 배열 dp
        Arrays.fill(dp, -1);    // dp 배열을 -1로 초기화하여 dp[i]가 -1이면 도착이 불가능한 칸임을 표현
        // 현재 보도블럭 기준 이전 보도블럭이 무엇인지를 판별하기 위한 map
        HashMap map = new HashMap<Character, Character>();
        map.put('B', 'J');    // 현재 보도블럭이 'B'이면 직전 블럭은 'J'여야함.
        map.put('O', 'B');    // 현재 보도블럭이 'O'이면 직전 블럭은 'B'여야함.
        map.put('J', 'O');    // 현재 보도블럭이 'J'이면 직전 블럭은 'O'여야함.

        dp[0] = 0;

        for(int i = 1; i < N; i++) {
            for(int j = 0; j < i; j++) {
                // 현재 보도블럭을 기준으로 이전에 밟아야 하는 보도블럭을 확인
                // 도착가능한 칸이라면
                if (s.charAt(j) == (char) map.get(s.charAt(i)) && dp[j] != -1) {
                    // dp[i]가 갱신된 적이 없거나 있더라도 그 값보다 더 작은 에너지로
                    // i 번째 칸으로 이동할 수 있다면 갱신함.
                    if(dp[i] == -1 || dp[i] > dp[j] + (i - j) * (i - j)) {
                        dp[i] = dp[j] + (i - j) * (i - j);
                    }
                }
            }
        }
        System.out.println(dp[N - 1]);
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
