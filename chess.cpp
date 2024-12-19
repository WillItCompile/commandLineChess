#include <iostream>
#include <string>

// Global spaces array declaration
char spaces[144] = { 
    ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', ' ', ' ',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    '1', ' ', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', ' ', '2',
    '2', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', ' ', '2',
    '3', ' ', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', ' ', '3',
    '4', ' ', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', ' ', '4',
    '5', ' ', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', ' ', '5',
    '6', ' ', 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x', ' ', '6',
    '7', ' ', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', ' ', '7',
    '8', ' ', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R', ' ', '8',
    ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
    ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', ' ', ' ' 
};

void drawBoard(char *spaces) {
    for (int i = 0; i < 144; i++) {
        if (i % 12 == 0) {
            std::cout << "\n";  // Start a new row every 12 elements
        }
        std::cout << "  " << spaces[i];  // Print the current space
    }
}

void playerMove(char *spaces, char player) {
    int row, col, result;
    std::string pieceLoc;

    std::cout << "Enter the corresponding letter and number for where you want to move your piece (e.g., a1): ";
    std::cin >> pieceLoc;

    col = pieceLoc[0] - 'a';  // Convert column letter to 0-indexed column
    row = pieceLoc[1] - '1';  // Convert row number to 0-indexed row

    if (col >= 0 && col < 8 && row >= 0 && row < 8) {
        result = ((row)* 12) + (col);  // Calculate the 1D array index
        std::cout << spaces[result];
        // Check if the space is empty
    //     if (spaces[result] == 'x') {
    //         spaces[result] = player;  // Place the player's piece
    //         std::cout << "Player " << player << " moved to " << pieceLoc << "." << std::endl;
    //     } else {
    //         std::cout << "That space is already occupied. Try again." << std::endl;
    //     }
    // } else {
    //     std::cout << "Invalid position. Try again." << std::endl;
    // }
    }
}

int main() {
    drawBoard(spaces);  // Display the board

    char currentPlayer = 'X';  // Let's assume player X moves first
    playerMove(spaces, currentPlayer);  // Let player X make a move

    drawBoard(spaces);  // Display the board after the move

    return 0;
}
