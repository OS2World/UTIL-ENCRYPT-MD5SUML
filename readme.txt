The MD5SUML utility allows you to calculate MD5 checksums for files larger
than 2 GB. The code is derived from the RSA Data Security, Inc.
MD5 Message-Digest Algorithm.

DISCLAIMER
There is no warranty that the program fits any particular purpose or will not
cause any damage. The program and sources are provided "as is" and may only
be used at your own risk.

DESCRIPTION

MD5SUML calculates MD5 checksums like many other programs.
It simply includes the feature of checking large files.
The source can be compiled with VisualAge C++ 3.0 for OS/2 without having
the Warp Developer's Toolkit 4.5 installed. Users of OpenWatcom may compile
the source in case OS2386.LIB of the Toolkit 4.5 is available for linking.
I have tested MD5SUML with a file of size 4,295,032,832 bytes which is beyond
the 4 GB barrier. The command-line switch "/d" has been included to provide
some reading friendly output. No specific error handling has been implemented.

It may be distributed freely as long as all copyright notices are preserved.

Comments and bug reports are welcome and should be e-mailed to
toriani@hotmail.com

FIlE LIST

D6F8-4E04-4AC4-0707-3196-3B50-22B6-99C5 FILE.C
B9BD-47DD-2669-D183-C79B-78A1-79D0-3CE1 FILE.H
691B-8D13-787E-4004-2408-F4CE-5DE6-582F GLOBAL.H
507F-9BF0-D724-939E-BC5E-83BC-CEAB-A6B9 MD5.C
2B47-6851-AFB8-F90D-8D59-6F6B-7B37-A1DA MD5.H
E33A-EADD-71C6-8553-76E6-6A8D-B966-939A MD5SUML.C
9257-F85C-19AA-BD94-BD59-3F54-0FE4-2F02 MD5SUML.DEF
1F51-1797-DEB4-FFD5-BEB3-6B92-DBCA-43D5 MD5SUML.EXE
7BE0-BFB1-3DE1-FBAD-E507-60FB-73E3-F5EE MD5SUML.MAK

(c) 2004 Axel Meiss





