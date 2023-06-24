# CLI  planner
# Day Planner Console Application

The Day Planner Console Application is a C++ program that allows you to plan and manage your daily tasks through a command-line interface.

## Features

- Add tasks with start time, end time, and description.
- Remove tasks by index or remove all tasks at once.
- List all tasks in a formatted manner.
- Save and load tasks to/from a .plan file.

## Getting Started

1. Clone the repository: `git clone https://github.com/your-username/day-planner.git`
2. Navigate to the project directory: `cd day-planner`
3. Build the application: `g++ plan.cpp -o plan`
4. Run the application: `./plan`

## Usage

The application accepts the following commands:

- `add`: Add a task. The format is `add <start time> <end time> <description>`.
- `remove -i <index>`: Remove a task by its index.
- `remove -a`: Remove all tasks.
- `list`: List all tasks.

## Example Usage

1. Add a task: `add 10:00am 11:30am Meeting with team`
2. List tasks: `list`
3. Remove a task: `remove -i 1`

## File Structure

- `plan.cpp`: The main C++ source code file.
- `plan.h`: Header file containing function declarations and class definitions.
- `README.md`: Documentation file.
- `LICENSE`: License information file.
- `myplan.plan`: Example .plan file to store task data.

## License

This project is licensed under the [MIT License](LICENSE).

