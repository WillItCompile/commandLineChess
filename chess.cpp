#include <iostream>
#include <string>

char spaces[64] = { 
    'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
    'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
    'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
    'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
    'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'
};

void helperDrawBoard(int index) {
    for (int i = 0; i < 8; i++) {
        std::cout << spaces[index + i] << " ";
    }
}
void drawBoard() {
    std::cout << '\n';
    
    std::cout << "  ";
    for (char col = 'a'; col <= 'h'; col++) {
        std::cout << col << " ";  
    }
    std::cout << "\n";

    for (int row = 0; row < 8; row++) {

        std::cout << 8 - row << " ";

        int startIndex = row * 8;

        helperDrawBoard(startIndex);

        std::cout << 8 - row << "\n";
    }
    
    std::cout << "  ";
    for (char col = 'a'; col <= 'h'; col++) {
        std::cout << col << " "; 
    }
    std::cout << "\n";
}

void pieceSwap(int curr, int updated) {
    int temp;
    temp = spaces[updated];
    spaces[updated] = spaces[curr];
    spaces[curr] = temp;
}

void playerMove(char *spaces) {
    int rowIn, rowOut, colIn, colOut, resultIn, resultOut;
    std::string pieceLoc;

    std::cout << "Enter the corresponding letter and number for where the piece you want to move is (e.g., a1): ";
    std::cin >> pieceLoc;

    colIn = pieceLoc[0] - 'a'; 
    rowIn = pieceLoc[1] - '1';  

    if (colIn >= 0 && colIn < 8 && rowIn >= 0 && rowIn < 8) {
        resultIn = ((rowIn)* 8) + (colIn);  
        // std::cout << spaces[result];
    }

    std::cout << "Enter the corresponding letter and number for where you want to move the piece (e.g., a1): ";
    std::cin >> pieceLoc;

    colOut = pieceLoc[0] - 'a'; 
    rowOut = pieceLoc[1] - '1';  

    if (colIn >= 0 && colIn < 8 && rowIn >= 0 && rowIn < 8) {
        resultIn = ((rowIn)* 8) + (colIn);  
         std::cout << spaces[resultIn];
    }

    if (colOut >= 0 && colOut < 8 && rowOut >= 0 && rowOut < 8) {
        resultOut = ((rowOut)* 8) + (colOut);  
         std::cout << spaces[resultOut];
    }
    pieceSwap(resultIn,resultOut);
}



int main() {
    drawBoard();  

    playerMove(spaces);  

    drawBoard();  

    return 0;
}
