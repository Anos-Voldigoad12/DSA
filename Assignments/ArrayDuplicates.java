import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
public class ArrayDuplicates
{
   public int[] getDuplicates(int arr[])
   {
       HashMap<Integer,Integer> map = new HashMap<>();
       for(int x:arr)
       {
           if(map.containsKey(x))
            map.put(x,map.get(x)+1);
           else
            map.put(x,1);
       }
       return map.keySet().stream().filter(k->map.get(k)>1).mapToInt(Integer::intValue).toArray();
   }
   public static void main(String args[])
   {
       Scanner in = new Scanner(System.in);
       ArrayDuplicates ad = new ArrayDuplicates();
       System.out.print("Enter Array Size: ");
       int arr_size = 0;
       if(in.hasNextInt())  arr_size = in.nextInt();
       int arr[] = new int[arr_size];
       System.out.print("Enter Array: ");
       for(int i=0; i<arr_size; i++)    arr[i] = in.nextInt();
       int[] duplicates = ad.getDuplicates(arr);
       if(duplicates.length==0) System.out.println("No Duplicate Elements.");
       else
       {
           System.out.print("[ "+duplicates[0]);
           for(int i=1;i<duplicates.length;i++)
            System.out.print(", "+duplicates[i]);
           System.out.println("]\n"); 
       }
   }
}
