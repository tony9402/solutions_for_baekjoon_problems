//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/f6af7431de9a4f799768bc46c479be4a

public class Main {
    // 만들어야 하는 수에서 만드는 수로 갈 수 있는지를 확인했다. (거꾸로 접근)
    public static void main(String[] args) throws Exception {
            FastReader rd = new FastReader();
            String[] s = rd.nextLine().split(" ");
            int basic= Integer.parseInt(s[0]);          // 초기값
            int result = Integer.parseInt(s[1]);        // 만들어야 하는 수

            int cnt = 1;

            while (basic != result) {
                if (result < basic) {       // 만들어야 하는 수가 초기값보다 작은 경우는 못 만드는 것을 의미
                    System.out.println(-1);
                    return;
                }
                if (result % 10  == 1) {        // 자릿값이 1일 경우 1을 없애줌.
                    result /= 10;
                }
                else if (result % 2 == 0) {     // 만들어야하는 수가 2로 나누어질 경우 2로 나눔.
                    result /= 2;
                }
                else {                          // 이 외의 경우는 초기값에서 만들어야하는 수로 만들 수 없음.
                    System.out.println(-1);
                    return;
                }
                cnt++;
            }
            System.out.println(cnt);
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
