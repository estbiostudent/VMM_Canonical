#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define Nnodes 10000                           //the maximum number of nodes in the network
#define BA_degree 2                         //the maximum degree of each node when added to the network
#define Nedges Nnodes*BA_degree-2   //the total number of edges in the network


#define directedGraph   //if defined, edges point in one way or the other depending on the "directed" parameter in the struct.
//#define weightedGraph   //if defined, edges are weighted as defined in the "weight" and "strength" struct parameters

struct edgeStruct{
    int start[Nedges];
    int end[Nedges];
#ifdef directedGraph
    int twoWay[Nedges];
#endif
#ifdef weightedGraph
    double weight[Nedges];
#endif
}
edgeStruct;

//if directed, nodes have in degrees and out degrees.
//if weighted, nodes have both degrees and strengths.

struct nodeStruct{
    int deg[Nnodes];		//this is the number of lines connected to a node.  This is _not_ the same as in+out degrees in a directed graph
#ifdef weightedGraph
    double strength[Nnodes];		//this is the sum of the in+out weights, divided by two.
#endif

#ifdef directedGraph
    int inDeg[Nnodes];		//for a directed graph, this is the in-degree
    int outDeg[Nnodes];		//and out degree
#ifdef weightedGraph
    double inStrength[Nnodes];	//and in strength
    double outStrength[Nnodes];	//and out strength
#endif
#endif


	//these are pecific to the project with Dervis Can Vural

	double neededSupply[Nnodes];		//this is the supply requirement of each node.
    double providedSupply[Nnodes];		//this is the supply of each nodes.

								//if node i is connected to at least supply[i] alive nodes, it remains alive
	int status[Nnodes];			//1=alive, 0=dead
    int timeOfDeath[Nnodes];
	int wasResurrected[Nnodes];
	int ressurectTime[Nnodes];
}
nodeStruct;

int importance[Nnodes];		//which node will kill the largest fraction of the network as a function of time?
int oldStatus[Nnodes];
int MostImportant[Nnodes][Nnodes];

int fedBy[Nnodes];




int i,j,k,l,m,n,M,N,seed;

struct edgeStruct edges;
struct nodeStruct nodes;


double q;		//minimum fraction nearest neighbors required to remain alive


FILE *f1,*f2,*f3;
char fn1[120],fn2[120],fn3[120];
