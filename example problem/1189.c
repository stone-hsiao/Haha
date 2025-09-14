#include<stdio.h>
#include<string.h>
//#define n 3

int main(int argc, char *argv[]) {

	int i;
	int MaxVal = 0; //�ثe�w���̤j��
	int MaxPos = 0; //�ثe�w���̤j�Ȫ���m 
	int n;
	
	scanf("%d", &n);
	int score[n];
	
	double sum=0;
	double aver;
	
	for(i=0;i<n;i++){
		scanf("%d", &score[i]);
	}
	
	for(i=0;i<n;i++){
		sum+=score[i];
	}
	
	aver=sum/n;
	
	printf("avg = %.2f\n", aver);
	printf("fail:\n");
	
	for(i=0;i<n;i++){
		if(score[i]<60){
			printf("%d: %d\n", i+1,score[i]);
		}
	}
	
	printf("highest:\n");
	
	for(i=0;i<n;i++){
		if(score[i]>MaxVal){
			MaxVal=score[i];
			MaxPos=i;
		}
	}
	
	printf("%d: %d\n", MaxPos+1,MaxVal);
	
	return 0;
}


