#include <stdio.h>
#include <stdlib.h>

int n_resources;
int n_processes;

typedef struct
{
	int* resource;
}ResourceState;

ResourceState* getAllocationTable()
{
	if(n_processes<=0 || n_resources<=0) return NULL;

	int i,j;
	ResourceState* at = (ResourceState*) malloc(sizeof(ResourceState)*n_processes);
	printf("For each process, enter space separated allocation of resources...\n");
	for(i=0; i<n_processes; i++)
	{
		at[i].resource = (int*) malloc(sizeof(int)*n_resources);
		printf("P%d: ",i);
		for(j=0; j<n_resources; j++) scanf("%d",at[i].resource+j);
	}
	printf("\n");
	return at;
}
ResourceState* getMaxTable()
{
	if(n_processes<=0 || n_resources<=0) return NULL;

	int i,j;
	ResourceState* mt = (ResourceState*) malloc(sizeof(ResourceState)*n_processes);
	printf("For each process, enter space separated max required allocation of resources...\n");
	for(i=0; i<n_processes; i++)
	{
		mt[i].resource = (int*) malloc(sizeof(int)*n_resources);
		printf("P%d: ",i);
		for(j=0; j<n_resources; j++) scanf("%d",mt[i].resource+j);
	}
	printf("\n");
	return mt;	
}
ResourceState* calculateNeedTable(ResourceState* at, ResourceState* mt)
{
	if(at==NULL || mt==NULL) return NULL;

	int i,j;
	ResourceState* nt = (ResourceState*) malloc(sizeof(ResourceState)*n_processes);
	for(i=0; i<n_processes; i++)
	{
		nt[i].resource = (int*) malloc(sizeof(int)*n_resources);
		for(j=0; j<n_resources; j++) nt[i].resource[j] = mt[i].resource[j] - at[i].resource[j];
	}
	return nt;	
}
int* calculateInitialAvailableTable(ResourceState* at, int* maxResources)
{
	if(maxResources==NULL || at==NULL) return NULL;

	int i,j;
	int* iat = (int *) calloc(n_resources,sizeof(int));
	for(i=0; i<n_processes; i++)
	{
		for(j=0; j<n_resources; j++) iat[j] += at[i].resource[j];
	}
	for(j=0; j<n_resources; j++) iat[j] = maxResources[j] - iat[j];
	return iat;	
}
int* calculateSafeState(ResourceState* at, ResourceState* nt, int* maxResources)
{
	if(at==NULL||nt==NULL||maxResources==NULL) return NULL;
	
	int* available = calculateInitialAvailableTable(at, maxResources);
	int* safe = (int*) malloc(sizeof(int)*n_processes);
	int* done = (int*) calloc(n_processes,sizeof(int));
	int i=0,j,k,flag;
	while(i<n_processes)
	{
		for(j=0; j<n_processes; j++)
		{
			if(done[j]) continue;

			flag = 1;
			
			for(k=0; k<n_resources; k++) flag = flag & (nt[j].resource[k] <= available[k]);

			if(!flag) continue;

			safe[i++] = j;
			done[j] = 1;
			for(k=0; k<n_resources; k++) available[k] += at[j].resource[k];
		}
	}
	return safe;
}
void printStafeState(int* safeState)
{
	if(safeState==NULL) return;
	
	int i;
	for(i=0;i<n_processes-1;i++)
	{
		printf("P%d -> ",safeState[i]);
	}
	printf("P%d\n",safeState[i]);
}
void printNeedTable(ResourceState* nt)
{
	int i,j;
	for(i=0;i<n_processes;i++)
	{
		printf("P%d: ",i);
		for(j=0; j<n_resources; j++) printf("%d ",nt[i].resource[j]);
		printf("\n");
	}
}
void main()
{
	int i;
	printf("\n\t[BANKER'S ALGORITHM]\n\n");
	printf("Enter number of Processes: "); scanf("%d",&n_processes);
	printf("Enter number of Resources: "); scanf("%d",&n_resources);
	printf("Enter space seperated Max available instances of each resource\n");
	int* maxResources = (int*) malloc(sizeof(int)*n_resources);
	for(i=0;i<n_resources;i++) scanf("%d",maxResources+i);
	printf("\n");
	ResourceState* at = getAllocationTable();
	ResourceState* mt = getMaxTable();
	ResourceState* nt = calculateNeedTable(at,mt);
	printf("\nNeed Table:\n"); printNeedTable(nt);
	printf("\nSafe State: "); printStafeState(calculateSafeState(at,nt,maxResources)); printf("\n");
}
