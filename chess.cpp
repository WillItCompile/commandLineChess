#include <iostream>
#include <string>
#include <cstdlib>

struct Piece {
    char type;    
    bool color;  
};

Piece spaces[64];

void initializeBoard() {
    // white pieces
    spaces[0] = {'R', false}; spaces[1] = {'N', false}; spaces[2] = {'B', false}; spaces[3] = {'Q', false}; 
    spaces[4] = {'K', false}; spaces[5] = {'B', false}; spaces[6] = {'N', false}; spaces[7] = {'R', false};
    for (int i = 8; i < 16; i++) {
        spaces[i] = {'P', false};  
    }

    // black pieces
    spaces[56] = {'R', true}; spaces[57] = {'N', true}; spaces[58] = {'B', true}; spaces[59] = {'Q', true}; 
    spaces[60] = {'K', true}; spaces[61] = {'B', true}; spaces[62] = {'N', true}; spaces[63] = {'R', true};
    for (int i = 48; i < 56; i++) {
        spaces[i] = {'P', true};  
    }

    
    for (int i = 16; i < 48; i++) {
        spaces[i] = {'.', true};  
    }
}

void drawBoard() {
   for (int row = 7; row >= 0; row--) {
        std::cout << row + 1 << " ";  

        for (int col = 0; col < 8; col++) {
            int index = row * 8 + col;  // calculates correct index
            char pieceType = spaces[index].type;
            bool pieceColor = spaces[index].color;

            if (pieceType == '.') {
                std::cout << ". "; 
            } else {
                if (pieceColor == false) {  // white pieces
                    std::cout << pieceType << " ";
                } else {  // black pieces
                    std::cout << pieceType << " ";
                }
            }
        }
        std::cout << "\n"; 
    }

    std::cout << "  a b c d e f g h\n";  
}

void pieceSwap(int curr, int updated) {
    Piece temp;
    temp = spaces[updated];
    spaces[updated] = spaces[curr];
    spaces[curr] = temp;
}

void playerMove() {
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
    rowOut = (pieceLoc[1] - '1');  

    if (colIn >= 0 && colIn < 8 && rowIn >= 0 && rowIn < 8) {
        resultIn = ((rowIn)* 8) + (colIn);  
        //  std::cout << spaces[resultIn].type;
    }

    if (colOut >= 0 && colOut < 8 && rowOut >= 0 && rowOut < 8) {
        resultOut = ((rowOut)* 8) + (colOut);  
        //  std::cout << spaces[resultOut].type;
    }
    pieceSwap(resultIn,resultOut);
}



int main() {

    initializeBoard();

    drawBoard();  

    playerMove();  

    drawBoard();  

    return 0;
}
