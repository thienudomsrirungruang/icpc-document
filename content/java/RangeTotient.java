
// find phi(i) from 1 to N fast
// O(N*loglogN)
long[] arr = new long[N+1];
for(int i=1; i <= N; i++)
	arr[i] = i;
for(int v=2; v <= N; v++)
	if(arr[v] == v)
		for(int a=v; a <= N; a+=v)
			arr[a] -= arr[a]/v;
