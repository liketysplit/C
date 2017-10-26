gameoflife: life.o neighborcount.o neighborvalue.o organismcalc.o liferule.o titlecreation.o randomspawn.o printboard.o
	gcc life.o neighborcount.o neighborvalue.o organismcalc.o liferule.o titlecreation.o randomspawn.o printboard.o -o gameoflife
life.o: life.c globalv.h printBoard.h titleCreation.h liferule.h printboard.h organismcalc.h randomspawn.h titlecreation.h
	gcc -c life.c -o life.o
neighborcount.o: neighborcount.c globalv.h neighborcount.h neighborvalue.h
	gcc -c neighborcount.c -o neighborcount.o
neighborvalue.o: neighborvalue.c neighborvalue.h
	gcc -c neighborvalue.c -o neighborvalue.o
organismcalc.o: organismcalc.c globalv.h organismcalc.h
	gcc -c organismcalc.c -o organismcalc.o
liferule.o: liferule.c globalv.h liferule.h
	gcc -c liferule.c -o liferule.o
titlecreation.o: titlecreation.c globalv.h titlecreation.h
	gcc -c titlecreation.c -o titlecreation.o
randomspawn.o: randomspawn.c globalv.h randomspawn.h
	gcc -c randomspawn.c -o randomspawn.o
printboard.o: printboard.c globalv.h printboard.h
	gcc -c printboard.c -o printboard.o
clean :
	rm gameoflife life.o neighborcount.o neighborvalue.o organismcalc.o liferule.o titlecreation.o randomspawn.o printboard.o
