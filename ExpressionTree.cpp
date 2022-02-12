#include <iostream>
#include <stack>
#include <string>

using namespace std;

class treeNode{
    public: 
        char info;
        treeNode *left, *right;
        treeNode(char el,treeNode *l,treeNode *r){
            info = el; left = l; right = r;
        }
        treeNode(){
            left = right = 0;
        }
};

void printStack(stack<char> a);
treeNode* buildTree(stack<char>a);
int isOperator(char a);
int isNumber(char a);
int isParen(char a);
void printTree(treeNode* root, int s);
int calculateSum(treeNode* root);
int toInt(char a);


int main(){
    string input = "(3 + ((5 + 9) * 2))";
    input.erase(std::remove (input.begin(), input.end(), ' '), input.end()); //removes whitespace
    stack<char> arith_exp;
    //parsing loop - could be its own function, but I didn't wanna break the code after getting it to work
    for(int i = 0; input[i] != 0; i++){
        string temp = "";
        if(input[i]=='('){
            temp.append("(");
            int j = i+1;
            int control = 1;
            int x = 0;
            int safety = 0;
            do{
                if(input[j]=='('){
                    control++;
                    if(x==0){
                        temp.append("X");
                        x++;
                    }
                }
                if(input[j]==')'){
                    control--;
                    if(control == 0){
                        temp.append(")");
                    }
                }
                if(control == 1&&input[j]!=')'){
                    temp.append(string(1,input[j]));
                }
                if(safety>200){
                    break;
                }
                j++;
                safety++;
            } while(control != 0);
            //STACK BUILDING:
            for(int a = 0; a<temp.length();a++){
                arith_exp.push(temp[a]);
            }
        }
    }

    printStack(arith_exp); //prints stack
    //build tree:
    treeNode *root = buildTree(arith_exp); 
    //print Tree to terminal:
    cout<<"HORIZONTAL EXPRESSION TREE: "<<endl;
    printTree(root,0);
    //Calculate sum of expression tree:
    cout<<"The sum of the expression tree is: "<<calculateSum(root)<<endl;
    return 0;
}

int isParen(char a){
    if(a=='('|| a==')'){ //could be expanded for more operators
        return 1;
    } else {
        return 0;
    }
}

int isOperator(char a){
    if(a=='+'|| a=='*'){ //could be expanded for more operators
        return 1;
    } else {
        return 0;
    }
}
int isNumber(char a){
    switch(a){
        case '0':
            return 1;
        case '1':
            return 1;
        case '2':
            return 1;
        case '3':
            return 1;
        case '4':
            return 1;
        case '5':
            return 1;
        case '6':
            return 1;
        case '7':
            return 1;
        case '8':
            return 1;
        case '9':
            return 1;
        default: 
            return 0;
    }
}

void printStack(stack<char> a){
    cout<<"STACK: "<<endl;
    stack<char> temp = a;
    while(!temp.empty()){
        cout<<temp.top()<<endl;
        temp.pop();
    }
}

treeNode* buildTree(stack<char> a){
    treeNode *root;
    treeNode *tempNode;
    treeNode *tempNode1;
    treeNode *parent;
    treeNode *right;
    treeNode *left;
    char previous;
    stack<char> temp = a;
    while(!temp.empty()){
        if(temp.top()== ')'){
            treeNode *right;
            treeNode *left;
            treeNode *parent;
        }
        if(isOperator(previous) && temp.top()!='X' && !isParen(temp.top())){
            left = new treeNode(temp.top(),NULL,NULL);
        }
        if(previous == ')' && temp.top()!='X' && !isParen(temp.top())){
            right = new treeNode(temp.top(),NULL,NULL);
        }
        
        if((isNumber(previous) || previous == 'X') && !isParen(temp.top())){
            parent = new treeNode(temp.top(),NULL,NULL);
            tempNode1 = tempNode;
            tempNode = parent;
    
        }
        if((isNumber(previous) || previous == 'X') && isParen(temp.top())){
            parent->left = left;
            parent->right = right;
        }
        if(temp.top()=='X'){ //x is placeholder for the parent of the last iteration's subtree
            if(previous == ')'){
                right = tempNode;
            } 
            if(isOperator(previous)){
                left = tempNode1;
            }
        }
        previous = temp.top();
        temp.pop();
        if(temp.empty()){
            root = parent;
        }
    }
    return root;
}

//Tree printing algorithm heavily influenced by: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void printTree(treeNode* root, int s){
    if(root==NULL){
        return;
    }
    s+=10;
    printTree(root->right,s);
    cout<<endl;
    for(int i = 10; i<s; i++){
        cout<<" ";
    }
    cout<<root->info<<endl;
    printTree(root->left, s);
}

int calculateSum(treeNode* root){
   if(!root){
       return 0;
   }
   if(!root->left&&!root->right){
       return toInt(root->info);
   }
   int left = calculateSum(root->left);
   int right = calculateSum(root->right);
   if(root->info=='+'){
       return left+right;
   }
   if(root->info=='*'){
       return left*right;
   }
   return left/right;
}

int toInt(char a){
    switch(a){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default: 
            return 0;
    }
}