# Summarize the project and what problem it was solving.
The Grocery application is reading data from an input file (a list of grocery), calculates the frequency of each item's purchases and diplays it to a user in different modes of view.
The application creates a backup file of frequencies at the very beginning. Next, it asks the user to choose one of menu's options: to lookup the frequency of a single input item, to display frequencies for all the items as an item - frequency pair or as a histogram, or to quit the application.  

# What did you do particularly well?
The application has more or less robust input processing with eliminating most crucial input mistakes and prompting the user for valid input.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
Interaction with the user could be further improved. For example, currently the application can only adequately process one-word item names. It should be modified to process item names line-for-line, so that frequencies can be calculated for many-word item names.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are # you adding to your support network?
The greatest challenge of the project was to provide adequate processing for all the inputs the user might probably enter. 

# What skills from this project will be particularly transferable to other projects or course work?
The project helped me to practice problem-solving and get better understanding of C++. 

# How did you make this program maintainable, readable, and adaptable?
While working on the project I tried to adhere to good practices of coding like isolating each piece of functionality in a separate method to avoid "spaghetti code", giving self-obvious names to variables and functions, preferring more readable construction over shorter ones, providing comments. 
