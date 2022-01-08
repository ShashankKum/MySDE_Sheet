//There is a rod and we have to make the cuts so that the price obtained is maximum
//We have a length array and its corresponding price array.
//price[i-1]+arr[i][j-length[i-1]] -> this is when cut is included
//arr[i-1][j]-> this is when cut is not included

int rodcut(int n,int length[],int price[],int size){
    int arr[n+1][size+1];
    //initialization
    for(int i=0;i<=n;i++)
    arr[i][0]=0;
    for(int j=0;j<=size;j++)
    arr[0][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=size;j++){
            if(length[i-1]<=size) //it can be considered or not
            arr[i][j]=max(price[i-1]+arr[i][j-length[i-1]], arr[i-1][j]);
            else
            arr[i][j]=arr[i-1][j]; //when it is not considered
        }
    }
	return arr[n][size]; //final answer consisting of max price obtained in making cuts
}