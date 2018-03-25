#include <stdio.h>
#include <string.h>
#define QSIZE 10001
int f;//front
int b;//back
int N;//command 횟수
char cmd[6]; //cmd error
int int_Q[QSIZE];
int val;
int size;

void enQ(int val);
int deQ();
int ret_back();
int ret_front();
int if_empty();

void enQ(int val){
	if((b+1) % QSIZE == f){//3개만 쓰겠다는 뜻
		printf("push error\n");
	}else{
		int_Q[b] = val;
		b = (b+1) % QSIZE;
		//printf("int_Q[b] = %d\n",int_Q[b]);
		//printf("b= %d\n",b);
		size++;
	}
}

int deQ(){
	if(if_empty()) return -1;//error
	else{
		int temp = int_Q[f];
		f = (f+1) % QSIZE;
		size--;
		return temp;
	}
}

int ret_front(){
	if( !if_empty() ) return int_Q[f];
	else return -1;
}

int ret_back(){
	if( !if_empty() ){ 
		//b가 0이면 b를 -1로 보내기 때문에 error
		if(b > 0) return int_Q[b-1];
		else{//b가 0인데 큐가 차있을 경우
			return int_Q[QSIZE - 1];
		}
	}
	else return -1;
}

int if_empty(){
	if(f == b) return 1;
	else return 0;
}

int main(void){
	//freopen("test.txt", "r", stdin);
	scanf("%d",&N);
	f = 0;
	b = 0;
	size = 0;
	for(int i = 0 ; i < N ; i++){
		scanf("%s",&cmd);
		if(!strcmp(cmd,"push")){
			scanf("%d",&val);
			enQ(val);
		}else if(!strcmp(cmd,"pop")){
			printf("%d\n",deQ());
		}else if(!strcmp(cmd,"size")){
			printf("%d\n",size);
		}else if(!strcmp(cmd,"empty")){
			printf("%d\n",if_empty());
		}else if(!strcmp(cmd,"front")){
			printf("%d\n",ret_front());
		}else if(!strcmp(cmd,"back")){
			printf("%d\n",ret_back());
		}else{
			;
		}
	}
}