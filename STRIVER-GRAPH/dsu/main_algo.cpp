DISJOINT set UNION
three completely different set
intersection of s1,s2,s3 is null

can be used in the question where no of component asked

DSU can  do two operation 1.combine two set (b,g)
                          2.tells if two sets (b,g) belong to same set or not
elements  a b c d e f g h
parent    a b c d e f g h  representator of each set

find if any two node are of same set or not --> if both have samee leader then they are of same set..                                                                                                                     
int find(int parent[],int X) // this can take o(logN) in worse case
{
       //add code here
       if(parent[X]==X) return X; // if X is root then return X
       return find(parent,parent[X]);
       
}
void unionSet(int parent[],int X,int Z)
{
	//add code here.
	// finding the parenys of x
	int xParent=find(parent,X);
	
		// finding the parenys of z
	int yParent=find(parent,Z);
	
	// maing anyons parent as leader
	if(xParent!=yParent){
	    parent[xParent]=yParent;
	}
}
****************dis-joint set union find using *rank and *path compression******************************

we will maintain a rank vector in which initially all element is zero 
and then which element is parent this elements rank will become increase
rank is used to balance the tree so that tree is as flat as possible 

optimised code

vector<int>parent;
vector<int>rank;
int find_parent(int X)
{
       //add code here
       if(parent[X]==X) return X;
       //insted of making a long chain we  are making one parent as
       //ultimate leadert for all the node
       return parent[X]=find_parent(parent[X]);
       
}
void unionSet(int X,int Z)
{

	parent.resize(n); // n will be given in thequestion
        rank.resize(n,0);
	//add code here.
	// finding the parenys of x
	int xParent=find_parent(X);
	
		// finding the parenys of z
	int yParent=find_parent(Z);

	// maing anyons parent as leader
	if(xParent==yParent){
	    return;
	   // whose rank is greater it will become the parent
	}else if(rank[xParent]<rank[yParent]){
	    parent[xParent]=yParent;
	    
	}else if(rank[xParent]>rank[yParent]){
	    parent[yParent]=xParent;
	    
	}else{
	   // bothn have same rank
	   //makew anyone parent and then inc. its rank
	   parent[xParent]=yParent;
	   //we have make yparent as partent
	   rank[yParent]++;
	}
}

https://leetcode.com/problem-list/5lhmb4mj/

examples  =>

990. Satisfiability of Equality Equations 
1319. Number of Operations to Make Network Connected
2316. Count Unreachable Pairs of Nodes in an Undirected Graph

****************dis-joint set union find using *size and *path compression******************************
here whose size will be greater it will become parent..

vector<int>parent;
vector<int>size;
int find(int A[],int x)
{
       //add code here
       if(parent[x]==x) return x;
       return parent[x]=find(A,parent[x]);
}
void unionSet(int A[],int x,int y)
{

    parent.resize(n); n will be the size of array (number of nodes)
    size.resize(n,0);
    //add code here.
    // find parent for x and y
    int x_parent=find(A,x);
    int y_parent=find(A,y);
	
	if(x_parent==y_parent) return;
	
	if(size[x_parent]>size[y_parent]){
	   parent[y_parent]=x_parent;
	   
	}else if(size[x_parent]<size[y_parent]){
	   parent[x_parent]=y_parent;
	   
	}else{
	    parent[x_parent]=y_parent;
	    size[y_parent]++;
	}
}