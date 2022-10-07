// Authored by : vswngjs
// Co-authored by : tony9402
// Link : http://boj.kr/d3b98dc013f74003a17cc04a1e6c55eb

package temp;
import java.io.*;
public class Main {
    public static void main(String [] args) throws  IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int number = Integer.parseInt(br.readLine());

        String [] numbers = br.readLine().split(" ");

        int [] multi_plus = new int[numbers.length];

        multi_plus[0] = Integer.parseInt(numbers[0]);
        for(int i=1; i<numbers.length; i++){                              // multi_plus : 누적합을 저장하는 리스트
            multi_plus[i] = multi_plus[i-1] + Integer.parseInt(numbers[i]);
        }

        int testcase = Integer.parseInt(br.readLine());                   // testcase 만큼 반복

        for(int j=0; j<testcase; j++){
            int result =0;
            String [] part = br.readLine().split(" ");
            int start = Integer.parseInt(part[0])-2;                      // start 인덱스 계산
            int end = Integer.parseInt(part[1])-1;                        // end 인덱스 계산

            if(start<0){
                result = multi_plus[end];
            }else{
                result = multi_plus[end] - multi_plus[start];
            }

            bw.write(Integer.toString(result));
            bw.newLine();
        }
        bw.close();

    }
}
