# RPG Maker
 
  Authors: [Orlean Lazaro](https://github.com/olaza003), [Ryan DeMello](https://github.com/rdemello7300), [Rudy Mendoza](https://github.com/UrbanCoffee)
 

## Project Description
* We are all familiar with video games and how role-playing games work. We will be more invested in the project since we can all relate to the idea more, and we can be   creative with what different features we add. We also have experience in knowing what makes a game fun and engaging, as well as how certain features are generally implemented. 

* Tools we'll be using:
  * C++ - The language we are the most familiar with.
  
* Input: Text Commands (“attack”, “check bag”, “run”)
* Output: Results of each command and battle
  
Design Patterns: 
* Strategy: 
  * The strategy pattern is used to abstract away algorithms. Having different types of characters, we need to create different algorithms for the attack function depending on what type of character the player creates. A problem with this is the type of character that will be created by the player will be decided at runtime. A solution to deciding which attack algorithm to use would be using a strategy pattern as it allows us to decide at runtime how to use an algorithm. This will lead to a good solution because it makes the characters easy to change dynamically. Warriors can use one algorithm for attacking while Knights can use another algorithm. 
 * Decorator: 
    * The decorator pattern is flexible to create an alternative for subclassing to extend its functionality. Without using the decorator pattern, we would have to write a lot more code than is necessary, writing whole classes for the same weapon that only has one extra attachment, instead of just adding the attachment to one class. So sword would have its own class and wooden sword and silver sword would have their own classes too when they don't need to, or like a sharper sword or a sword with a better hilt on it. Each addition would require a new class for the entire weapon. But with the decorator pattern, we can just make new classes for the attachments themselves instead of the whole weapon. We can use this by extending a base class for weapons which we will extend to add ornaments that enhance its capabilities (basically attachments). This project would require better stats to defeat certain enemies in which the decorator pattern would give users better flexibility to defeat them. The decorator can further enhance user abilities throughout the game. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 > 
![example project diagram](https://github.com/cs100/final-project-olaza003-rdeme005-rmend048/blob/master/images/Project_Diagrams.png?raw=true)
* The following image above is the project diagram that represents the character interface. Since this is a text-based RPG, portions of the game remain adaptable to the player's choice and gameplay. The portion of the diagram that is connected with red lines outlines the Strategy Pattern of the project which involves changing how the character operates depending on the player. Depending on what character type they choose, algorithms such as *attack* will also dynamically change along with it. The other portion of the diagram where the classes are connected with green lines represent the Decorative Pattern. Here, each item can be modified, or decorated, with an additional enchantment class to therefore create a combined object of the two.
   
* To further highlight the Strategy Pattern of this diagram, the character class under the abstract class *Entity* will inherit its virtual function. It also has aggregation towards items and characterAttack. CharacterAttack will have to be able to use CharacterCreation to create different types of character for the game. In which we see WarriorAttack, KnightAttack, HunterAttack, etc. have their own attack function.
 
* As for the Decorator Pattern, it will have items class under it. In which would have an abstract weapon and consumable inheriting from it. Further down the weapon class would have types of weapons such as wand, sword, and bow be used by unique characters. As for consumables, since they will have limited uses, an int-variable would be used to indicate when they should be used up. 

   
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
