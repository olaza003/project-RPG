# Dungeon Crawler
 
  Authors: [Orlean Lazaro](https://github.com/olaza003), [Ryan DeMello](https://github.com/rdemello7300), [Rudy Mendoza](https://github.com/UrbanCoffee)
 

## Project Description
* We are all familiar with video games and how role-playing games work. We will be more invested in the project since we can all relate to the idea more, and we can be   creative with what different features we add. We also have experience in knowing what makes a game fun and engaging, as well as how certain features are generally implemented. 

* Tools we'll be using:
  * C++ - The language we are the most familiar with.
  
* Input: The player will be prompted with a series of options that they will chose by entering characters ("a", "b", ...) or numbers depending on the situation.
* Output: Results of each command and battle
  
Design Patterns: 
* Strategy: 
  * The strategy pattern is used to abstract away algorithms. Having different types of characters, we need to create different algorithms for the attack function depending on what type of character the player creates. A problem with this is the type of character that will be created by the player will be decided at runtime. A solution to deciding which attack algorithm to use would be using a strategy pattern as it allows us to decide at runtime how to use an algorithm. This will lead to a good solution because it makes the characters easy to change dynamically. Warriors can use one algorithm for attacking while Knights can use another algorithm. 
 * Decorator: 
    * The decorator pattern is flexible to create an alternative for subclassing to extend its functionality. Without using the decorator pattern, we would have to write a lot more code than is necessary, writing whole classes for the same weapon that only has one extra attachment, instead of just adding the attachment to one class. So a sharper sword or a sword with a better hilt on it would both need its own class. Each addition would require a new class for the entire weapon. But with the decorator pattern, we can just make new classes for the attachments themselves instead of the whole weapon. We can use this by extending a base class for weapons which we will extend to add ornaments that enhance its capabilities (such as enchantments). This project would require better stats to defeat certain enemies in which the decorator pattern would give users better flexibility to defeat them. The decorator can further enhance user abilities throughout the game by using the Enchantment decorator which adds on the damages and extends the name on the passed object.

## Class Diagram
![example project diagram](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/RevisedDiagram.jpg?raw=true)
* The following image above is the project diagram that represents the character interface. Since this is a text-based RPG, portions of the game remain adaptable to the player's choice and gameplay. The portion of the diagram that is connected with red lines outlines the Strategy Pattern of the project which involves changing how the character operates depending on the player. Depending on what character type they choose, algorithms such as *attack* will also dynamically change along with it. The other portion of the diagram where the classes are connected with green lines represent the Decorative Pattern. Here, each item can be modified, or decorated, with an additional enchantment class to therefore create a combined object of the two.
   
* To further highlight the Strategy Pattern of this diagram, the character class under the abstract class *Entity* will inherit its virtual function. It also has aggregation towards items and characterAttack. CharacterAttack will have to be able to use CharacterCreation to create different types of character for the game. In which we see WarriorAttack, KnightAttack, HunterAttack, etc. have their own attack function.
 
* As for the Decorator Pattern, it will have a Weapon_Enchantment class under it that serves as the base decorator class. A FireEnchant class would derive from this base class to create a fire enchantment that wraps around the original weapon that is passed in. This weapon would have different types such as dagger, sword, and bow be used by unique characters. The enchantments wouldn't change the actual weapon itself, all of that code would stay the same. The enchantment would only deocrate the weapon and add to the damage value as well as the name. So a fiery sword still remains a sword, it just has more fire damage and is now called a Fiery Sword. 
 
 ## Screenshots
Win:
![wsc1](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.41.52%20PM.png)
![wsc2](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.42.10%20PM.png)
![wsc3](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.42.23%20PM.png)
![wsc4](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.42.36%20PM.png)
![wsc5](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.42.48%20PM.png)
![wsc6](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.42.55%20PM.png)
![wsc7](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.43.07%20PM.png)
![wsc8](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.43.17%20PM.png)
![wsc9](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.43.30%20PM.png)
Loss:
![lsc1](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.45.29%20PM.png)
![lsc2](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.45.37%20PM.png)
![lsc3](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.45.45%20PM.png)
![lsc4](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.45.54%20PM.png)
![lsc5](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.46.04%20PM.png)
![lsc6](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.46.14%20PM.png)
![lsc7](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project%20Screenshots/Screen%20Shot%202021-03-09%20at%202.46.21%20PM.png)

 ## Installation/Usage
* Step 1: Download all files from executable folder
* Step 2: Compile all cpp files and run them in a main executable:
    * Install cmake in machine and run the following commands in your terminal inside of the executable directory:
        * $ cmake . 
        * $ make
        * $ ./exe
        
    &nbsp;&nbsp;&nbsp;&nbsp;OR

    * Compile each file manually using g++:
        * $ g++ -std=c++11 -o exe main.cpp entities.cpp sequenceManager/seqMan.cpp items/protoITEMS/storage.cpp items/protoITEMS/protoITEMS.cpp
        * $ ./exe

* Step 3: Play game

 ## Testing
Our project was tested and validated using googletest to run unit tests on each function used and integration tests using multiple functions together, as well as extensive play testing using the ./main executable. Every test that was used is in the unit_test folder in the repository, as well as the early versions of some of these tests in the legacyTESTING folder. 
 
