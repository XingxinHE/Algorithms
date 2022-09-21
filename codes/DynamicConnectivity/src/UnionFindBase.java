public abstract class UnionFindBase {
    protected int[] id;        // the id has diff meaning in diff contexts
    protected int amount;      // the amount of components
    private int length;        // the length of elements

    /*
     * Constructor
     */
    protected UnionFindBase() {
    }

    /*
     * This is the explicit method to initialize this data structure
     *
     * @param n the number to initialize
     */
    public void construct(int n) {
        if (n < 0) throw new IllegalArgumentException();
        amount = length = n;
        id = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i] = i;
        }
    }

    /*
     * getter the length
     */
    public int length() {
        return length;
    }

    /*
     * If the ids are the same. They are connected.
     */
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    /*
     * ⭐union function to override
     */
    public abstract void union(int p, int q);

    /*
     * ⭐find function to override
     */
    public abstract int find(int p);
}
