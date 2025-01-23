#include <iostream>
#include <string>

using namespace std;

int nodeCount = 5; // Number of nodes
string *nodeData; // Array to store node names
int **edgeData; // 2D array to store edge weights
bool matrixCheck = false; // Flag to check if matrix is created
int currentIndex, currentNode, startNode, endNode, currentDistance, oldDistance, newDistance;
int visited = 1; // Flag for visited nodes
int notVisited = 0; // Flag for not visited nodes
int *knownDistance; // Array to store known shortest distances
int *visits; // Array to store visit status of nodes
int *predecessors; // Array to store predecessors of nodes

void createMatrix(){
    nodeData = new string[nodeCount]; // Allocate memory for node names
    edgeData = new int*[nodeCount]; // Allocate memory for edges
    edgeData[0] = new int[nodeCount * nodeCount]; // Create a continuous block of memory

    for(int i = 1; i < nodeCount; i++){
        edgeData[i] = edgeData[i-1] + nodeCount; // Assign row pointers
    }

    cout << "Please enter the names of the nodes" << endl;
    for(int i = 0; i < nodeCount; i++){
        cout << "City " << i+1 << " : ";
        cin >> nodeData[i]; // Read node names
    }

    cout << "Please enter the weights between nodes" << endl;
    for(int row = 0; row < nodeCount; row++){
        for(int col = 0; col < nodeCount; col++){
            cout << nodeData[row] << " --> " << nodeData[col] << " : ";
            cin >> edgeData[row][col]; // Read edge weights
        }
    }
    matrixCheck = true; // Set the flag indicating matrix creation is complete
}

void calculateShortestDistance(){
    if(matrixCheck){
        knownDistance = new int[nodeCount]; // Allocate memory for known distances
        visits = new int[nodeCount]; // Allocate memory for visit status
        predecessors = new int[nodeCount]; // Allocate memory for predecessors

        for(int i = 0; i < nodeCount; i++){
            knownDistance[i] = 999; // Set initial distances to infinity
            visits[i] = notVisited; // Mark all nodes as not visited
            predecessors[i] = -1;
        }

        visits[startNode] = visited; // Mark start node as visited
        knownDistance[startNode] = 0; // Distance to start node is zero
        currentNode = startNode; // Initialize current node

        while(currentNode != endNode){
            oldDistance = 999; // Set old distance to infinity
            currentDistance = knownDistance[currentNode]; // Get current distance
            for(int i = 0; i < nodeCount; i++){
                if(visits[i] == notVisited){
                    newDistance = currentDistance + edgeData[currentNode][i]; // Calculate new distance
                    if(newDistance < knownDistance[i]){
                        knownDistance[i] = newDistance; // Update known distance if new distance is shorter
                        predecessors[i] = currentDistance;
                    }
                    if(knownDistance[i] < oldDistance){
                        oldDistance = knownDistance[i]; // Update old distance
                        currentIndex = i; // Update current index
                    }
                }
            }
            currentNode = currentIndex; // Move to the next node
            visits[currentNode] = visited; // Mark the current node as visited
        }
        cout << "The shortest distance from " << nodeData[startNode] << " to " << nodeData[endNode] << " is " << knownDistance[endNode] << endl;

        //print the shortest path
        int path[nodeCount];
        int pathlength = 0;
        for(int v = endNode; v != -1; v = predecessors[v]){
            path[pathlength++] = v;
        }
        cout << "The path is: ";
        for(int i = pathlength - 1; i >= 0 ; i--){
            cout << nodeData[path[i]];
            if (i > 0) {
                cout << " -> " ;
            }
        }
        cout << endl;

        delete[] knownDistance; // Free memory
        delete[] visits; // Free memory
        delete[] predecessors; //free memory
    }
}

void displayMatrix(){
    if(matrixCheck){
        for(int i = 0; i < nodeCount; i++){
            cout << nodeData[i] << " "; // Display node names
        }
        cout << endl;
        for(int row = 0; row < nodeCount; row++){
            for(int col = 0; col < nodeCount; col++){
                cout << edgeData[row][col] << " "; // Display edge weights
            }
            cout << endl;
        }
    }else{
        cout << "No matrix available" << endl;
    }
}

int main(){
    char exit; 
    cout << "Please enter the number of cities (number) : ";
    cin >> nodeCount; // Read the number of nodes
    createMatrix(); // Create the adjacency matrix
    displayMatrix(); // Display the adjacency matrix

    do{
        cout << "Please enter the start node (0 - " << nodeCount-1 << ") : ";
        cin >> startNode; // Read the start node
        cout << "Please enter the end node (0 - " << nodeCount-1 << ") : ";
        cin >> endNode; // Read the end node
        calculateShortestDistance(); // Calculate the shortest distance

        cout << endl << endl;
        cout << "Exit (y/n) ? : ";
        cin >> exit; // Read the exit choice

        if(tolower(exit) != 'y'){
            system("cls"); // Clear the screen (works on Windows)
        }
    }while(tolower(exit) != 'y');

return 0;
}