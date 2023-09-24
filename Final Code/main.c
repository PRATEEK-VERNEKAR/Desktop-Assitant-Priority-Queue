#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<MMSystem.h>


#define MAX(a,b) (((a)>(b))? 1:((a)==(b))? 0 : -1);


struct heap{
    int arr[100];
    int size;
    int max_size;
};

void swap(int* a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void insert(struct heap* heapptr,int val){
    int par;
    heapptr->size+=1;
    int index=heapptr->size;
    heapptr->arr[index]=val;

    while(index>1){
        par=index/2;
        if(heapptr->arr[index]>heapptr->arr[par]){
            swap(&(heapptr->arr[index]),&(heapptr->arr[par]));
            index=par;
        }
        else{
            break;
        }
    }
}

void deletion(struct heap* heapptr){
    int leftnode,rightnode;
    int check;
    if(heapptr->size==0){
        printf("Nothing to delete\n");
    }
    else{                                                                           //Put last element into first node
        heapptr->arr[1]=heapptr->arr[heapptr->size];
        heapptr->size--;
        int i=1;
        while(i<=heapptr->size){
            leftnode=2*i;
            rightnode=2*i+1;

            if(heapptr->size==2){
                if(heapptr->arr[leftnode]>heapptr->arr[i]){
                    swap(&(heapptr->arr[i]),&(heapptr->arr[leftnode]));
                }
            }
            check=MAX(heapptr->arr[leftnode],heapptr->arr[rightnode]);

            if(leftnode <= heapptr->size && heapptr->arr[i]<heapptr->arr[leftnode]){
                if(check==1 || check==0){
                    swap(&(heapptr->arr[i]),&(heapptr->arr[leftnode]));
                    i=leftnode;
                }
                else{
                    swap(&(heapptr->arr[i]),&(heapptr->arr[rightnode]));
                    i=rightnode;
                }
            }
            else if(rightnode <= heapptr->size && heapptr->arr[i] < heapptr->arr[rightnode]){
                if(check==-1 || check==0){
                    swap(&(heapptr->arr[i]),&(heapptr->arr[rightnode]));
                    i=rightnode;
                }
                else{
                    swap(&(heapptr->arr[i]),&(heapptr->arr[leftnode]));
                    i=leftnode;
                }
            }
            else{
                return;
            }
        }
    }
}

void print(struct heap temp,int size){
    for(int i=1;i<=size;i++){
        printf("%d ",temp.arr[i]);
    }
    printf("\n");
}

void heapify(int arr[],int size, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=size && arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=size && arr[largest]<arr[right]){
        largest=right;
    }

    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,size,largest);
    }
}

void delay(int a){
    int add;
    int time;
    int i;

    time=a*1000000;

    for(i=0;i<time;i++){
        add*=i;
        add++;
        add++;
    }
}

void voicecallf(){
    char str[100];
    printf("\nEnter Your ID\n-> ");
    getchar();
    scanf("%[^\n]s",str);
    printf("\nEnter ID of the person you are trying to call\n-> ");
    getchar();
    scanf("%[^\n]s",str);
    printf("\nConnecting the call\n\n");

	PlaySound(TEXT("ring.wav"),NULL,SND_ASYNC);
    delay(1200);
	PlaySound(TEXT("Busy.wav"),NULL,SND_ASYNC);
	delay(600);
    printf("\nCall Ended\n");
}

void chromef(){
    printf("Opening Chrome\n\n");
    system("START www.google.com/");
    printf("Chrome Opened Successfully\n\n");
    return ;
}

void emailf(){
    char str[100];
    printf("\nEnter Senders Email-ID\n-> ");
    getchar();
    scanf("%[^\n]s",str);
    printf("\nEnter Recipients Email-ID\n-> ");
    getchar();
    scanf("%[^\n]s",str);
    printf("\nEnter Subject\n-> ");
    getchar();
    scanf("%[^\n]s",str);
    printf("\nEnter mail body\n-> ");
    getchar();
    scanf("%[^\n]s",str);
}

void paintf(){
    printf("Opening MS Paint\n\n");
    system("cmd /c mspaint");
    printf("MS-Paint Opened Successfully\n\n");
    return ;
}

void notepadf(){
    printf("Opening NotePad\n\n");
    system("cmd /c notepad");
    printf("Notepad Opened Successfully\n\n");
    return ;
}

