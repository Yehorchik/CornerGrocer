# Corner Grocer Item Tracker

Yehor Melnyk  
CS 210: Programming Languages — Project Three

## Overview

This C++ program reads the Corner Grocer's purchase records and counts how many times each item was bought. The store can use this information to see which products are popular and decide how to arrange its produce section.

Users can search for an item, view all purchase counts, or display a histogram. The program also saves the results to `frequency.dat` automatically when it starts.

## Project Files

| File | Description |
| --- | --- |
| `main.cpp` | Displays the menu and checks user input |
| `GroceryTracker.h` | Declares the GroceryTracker class |
| `GroceryTracker.cpp` | Reads the file, counts items, displays results, and saves the backup |
| `CS210_Project_Three_Input_File.txt` | Contains the provided purchase records |
| `test_inputs/` | Contains additional files used for testing |
| `README.md` | Includes instructions and my project reflection |

The program creates `frequency.dat`, so this file does not need to exist before running it.

## How to Compile and Run

I used VS Code on my Mac. Open a terminal in the project folder and run:

```bash
clang++ -std=c++17 -Wall -Wextra main.cpp GroceryTracker.cpp -o CornerGrocer
./CornerGrocer
```

If you use GCC, run:

```bash
g++ -std=c++17 -Wall -Wextra main.cpp GroceryTracker.cpp -o CornerGrocer
./CornerGrocer
```

Make sure you run the program from the folder containing `CS210_Project_Three_Input_File.txt`.

## Menu Options

1. **Find an item:** Enter an item name to see how many times it was bought. The spelling and capitalization must match the input file. If the item is not found, the program displays zero.
2. **Print all frequencies:** Display every item and its count in alphabetical order.
3. **Print histogram:** Display each item with one asterisk for each purchase.
4. **Exit:** Close the program.

If the user enters an invalid menu choice, the program shows an error and asks again. It also reports errors if it cannot read the input file or save the backup.

## Testing

I tested the program with the provided input file and several additional files. These included a small file where I could check the counts by hand, a file with extra spaces and tabs, an empty file, and a larger file with 300 words.

I also tried incorrect menu entries and searched for items that were not in the records. The program handled these cases without crashing.

## Project Reflection

### Summarize the project and what problem it was solving.

The Corner Grocer needed a way to count how often customers bought different items. Its records listed purchases in order, so finding the total for each item by hand would take time. My program reads those records and shows the totals through a search, a complete list, or a histogram. This helps the store compare products and make decisions about where to place them.

### What did you do particularly well?

I think I did well with keeping the code organized. The menu and user input are handled in `main.cpp`, while the GroceryTracker class handles the purchase data. This makes the program easier to follow because each part has a clear purpose.

I also paid attention to input validation and file errors. For example, the menu rejects entries that contain extra text after a number. Using a map was another useful choice because it stores one count for each item and keeps the results in alphabetical order.

### Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

I could improve the search so it accepts different capitalization. For example, searching for `apples` should return the same result as `Apples`. This would make the program easier to use. I could also add support for item names with more than one word.

Another improvement would be automated tests. Manual testing worked for this small project, but automated tests would help me check future changes more quickly. I could also let users provide the input filename when starting the program, so they would not need to edit and compile the code to use a different file.

### Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

The main logic was straightforward, but working with C++ input streams required more attention. I wanted the program to reject invalid entries, including numbers followed by extra text.

I used `getline` to read the whole line and `istringstream` to check its contents. Breaking the program into small functions and trying different inputs helped me check its behavior. For future C++ work, I plan to keep using VS Code, compiler warnings, and C++ reference documentation.

### What skills from this project will be particularly transferable to other projects or course work?

This project uses standard object-oriented programming practices, such as separating responsibilities, keeping data private, and giving each method a clear purpose. These practices can be applied across different projects and programming languages.

File processing, input validation, and counting records are also useful in many applications. The same approach could be adapted for other programs that read data and summarize results.

### How did you make this program maintainable, readable, and adaptable?

I followed standard object-oriented programming practices by keeping the purchase data and related methods inside the GroceryTracker class. The menu is separate from the class, and the frequency map is private. This gives each part a clear responsibility and helps prevent unintended changes to the data.

I also used descriptive names, focused methods, and separate header and implementation files. This structure makes the code easier to understand, update, and reuse. For example, the GroceryTracker class could work with a different menu without changing its counting logic.