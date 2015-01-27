import java.util.ArrayList;
import java.util.List;
import java.util.Random;

class Block {
    private int row;
    private int col;
    private int val;
    private boolean open;
    Block(int row_, int col_, int val_, boolean open_) {
        row = row_;
        col = col_;
        val = val_;
        open = open_;
    }
    public int getVal() {
        return val;
    }
    public int getRow() {
        return row;
    }
    public int getCol() {
        return col;
    }
    public boolean getOpen() {
        return open;
    }
    public void setOpen(boolean open_) {
        open = open_;
    }
}
class Grid {
    private int rows;
    private int cols;
    private List < List<Block> > g = new ArrayList< List<Block> >();
    public Grid(int rows_, int cols_) {
        rows = rows_;
        cols = cols_;
        for (int i=0; i < rows+2; i++) {
            List<Block> blockRow = new ArrayList<Block>();
            for (int j=0; j < cols+2; j++) {
                if (i == 0 || j == 0 || i == rows+1 || j == cols + 1) {
                    blockRow.add(new Block(i, j, -1, false));
                } else {
                    int val = (i-1)*rows + j;
                    blockRow.add(new Block(i, j, val, false));
                }
            }
            g.add(blockRow);
        } 
    }
    public boolean isOpen(int row, int col) {
        return g.get(row).get(col).getOpen();
    }
    public boolean isFull(int row, int col) {
        return !isOpen(row, col);
    }
    public void open(int row, int col) {
        g.get(row).get(col).setOpen(true);
    }
    public Block getBlock(int row, int col) {
        return g.get(row).get(col);
    }
    
    public List<Block> neighbour(int row, int col) {
        List<Block> ret = new ArrayList<Block>();
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0)
                    continue;
                Block b = getBlock(row + i, row + j);
                if (b.getVal() == -1)
                        continue;
                ret.add(b);
            }
        }
        return ret;
    }
    public int noOfRows() {
        return g.size()-2;
    }
    public int noOfCols() {
        return g.get(0).size()-2;
    }
}
public class Percolation {
    // Grid for maintaining the values
    private Grid GRID;
    private WeightedQuickUnionUF F;
    private int N;
    private int totalN;
    public Percolation(int N_) {
        N = N_;
        // Add top connected and bottom connected
        totalN = (int)Math.pow(N, 2) + 2 ; 
        GRID = new Grid(N, N);
  
        F = new WeightedQuickUnionUF(totalN);
        // Connect first node at the top to all the nodes in
        // the first row
        for (int i=1; i <= N; i++)
             F.union(0, i);
        
        // Connect last Node to all the rows in the bottom
        // row
        for (int i=totalN-2; i > totalN-2-N; i--) 
            F.union(totalN-1, i);
        
        
    }
    public void open(int row, int col) {
        Block b = GRID.getBlock(row, col);
        int blockIndex = b.getVal();
        b.setOpen(true);
        List<Block> neighbour = GRID.neighbour(row, col);
        for (int i=0; i < neighbour.size(); i++) {
            Block nb = neighbour.get(i);
            if (nb.getOpen()) { 
                F.union(blockIndex, nb.getVal());
            }
        }
        
    }
    
    public boolean isOpen(int row, int col) {
        return GRID.getBlock(row, col).getOpen();
        
    }
    public boolean isFull(int row, int col) {
        return isOpen(row, col);
    }
    public boolean percolates() {
        return F.connected(0, totalN-1);
    }
    
    public int countOpen() {
        int count = 0;
        for (int i=1; i <= GRID.noOfRows(); i++) {
            for(int j=1; j <= GRID.noOfCols(); j++) {
                Block b = GRID.getBlock(i, j);
                if (b.getOpen())
                    count++;
            }
        }
        return count;
    }
    public static void main(String[] args) {
        int N = 20;
        Percolation p = new Percolation(N);
        //Grid g = new Grid(3, 3);
        //System.out.println(g.isFull(3,3));
        //System.out.println(g.neighbour(2, 2));
        Random rn = new Random();
        int i = 0;
        while (!p.percolates()) {
            int row = rn.nextInt(N)+ 1;
            
            int col = rn.nextInt(N)+ 1;
            System.out.print(row);
            System.out.print(" ");
            System.out.println(col);
            p.open(row, col);
            i = i+1;
        }
       System.out.println("Count of Value");
       System.out.println(p.countOpen());
       System.out.println("Done");
    }
    
}
