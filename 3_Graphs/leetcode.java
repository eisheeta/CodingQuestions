//LEET CODE
//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.

import java.util.Scanner;
import java.util.ArrayList;
public class leetcode{

    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {

    }

    public static void surroundedRegions130(char[][] board){
        if(board == NULL || board.length == 0){
            return;
        }

        int n = board.length;
        int m = board[0].length;

        for(int i=0; i<n; i++){
            if(board[i][0]== "O"){
                mark(i, 0, board);
            }

            else if(board[i][m-1] == "O"){
                mark(i, m-1, board);
            }
        }


    }
}

