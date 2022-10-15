public class treeNode<T>{
    T data;
    ArrayList<treeNode<T>> child;

    treeNode(T data){
        this.data= data;
        child= new ArrayList<>();
    }
}

public class BinaryTreeNode<T> {
    T data;
    BinaryTreeNode<T> left;
    BinaryTreeNode<T> right;
}

public class triple<V,T,S> {
    public V first;
    public T second;
    public S third;
}

import java.util.Scanner;
import java.util.*;

public class treeUse {
    public static treeNode<Integer> takeInput(Scanner sc){
        int n;

        System.out.println("Enter the node data: ");
        n= sc.nextInt();
        treeNode<Integer> root= new treeNode<>(n);
        System.out.println("Enter the no. of children: ");
        int childCount= sc.nextInt();
        for (int i=0; i<childCount; i++){
            treeNode<Integer> node= takeInput(sc);
            root.child.add(node);
        }
        return root;
    }

    public static void print(treeNode<Integer> root){
        String s= root.data +": ";
        for(int i=0; i<root.child.size(); i++){
            s= s+ root.child.get(i).data +",";
        }
        System.out.println(s);
        for(int i=0; i<root.child.size(); i++){
            print(root.child.get(i));
        }
        return;
    }

    public static treeNode<Integer> takeInputLevelWise(){
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the root node data: ");
        int n= sc.nextInt();
        treeNode<Integer> root= new treeNode<>(n);
        Queue<treeNode> pendingNode= new LinkedList<>();
        pendingNode.add(root);
        while(!pendingNode.isEmpty()){
            treeNode<Integer> frontNode= pendingNode.poll();
            System.out.println("Enter the no. of child of " + frontNode.data);
            int childCount= sc.nextInt();
            for(int i=0; i<childCount; i++){
                System.out.println("Enter "+ (i+1)+"th element of "+ frontNode.data);
                int child= sc.nextInt();
                treeNode<Integer> childNode= new treeNode<>(child);
                pendingNode.add(childNode);
                frontNode.child.add(childNode);
            }
        }
        return root;
    }

    public static void printLevelWise(treeNode<Integer> root){

        Queue<treeNode> pendingNode= new LinkedList<>();
        pendingNode.add(root);
        while(!pendingNode.isEmpty()){
            treeNode<Integer> frontNode= pendingNode.poll();
            String s= frontNode.data +": ";
            for(int i=0; i<frontNode.child.size(); i++){
                s= s+ frontNode.child.get(i).data+ ", ";
                pendingNode.add(frontNode.child.get(i));
            }
            System.out.println(s);
        }
        return;


    }

    public static triple<Boolean, Integer, Integer> isBST(BinaryTreeNode<Integer> root){
        if(root==null){
            triple<Boolean, Integer, Integer> output= new triple<>();
            output.first= true;
            output.second= Integer.MAX_VALUE;
            output.third= Integer.MIN_VALUE;
            return output;
        }
        triple<Boolean, Integer, Integer> outputLeft= isBST(root.left);
        triple<Boolean, Integer, Integer> outputRight= isBST(root.right);
        int min= Math.min(root.data, Math.min(outputLeft.second, outputRight.second));
        int max= Math.max(root.data, Math.max(outputLeft.third, outputRight.third));
        boolean isBST= (root.data> outputLeft.third) && (root.data< outputRight.second) && outputLeft.first && outputRight.first;

        triple<Boolean, Integer, Integer> output= new triple<>();
        output.first= isBST;
        output.second= min;
        output.third= max;
        return output;

    }

    public static void main(String[] args) {
//        Scanner sc= new Scanner(System.in);
//        treeNode<Integer> root= takeInput(sc);
//        print(root);
        treeNode<Integer> root= takeInputLevelWise();
        printLevelWise(root);

//        treeNode<Integer> root= new treeNode<>(4);
//        treeNode<Integer> node1= new treeNode<>(7);
//        treeNode<Integer> node2= new treeNode<>(6);
//        treeNode<Integer> node3= new treeNode<>(5);
//        treeNode<Integer> node4= new treeNode<>(8);
//
//        root.child.add(node1);
//        root.child.add(node2);
//        root.child.add(node3);
//
//        node1.child.add(node4);

    }

}



