#!/bin/bash

# Check if gnome-terminal is installed
if ! command -v gnome-terminal &> /dev/null; then
    echo "Error: gnome-terminal is not installed."
    exit 1
fi

# Compile the hello.c file
gcc -o server1 test1.c headers.h functions.c colours.h
gcc -o server2 test2.c headers.h functions.c colours.h
gcc -o client test.c headers.h functions.c colours.h

# Function to run hello program in a new terminal
run_client() {
    gnome-terminal --tab --title="Terminal 1" -- bash -c "./client; read -p 'Press Enter to close this terminal.'"
    sleep 1
}

run_server1() {
    gnome-terminal --tab --title="Terminal 2" -- bash -c "./server1; read -p 'Press Enter to close this terminal.'"
    sleep 1
}

run_server2() {
    gnome-terminal --tab --title="Terminal 3" -- bash -c "./server2; read -p 'Press Enter to close this terminal.'"
    sleep 1
}

# Run the program in three terminals
run_server1
run_server2
run_client

# Clean up compiled executable
rm client
rm server1
rm server2
