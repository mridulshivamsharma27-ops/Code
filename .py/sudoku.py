class SudokuSolver:
    def __init__(self, board):
        self.board = board

    def display(self):
        """Prints the board nicely formatted."""
        for i in range(9):
            if i % 3 == 0 and i != 0:
                print("-" * 21)

            for j in range(9):
                if j % 3 == 0 and j != 0:
                    print("| ", end="")

                val = self.board[i][j]
                # Print '.' for empty cells (0)
                print(f"{val if val != 0 else '.'} ", end="")
            print()

    def is_valid(self, row, col, num):
        """Checks if placing 'num' at (row, col) is valid."""
        # Row Check
        if num in self.board[row]:
            return False

        # Column Check
        if num in [self.board[i][col] for i in range(9)]:
            return False

        # 3x3 Box Check
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if self.board[i][j] == num:
                    return False
        
        return True

    def solve(self):
        """Backtracking algorithm to find the solution."""
        for row in range(9):
            for col in range(9):
                if self.board[row][col] == 0:  # Empty cell found
                    
                    for num in range(1, 10):   # Try 1-9
                        if self.is_valid(row, col, num):
                            self.board[row][col] = num

                            if self.solve():
                                return True

                            self.board[row][col] = 0  # Backtrack

                    return False
        return True

# --- Main Program ---

# 1. Define the Puzzle
puzzle = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

game = SudokuSolver(puzzle)

# 2. Show Unsolved Board
print("\n--- UNSOLVED SUDOKU ---")
game.display()

# 3. WAIT for user input
# The program pauses here until you type something and press Enter
input("\nType 'solution' and press Enter to see the answer... ")

# 4. Solve and Show Answer
print("\n... Calculating ...\n")
if game.solve():
    print("--- ANSWER ---")
    game.display()
else:
    print("No solution exists.")