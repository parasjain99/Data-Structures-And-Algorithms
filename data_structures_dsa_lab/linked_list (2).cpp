#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
Node *head=NULL;
Node *start=NULL;

void display(Node *s){
    if(s==NULL) cout<<"List is Empty\n";
    while(s!=NULL){
        cout<<s->data<<"->";
        s = s->next;
    }
    cout<<endl;
}
void delN(Node *s){
    Node *temp;
    int x;
    cout<<"Enter index number\n";
    cin>>x;
    if(s==NULL){
        cout<<"List is Empty\n";
    }
    else if(x==0){
        temp = start;
        start=start->next;
        delete temp;
        cout<<"Deleted\n";
        if(start==NULL) cout<<"List is now empty\n";
    }
    else{
        for (int i = 0; i < x - 1; i++)
        {
            if (s->next == NULL)
            {
                cout << "Index out of range\n";
                return;
            }
            else
            {
                s = s->next;
            }
        }
        if (s->next == NULL)
        {
            cout << "Index out of range\n";
        }
        else
        {
            temp = s->next;
            s->next = temp->next;
            cout << "Deleted value " << temp->data << endl;
            delete temp;
        }
    }

}

void delV(Node *s){
    Node *temp;
    int x;
    cout<<"Enter value to be deleted\n";
    cin>>x;
    while(s!=NULL){
        if(start->data==x){
            temp=start;
            start=start->next;
            cout << "Deleted " << temp->data;
            cout<<endl;
            delete temp;
            s=start;
        }
        else if(s->data==x){
            temp->next = s->next;
            cout<<"Deleted "<<s->data;
            cout<<endl;
            delete s;
            s=temp->next;
        }
        else {
            temp = s;
            s=s->next;
        }
    }
}

void insert(Node *s){
    int x,val;
    Node *temp;
    cout<<"enter index and value ";
    cin>>x>>val;
    Node *nn= new Node();
    nn->data=val;
    if(start==NULL){
        start=nn;
    }
    else if(x==0){
        nn->next=start;
        start=nn;
        
    }
    else{
        for(int i=0;i<x-1;i++){
            if(s->next==NULL) break;
            else s=s->next;
        }
        nn->next=s->next;
        s->next=nn;
    }
    cout << "Inserted\n";
}

void empty(Node *s){
    while(start!=NULL){
        s=start;
        start=start->next;
        delete s;
    }
}

int length(Node *s){
    int count = 0;
    while(s!=NULL){
        s=s->next;
        count++;
    }
    // cout<<count<<endl;
    return count;
}

void find(Node *s){
    int x,pos=0;
    bool match=false;
    cout<<"Enter the element\n";
    cin>>x;
    while(s!=NULL){
        if(x==s->data){
            cout<<pos<<endl;
            match=true;
        }
        pos++;
        s=s->next;
    }
    if(match==false) cout<<"Not found\n";
}
void swap(Node *s){
    int x,y;
    Node *nx, *ny, *prev1=s, *prev2=s,*nxt1,*nxt2;
    cin>>x>>y;
    int l=length(s);
    if(x<l&&y<l&&x>0&&y>0){
        for(int i=0;i<x-1;i++) prev1=prev1->next;
        nx=prev1->next;
        nxt1=nx->next;
        for(int i=0;i<y-1;i++) prev2=prev2->next;
        ny=prev2->next;
        nxt2=ny->next;
        //swap
        prev1->next=ny;
        prev2->next=nx;
        ny->next=nxt1;
        nx->next=nxt2;
        cout<<"Done\n";
    }
    else if(x==0||y==0){
        if(x!=0){
            for (int i = 0; i < x - 1; i++)
                prev1 = prev1->next;
            nx = prev1->next;
            nxt1 = nx->next;
            ny=s;
            nxt2=ny->next;
            //swap
            head=nx;
            nx->next=nxt2;
            prev1->next=ny;
            ny->next=nxt1;
        }
        else if(y!=0){
            for (int i = 0; i < y - 1; i++)
                prev2 = prev2->next;
            ny = prev2->next;
            nxt2 = ny->next;
            nx=s;
            nxt1=nx->next;
            //swap
            head=ny;
            ny->next=nxt1;
            prev2->next=nx;
            nx->next=nxt2;
        }
    }
    else{
        cout<<"Fail! Index out of range\n";
    }
}

int main(){
    
    int n,x;
    cout<<"Enter number of nodes\n";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter node "<<i<<endl;
        cin>>x;
        Node *nn = new Node();
        nn->data = x;
        nn->next = NULL;
        if (i == 0){
            start = nn;
            head=nn;
        }
        else{
            head->next = nn;
            head = nn;
        }
        
    }
    Node *ptr = start;
    x=1;
    while(x){
        cout << "1 to display\n2 to delete a node\n3 to delete a value\n4 to insert a node\n5 to empty the list\n6 to find length \n7 to find an element\n8 To swap 2 nodes\n0 to exit\n";
        cin >> x;
        switch(x){
            case 0:{
                break;
            }
            case 1 :{
                display(start);
                break;
            }
            case 2: {
                delN(start);
                break;
            }
            case 3: {
                delV(start);
                break;
            }
            case 4: {
                insert(start);
                break;
            }
            case 5:{
                empty(start);
                break;
            }
            case 6:{
                cout<<length(start)<<endl;
                break;
            }
            case 7:{
                find(start);
                break;
            }
            case 8:{
                swap(start);//swap function not working properly
            }
            default : {
                cout<<"Enter a valid choice\n";
                break;
            }
        }
    }
}