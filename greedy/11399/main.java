// Authored by : gyeong_sun
// Co-authored by : -
// Link : http://boj.kr/877fee97525c40b290560c66dcaa357e

import java.util.*;
import java.util.Arrays;
import java.io.*;

public class Main {
	public static void main(String[] args) {
			FastReader rd = new FastReader();
			
			int[] time = null;   		//배열 동적 할당
			int n = rd.nextInt();       //사람 수 : n
			time = new int[n];          //배열 동적할당
			
			for (int i=0; i<n;i++) {   
				time[i] = rd.nextInt();		//백준 문제에서 두 번째 줄의 입력
			}

			Arrays.sort(time);         //오름차순 정렬
		
			int totalTime = 0;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j <= i; j++) {
					totalTime += time[j];
				}
			}
			System.out.println(totalTime);
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