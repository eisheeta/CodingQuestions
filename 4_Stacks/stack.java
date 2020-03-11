import java.util.Scanner;

public class stack{

    public class stack{
        private int[] arr;
        private int size=0;
        private int index =-1;
        
        public void push(int num){
            if(index == -1){
                arr[0] = num;
                index ++;
            }

            else if(index >= size){
                System.out.print("Stack is full!");
            }

            else {
                index++;
                arr[index] = num;
        
            }
        }

        public stack(){
            arr = new int[10];
            System.out.println("Object created");
        }

        public stack(int size){
            this.size = size;
            arr = new int[size];
        }

        public int top(){
            return arr[index];
        }

        public int size(){
            return this.size;
        }

        public boolean isEmpty(){
            return (this.size == 0);
        } 
        
        public void pop(){
            arr[index] = null;
            index --;
        }
    }

    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args){
        //System.out.print("Hello");
    }


}