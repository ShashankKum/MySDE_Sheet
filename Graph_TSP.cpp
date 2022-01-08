//Travelling Salesman problem : Traverse all cities from a particular city and than return back to the same city using minimum cost.

It is a NP HARD problem so there is no particular solution of this problem, in brute force we can travel all the paths using recursion and than choose the path which gives 
the minimum cost.

But we can solve it using dynamic problem keeping in mind that minimum distance from node A to node B is the direct distance between node A and node B, and not 
dist(A->k)+dist(B->k).But it is not true for all the cases but as it is NP HARD we need to keep this approximation.

So to do this we will take 1 as starting node and do a mst for the same using prims and than add 1 to the sequence obtained as we again need to reach back to the same node 
after travelling to all nodes.