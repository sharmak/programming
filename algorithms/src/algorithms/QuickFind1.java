package algorithms;

import java.util.ArrayList;
public class QuickFind1 {
	private ArrayList<Integer> ar = new ArrayList<Integer>();
 	public QuickFind1(int n) {
		for (int i=0; i < n ; i++)
			ar.add(i);
	}
 	public void printArray() {
 		for (int i=0; i < ar.size(); i++) {
 			System.out.print(ar.get(i));
 			System.out.print(" ");
 		}
 		System.out.println();
 	}
 	public boolean isConnected(int first, int second) {
 		// if the value of the element at the index
 		// are same then they are connected
 		// Complexity: O(1)
 		return ar.get(first) == ar.get(second);
 	}
 	public void union(int first, int second) {
 		// Complexity: O(n)
 		int firstValue = ar.get(first);
 		int secondValue = ar.get(second);
 		for (int i=0; i < ar.size(); i++) {
 			// Check all the values for which we match secondValue
 			// and replace with first value
 			if (ar.get(i) == secondValue) {
 				ar.set(i, firstValue);
 			}
 		}
 	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		QuickFind1 q = new QuickFind1(5);
		q.printArray();
		q.union(0, 1);
		q.printArray();
		q.union(2, 3);
		q.printArray();
		System.out.println(q.isConnected(1, 3));
		// Connect 1,2 so that 1 and 3 become connected.
		q.union(1,2);
		System.out.println(q.isConnected(1, 3));
	}
}
