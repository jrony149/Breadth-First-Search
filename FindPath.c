//Name: Joshua Rony
//UserID: jrony
//Assignment Name: pa4

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<inttypes.h>

#include "Graph.h"


#define MAX 100




int main(int argc, char *argv[]){
	
	
	
	if(argc != 3){
		
		printf("%s", "Number of arguments must not be less than or greater than 2.\n");
		exit(1);
	}
	
	List pathList = newList();
	
	int v1 = 0;
	
	int v2 = 0;
	
	char input[MAX];
	
	int lineCount0 = 0;
	
	int lineCount1 = 0;
	
	int flag = 0;
	
	int order = 0;
	
	FILE *pToFile0 = fopen(argv[1], "r");
	
	while(fgets(input, MAX, pToFile0)){
		
		lineCount0++;
		
	}
	
	//printf("%s%d%s", "The number of lines in the file is: ", lineCount0, "\n");
	
	fclose(pToFile0);
	
	
	FILE *pToFile1 = fopen(argv[1], "r");
	
	FILE *pToFile2 = fopen(argv[2], "w");
	
	fgets(input, MAX, pToFile1);
	
	sscanf(input, "%d", &order);
	
	Graph myGraph = newGraph(order);
	
	//printf("%s%d", "The order of the graph is: ", getOrder(myGraph));
	
	
	
	
	
	while(fgets(input, MAX, pToFile1)){
		
		//lineCount0 = total number of lines in file
		
		//lineCount1  is the variable you're incrementing in the while loop.
		
		sscanf(input, "%d %d", &v1, &v2);
		
		if((v1 == 0 && v2 == 0)  && (lineCount1 < lineCount0)){
			
			flag = 1;
		}
		
		if((flag == 0) && (lineCount1 < lineCount0) && (v1 != 0 && v2 != 0)){
		
			addEdge(myGraph, v1, v2);
			
		}
		
		if(flag == 1 && (lineCount1 < lineCount0) && (v1 != 0 && v2 != 0)){
			
			BFS(myGraph, v1);
			
			getPath(pathList, myGraph, v2);
			
			//printGraph(pToFile2, myGraph);
			
			int destination = back(pathList);
	
			if(front(pathList) != getSource(myGraph)){
		
				fprintf(pToFile2, "%s%d%s%d%s\r\n", "The distance from ", getSource(myGraph), " to ", v2, " is infinity.");
		
				fprintf(pToFile2, "%s%d%s%d%s\r\n", "No ", getSource(myGraph), " - ", v2, " path exists.\n");
				
				
		
			}
	
			else if(front(pathList) == getSource(myGraph)){
	
				fprintf(pToFile2, "%s%d%s%d%s%d\r\n", "The distance from ", getSource(myGraph), " to ", destination, " is ", getDist(myGraph, destination));
		
				fprintf(pToFile2, "%s%d%s%d%s", "A shortest ", getSource(myGraph), " - ", destination, " path is: ");
		
				moveFront(pathList);
		
				for(int x = 0; x < length(pathList); x++){
			
					fprintf(pToFile2, "%d%s", get(pathList), " ");
			
					moveNext(pathList);
				}
		
				fprintf(pToFile2, "\r\n");
		
				fprintf(pToFile2, "\r\n");
		
			}
	
			clear(pathList);
			
		}
		
		lineCount1++;
		
		if(v1 == 0 && v2 == 0 && lineCount1 + 1 != lineCount0){
			
			printGraph(pToFile2, myGraph);
		}
		
		//printf("%s%d", "The lineCount1 variable is: ", lineCount1);
		
	}
	
	
	
	fclose(pToFile1);
	
	fclose(pToFile2);
	
	freeGraph(&myGraph);
	
	freeList(&pathList);
	
	
	
	
	
	
	
	
}

