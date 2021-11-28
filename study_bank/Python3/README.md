**IMPORTANT CONCEPTS IN PYTHON3**

DATA STRUCTURES:
==============

Lists, Tuples
--------------

|General Questions| References (0x03)|
|:---------------:|:----------|
|What are lists and how to use them| |
|What are the differences and similarities between strings and lists| |
|What are the most common methods of lists and how to use them| |
|How to use lists as stacks and queues| |
|What are list comprehensions and how to use them| |
|What are tuples and how to use them| |
|When to use tuples versus lists| |
|What is a sequence| |
|What is tuple packing| |
|What is sequence unpacking| |
|What is the del statement and how to use it| |


|Data types|Description|Ordered or Unordered|Changeable or Unchangeable|Duplicates|syntax|
|:-|:-:|:--:|:-:|:--:|---|
|**List**|<p>Lists are used to store multiple items in a single variable. </p>|<p>  lists are **ordered**, it means that the items have a defined order, and that order will not change. If you add new items to a list, the new items will be placed at the end of the list. </p>| ````thislist = ["item 1", "item 2", "item 3"]```` ````print(thislist)````|
|**Tuple**|<p>Tuples are used to store multiple items in a single variable.</p>|**ordered**: It has a defined order and cannot be changed|**Unchangeable**|**Allows Duplicates**|````thistuple = ("apple", "banana", "cherry")```` ````print(thistuple)````|
|**Set**|<p> Sets are used to store multiple items in a single variable. </p>|**Unordered**:<p> the items in a set do not have a defined order. Set items can appear in a different order every time you use them, and cannot be referred to by index or key.</p>|<p>**Unchangeable**: Set items are unchangeable, meaning that we cannot change the items after the set has been created. (*Once a set is created, you cannot change its items, but you can remove items and add new items.*) </p>|**Duplicates Not Allowed:**<p> Sets cannot have two items with the same value.</p>|````myset = {"apple", "banana", "cherry"}````|
|**Dictionary**|Dictionaries are used to store data values in key:value pairs.|A dictionary is a collection which is ordered`*`,|changeable <p>we can change, add or remove items after the dictionary has been created.</p>| Not allow duplicates: Dictionaries cannot have two items with the same key (duplicate values will overwrite existing values)|````thisdict = {"brand": "Jeep", "model": "compass", "year": 2012}````|

**meaning of:**
<p>
In Python, you have heard that lists, strings and tuples are;
  * ordered collection of objects

And sets and dictionaries are;
  * unordered collection of objects
</p>

+ ordered:
+ un-ordered:
+ duplicate
+ not duplicate

***Read or watch:***
* [3.1.3. Lists](https://docs.python.org/3/tutorial/introduction.html#lists)
  * [lists](https://www.w3schools.com/python/python_lists.asp)
  * [tuples](https://www.w3schools.com/python/python_tuples.asp)
* [Data structures](https://docs.python.org/3/tutorial/datastructures.html) (until `5.3. Tuples and Sequences` included)
* [Learn to Program 6](https://www.youtube.com/watch?v=A1HUzrvS-Pw) : Lists


Set, Dictionaries:
-------------------


**Set VS. Dictionaries**
--------------------------


***Read or watch:***
* [sets](https://www.w3schools.com/python/python_sets.asp)
* [dictionaries](https://www.w3schools.com/python/python_dictionaries.asp)
