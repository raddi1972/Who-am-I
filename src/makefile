all_sources = Main.cpp Application.cpp Helper.cpp HollowKnight.cpp Physics.cpp Spritesheet.cpp Object.cpp Ledge.cpp Map.cpp Health.cpp SDCounter.cpp NDCounter.cpp CannonFire.cpp Crawlid.cpp Enemy.cpp ShootingEnemy.cpp EnemyController.cpp Attack.cpp
DEPS = Core.h Application.h Helper.h HollowKnight.h Physics.h Spritesheet.h Object.h Ledge.h Map.h Health.h SDCounter.h NDCounter.h CannonFire.h Crawlid.h Enemy.h ShootingEnemy.h EnemyController.h Attack.h
all_objs = $(all_sources:.cpp=.o)
project : $(all_objs)
	g++-11 -o project $(all_objs) -F/library/Frameworks -framework SDL2
%.o : %.cpp $(DEPS)
	g++-11 -c $<
source_file.o : $(all_sources)
	g++-11 -c $^
clean:
	rm project *.o