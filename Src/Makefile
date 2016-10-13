TARGET = kof
CC = gcc

LIBS = main.o
LIBS += athena.o
LIBS += init.o
LIBS += kernel.o
LIBS += key.o
LIBS += public.o
LIBS += show.o

LDFLAGS =  -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -lX11

$(TARGET): $(LIBS)
	$(CC) $^ -o $@ $(LDFLAGS)
%.o:%.c
	$(CC) -c $< -o $@
clean:
	rm $(LIBS) $(TARGET) -f
