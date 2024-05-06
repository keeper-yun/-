#include <iostream>
#include <string>

using namespace std;



//preorder
void preorder(const char a[],int n,int root){
	if(root >= n || a[root] == ' ') return ;
	cout<<a[root];
	preorder(a,n,2*root+1);
	preorder(a,n,2*root+2);
}



int main() {
	
    //ABC DE   F  G
    
	string s1;
	getline(cin,s1);
	
    preorder(s1.c_str(),s1.length(),0);
    
    cout<<endl;

    return 0;
}

