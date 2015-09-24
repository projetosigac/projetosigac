ROOT=./
CC_FLAGS=-ansi -I . -I ../../UA/UTICounts/KCG/ -I ../CommunicationFramework/ -I "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/" -I "C:/Program Files (x86)/Esterel Technologies/Esterel SCADE 6.4.2/SCADE/include" -Wall -Wno-unused-variable -Wno-unused-function -Wno-unused-value
SRC=UTICounts.c ../CommunicationFramework/CommunicationFramework.c ../../UA/UTICounts/KCG/kcg_consts.c ../../UA/UTICounts/KCG/kcg_types.c ../../UA/UTICounts/KCG/UTICounts.c ../../UA/UTICounts/KCG/ua.c

OBJ=$(SRC:.c=.o)

UTICounts.exe: $(OBJ)
	gcc -o $@ $(OBJ)

.c.o:
	gcc $(CC_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) UTI-availability.exe

.PHONY: clean
