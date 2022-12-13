import java.util.ArrayList;
import java.util.Scanner;

public class Main2 {
    public static int numberOfQueries;
    public static int queryLength;
    public static int baseStringLength;
    public static String baseString;
    public static String query;
    static ArrayList<String> queries = new ArrayList<String>();

    public static void main(String[] args) {

        long startTime = System.nanoTime();

        Scanner input = new Scanner(System.in);
        baseString = input.next();
        numberOfQueries = input.nextInt();
        queryLength = input.nextInt();
        baseStringLength = baseString.length();
        for (int i = 0; i < numberOfQueries; i++) {
            queries.add(input.next());
        }

        for (int i = 0; i < numberOfQueries; i++) {
            query = queries.get(i);
            boolean flag = false;
            for(int j=0; j<(baseStringLength-queryLength-1); j++){
                if(baseString.substring(j, j + queryLength).equals(query)){
                    System.out.println("The sequence: '" + query + "' found at the position: " + (baseString.indexOf(query)+1) );
                    flag = true;
                    break;
                }
            }

            if (!flag){
                System.out.println("The sequence: '" + query + "' not found!");
            }
        }

        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        System.out.println("The program execution time in ms: "+duration);

    }
}
