// Created by wlk on 2019/7/20 22:11.
#include "BinaryTree.h"

int Comm_Ancestor(int T[],int i,int j){
    if(T[i]!='#'T[j]!='#')
    {
        while (i!=j)
        {
            if(i>j)
            {
                i=i/2;
            } else{
                j=j/2;
            }
        }
        return T[i];
    }
}

int main() {


    return 0;
}