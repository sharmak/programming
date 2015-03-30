public class Subset {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        int k =  StdIn.readInt();
        //System.out.println(k);
        String s = StdIn.readLine();
        s = StdIn.readLine();
        String [] sArray = s.split(" ");
        String [] sample = new String[k];

        // Copy first k elements
        for (int i=0; i < k; i++)
            sample[i] = sArray[i];
        
        // Randomly choose an element from first k+i elements 
        // and swap with sample array
        for (int i=k; i < sArray.length; i++) {
            int r  = StdRandom.uniform(i);
            if (r < k-1) {
                String test = sArray[i];
                sArray[i] = sample[r];
                sample[r] = test;
            }
        }
        for (int i=0; i < k; i++)
            System.out.println(sample[i]);
    }
    
}
