// Authored by : gyeong_sun
// Co-authored by : -
// Link : http://boj.kr/d8b491b7c1f14acdbf03026d9a33c794 

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	//public golbal variables
	static int[] preorder; //전위 순회
	static int[] inorder; //중위 순회 

	static void solve(int s, int e, int root) {
		for(int i=s; i<e;i++) {
			if(preorder[root] == inorder[i]) {	//preorder 
				solve(s, i, root+1);   //좌 서브 트리 서칭
				solve(i+1, e, root+i-s+1);	//우 서브 트리 서칭
				System.out.print(inorder[i]+" ");
			}
		}		
	}
	
	public static void main(String[] args) {
		FastReader rd = new FastReader();
		int tc = rd.nextInt(); 		//test case 개수 
		
		for(int i=0;i<tc;i++) {	
			int n = rd.nextInt();			//노드 n 개수 
			preorder = new int[n+1];
			inorder = new int[n+1];
			for(int j = 0; j<n ; j++) 
				preorder[j] = rd.nextInt();
			for(int j = 0; j<n ; j++) 
				inorder[j] = rd.nextInt();
			
			solve(0, n, 0);
			System.out.println();
		}
	}
	
	public static class FastReader {
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