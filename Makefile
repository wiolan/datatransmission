CC = g++
FLAGS = -L/usr/include/mysql -lmysqlclient -I/user/include/mysql
TARGET = testBuild
SOURCE = main.cpp DataT.cpp

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) $(FLAGS)

pedant: $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET) -Wall -pedantic  $(FLAGS)

clean: $(TARGET_2D) $(TARGET_3D)
	rm $(TARGET)