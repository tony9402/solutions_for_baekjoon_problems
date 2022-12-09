//Authored by : gyeong_sun
//Co-authored by : -
//Link : http://boj.kr/8e1bc465e7c84e67a0285fb415ae5922 

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        FastReader rd = new FastReader();

        int cnt = 0;
        int t = rd.nextInt();
		for (int i = 0; i < t; i++) {  
			int num = rd.nextInt();
			if(isPrime(num)) 
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
    
	public static boolean isPrime(int n) {  //소수: True(1) 소수 아닌 경우 :False(0)반환
		if (n <=1)
			return false;
		for(int i = 2; i <= (int)Math.sqrt(n); i++) {  //sqrt함수 사용
			if(n % i==0)
				return false;
		}
		return true;
	} 
}