all:

build:
	gcc hanoi.c -o hanoi
	gcc merge-sort.c -o merge
	gcc spectacol.c -o spectacol
	gcc backpack.c -o backpack
	gcc backpack_d.c -o backpack_d
	gcc subsir_crescator.c -o subsir
	gcc sumemod3.c -o sumemod3
	gcc garduri.c -o garduri
	gcc backtrack.c -o backtrack
	gcc bfs.c -o bfs
	gcc dfs.c -o dfs

clean:
	rm hanoi
	rm merge
	rm spectacol
	rm backpack
	rm backpack_d
	rm subsir
	rm sumemod3
	rm garduri
	rm backtrack
	rm bfs
	rm dfs

hanoi:
	./hanoi

merge:
	./merge

spectacol:
	./spectacol

backpack:
	./backpack

backpackd:
	./backpack_d
	
subsir:
	./subsir

sumemod3:
	./sumemod3

garduri:
	./garduri

backtrack:
	./backtrack

bfs:
	./bfs

dfs:
	./dfs
