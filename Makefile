rows=5
cols=5

run: maze
	./maze $(rows) $(cols) $(seed) 2>>log.txt

maze: maze.c 
	gcc maze.c -o maze

clean:
	rm maze
	rm log.txt
