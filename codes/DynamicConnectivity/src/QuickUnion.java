public class QuickUnion extends UnionFindBase {


    public QuickUnion() {
    }

    public int find(int p) {
        while (p != id[p]) p = id[p];
        return p;
    }

    public void union(int p, int q) {
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) {
            return;
        } else {
            id[pRoot] = qRoot;
            amount--;
        }
    }

}
