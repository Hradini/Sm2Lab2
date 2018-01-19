#include <iostream>
using namespace std;

struct node{
	int data;
	node *next;
};

class list{
	node *head, *tail;
	public:
		//default constructor
		list(){
			head=NULL;
			tail=NULL;
		}
		//function to insert new node
		void insert(int value){
			node *temp = new node;
			temp->data= value; //assigns value to temp
			temp->next=NULL;//points temp to null
			if (head == NULL){
				head = temp;
				tail=temp;
			}else{
				tail->next=temp; //points last node to temp
				tail=temp;//points tail to temp
			}
		}
		//function to insert node at particular location
		void insert_pos(int pos, int value){
			node *cur=new node; 
			node *prev= new node;
			node *temp= new node;
			temp->data=value;
			temp->next=NULL;
			int i;
			cur=head;
			//finds the position where the node should be inserted 
			for(i=1;i<pos;i++)
			{
				if(cur==NULL){
					cout<<"Linked list does not have enough elements";
					i=pos+5;		
				}
				else
				{	
					prev=cur;
					cur=cur->next;	
				}
			}
		//checks if there is only one element in the linked list
		if(i==pos&&i==1){
		head=temp;
		temp->next=cur;
		}else if(i==pos&&i!=1){
			prev->next=temp;//points the prev node at temp
			temp->next=cur;//points temp to the cur node
			}
		}
		
		//function to delete node at the end
		void Delete(){
			node *cur=new node;
			node *prev= new node;
			cur=head;
			//traverses the linked list till the end
			while(cur->next!=NULL){
			prev=cur;
			cur=cur->next;			
			}
				prev->next=NULL; 
				tail=prev;//point tail at the last but one node
				delete cur;//delete the last node
				
		}
		//function to delete specific position
		void delete_pos(int pos){
			node *cur=new node;
			node *prev= new node;
			cur=head;
			int i;
			//look for the particular node
			for(i=1;i<pos; i++){
			prev=cur;
			cur=cur->next;	
			}
			prev->next=cur->next;//point prev node to node after
			delete cur;//delete the required node
		}
		//function to count items
		int countItems(){
			node *cur=new node;
			int i=0;
			cur =head;
			while(cur!=NULL){//traverse the list till end 
				cur=cur->next;
				++i;//keeps track of the number of nodes
			}
			return i;
		}
		//function to display all items in the list
		void display(){
			node*cur= new node;
			cur=head;
			//traverses the linked list and preint every data from the node
			while(cur!=NULL){
				cout<< cur->data << "-> ";
				cur=cur->next;
			}
				cout<< "NULL\n";
			}
		
		
};

int main(){
	list list1;
	list1.insert(32);
	list1.insert(45);
	list1.insert(65);
	list1.display();
	list1.insert_pos(2,89);
	list1.display();
	list1.insert_pos(6,9);
	list1.display();
	list1.Delete();
	list1.display();
	list1.delete_pos(3);
	list1.display();
	cout <<"the number of items on the list are " <<list1.countItems();
}

