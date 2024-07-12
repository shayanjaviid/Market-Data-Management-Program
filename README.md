# Market Data Management Program

This repository contains a C program designed to manage market data stored in a file. The program allows users to read, view, update, and calculate the total value of different products using arrays and structures.

## Features

### 1. Read Market Data from File
- **Structure Definition**:
  - The `Product` structure represents each product, containing:
    - `name` (string) -- Marks: 1
    - `price` (float) -- Marks: 1
    - `quantity` (integer) -- Marks: 1
  - Example:
    ![1](https://github.com/user-attachments/assets/ed6f5b0f-d38b-4420-ab62-6cf4c43bc49b)


- **File Reading Function**:
  - Reads product data from a file and stores it in the `products` array. -- Marks: 2
  - Includes error handling for file opening failure. -- Marks: 1
  - Checks for array bounds to avoid overflow. -- Marks: 1
  - Example:
    ![2](https://github.com/user-attachments/assets/914aa86c-f052-4903-bdaf-a7a9f82b3cc5)


### 2. Viewing Market Data
- **Function**: `viewMarketData` -- Marks: 1
  - Displays all market data stored in the structure array. -- Marks: 2
  - Example:
   ![3](https://github.com/user-attachments/assets/45d593fb-05a1-4d19-b0b1-9f6dafee13ca)


### 3. Calculate Total Value
- **Function**: `calculateTotalValue` -- Marks: 1
  - Calculates the total value of the market data (sum of the product of price and quantity for each product). -- Marks: 2
  - Example:
    ![4](https://github.com/user-attachments/assets/cbc6df3c-2e07-41ee-9bca-a23167157643)


### 4. Update Product Quantity
- **Function**: `updateProductQuantity` -- Marks: 1
  - Updates the quantity of a specific product based on user input. -- Marks: 2
  - Example:
  ![5](https://github.com/user-attachments/assets/d30dace1-18be-4793-8ae3-01580a44d4e6)


### 5. Exit
- **Function**: Exit the program -- Marks: 1
  - Example:
  ![6](https://github.com/user-attachments/assets/7f92ae3d-d404-4c37-8f3b-59319e0a4b3f)


### Error Handling
- The program includes basic error handling for file operations and invalid user inputs. -- Marks: 2

### Modular Design
- Functions are used to separate different operations, making the code more modular and easier to maintain. -- Marks: 2

### User-Friendly Interface
- The menu-driven interface is intuitive, providing clear options for users to interact with the program. -- Marks: 2

### Data Encapsulation
- The use of structures encapsulates product data effectively, promoting clean and organized code. -- Marks: 2

### File Format
- The data file (`MarketData.txt`) should have the following format: -- Marks: 1
![7](https://github.com/user-attachments/assets/73b65d4d-a92b-49a7-8098-1aaf3eec5cdb)

## Contact
I'm eager to hear your thoughts, suggestions, and feedback on this project. Feel free to reach out if you have any questions or if you'd like to collaborate on similar projects. -- Marks: 1

Thank you for your support and interest!
