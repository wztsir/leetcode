
struct node {
    int data;
    node* next;
};
int main(){
    node n;
    n.data = 2;
        for (int rooster = 0; rooster <= 33; ++rooster) {  
        for (int hen = 0; hen <= 33; ++hen) {  
            int chick = 100 - rooster - hen;  
            if ((rooster * 5 + hen * 3 + chick / 3) == 100) {  
                solutions.push_back({rooster, hen, chick});  
            }  
        }  
    }  
}