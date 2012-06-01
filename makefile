# Encore un petit effort et ça marche presque tout seul !

# Personne ne pourra deviner son nom pour vous
CIBLE=RPG

# AUTO : les sources
SOURCES=$(wildcard *.cpp)
# AUTO : les entêtes
HEADERS=$(wildcard *.hpp)
# AUTO : les objets
OBJETS=$(patsubst %.cpp,%.o,$(SOURCES))

### les FLAGS pour tout contrôler (rappel : ajustables sur la ligne de commande)
# FLAGS de précompilation (-I... pour la recherche des .hpp ...)
# CPPFLAGS=
# FLAGS de compilations (-g, -O ...)
override CXXFLAGS+=-Wall -g
# FLAGS pour l'édition des liens (-L... -l... librairies et leurs chemins ...)
#LDFLAGS= 

# La cible principale
$(CIBLE): $(OBJETS)
	$(CXX) -g -o $@ $^ $(LDFLAGS)

# Une règle pour mettre les dépendances dans un fichier ...
depends: $(SOURCES) $(HEADERS)
	$(CXX) -MM $(SOURCES) > $@ 
# ... que l'on inclu ici
-include depends

# Un raffinement (pour toutes les régles dont la cible n'est pas un fichier)
.PHONY: clear

# De quoi revenir au minimum indispensable
clear:
	@$(RM) a.out core *~ *.o depends
