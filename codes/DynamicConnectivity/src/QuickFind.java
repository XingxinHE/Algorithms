public class QuickFind extends UnionFindBase {

    public QuickFind() {
        super();
    }

    /*
     * find: the component id is the id itself. That's why it is called quick find
     */
    public int find(int p) {
        return id[p];
    }

    /*
     * union: find all the ids which contain obsolete id and then update
     */
    public void union(int p, int q) {
        int pId = find(p);
        int qId = find(q);
        if (pId == qId) {
            return;
        }
        for (int i = 0; i < length(); i++) {
            if (id[i] == pId) {
                id[i] = qId;
            }
        }
        amount--;
    }
}
