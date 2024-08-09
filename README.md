**Problem Statement:**

You have a folder named TradeData containing multiple text files. Each file holds trade data for a tradable script, with each line in the file representing a different dataset. 
Your task is to design a program that efficiently reads these files and updates an internal data structure with the next available dataset when requested.

**Objective:**

Create a program that:

Efficiently Reads Trade Data: Reads and parses data from multiple text files within the TradeData folder.

Updates Data Structure: Updates an internal data structure with the next available dataset from the files.

Provides Access to Next Dataset: Implements a method to retrieve and update the internal data structure with the next dataset upon request.

The text files in the TradeData folder contain lines formatted as follows:
Time,Open,High,Low,Close,Volume,... (various other fields)


**Requirements:**

Data Structure:Define a data structure to store the following information from each line:

time (string): The time of the trade.

open (int): The opening price.

high (int): The highest price.

low (int): The lowest price.

close (int): The closing price.

volume (int): The trading volume.

Include additional fields as needed.

File Reading:Implement a method to read and parse each text file line by line.Ensure each line is correctly parsed into the TradeData structure.

NextData Function:Implement a function named NextData() that:Loads the next dataset from the current file.

