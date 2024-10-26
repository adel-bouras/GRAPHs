#include <cstdio>
#include <iostream>
#include <vector>
#include <string>



// class for a single node on the graph and its propertys
class node{
		int nodeId; // the id of the a specific node
		std::vector<int> neighbors;
public:

	int getId(){
		return this->nodeId;
	}

	void setId(int i){
		this->nodeId = i;
	}

	void setVoisins(std::vector<int> v){
		this->neighbors = v;
	}

	std::vector<int> getVoisins(){
		return neighbors;
	}

	void displayVoisins(){
		printf("\n neighbors : \n");
		for(int n : this->neighbors){
			printf("%d ,", n);
		}
		printf("\n");
	}
};

// class for the hole graph and its properties
class graph{

  	int order; //order of the graph
  	std::string name; // name of the graph
  	std::vector<node> nodes; // the nodes included on the graph

public :
  	graph(int order , std::string name) : order(order) , name(name) , nodes({}){} // a simple constactor that initialize our graph

	
	int getOrder(){
		return this->order;
	} 

	void setName(std::string s){
		this->name = s;
	}

	std::string getName (){
		return this->name;
	}

	std::vector<node> getNodes(){
		return this->nodes;
	}
	
	// add a new node on our graph
	void setNewNode(node n ){	
		this->order++;
		this->nodes.push_back(n);
	}
	
	// printing our graph
	void displayGraph(){
		for(node n : nodes){
			std::cout<<"\nOur graph " << this->name<<" :\n"<<std::endl;
			printf("node %d, ",n.getId());
			n.displayVoisins();
			printf("\n");
		}
	}
};

int main(){

	//geting the number of nodes that we have in our graph
int n;
printf("Please set the number of nodes : ");
scanf("%d" , &n);

	//optional option : name of graph but essential in multigraph case :)
std::string s;
printf("Enter the name of your graph : ");
std::getline(std::cin,s);

//instatiate our graph and initialize propriety
graph g(n , s);
for (int i = 0; i < n; i++) {
	int id , id2; //id is the id (name) of our new node ; id2 its voisins ids (name)
	printf("Enter the id of the new node : ");
	scanf("%d" , &id);
	//number of nodes that are connected (neighbors) with the new nodes
	int neighbors;
	std::vector<int> vo; // vector of neighbors
	printf("Enter the number of the neighbors of the new node : ");
	scanf("%d" , &neighbors);
		for (int j = 0; j < neighbors; j++) {
			//looping on our new node's neighbors and add the ids of them in its neighbors array
			printf("Enter the id of the voisin node :");
			scanf("%d" , &id2); // this is the essential use of the id2 ;)
			vo.push_back(id2);
		}
	node newNode; //instatiate the new node and all its propriety
	newNode.setId(id); 
	newNode.setVoisins(vo);
	g.setNewNode(newNode);//set the new node to our graph
}

g.displayGraph();

return 0;
}
