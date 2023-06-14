import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
public class Majority
{
   public int getMajority(int arr[])
   {
       HashMap<Integer,Integer> map = new HashMap<>();
       for(int x:arr)
       {
           if(map.containsKey(x))
            map.put(x,map.get(x)+1);
           else
            map.put(x,1);
       }
       for(Map.Entry<Integer,Integer> e:map.entrySet())
       {
           if(e.getValue()>arr.length/2)
            return e.getKey();
       }
       return -1;
   }
   public static void main(String args[])
   {
       Scanner in = new Scanner(System.in);
       Majority m = new Majority();
       System.out.print("Enter Array Size: ");
       int arr_size = 0;
       if(in.hasNextInt())  arr_size = in.nextInt();
       int arr[] = new int[arr_size];
       System.out.print("Enter Array: ");
       for(int i=0; i<arr_size; i++)    arr[i] = in.nextInt();
       int majority = m.getMajority(arr);
       if(majority!=-1) System.out.println("Majority Element: "+majority);
       else System.out.println("Majority Element Not Found!");
   }
}
