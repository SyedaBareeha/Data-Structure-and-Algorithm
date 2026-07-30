#include<iostream>
#include<cstdlib>
using namespace std;

bool mat[8][8]; 
int gsize = 8;

struct queue{
	int data;
	queue* next;
}
*front = NULL , *rear = NULL;

void enqueue(int v){
	queue* ptr = (queue*)malloc(sizeof(queue));
	ptr->data = v;
	ptr->next = NULL;
	
	if(front==NULL){
		rear = ptr;
		front = ptr;
		return;
	}
	else{
		rear->next = ptr;
		rear = ptr;
		return;
	}
}

int dequeue(){
	int tmp = front->data;
	if(front->next == NULL){
		queue* t = front;
		front=NULL;
		free(t);
	}
	else{
		queue* t = front;
		front = front->next;
		free(t);
	}
	return tmp;
}


int stack[10];
int top=0;

void push(int value){
	stack[top++] = value;
}

int pop(){
	if(top==0){
		return 0;
	}
	return stack[--top];
}

void Dinsert(){
	int s, d;
	cout<<"enter source vertex (<=8) : ";		cin>>s;
	cout<<endl<<"enter destination vertex (<=8) : ";	cin>>d;
	s--; d--;
	if((s<gsize && s>=0) && (d<gsize && d>=0)){
		mat[s][d] = 1;
		cout<<"inserted succesfully"<<endl;
	}
	else{
		cout<<"invalid vertex"<<endl;
	}
}

