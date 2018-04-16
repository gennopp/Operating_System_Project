#include <stdio.h>

struct Process
{
	int p_id, burst_time, priority;	
};

void sort_priority_based(struct Process [], int);

int main(){
	int n, i=0, j;
	char ch;
	printf("Enter the total number of Processes:-  ");
	scanf("%d", &n);
	struct Process queue[n];
	//queue = (Process*)malloc(n*sizeof(Process));
	for(j=0;j<n;j++){
		queue[j].p_id = j+1;
		printf("\nEnter the Details of the process number %d", queue[j].p_id);
		printf("\nEnter the Burst time of the Process: ");
		scanf("%d", &(queue[j].burst_time));
		printf("\nEnter the priority of the Process: ((1) for teachers/(0) for students: ");
		scanf("%d", &(queue[j].priority));
	}

	sort_priority_based(queue, n);

	printf("\nProcessID		Burst Time 	     Priority");
	printf("\n**************************************************************");
	for(i=0;i<n;i++){
		printf("\n%d  				%d  		%d", queue[i].p_id, queue[i].burst_time, queue[i].priority);
	}

	get_average_time(queue, n);

	return 0;
}

void sort_priority_based(struct Process a[], int n){
	int i, j;
	struct Process temp;
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(a[j].priority < a[j+1].priority){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

