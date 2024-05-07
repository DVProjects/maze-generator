rows=5
cols=5

run: maze
	./maze $(rows) $(cols) $(seed)

maze: maze.c 
	gcc maze.c -o maze > log.txt
