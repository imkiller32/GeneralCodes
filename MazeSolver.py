#PYTHON_MAZE_SOLVER

ASCII_MAZE1 = """
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|        |        |                                            |
+  +--+  +  +--+--+  +--+--+--+--+--+--+--+--+--+  +--+--+--+  +
|     |     |        |     |     |              |     |        |
+--+  +  +--+  +--+--+  +  +  +  +  +--+--+--+  +--+  +  +--+--+
|     |  |     |        |     |  |        |  |  |     |     |  |
+  +--+  +  +--+  +--+--+--+--+--+--+  +--+--+  +--+--+--+  +--+
|  |     |  |  |  |              |  |  |     |        |  |     |
+  +--+--+  +--+  +  +--+--+--+  E  +  +  +  +--+  +  +--+--+  +
|        |  |     |     |     |  |  |     |     |  |           |
+  +--+  +  +  +--+--+  +--+  +  +--+--+--+--+  +  +--+--+--+--+
|  |     |  |        |     |  |              |  |           |  |
+  +  +--+  +--+--+--+--+  +  +--+--+--+--+  +  +--+  +--+  +--+
|  |  |                    |              |  |     |  |  |     |
+  +  +  +--+--+--+--+--+--+--+  +--+--+  +- +--+  +  +  +--+  +
|  |        |     |                    |  |     |  |     |     |
+  +--+--+  +  +  +  +--+  +--+--+  +--+--+  +  +  +--+  +  +--+
|  |        |  |  |     |        |  |        |  |  |  |  |     |
+  +  +--+--+  +  +--+  +  +--+--+--+  +--+--+--+  +  +  +--+  +
|  |  |        |     |  |     |     |           |  |     |  |  |
+  +  +  +--+--+--+--+  +--+  +  +--+--+--+--+  +  +--+--+--+  +
|  |                          |     |  |  |     |        |  |  |
+  +  +--+--+--+--+--+--+--+--+--+  +--+--+  +--+--+--+  +--+  +
|  |        |     |  |        |  |  |  |              |  |     |
+--+--+--+  +  +  +  +  +--+  +--+  +--+  +--+  +--+--+  +  +--+
|     |     |  |  |  |  |  |        |  |  |     |     |  |     |
+  +--+  +--+  +  +  +  +--+--+--+--+--+  +  +--+  +  +  +--+--+
|           |  |  |  |                 |  |  |     |  |        |
+--+--+--+  +--+  +  +--+--+--+--+--+  +  +  +--+--+--+--+--+  +
S          |                 |     |              |            +
+-----+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
"""

ASCII_MAZE2 = """
___________________________________  
| _____ |   | ___ | ___ ___ | |   | |
| |   | |_| |__ | |_| __|____ | | | |
| | | |_________|__ |______ |___|_| |
| |_|   | _______ |______ |   | ____|
| ___ | |____ | |______ | |_| |____ |
|___|_|____ | |   ___ | |________ | E
|   ________| | |__ | |______ | | | |
| | | ________| | __|____ | | | __| |
|_| |__ |   | __|__ | ____| | |_| __|
|   ____| | |____ | |__ |   |__ |__ |
S |_______|_______|___|___|___|_____|
"""

ASCII_MAZE3 = """
"""

ASCII_MAZE4 = """
"""

ASCII_MAZE5 = """
"""

PATH, START, EXIT, VISITED, SOLUTION = " SE.#"

class Maze():
    def __init__(self, ascii_maze):
        self.maze = [list(row) for row in ascii_maze.splitlines()]
        self.start_y = [row.count(START) for row in self.maze].index(1)
        self.start_x = self.maze[self.start_y].index(START)

    def __repr__(self):
        return "\n".join("".join(row) for row in self.maze)

    def solve(self, x = None, y = None):
        if x == None:
            x, y = self.start_x, self.start_y
        if x>63 or x<0 or y<0 or y>31:
            return False
        #print(self.maze[y][x])
        if self.maze[y][x] in (PATH, START):
            self.maze[y][x] = VISITED
            if( self.solve(x+1,y) or self.solve(x-1,y) or self.solve(x,y+1) or self.solve(x,y-1) ):
                self.maze[y][x] = SOLUTION
                return True
        elif self.maze[y][x] == EXIT:
            return True
        return False

if __name__ == "__main__":
    maze = Maze(ASCII_MAZE1)
    if (maze.solve()):
        print (maze)
    else:
        print (maze)
        print("No Solution Found For Given Start and End of maze 1")
        
