import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static int numberOfQueries;
    public static int queryLength;
    public static int baseStringLength;
    public static int decimal = 256;
    public static int primeNumber = 1117;
    public static String baseString;
    public static String query;
    static ArrayList<Integer> hashes = new ArrayList<Integer>();
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

        hashFunction(baseString);

        for (int i = 0; i < numberOfQueries; i++) {
            query = queries.get(i);
            int index =doesDatasetHave(query);
            if (index != -1){
                System.out.println("The sequence: '" + query + "' found at the position: " + (index+1));
            }else {
                System.out.println("The sequence: '" + query + "' not found!");
            }
        }

        long endTime = System.nanoTime();
        long duration = (endTime - startTime) / 1000000;
        System.out.println("The program execution time in ms: "+duration);


    }
    static void hashFunction(String text){
        int i;
        int totalHash = 0;
        int hash = 1;

        for (i = 0; i < queryLength - 1; i++) {
            hash = (hash * decimal) % primeNumber;
        }

        for (i = 0; i < queryLength; i++){
            totalHash = (decimal * totalHash + text.charAt(i)) % primeNumber;
        }

        hashes.add(totalHash);

        for (i = 0; i < baseStringLength - queryLength; i++) {
            totalHash = (decimal * (totalHash - text.charAt(i) * hash) + text.charAt(i + queryLength)) % primeNumber;

            if (totalHash < 0) {
                totalHash += primeNumber;
            }
            hashes.add(totalHash);
        }
    }


    public static int doesDatasetHave(String query){
        int i, j, localHash = 0;
        for (i = 0; i < queryLength; i++) {
            localHash = (decimal * localHash + query.charAt(i)) % primeNumber;
        }
        for ( i = 0; i < hashes.size(); i++) {
            if( localHash == hashes.get(i) ){

                for (j = 0; j < queryLength; j++){
                    if ( baseString.charAt(i+j) != query.charAt(j) )
                        break;
                }
                if (j == queryLength)
                    return i;
            }
        }
        return  -1;
    }
}