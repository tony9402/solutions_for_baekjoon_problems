//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/516d918058e7420bb5f73812aa42b37f
import java.io.*;
import java.util.*;

public class Main {
    static int N, M, H, W, Sr, Sc, Fr, Fc;
    static int[][] arr;
    static boolean[][] isVisited;
    static List<Point> list;
    static int [] dx = {-1, 1, 0, 0};
    static int [] dy = {0, 0, -1, 1};

    static class Point {
        int x, y, count;

        public Point(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int bfs(int x, int y, int endX, int endY) {
        Queue<Point> queue = new LinkedList<>();
        isVisited[x][y] = true;
        queue.add(new Point(x, y, 0));

        while(!queue.isEmpty()) {
            Point temp = queue.poll();
            int nowX = temp.x;
            int nowY = temp.y;

            if(nowX == endX && nowY == endY) {
                return temp.count;
            }

            for(int i = 0; i < 4; i++) {
                int nextX = nowX + dx[i];
                int nextY = nowY + dy[i];

                if(nextX < 1 || nextY < 1 || nextX > N || nextY > M || isVisited[nextX][nextY]) {
                    continue;
                }
                if(!innerCheck(nextX, nextY)) {
                    continue;
                }
                isVisited[nextX][nextY] = true;
                queue.add(new Point(nextX, nextY ,temp.count + 1));
            }
        }
        return -1;
    }
    static boolean innerCheck(int x, int y) {               // 벽이 직사각형 크기 안에 포함되어 있는지 확인하는 method
        if (x + H -1 > N || y + W - 1 > M) {
            return false;
        }
        for(int i = 0; i< list.size(); i++) {
            Point p = list.get(i);

            int px = p.x;
            int py = p.y;

            if(px >= x && px <= x + H -1 && py >= y && py <= y + W - 1) {
                return  false;
            }
        }
        return  true;
    }
    public static void main(String [] args) {
        FastReader fr = new FastReader();
        StringTokenizer st = new StringTokenizer(fr.nextLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        list = new ArrayList<>(); // 벽 위치를 넣을 리스트
        isVisited = new boolean[N + 1][M + 1];

        for (int i = 1; i < N + 1; i++) {
            st = new StringTokenizer(fr.nextLine(), " ");
            for (int j = 1; j < M + 1; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if(arr[i][j] == 1) {
                    list.add(new Point(i, j));
                }
            }
        }
        st = new StringTokenizer(fr.nextLine(), " ");

        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        Sr = Integer.parseInt(st.nextToken());
        Sc = Integer.parseInt(st.nextToken());
        Fr = Integer.parseInt(st.nextToken());
        Fc = Integer.parseInt(st.nextToken());

        int count = bfs(Sr, Sc, Fr, Fc);

        System.out.println(count);
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
