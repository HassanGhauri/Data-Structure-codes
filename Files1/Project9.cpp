#include <iostream>
using namespace std;

class Graph {
   private:
  int** adjMatrix;
  int numVertices;

   public:
  // Initialize the matrix to zero
  Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++) {
      adjMatrix[i] = new int[numVertices];
      for (int j = 0; j < numVertices; j++)
        adjMatrix[i][j] = false;
    }
  }

  // Add edges
  void addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
  }

  // Remove edges
  void removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
  }

  // Print the martix
  void toString() {
    for (int i = 0; i < numVertices; i++) {
      cout << i << " : ";
      for (int j = 0; j < numVertices; j++)
        cout << adjMatrix[i][j] << " ";
      cout << "\n";
    }
  }
  // to check edges between vertices
  void chechEdge(int i, int j){
    if(adjMatrix[i][j] == 1){
      cout<< "There exits an edge between vertices "<< i << " and " << j<<endl;
    }
    else{
      cout<<"there is no edge!"<<endl;
    }
  }
};


int main() {
  Graph g(4);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.toString();
  g.chechEdge(0,2);
  return 0;
}