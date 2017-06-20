// KMP algorithm
// arr[i] - maximum length of suffix finished at i 
// that is equal to prefix (proper prefix - sufix)
// string is indexed from 1 to n (it's length)
// Complexity O(n)

int t;
int arr[N];

void kmp(string s){
	int n = s.size();

	for(int i=1; i<n; i++){
		while(s[i] != s[t] && t>0){
			t = arr[t];
		}

		if (s[i] == s[t]){
			t++;
		}

		arr[i+1] = t;
	}

	return;
}