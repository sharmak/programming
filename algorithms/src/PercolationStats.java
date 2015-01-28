import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class PercolationStats {
    // perform T independent experiments on an N-by-N grid
    private int N;
    private int T;
    private List<Double> timings;
    public PercolationStats(int N_, int T_) {
        N = N_; T = T_;
        timings = new ArrayList<Double>(T);
    }
    public void runStats() {
        for (int j = 0; j < T; j++) {
            Percolation p = new Percolation(N);

            Random rn = new Random();
            int i = 0;
            while (!p.percolates()) {
                int row = rn.nextInt(N) + 1;
                
                int col = rn.nextInt(N) + 1;
                //System.out.print(row);
                //System.out.print(" ");
                //System.out.println(col);
                p.open(row, col);
                i = i + 1;
            }
            timings.add(((double)(p.countOpen())/(N*N)));
        }
    }
     // sample mean of percolation threshold
    public double mean()    {
        double sum = 0.0;
        for (Double d : timings) {
            sum += d;
        }
        return sum  / timings.size();
    }
    // sample standard deviation of percolation threshold
    public double stddev() {
        double meanVal = mean();
        double sumOfSquares = 0;
        for (double d : timings) {
            sumOfSquares += Math.pow(d-meanVal, 2);
        }
        return Math.sqrt(sumOfSquares/(T-1));
        
    }

    //low  endpoint of 95% confidence interval
    public double confidenceLo()    {
        double meanVal = mean();
        double stdVal = stddev();
        return meanVal - ((1.96*stdVal)/Math.sqrt(T));
    }
    // high endpoint of 95% confidence interval
    public double confidenceHi()     {
        double meanVal = mean();
        double stdVal = stddev();
        return meanVal + ((1.96*stdVal)/Math.sqrt(T));
            
    }
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        PercolationStats t = new PercolationStats(200, 100);
        t.runStats();
        System.out.println(t.mean());
        System.out.println(t.stddev());
        System.out.println(t.confidenceHi());
        System.out.println(t.confidenceLo());
        
    }
    
}
