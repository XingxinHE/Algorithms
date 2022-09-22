import java.util.Arrays;

public class WeightedUnion extends QuickUnion {
    protected int[] size;

    public WeightedUnion() {
        super();
    }

    public void construct(int n) {
        super.construct(n);
        size = new int[length()];
        Arrays.fill(size, 1);
    }

    public void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;
        if (size[pRoot] < size[qRoot]) {
            id[pRoot] = qRoot;
            size[qRoot] += size[pRoot];
        } else {
            id[qRoot] = pRoot;
            size[pRoot] += size[qRoot];
        }
        amount--;
    }
}
