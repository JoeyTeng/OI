import java.io.*;
import java.util.*;

public class Sort {
   public static void main(String[] args) throws IOException {
      BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter writer = new PrintWriter(new OutputStreamWriter(System.out));
      int N = Integer.parseInt(reader.readLine());
      int[] A = new int[N];
      for(int i = 0; i < N; i++) {
         A[i] = Integer.parseInt(reader.readLine());
      }
      Arrays.sort(A);
      for(int i = 0; i < N; i++) {
         writer.println(A[i]);
      }
      writer.flush();
   }
}