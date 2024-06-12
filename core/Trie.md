## Trie data structure

### Node Structure
Each node in the trie represents a character in a string.

Each node has a maximum of 26 children (for the English alphabet), 
which are pointers to other nodes.

Each node also has a boolean flag `isEoW`(is End of Word) to indicate whether a word ends at the node.


### Insertion
To insert a string into the trie, start from the root node.
For each character in the string, move to the corresponding child node. If the child node does not exist, create it.

Mark the last node as the end of the word by setting wordEnd to true.


### Search
To search for a string in the trie, start from the root node.

For each character in the string, move to the corresponding child node. If the child node does not exist, the string is not in the trie.

If all characters are found and the last node has wordEnd set to true, the string is present in the trie.
