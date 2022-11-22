//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/43d2e831dcd04aaa9bab47add750dde5
import java.util.*;
import java.io.*;

public class Main {
    static final int INF = 987654321;
    static int [][] village;

    public static void main(String [] args) throws IOException {
        FastReader fr = new FastReader();
        StringTokenizer st = new StringTokenizer(fr.nextLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        village = new int[v+1][v+1];

        for(int [] i : village) Arrays.fill(i, INF);

        for(int i = 0; i < e; i++) {                            // 그래프 정점과 간선 가중치 기록
            st = new StringTokenizer(fr.nextLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int weight = Integer.parseInt(st.nextToken());

            village[start][end] = weight;
        }

        for(int i = 1; i <= v; i++) {                           // 플로이드 - 워셜 알고리즘 수행
            for(int j = 1; j <= v; j++) {
                for(int k = 1; k <= v; k++) {
                    if(j == k || i == j || i == k) continue;
                    if(village[j][k] > village[j][i] + village[i][k]) {
                        village[j][k] = village[j][i] + village[i][k];
                    }
                }
            }
        }

        int result = INF;

        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (i == j) {
                    continue;
                }

                if (village[i][j] != INF && village[j][i] != INF) {                     // 두 정점 사이의 간선이 존재함을 의미.
                    result = Math.min(result, village[i][j] + village[j][i]);
                }
            }
        }

        if(result == INF) {
            result = -1;
        }
        System.out.print(result);
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