void printPath(){
	cout<<"path : ";
	int arr[8];
	int i=0;
	while(top != 0){
		arr[i] = pop()+1;
		i++;
	}
	i--;
	for(; i>=0; i--){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void path(){
	int s, d, j = 0;
	bool flag;
	cout<<"enter source vertex (<=8) : ";		cin>>s;
	cout<<endl<<"enter destination vertex (<=8) : ";	cin>>d;
	s--; d--;
	
	for( ; s < gsize && s >= 0; ){
		push(s);
		if(s==d){
			break;
		}
		for( ; j<gsize; j++){
			flag=false;	
			if(mat[s][j] == 1){
				
				cout<<j<<" ";
				for(int k=top-1; k>=0; k--){
					if(stack[k] == j){
						flag = true;
						
						break;
					}
				}
				if(flag == true){	continue;}
				s = j;
				break;
			}
		}
		if(j != gsize){
			j = 0;
		}
		else{
			j = pop() + 1;
			if(top != 0)	s = pop();
			else	break;
		}
	}
	
	if(top == 0){					// if path not exist
		cout<<"path not exist"<<endl;
	}
	else{							// path print
		printPath();
	}
}

void cycle(){
	int s, d, j = 0;
	bool flag;
	cout<<"enter vertex for cycle (<=8) : ";	cin>>s;
	s--;
	d=s;
	
	for( ; s < gsize && s >= 0; ){
		push(s);
		if(s==d && top>1){
			break;
		}
		for( ; j<gsize; j++){
			flag=false;	
			if(mat[s][j] == 1){
		//		if(top>=2 && stack[top - 2] == j) continue;		//avoid to again go to prev source for undir 121 x
				//this line is only for undirected not for directed, abh undir incomplete h iski wjha se
				
				for(int k=top-1; k>=0; k--){
					if(stack[k] == j && j!=d){
						flag = true;
						break;
					}
				}
				if(flag == true){	continue;}
				s = j;
				break;
			}
		}
		if(j != gsize)	j = 0;
		else{
			j = pop() + 1;
			if(top != 0)	s = pop();
			else	break;
		}
	}
	if(top == 0)	cout<<"cycle not exist"<<endl;		// if cycle not exist
	else	printPath();								// cycle print
}

void DdegOfVertex(){
	int ver, in = 0, out = 0;
	cout<<"enter vertex for degree: ";
	cin>>ver;
	ver--;
	for(int i=0; i<gsize; i++){
		if(mat[i][ver] != 0){	//column fix
			in++;
		}
	}
	cout<<"in degree: "<<in<<endl;
	
	for(int j=0; j<gsize; j++){
		if(mat[ver][j] != 0){	//row fix
			out++;
		}
	}
	cout<<"out degree: "<<out<<endl;
	
	cout<<"total degree: "<< (in+out) <<endl;
}

void UDinsert(){
	int s, d;
	cout<<"enter source vertex (<=8) : ";		cin>>s;
	cout<<endl<<"enter destination vertex (<=8) : ";	cin>>d;
	s--; d--;
	if(s < gsize && d < gsize){
		mat[s][d] = 1;
		mat[d][s] = 1;
		cout<<"inserted succesfully"<<endl;
	}
	else{
		cout<<"invalid vertex"<<endl;
	}
}

void UDdegOfVertex(){
	int ver, deg = 0;
	cout<<"enter vertex for degree: ";
	cin>>ver;
	ver--;
	for(int i=0; i<gsize; i++){
		if(mat[i][ver] != 0){
			deg++;
		}
	}
	cout<<"total degree: "<<deg<<endl;
}

void dfsMatrix(){			// full graph triverse path for matrix from single vertex.
	int s, i=0, j = 0;
	int arr[10];
	bool flag;
	cout<<"enter source vertex (<=8) : ";		cin>>s;
	s--;
	arr[i++] = s;
	for( ; s < gsize && s >= 0; ){
		push(s);
		for( ; j<gsize; j++){
			flag=false;	
			if(mat[s][j] == 1){
				for(int k=0; k < i; k++){
					if(arr[k] == j){
						flag = true;
						break;
					}
				}
				if(flag == true){	continue;}
				s = j;
				arr[i++] = s;
				break;
			}
		}
		if(j != gsize)	j = 0;
		else{
			j = pop() + 1;
			if(top != 0)	s = pop();
			else	break;
		}
	}
	cout<<"dfs: ";
	for(int k=0; k<i; k++){
		cout<<arr[k]+1<<" ";
	}
	cout<<endl;
}

void bfsMatrix(){
	int s, i=0;
	int arr[10];

	cout<<"enter source vertex (<=8) : ";		cin>>s;
	s--;
	arr[i++] = s;
	enqueue(s);
	while(front!=NULL){
		
		s = dequeue();
		
		for(int j = 0; j<gsize; j++){
			bool flag=false;
			if(mat[s][j] == 1){
				for( int k=0; k<i; k++){
					if(arr[k] == j){
						flag = true;
						break;
					}
				}
				if(flag == true){	continue;}
				enqueue(j);
				arr[i++] = j;
			}
		}
	}
	cout<<"bfs: ";
	for(int k=0; k<i; k++){
		cout<<arr[k]+1<<" ";
	}
	cout<<endl;
}

void print(){
	
	cout<<"your graph: "<<endl;
	
	for(int i = 0; i < gsize; i++) {
		for(int j = 0; j < gsize; j++) {
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	
	int choice;

//	mat[0][1]=1;
//	mat[0][2]=1;
//	mat[1][3]=1;
//	mat[3][4]=1;
//	mat[4][5]=1;
//	mat[3][6]=1;
//	mat[2][7]=1;
//	mat[6][2]=1;
//	mat[3][2]=1;
//	mat[2][3]=1;
//	print();
//	while(true){
//		cout<<"choice: ";
//		cin>>choice;
//		if(choice == 2){
//			bfsMatrix();
//		}
//		else break;
//	}

	cout<<"MENU: DIRECTED	UNDIRECTED"<<endl;
	cin>>choice;
	if(choice==1){
	while(true){
			int ch;
			cout<<"1. insert	2. path		3. cycle	4. degree of vertex		5. dfsgraph		6. bfsgraph 	7.print"<<endl;
			cin>>ch;
			if(ch!=0){
			switch(ch){
				case 1: Dinsert();	break;
				case 2: path();	break;
				case 3: cycle();	break;
				case 4: DdegOfVertex();	break;
				case 5: dfsMatrix();	break;
				case 6: bfsMatrix();	break;
				case 7: print();	break;
				default : cout<<"invalid choice";
			}
		  }
		  else break;
		}
	}
	else if(choice == 2){
		while(true){
		int ch;
		cout<<"1. insert	2. path		3. cycle	4. degree of vertex		5. dfsgraph		6. bfsgraph		7. print"<<endl;
		cin>>ch;
		if(ch!=0){
			switch(ch){
				case 1: UDinsert();	break;
				case 2: path();	break;
				case 3: cycle();	break;
				case 4: UDdegOfVertex();	break;
				case 5: dfsMatrix();	break;
				case 6: bfsMatrix();	break;
				case 7: print();	break;
				default : cout<<"invalid choice";
			}
		}
		else	break;
	}
}
else cout<<"invalid graph choice";

}