void wordpadf(){
    printf("Opening WordPad\n\n");
    system("cmd /c write");
    printf("Wordpad Opened Successfully\n\n");
    return ;
}

void calculatorf(){
    printf("Opening Calculator\n\n");
    system("cmd /c calc");
    printf("Calculator Opened Successfully\n\n");
}

void whichdelete(int del){
    switch (del){
    case 1:
        printf("-->Removing Wordpad from CPU<--\n");
        break;
    case 2:
        printf("-->Removing Calculator from CPU<--\n");
        break;
    case 3:
        printf("-->Removing Notepad from CPU<--\n");
        break;
    case 4:
        printf("-->Removing Paint from CPU<--\n");
        break;
    case 5:
        printf("-->Removing Email from CPU<--\n");
        break;
    case 6:
        printf("-->Removing Chrome from CPU<--\n");
        break;
    case 7:
        printf("-->Removing Voicecall from CPU<--\n");
        break;
    }
}
void execute(struct heap *blueprint){
    int opclose;
    char signal[50];
    int del;

    while(1){
        printf("\n\nPriority Queue Size = %d\n",blueprint->size);
        struct heap tempst=*blueprint;

        print(tempst,blueprint->size);

        printf("\n\n");
        printf("\t\tPress 1 To Open New Tab(Case Sensitive)\n\t\tPress 0 To Close High Priority Tab\n");
        printf("\t\tAny other key will result in termination of the Job Scheduling\n");
        printf("--> ");
        scanf("%d",&opclose);
        switch(opclose){
            case 1:
                if(blueprint->size >= blueprint->max_size){
                    printf("\n\n\t\t!!!Job Schedule Exceeded!!!\n\n");
                    printf("\t\t**Removing Topmost Operation To Make Space**\n\t\t");
                    del=blueprint->arr[1];
                    whichdelete(del);
                    deletion(blueprint);
                }
                else{
                    printf("\nEnter Tab Name (Case Sensitive)\n");
                    printf("--> ");
                    scanf("%s",signal);
                    printf("\n\nYou selected %s\n\n",signal);
                    if(!(strcmp(signal,"Voicecall"))){
                        insert(blueprint,7);
                        voicecallf();
                    }
                    else if(!(strcmp(signal,"Chrome"))){
                        printf("Chrome\n");
                        insert(blueprint,6);
                        chromef();
                    }
                    else if(!(strcmp(signal,"Email"))){
                        insert(blueprint,5);
                        emailf();
                    }
                    else if(!(strcmp(signal,"Paint"))){
                        insert(blueprint,4);
                        paintf();
                    }
                    else if(!(strcmp(signal,"Notepad"))){
                        insert(blueprint,3);
                        notepadf();
                    }
                    else if(!(strcmp(signal,"Calculator"))){
                        insert(blueprint,2);
                        calculatorf();
                    }
                    else if(!(strcmp(signal,"Wordpad"))){
                        insert(blueprint,1);
                        wordpadf();
                    }
                    else{
                        printf("!!!***No such tab exists***!!!\n");
                    }
                }
                break;
            case 0:
                if(blueprint->size==0){
                    printf("\n\n**No opened tabs to remove**\n");
                }
                else{
                    printf("\n\t\tRemoving Topmost Operation\n\t\t");
                    del=blueprint->arr[1];
                    whichdelete(del);
                    deletion(blueprint);
                }
                break;
            default:
                printf("\t\t\t!!**Error Occured**!!\n\t\t\t**Closing Down the system**\n");
                exit(0);
        }

        printf("\n\n*********************************************************************************************\n\n");
    }
}

int main(){
    struct heap blueprint;
    blueprint.size=0;
    blueprint.max_size=7;


    printf("\n\n\t\t!!!!!!!!!!!!!!!!!!!WELCOME!!!!!!!!!!!!!!!!!!!");
    printf("\n\n\t\tYou can open 7 tab at a time\n");
    printf("\t\tIf more than 7 operations are queued then the topmost (topmost priority) will be eliminated\n");
    printf("\t\tClose the windows also via the code after closing then using \"Close\" button\n");


    printf("1)Wordpad\n");
    printf("2)Calculator\n");
    printf("3)Notepad\n");
    printf("4)Paint\n");
    printf("5)Email\n");
    printf("6)Chrome\n");
    printf("7)Voicecall\n");

    execute(&blueprint);

    return 0;
}
