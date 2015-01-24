package kishor;

import java.util.ArrayList;

public class QuickFind2 {
	private ArrayList<Integer> ar = new ArrayList<Integer>();
	private ArrayList<Integer> sz = new ArrayList<Integer>();
	
	// Initialize QuickFind data structure with some length
	QuickFind2(int n) {
		for(int i=0; i < n; i++) {
			ar.add(i);
			sz.add(1);
		}
	}
	
	public int root(int index_) {
		int indexVal = ar.get(index_);
		while (indexVal != index_) {
			index_ = ar.get(indexVal);
			indexVal = ar.get(index_);
		}
		return index_;
	}
 	
	public void printArray() {
		System.out.println("Array ");
 		for (int i=0; i < ar.size(); i++) {
 			System.out.print(ar.get(i));
 			System.out.print(" ");
 		}
 		System.out.println();
 		System.out.println("Size: ");
 		for (int i=0; i < sz.size(); i++) {
 			System.out.print(sz.get(i));
 			System.out.print(" ");
 		}
 		System.out.println();
 	}
	
	public boolean isConnected(int first, int second) {
		System.out.println("Root First " + root(first));
		return root(first) == root(second);
	}
	
	public void union(int first, int second) {
		int firstRoot = root(first);
		int secondRoot = root(second);
		int firstSize = sz.get(firstRoot);
		
		// Path compression
		int secondSize = sz.get(secondRoot);
		if (firstSize < secondSize) {
			ar.set(firstRoot, secondRoot);
			sz.set(secondRoot, sz.get(secondRoot) + sz.get(firstRoot));
		} else {
			ar.set(secondRoot, firstRoot);
			sz.set(firstRoot, sz.get(secondRoot) + sz.get(firstRoot));
		}
			
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		QuickFind2 q = new QuickFind2(10);
		q.union(0, 1);
		q.printArray();
		q.union(2, 3);
		q.printArray();
		q.union(4, 5);
		q.printArray();
		q.union(7, 8);
		q.printArray();
		q.union(0, 5);
		q.printArray();
		//System.out.println(q.root(5));
		System.out.println(q.isConnected(5, 7));;
	}

}
