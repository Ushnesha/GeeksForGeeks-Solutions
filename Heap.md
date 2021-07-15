## Binary Heap
### Table of contents
1. [Binary Heap Operations](#heapOperations)
2. [Find Median in a stream](#streammedian)
3. [Heap Sort](#heapsort)
4. [K largest elements](#klargestelems)
5. [K most occuring elements](#kmostoccuring)
6. [Kth largest element](#kthlargest)
7. [Kth largest element in a stream](#kthlargestinastream)
8. [Kth smallest element](#kthsmallest)
9. [Merge K sorted arrays](#mergeksortedarrays)
10. [Minimum cost of ropes](#mincostropes)
11. [Nearly sorted](#nearlysorted)
12. [Rearrange characters](#rearrangechars)
---
### Binary Heap Operations <a name = "heapOperations"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | CPP | O(Q\*Log(Heap Size))| O(n) |
\* Q = # of queries
```cpp
/*The structure of the class is
struct MinHeap
{
    int *harr;
    int capacity, heap_size;
    MinHeap(int cap) {heap_size = 0; capacity = cap; harr = new int[cap];}
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    int parent(int i);
    int left(int i);
    int right(int i);
};*/



//Function to extract minimum value in heap and then to store 
//next minimum value at first index.
int MinHeap::extractMin() 
{
    // Your code here
    if(heap_size==0) return -1;
    if(heap_size == 1){
        heap_size--;
        return harr[0];
    }
    swap(harr[0],harr[heap_size-1]);
    heap_size--;
    MinHeapify(0);
    return harr[heap_size];
}

//Function to delete a key at ith index.
void MinHeap::deleteKey(int i)
{
    // Your code here
    if(heap_size > i){
        decreaseKey(i, INT_MIN);
        extractMin();
    }
}

//Function to insert a value in Heap.
void MinHeap::insertKey(int k) 
{
    // Your code here
    heap_size++;
    harr[heap_size-1] = k;
    for(int i = heap_size-1; i != 0 && harr[parent(i)] > harr[i];){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

//Function to change value at ith index and store that value at first index.
void MinHeap::decreaseKey(int i, int new_val) 
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

/* You may call below MinHeapify function in
   above codes. Please do not delete this code
   if you are not writing your own MinHeapify */
void MinHeap::MinHeapify(int i) 
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) smallest = l;
    if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
    if (smallest != i) {
        swap(harr[i], harr[smallest]);
        MinHeapify(smallest);
    }
}
```
---
### Find median in a stream <a name = "streammedian"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(n))| O(n) |
```java
class Solution
{
    static PriorityQueue<Integer> gh = new PriorityQueue<Integer>();
    static PriorityQueue<Integer> sh = new PriorityQueue<Integer>(Collections.reverseOrder());
    //Function to insert heap.
    public static void insertHeap(int x)
    {
        // add your code here
        if(sh.size() == 0){
            sh.add(x);
            return;
        }
        else{
            if(sh.size() > gh.size()){
                if(x < sh.peek()){
                    gh.add(sh.poll());
                    sh.add(x);
                }else gh.add(x);
            }else{
                if(x <= sh.peek()) sh.add(x);
                else{
                    gh.add(x);
                    sh.add(gh.poll());
                }
            }
        }
    }
    
    //Function to balance heaps.
    public static void balanceHeaps()
    {
       // add your code here
      
    }
    
    //Function to return Median.
    public static double getMedian()
    {
        // add your code here
        if(sh.size() > gh.size())
            return (double)sh.peek();
        else return (double)(sh.peek() + gh.peek())/2;
    }
    
}
```
---
### Binary Heap Sort <a name = "heapsort"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | CPP | O(nLog(n))| O(1) |
```cpp
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
      int largest = i;
      int lt = 2*i + 1;
      int rt = 2*i + 2;
      if(lt < n && arr[lt] > arr[largest] )
            largest = lt;
      if(rt < n && arr[rt] > arr[largest])
            largest = rt;
      if(largest != i){
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
        for(int i = (n-2)/2; i >= 0; i--)
            heapify(arr, n, i);
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        for(int i = n-1; i >= 1; i--){
            swap(arr[0],arr[i]);
            heapify(arr, i, 0);
        }
    }
};
```
---
### K largest elements <a name = "klargestelems"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(k) |
```java
class Solution
{
    //Function to return k largest elements from an array.
    public static ArrayList<Integer> kLargest(int arr[], int n, int k)
    {
        // code here 
        //create a minheap and put first k elements
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i = 0; i < k; i++){
            pq.add(arr[i]);
        }
        //now for every k to n-1 elements check if the top is < the current element
        //if yes then remove the top and add the current elements
        for(int i = k; i < n; i++){
            if(pq.peek() < arr[i]){
                pq.poll();
                pq.add(arr[i]);
            }
        }
        //the minheap now contains the k largest elements
        ArrayList<Integer> res = new ArrayList<Integer>();
        while(pq.isEmpty() == false){
            res.add(pq.poll());
        }
        Collections.reverse(res);
        return res;
    }
}
```
---
### K most occuring elements <a name = "kmostoccuring"></a>
##### Find the sum of total frequencies of K most occurring elements
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(k) |
```java
class Solution
{
    //Function to print the sum of frequencies of k numbers
    //with most occurrences in an array.
    
    int kMostFrequent(int arr[], int n, int k){
        // your code here
        HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
        for(int i=0; i<n; i++){
            hm.put(arr[i], hm.getOrDefault(arr[i],0)+1);
            
        }
        PriorityQueue<Map.Entry<Integer,Integer>> pq = new PriorityQueue<>(
            (a,b) -> a.getValue().equals(b.getValue()) ?
                    Integer.compare(b.getKey(),a.getKey()) :
                    Integer.compare(b.getValue(),a.getValue()));
        for(Map.Entry<Integer, Integer> e : hm.entrySet()){
            pq.add(e);
        }
        int count = 0;
        while(k>0){
            Map.Entry<Integer, Integer> e = pq.poll();
            count+=e.getValue();
            k--;
        }
        return count;
    }
}
```
---
### Kth largest element <a name = "kthlargest"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(k) |
```java
class Solution 
{
    //Function to return kth largest element from an array.
    public static int KthLargest(int arr[], int n, int k) 
    {
        // Your code here
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i = 0; i<k; i++){
            pq.add(arr[i]);
        }
        for(int i = k; i < n; i++){
            if(pq.peek() < arr[i]){
                pq.poll();
                pq.add(arr[i]);
            }
        }
        return pq.peek();
    }
}
```
---
### Kth largest element in a stream <a name = "kthlargestinastream"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(k) |
```java
class Solution
{
    //Function to print kth largest element for each element in the stream.
    public void kthLargest(int arr[], int n, int k){
        // Your code here
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for(int i = 0; i<k; i++){
            pq.add(arr[i]);
            if(i<k-1)
            System.out.print("-1 ");
            else
            System.out.print(pq.peek()+" ");
        }
        for(int i = k; i < n; i++){
            if(pq.peek() < arr[i]){
                pq.poll();
                pq.add(arr[i]);
            }
            System.out.print(pq.peek()+" ");
        }
    }
}
```
---
### Kth smallest element <a name = "kthsmallest"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(k) |
```java
class Solution
{
    //Function to find the kth smallest element in the array.
    public static int kthSmallest(int arr[], int n, int k)
    {
        // Your code here
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>(Collections.reverseOrder());
        for(int i = 0; i<k; i++){
            pq.add(arr[i]);
        }
        for(int i = k; i < n; i++){
            if(pq.peek() > arr[i]){
                pq.poll();
                pq.add(arr[i]);
            }
        }
        return pq.peek();
    }
}
```
---
### Merge K sorted arrays <a name = "mergeksortedarrays"></a>
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O((nk)\*Log(k)) | O(k) |
```java
//create a class index for the element's value and its array position and value position
class Index{
    int val;
    int aPos;
    int vPos;
    Index(int vl, int ap, int vp){
        val = vl;
        aPos = ap;
        vPos = vp;
    }
}

class Solution
{
    //Function to merge k sorted arrays.
    public static ArrayList<Integer> mergeKArrays(int[][] arr,int K) 
    {
        // Write your code here.
        ArrayList<Integer> res = new ArrayList<Integer>();
        //create a minheap of k elements along with its array position and value position
        PriorityQueue<Index> pq = new PriorityQueue<>((a,b) -> a.val - b.val);
        for(int i = 0; i< arr.length; i++){
            pq.add(new Index(arr[i][0],i,0));
        }
        //now for smallest element, poll it out and push it to the resultant array
        //and put the next element of the same array from which the smallest has been taken into the minheap
        while(pq.isEmpty()==false){
            Index in = pq.poll();
            res.add(in.val);
            if(in.vPos+1 < arr[in.aPos].length) pq.add(new Index(arr[in.aPos][in.vPos+1], in.aPos, in.vPos+1));
        }
        return res;
    }
}
```
---
### Minimum Cost of ropes <a name = "mincostropes"></a>
##### There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(n))| O(n) |
```java
class Solution
{
    //Function to return the minimum cost of connecting the ropes.
    long minCost(long arr[], int n) 
    {
        // your code here
        if(n == 1) return 0;
        PriorityQueue<Long> pq = new PriorityQueue<Long>();
        for(int i = 0; i<n; i++)
            pq.add(arr[i]);
        long totalCost = 0;
        while(pq.isEmpty() == false){
            long cost = 0;
            cost+=pq.poll();
            cost+=pq.poll();
            totalCost+=cost;
            if(pq.isEmpty()==true) break;
            pq.add(cost);
        }
        return totalCost;
    }
}
```
---
### Nearly Sorted <a name = "nearlysorted"></a>
##### Given an array of n elements, where each element is at most k position away from its target position, you need to sort the array optimally.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | Java | O(nLog(k))| O(n) |
```java
class Solution
{
    //Function to return the sorted array.
    ArrayList <Integer> nearlySorted(int arr[], int num, int k)
    {
        // your code here
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        ArrayList<Integer> al = new ArrayList<Integer>();
        for(int i = 0; i <= k; i++){
            pq.add(arr[i]);
        }
        for(int i = k+1; i < num; i++){
            al.add(pq.poll());
            pq.add(arr[i]);
        }
        while(pq.isEmpty()==false){
            al.add(pq.poll());
        }
        return al;
    }
}
```
---
### Rearrange Characters <a name = "rearrangechars"></a>
##### Given a string S such that it may contain repeated lowercase alphabets. Rearrange the characters in the string such that no two adjacent characters are same.
| Data Structure | Language | Time Complexity | Space Complexity |
| ----------- | ----------- | ----------- | ----------- |
| Heap | CPP | O|S|Log(|S|))| O(1) |
```cpp
class Solution{
public:
    //Function to rearrange the characters in a string such that 
    //no two adjacent characters are same.
    
    struct Key{
        char ch;
        int freq;
        bool operator<(const Key& k) const{
            return freq < k.freq;
        }
    };
    string rearrangeString(string str)
    {
    	// Your code here
		int freqCh[26] = {0};
		for(int i = 0; i < str.length(); i++){
		    freqCh[str[i]-'a']++;
		}
		//create a maxheap and put characters with their frequencies
		//the maxheap created wrt to the frequencies of the elements
		priority_queue<Key> pq;
		for(char c = 'a'; c <= 'z'; c++){
		  //  int val = c - 'a';
		    if(freqCh[c-'a']>0)
		    pq.push(Key{c, freqCh[c-'a']});
		}
		str = "";
		//keep track of the last character used so that not to choose that character next time
		Key prev{'#', -1};
		//pop the element with highest freq and add it to the resultant string and keep it 
		//as last element used in prev, push it into the heap after the next element is used
		while(pq.size() > 0){
		    Key temp = pq.top(); 
		    pq.pop();
		    str+=temp.ch;
		    if(prev.freq > 0)
		        pq.push(prev);
		    (temp.freq)--;
		    prev = temp;
		}
	    return str;	
    }
};
```
---
