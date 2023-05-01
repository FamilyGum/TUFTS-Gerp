Compile/run:
     - Compile using
            make gerp
     - run executable with
            ./gerp InputDirectory outputFile

Program Purpose: This program's purpose is to take queries from the user and 
output the lines within the files in the directory that the query appears on.
Depending on whether the user inputs a sensitive or insensitive query, the 
program will look for instances of the exact query or all variations of the 
query.

Acknowledgements: TAs

_______________________________________________________________________________
Files Provided: 

Gerp.cpp: The file will run the program, repeatedly asking for query from the
user until either the query stream is finished or the user quits. 
Based off the input string a gerp object will files 2D vector and fill the
hash table with the file contents.

Gerp.h: This class is responsible for running up the query, storing the files 
and filling the hash table with the words from each file.

hash_table_values.cpp: The hash table has three functions, insertting an
element, getting an element, and getting a group of elements that contain 
the insensitive version of the key. The table also will expand and rehash 
if the number of elements require it to.

hash_table_values.h: this class is responsible for implementing a hash table 
that takes words as the key and stores vectors of values that indicate the file
and the line the key appears on. It is used by the Gerp class

stringProcessing.cpp: This class contains one function that strips the
alphanumeric characters off the front and back of the string

stringProcessing.h: This class is used within the Gerp class to strip the 
alphanumeric characters off of the words passed in from the files as well as 
from the user input.

unit_tests.h: Testing file for the Gerp file, stringProcessing file, 
hash_table_values class, and the file file.

test_main.cpp: testing main for extra testing for the file, stringProcessing, 
and hash_table_values files.

file.h: this class is used by Gerp to store all of the files and their contents
within a 2D vector.

file.cpp: This class will save all of the file paths in one vector, and the 
files themselves in a 2D vector

main.cpp: based off the user input on the command line, this will create an 
instant of the Gerp class based off of the given directory and the output 
file. It will also cause the program to run by calling the run function on 
Gerp. When the program terminates, this function will cout the ending message.

README: this file.

2letter.in: input testing file for 2 letter word testing

3letter.in: input testing file for 3 letter word testing

4letter.in: input testing file for 4 letter word testing

5letter.in: input testing file for 5 letter word testing

large.in: input testing file for large word testing

Makefile: used for easy compilation of the program's files and easy compilation
for submission.

_______________________________________________________________________________
An â€œarchitectural overview,â€ i.e., a description of how your various program 
modules relate. For example, the FSTree implementation keeps a pointer to the 
root DirNode.

The file class will return the file paths and the files and their contents
for use by the Gerp class to fill the hash table. 

File will utilize the provided FSTree class, which uses the provided DirNode 
class to store the paths and file contents in a 1D and 2D vector.

Gerp will use the Hash table class to search for queries that the user inputs.

_______________________________________________________________________________
An outline of the data structures and algorithms that you used: 

The main data structure used in this program is the hash table. This data 
structure functions much like an array but the indexes to the values are keys
instead of integers. Keys can be any data type, such as ints, strings, or a 
datatype that you make. When the key is called, the hash table is able to 
retrieve the value stored at that key in constant time complexity. The hash 
table maps each key using a hash function, which in most cases is a very 
complex mathematical function, this allows each key to be mapped to its own 
bucket. However, collisions are inevitable (where a different keys map to the
same bucket), but there are many ways that hashtables can handle them. One way
is chaining, where the different keys are stored in a linked list in the same 
bucket. Another is linear probing, where the hash table will look for the 
nearest open bucket to insert the key into. The last method, and the easiest
to implement, is to make the chances of a collision happening as little as 
possible; this can be done by using a good hash function, and/or mapping keys
to a larger variety of buckets.

The hash table has many use cases: One use case can be to map capitals to 
states. Another use case can be to map people's names to phone numbers.

An advantage to hash tables is that they are a very efficient way to get 
elements from, as the time complexity of searching up a key is O(1). They are 
also way more versatile than other data structures becuase of their ability to
search using keys.

A disadvantage to using hash tables is the fact that they sometimes can take up
a lot of space when storing larger amounts of data. In our project, majority of
the memory taken up by our program was due to the hash table.

We also used vectors prominently in this project which is a 
dynamically expanding array. We stored the files and the values in vectors.
If the number of items is ever equal to 
the capacity, the array will automatically expand, allowing for an 
arbitrary number of elements to be inserted into the vector. 

Some advantages of vectors is that it can have O(1) access to any element as 
long as the index is known. 

A disadvantage is that insertting is slower as you need to push all of the
elements back one index.

We also used linked list for chaining, which is a 
series of nodes connected to each other. This allows the LinkedList to 
change size, as it is not bounded by a set number of elements. Some pros
of LinkedLists is that insertting and removing an element is faster
than an ArrayList, and expanding a LinkedList is also much easier and 
faster than an ArrayList. Some cons of an LinkedList is that finding an 
element in a LinkedList requires the parsing through of each node, which 
is more complicated and slower than an ArrayList.

_______________________________________________________________________________
Details and an explanation of how you tested the various parts of assignment 
and the program as a whole: 

We tested this each function in this assignment using unit tests. We tested 
FSTreeTraversal by inputting a root directory and testing that it printed
all of the file directories correctly. The filenames function relies on 
FSTreeTraversal, it just stores all of the paths in the vector, so we just
tested that the directories printed correctly when calling filenames. We tested
the file_saving function by giving it a small directory with multiple 
files and testing that all the lines of all the files print out. We 
tested the hash and get functions together, we created a hash table and 
insertted values and keys into the hash table. We then got the values back 
using the get function and asserted that they were the same as the ones we 
inputted. We inputting many values with the same key into
the table and tested that the values vector worked properly. We tested the 
hash function by asserting that two keys that are the same will map to the same
bucket and that two different keys will map to different buckets. We tested 
rehash by setting the number of buckets to 1 and seeing if the rehash worked by
not segmentation faulting the program and being able to print out the two 
values that we inputted. We tested insensitive search by insertting two 
different variations of a key ("a" and "A") and asserting that when the 
insensitive query was called, values contained in both variations were printed.
We tested filling the hash table by inputting a small test directory and 
assertingthat the hash table took all of the table's values in by seeing if 
querying a key the table recieved all of the words in the files. We tested the
sensitive queries by sending the program a small test directory and seeing if
the sensitive search printed all of the expected lines. We tested the 
insensitive query in the same way. We lastly tested the empty query and a 
query with a just alphanumerics to assert they would output the same thing. 
This test also implicitly tested that the stripalphanumeric function works 
properly as well. We threw each test into the test main as well just to make
sure the functions worked outside the testing environment.

We then tested the code by inputting queries into the given project directories
to see if the code worked at a larger scale. We asserted that our outputs were
correct by diff testing our output files with the demo's output files. We 
tested a series of a small word (1-2 letters) a medium sized word (4-5 letters)
and a large word(5-6 letters) and diffed the output files. Lastly, we inputted
a string of all alphanumeric to represent a empty string query to test if It
returned no values. We tested these files sensitively and insensitively.
