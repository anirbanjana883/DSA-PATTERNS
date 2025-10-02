leetcode 1245  diameter of an undirected graph

https://youtu.be/na3LE8CBYLo?si=HkLTJaXYSxtGbRWt

diameter-no of edges in the longest path between any two nodes in the graph

##########  one fact :::-
if youi choose a random node (u) and find the farthest node (v)
from u then this node (v) will always be the one end of the diameter of the graph

another obvious fact is that -> the fartest node from one end of the 
diameter is the ather end of the diameter 

see how much the problem become easier 
so conclusion  
1. so if you pick any node(U) and find fartest node from
   it(let B) then it(B) must be one end of the diameter
2. now if you find the farthest node from (B) then you will find the 
   another end of diameter

## finding fartest node form any node
   we will do BFS and keep a track of the last node  

since it is a leetcode premium a similaar problem of 
it harder version 
3203. Find Minimum Diameter After Merging Two Trees