// KMP algorithm
// arr[i] - size of longest matching prefix 
// to sufix which ends at position i
// indexed from 1 to n
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