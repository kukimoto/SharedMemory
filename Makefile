all:shmCommon.cpp shmViewer.cpp shmWrite.cpp
	g++ -o shmViewer shmViewer.cpp shmCommon.cpp
	g++ -o shmWrite shmWrite.cpp shmCommon.cpp
