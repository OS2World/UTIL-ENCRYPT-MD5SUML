# md5suml.mak 19-Feb-2004 14:46:10 Axel Meiss
CC = icc
LINKER = ilink
DEBUG = 0
CCFLAGS =  /c
LFLAGS = /PMTYPE:VIO /STACK:32768 /NOFREE
CCFLAGS_D = /Ti+
CCFLAGS_R =
LFLAGS_D = /DEBUG /MAP /PMTYPE:VIO /STACK:32768 /NOFREE
LFLAGS_R =

all: md5suml.exe

md5suml.exe: md5suml.obj md5.obj file.obj md5suml.def
!IF $(DEBUG) != 0
  $(LINKER) $(LFLAGS) $(LFLAGS_D) md5suml.obj md5.obj file.obj md5suml.def
!ELSE
  $(LINKER) $(LFLAGS) $(LFLAGS_R) md5suml.obj md5.obj file.obj md5suml.def
!ENDIF


md5suml.obj: md5suml.c md5.h file.h global.h
!IF $(DEBUG) != 0
  $(CC) $(CCFLAGS) $(CCFLAGS_D) md5suml.c
!ELSE
  $(CC) $(CCFLAGS) $(CCFLAGS_R) md5suml.c
!ENDIF
md5.obj: md5.c md5.h global.h
!IF $(DEBUG) != 0
  $(CC) $(CCFLAGS) $(CCFLAGS_D) md5.c
!ELSE
  $(CC) $(CCFLAGS) $(CCFLAGS_R) md5.c
!ENDIF
file.obj: file.c file.h
!IF $(DEBUG) != 0
  $(CC) $(CCFLAGS) $(CCFLAGS_D) file.c
!ELSE
  $(CC) $(CCFLAGS) $(CCFLAGS_R) file.c
!ENDIF
