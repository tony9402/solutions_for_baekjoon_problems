// Authored by : gyeong_sun
// Co-authored by : -
// Link : http://boj.kr/0f1314337dda43f8b0f00a0a9c248ef6

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
        FastReader rd = new FastReader();
        int[] arr= new int[10];
        int n, k;
        int cnt = 0;
        
        n = rd.nextInt();
        k = rd.nextInt();
        for (int i=0; i<n;i++) arr[i] = rd.nextInt();
        
        for(int i=n-1; i>=0; i--) {
        	cnt += (k / arr[i]);
        	k %= arr[i];
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