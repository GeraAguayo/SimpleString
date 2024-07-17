# Simple String implementation
#### By Gerardo Aguayo

This is a simple **String** implementation example in C++ that has functions like **copy constructor, Copy assignment operator, Move Operator** and **printing & adding lines**


# Use
SimpleString my_string {max_size}

```  
SimpleString name{50};	

//Add a line
name.add_line("Anakin Skywalker");	

//Print the contents and the memory address of the string 
name.print();
```

## Copy constructor utilization

The copy constructor works copying all the info from a previous string to a new one, keeping both on different memory addresses
```  
SimpleString anakin{50};	

anakin.add_line("Anakin Skywalker");	

//Copy the contents from anakin to seb
SimpleString seb{ anakin };

```

## Copy Assignment Operator Utilization

The copy assignment operator allows assigning the contents of one `SimpleString` instance to another existing instance. It ensures deep copying by allocating new memory for the destination buffer and copying the contents from the source buffer.
```  
SimpleString luke{50}; 
luke.add_line("Luke Skywalker"); 

SimpleString leia{25}; 

// Assigning contents of luke to leia 
leia = luke; 
leia.print();

```

## Move Operator Utilization
The move operator transfers the contents from one `SimpleString` instance (source) to another (destination) and leaves the source in a valid but unspecified state (usually empty).

 ```  
SimpleString han{50}; 
han.add_line("Han Solo"); 

SimpleString chewbacca{25}; 
han.moveTo(chewbacca); // Moving contents of han to chewbacca 

chewbacca.print(); 
han.print(); // Should print an empty or null string

```

