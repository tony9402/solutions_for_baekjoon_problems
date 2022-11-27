//Authored by : vswngjs
//Co-authored by : -
//Link : http://boj.kr/8439efb88488421fbb53720777d8b941
import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] nums;
    static boolean[] isVisited;
    static List<Integer> solution;

    public static void main(String [] args) {
        FastReader fr = new FastReader();
        N = Integer.parseInt(fr.nextLine());
        nums = new int[N + 1];
        isVisited = new boolean[N + 1];
        solution = new ArrayList<>();
        
        for(int i = 1; i <= N; i++) {       // 인덱스 관리를 편하게 하기위해 1부터 시작
            nums[i] = Integer.parseInt(fr.nextLine());
        }
        
        for(int i = 1; i <= N; i++) {
            isVisited[i] = true;
            DFS(i, i);              //cycle 여부 확인을 위해 endcycle 변수 삽입
            isVisited[i] = false;
        }
        
        Collections.sort(solution);
        System.out.println(solution.size());
        for(int val : solution) {
            System.out.println(val);
        }
    }
    
    static void DFS(int n, int endcycle) {      
        if(nums[n] == endcycle) {
            solution.add(n);
        }
        
        if(!isVisited[nums[n]]) {
            isVisited[nums[n]] = true;
            DFS(nums[n], endcycle);
            isVisited[nums[n]] =false;
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
