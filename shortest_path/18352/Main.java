//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/6baba8a36f4e4822a693e1ae56458e09
import java.util.*;
import java.io.*;

public class Main {
    static final int INF = Integer.MAX_VALUE;
    static List<List<City>> list = new ArrayList<>();
    static int dist[];                              // 시작 점으로부터 거리를 담아 두기 위한 array
    static int N, M, K, X;
    static class City implements Comparable<City> {
        int cityNum;
        int weight;

        public City(int cityNum, int weight) {
            this.cityNum = cityNum;
            this.weight = weight;
        }

        public int compareTo(City o) {
            return weight - o.weight;       // 오름차순 정렬
        }
    }
    public static void main(String [] args) throws IOException {
        FastReader fr = new FastReader();
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        st = new StringTokenizer(fr.nextLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken());

        dist = new int[N + 1];
        Arrays.fill(dist, INF);                 // 최단 거리를 저장할 것이므로 가장 큰 값으로 초기화
        list = new ArrayList<>();
        for(int i = 0; i <= N; i++) {
            list.add(new ArrayList<>());
        }

        for(int i = 0; i < M; i++) {
            st = new StringTokenizer(fr.nextLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            list.get(x).add(new City(y, 1));         // x 가 시작점이고 x와 연결된 종점을 x 리스트에 저장
        }
        dijkstra(X);                                    // 다익스트라를 이용하여 해당 시작점으로부터 각 점까지의 최단 거리를 갱신

        for(int i = 1; i < dist.length; i++) {
            if(dist[i] == K) {                      // 최단거리가 K라면 sb에 담는다.
                sb.append(i).append('\n');
            }
        }
        if(sb.length() == 0) {
            System.out.println(-1);
        }
        else {
            System.out.println(sb);
        }

    }

    static void dijkstra(int cityNum) {
        PriorityQueue<City> queue = new PriorityQueue<>();
        boolean visit[] = new boolean[N + 1];
        dist[cityNum] = 0;

        queue.offer(new City(cityNum, 0));

        while(!queue.isEmpty()) {
            City city = queue.poll();
            int num = city.cityNum;

            if(visit[num]) continue;
            visit[num] = true;

            for(City c : list.get(num)) {
                if (!visit[c.cityNum] && dist[c.cityNum] > (c.weight + dist[num])) {        // 방문하지 않았고 해당 도시의 weight를 더한 값이 현재 거리보다 큰 경우 갱신
                    dist[c.cityNum] = c.weight + dist[num];
                    queue.offer(new City(c.cityNum, dist[c.cityNum]));
                }
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
