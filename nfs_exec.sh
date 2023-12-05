#!/bin/bash

# Check if gnome-terminal is installed
if ! command -v gnome-terminal &> /dev/null; then
    echo "Error: gnome-terminal is not installed."
    exit 1
fi

# Compile the hello.c file
gcc -o hello hello.c

# Function to run hello program in a new terminal
run_in_terminal() {
    gnome-terminal --tab --title="Terminal $1" -- bash -c "./hello; read -p 'Press Enter to close this terminal.'"
    sleep 1
}

# Run the program in three terminals
for i in {1..3}; do
    run_in_terminal $i
done

# Clean up compiled executable
rm hello
