# Project's struct
- `hash.h`: Definition of the data type stored in the queue, the pointer "p_queue", the size of the array and function prototypes.
- `hash.c`: Definition of the data types "p_queue", implementation of the functions.
	- `main.c`: Management of the user interface and input/output (I/O) operations.
- `hash_test.c`: Implementation of the test functions.
	- `main_test.c`: Unitary test for validate the creation and manipulation.

	The purpose of this project is to learn the applications of hash table.
	
• Hash table: It's a generalization of the idea of an array. Utilizes a function to spread the elements which we want to store. The spread disperse the elements unsorted. It associates a value to a key.

• Key: Part of the information that composes the insert or searched element.

• Value: It's the index in which the element locate itself in the array that defines the table.

• Hash function: Spread the elements in the table.

• Advantages:	Highly efficient in the search operation O(1).
		Search time is independent from the number of keys stored.
		Simple implementation.
		
• Disadvantages: High cost to recover the elements from the table sorted by the key. In this case, it's needed sort the table.
		 Worst case is O(N), begin "N" the table's size: high number of collisions.
		 
• Folding Method: Fold and sum the value digits to calculate it position. While the value be bigger than the table's size, fold and the digits overlapping are sumed, disregarding the tens.

• Universal hashing: Chose a prime number "p" in such a way that any key "k" will be lower than "p" and bigger or same as zero. "p" is bigger that the table size. Chose randomly two integers "a" and "b" (0 < a <= p | 0 <= b <= p).

• Perfect hashing: Ensure that won't have key colisions in the table, in other words, different keys will always generate different positions. In the worst scenario, the search and insertion will always be executed in constant time O(1)

• Imperfect hasing: For two different keys, the function's output is the same position in the table. Key's colision aren't necessarily bad, they're just unpleasent because they slow down the system's performance. Many hash tables uses another function to lead with this problem

• Open addressing: When collide, go through  the hash table searching for the next position vague
		Advantages: Wide numbers of position for the same quantity of used memory in the separate chaining, lowering the colisions. The search is done inside the hash table, allowing a faster recupperation. Instead of acessing pointers, it calculate the sequence of position to be stored
		Disadvantages: More processing effort in the positions calculations. Insertion cost of O(N) when every element inserted collide
		
• Separete chaining: Don't search for vague positions. Store inside of each array's position the begin of a dynamic linked list.
		Advantages: Worst case of insertion is O(1) if the list is unsorted.
		Disadvantages: The search time is proportional to the number of elements in the list, in other words, it's needed go through the list for that element. Higher cost of memory: it's needed to store the list's pointers.
		
• Linear probing: Try to spread the elements in sequence based on the position calculated using the hash function. Even if it's simples, it presents a problem know as primary clustering.

• Primary clustering: Presence of long sequences of ocupied positions. As the hash table fill, the insertion and search time increases. The bigger the primary clustering, the higher is the probabillity of increasing it with the insertion of a new element, worsening the table's performance.

• Quadratic probing: Try to spread the elements using a quadratic equation (pos + (c1 * i) + (c2 * i^2)). It solves the primary clustering, but creates another problem know as secundary clustering.
			pos : position obtained by the hash function
			i: the actual attempt
			c1 and c2: coefficients of the equation
			
• Secundary clustering: This occur because every key that produces the same inital position in the hash table also generates the same positions in the quadratic probing. Fortunately, the decay in the table is smaller than the one produced by linear probing;

• Double hashing: Try to spread using two hash functions (h1 + i * h2)
			h1: used to calculate the element's inital position 
			h2: used to calculate the displacement in relation with the initial position when a collision occurs
			
• Rabin-Karp algorithm: Calculates the model's hash and compare with the input's' substrings hash. If the hash's are the same, than compare the caracteres to confirm if it's a valid occureance. Uses the rolling hash technique. The new hash value is calculated rapidly removing the old value from the old hash and adding the new value
	Advantages: Simple to implement, capable of searching multiples instances in one string and it's efficient and scalable, capable of sustaining longer strings
	Disadvantages: High risk of hash collisions, leading to false positives and it's slower than other model search algorithms when there's many collisions.
