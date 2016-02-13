# Construct Order In Multiple Inheritance
The order in which base classes are constructed depends on the order in which they
appear in the class derivation list. The order in which they appear in the constructor
initializer list is irrelevant.

[code](/code_for_post/Panda.cpp)   
<a href="/code_for_post/Panda.cpp">code in html format</a>

Output as below, 

	ZooAnimal construct called!
	Bear construct called!
	Endangered construct called!
	Panda construct called!

A Panda object is initialized as follows

*   ZooAnimal, the ultimate base class up the hierarchy from Panda’s first direct base class, Bear, is initialized first.
*   Bear, the first direct base class, is initialized next.
*   Endangered, the second direct base, is initialized next.
*   Panda, the most derived part, is initialized last.


