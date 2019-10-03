bool isSafe(vector<vector<char>> A,int i ,int j,char val){
    int count=0;
    for(int k=0;k<9;k++){
        if(A[k][j]==val && count)return 0;
        if(A[k][j]==val)count++;
    }
    count=0;
    for(int k =0;k<9;k++){
        if(A[i][k]==val && count)return 0;
        if(A[i][k]==val)count++;
    }
    int x=(i/3+1)*3,y=(j/3+1)*3;
    int k=(i/3)*3 ,l=(j/3)*3;
    
    count=0;
    for(;k<x;k++){
        for(l=(j/3)*3;l<y;l++){
            if(A[k][l]==val && count)return 0;
            if(A[k][l]==val)count++;
        }
    }

    return true;
}
bool helper(vector<vector<char>>&A,int i ,int j){
    // cout<<i<<j<<endl;
    if(i==9){return true;}
    if(A[i][j]=='.'){
        // vector<vector<char>> c=cur;
        for(int k=1;k<10;k++){
            A[i][j]=char(k+'0');
            if(isSafe(A,i,j,char(k+'0')) && helper(A,i,j+1)){return true;}
            else{A[i][j]='.';}
        }
        return false;
    }
    else{
        if(j<8)return helper(A,i,j+1);
        else{return helper(A,i+1,0);}
    }
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    helper(A,0,0);
}
