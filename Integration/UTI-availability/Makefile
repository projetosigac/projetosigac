ROOT=./
CC_FLAGS=-ansi -I . -I ../../UA/UTI-availability/KCG/ -I ../CommunicationFramework/ -I "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/" -I "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/include" -Wall -Wno-unused-variable -Wno-unused-function -Wno-unused-value
SRC=UTI-availability.c ../CommunicationFramework/CommunicationFramework.c ../../UA/UTI-availability/KCG/kcg_consts.c ../../UA/UTI-availability/KCG/kcg_types.c ../../UA/UTI-availability/KCG/UTI.c ../../UA/UTI-availability/KCG/ua.c

OBJ=$(SRC:.c=.o)

UTI-availability.exe: $(OBJ)
	gcc -o $@ $(OBJ)

.c.o:
	gcc $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) UTI-availability.exe

.PHONY: clean
