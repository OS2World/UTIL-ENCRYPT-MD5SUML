/** MD5SUML.C Copyright (c) 2004 Axel Meiss                                **/
/** may be distributed freely as long as copyright notice is preserved     **/
/** derived from the RSA Data Security, Inc. MD5 Message-Digest Algorithm  **/
/** It is provided "as is" without express or implied warranty of any kind **/



#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define PROTOTYPES

#include "global.h"
#include "md5.h"
#include "file.h"



void main (int argc, char *argv[])
{
  MD5_CTX context;
  int len;
  int iSepSize;
  int iSeparatorFlag = 0;
  unsigned char digest[16];
  long l_FileSize;
  unsigned long ulFileHandle;
  unsigned long ulErrorCode;
  unsigned char filebuffer[1024];

  FILE *fp;
  char *pszFileName;

  if(argc < 2)
  {
    printf("Usage: %s [/d] <file> ", argv[0]);
    exit(1);
  }
  if(argc == 3)
  {
    if(*argv[1] == '/')
    {
      if(toupper(*(argv[1] + 1)) == 'D')
        iSeparatorFlag = 1;

      pszFileName = argv[2];
    }
    else
      pszFileName = argv[1];
  }
  else
    pszFileName = argv[1];


  if((ulFileHandle = LFileOpen(pszFileName)) != 0)
  {
    MD5Init(&context);

    while((l_FileSize =
           LFileRead(filebuffer,sizeof(filebuffer),ulFileHandle))
           == sizeof(filebuffer))
    {
      MD5Update(&context,filebuffer,sizeof(filebuffer));
    }

    if((ulErrorCode = LGetLastFileError()) == 0)
    {
      MD5Update(&context,filebuffer,l_FileSize);
      MD5Final(digest,&context);
      for(len = 0;len < sizeof(digest);len += 2)
      {
        printf("%02X%02X",digest[len],digest[len + 1]);
        if(iSeparatorFlag == 1 && len < sizeof(digest) - 2)
          putchar('-');
      }
      printf(" %s\n",pszFileName);

    }
    else
      fprintf(stderr,"File error: %ld", ulErrorCode);

    LFileClose(ulFileHandle);
  }
  else
  {
    ulErrorCode = LGetLastFileError();
    fprintf(stderr,"File error: %ld", ulErrorCode);
  }
  exit(0);
}
