public class avl {

    public static void main(final String[] args) {
        Node root=null;
        for(int i=1;i<=20;i++){
            root=addData(root, i*10);

        }
        display(root);

    }

    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

        int height = -1;
        int bal = 0;

        Node(final int data, final Node left, final Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public static void display(final Node node) {
        if (node == null)
            return;
        String str = "";

        str += node.left == null ? "." : node.left.data;
        str += " -> " + node.data + " <- ";
        str += node.right == null ? "." : node.right.data;
        System.out.println(str);

        display(node.left);
        display(node.right);
    }

    public static void updateHeight_balance(final Node node) {
        int lh = -1;
        int rh = -1;

        if (node.left != null)
            lh = node.left.height;
        if (node.right != null)
            rh = node.right.height;

        node.height = Math.max(lh, rh) + 1;
        node.bal = lh - rh;
    }

    // ll_rot
    public static Node ll(final Node x) {
        final Node y = x.left;
        final Node yKaRight = y.right;

        y.right = x;
        x.left = yKaRight;

        updateHeight_balance(x);
        updateHeight_balance(y);

        return y;
    }

    public static Node rr(final Node x) {
        final Node y = x.right;
        final Node yKaLeft = y.left;

        y.left = x;
        x.right = yKaLeft;

        updateHeight_balance(x);
        updateHeight_balance(y);

        return y;
    }

    public static Node getRotate(final Node node) {
        updateHeight_balance(node);
        if (node.bal == 2) { // ll,lr
            if (node.left.bal == 1) { // ll
                return ll(node);
            } else { // lr
                node.left = rr(node.left);
                return ll(node);
            }
        } else if (node.bal == -2) { // rr,rl
            if (node.right.bal == -1) { // rr
                return rr(node);
            } else { // rl
                node.right = ll(node.right);
                return rr(node);
            }
        }

        
        return node;
    }

    public static Node addData(Node root, final int data) {
        if (root == null) {
            final Node node = new Node(data, null, null);
            return node;
        }

        if (data < root.data) {
            root.left = addData(root.left, data);
        } else {
            root.right = addData(root.right, data);
        }
        root=getRotate(root);
        return root;
    }

    public static int findMaxInBST(final Node node) {
        Node rnode = node;
        while (rnode.right != null) {
            rnode = rnode.right;
        }

        return rnode.data;

    }

    public static Node removeData(Node node, final int data) {
        if (data < node.data) {
            node.left = removeData(node.left, data);
        } 
        
        else if (data > node.data) {
            node.right = removeData(node.right, data);
        } 
        
        else {
            
            if (node.left == null || node.right == null) {
                return node.left == null ? node.right : node.left;
            }

            final int rdata = findMaxInBST(node.left);
            node.data = rdata;

            node.left = removeData(node.left, rdata);
        }
        node=getRotate(node);
        return node;
    }


}