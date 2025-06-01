# Simple To-Do List Application

This is a simple console-based To-Do List application written in C++. It allows users to manage their tasks by adding, deleting, modifying, and updating the status of tasks. The application stores tasks in text files, making it easy to persist data between sessions.

## Features

- **Add New Tasks**: Users can write new tasks to their to-do list.
- **Delete Tasks**: Users can delete tasks by selecting the task number.
- **Modify Tasks**: Users can change the content of existing tasks.
- **Update Task Status**: Users can set the status of tasks to "Incomplete", "Complete", or "In Progress".
- **Persistent Storage**: Tasks and their statuses are saved in text files, allowing data to persist between application runs.

## File Structure

- `data.txt`: Stores the list of tasks.
- `idData.txt`: Stores the status of each task.
- `size.txt`: Stores the number of tasks in the list.

## Usage

1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   
2. Compile the application using a C++ compiler:
    ```bash
    g++ -o todo todo.cpp
    
3. Run the application:
    ```bash
    ./todo
Follow the on-screen instructions to manage your tasks.

Debugging
The application includes debugging options. You can enable or disable debugging by defining or commenting out the #define DEBUG and #define DEBUGo lines in the code.
