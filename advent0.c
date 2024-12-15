/** 
 * @file 
 */

/*      program ADVENT0.C                                       *\
        \*      execution will read the four adventure text files       *\
        \*      files; "advent1.txt", "advent2.txt", "advent3.txt" &    *\
        \*      "advent4.txt".  it will create the file "advtext.h"     *\
        \*      which is an Index Sequential Access Method (ISAM)       *\
        \*      header to be #included into "advent.c" before the       *\
        \*      header "advdef.h" is #included.                         */


#include        <stdio.h>       /* drv = 1.1st file 2.def 3.A   */
#include        "advent.h"

/* #ifndef __QNX__ */
/* extern       int     fclose(); */
/* extern       char    *fgets(); */
/* extern       FILE    *fopen(); */
/* extern       int     fprintf(); */
/* extern       int     fputs(); */
/* extern       long    ftell(); */
/* extern       int     printf(); */
/* #else */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* #define Ltoa(a,b) strlen(ltoa(a,b,10)) */ 
#define Ltoa(a,b) sprintf((b), "%ld", (long)(a))
/* #endif */



int main(int argc, char** argv)
{
    FILE    *isam, *fd1, *fd2, *fd3, *fd4;
    char    itxt[255], otxt[80], lstr[12];
    int     cnt, llen;
    char*   text1   = argc==1 ? "advent1.txt" : argv[1];
    char*   text2   = argc==1 ? "advent2.txt" : argv[2];
    char*   text3   = argc==1 ? "advent3.txt" : argv[3];
    char*   text4   = argc==1 ? "advent4.txt" : argv[4];
    char*   outfile = argc==1 ? "advtext.h" : argv[5];

    if (! (argc == 1 || argc == 6)) {
        printf("Usage: %s [ADVENT1_FILE ADVENT2_FILE ADVENT3_FILE ADVENT4_FILE OUTFILE.H]\n", argv[0]);
        exit(-1);
    }

    printf("text1 is %s\n", text1);
    printf("text2 is %s\n", text2);
    printf("text3 is %s\n", text3);
    printf("text4 is %s\n", text4);
    printf("outfile is %s\n", outfile);
        
    isam = fopen(outfile, "w");
    if (!isam) {
        printf("Sorry, I can't open advtext.h...\n");
        exit(-1);
    }
    fd1 = fopen(text1, "r");
    if (!fd1) {
        printf("Sorry, I can't open advent1.txt...\n");
        exit(-1);
    }
    fd2 = fopen(text2, "r");
    if (!fd2) {
        printf("Sorry, I can't open advent2.txt...\n");
        exit(-1);
    }
    fd3 = fopen(text3, "r");
    if (!fd3) {
        printf("Sorry, I can't open advent3.txt...\n");
        exit(-1);
    }

    fd4 = fopen(text4, "r");
    if (!fd4) {
        printf("Sorry, I can't open advent4.txt...\n");
        exit(-1);
    }

    fprintf(isam, "\n/");
    fprintf(isam, "*\theader: ADVTEXT.H\t\t\t\t\t*/\n\n\n");


    cnt = -1;
    lstr[0] = '\0';
    fprintf(isam, "long\tidx1[MAXLOC] = {\n\t");
    while (fgets(itxt, 255, fd1)) {
/*              printf("%s", itxt); */
        if (itxt[0] == '#') {
            if (lstr[0])
                fprintf(isam, "%s,", lstr);
            llen = Ltoa(ftell(fd1), lstr);
            if (!llen) {
                printf("Ltoa err in advent1.txt\n");
                exit(-1);
            }                       /* if (!llen)   */
            if (++cnt == 5) {
                fprintf(isam, "\n\t");
                cnt = 0;
            }                       /* if (cnt)     */
        }                               /* if (itxt[0]) */
    }                                       /* while fgets  */
    fprintf(isam, "%s\n\t};\n\n", lstr);

    cnt = -1;
    lstr[0] = '\0';
    fprintf(isam, "long\tidx2[MAXLOC] = {\n\t");
    while (fgets(itxt, 255, fd2)) {
/*              printf("%s", itxt); */
        if (itxt[0] == '#') {
            if (lstr[0])
                fprintf(isam, "%s,", lstr);
            llen = Ltoa(ftell(fd2), lstr);
            if (!llen) {
                printf("Ltoa err in advent2.txt\n");
                exit(-1);
            }                       /* if (!llen)   */
            if (++cnt == 5) {
                fprintf(isam, "\n\t");
                cnt = 0;
            }                       /* if (cnt)     */
        }                               /* if (itxt[0]) */
    }                                       /* while fgets  */
    fprintf(isam, "%s\n\t};\n\n", lstr);

    cnt = -1;
    lstr[0] = '\0';
    fprintf(isam, "long\tidx3[MAXOBJ] = {\n\t");
    while (fgets(itxt, 255, fd3)) {
/*              printf("%s", itxt); */
        if (itxt[0] == '#') {
            if (lstr[0])
                fprintf(isam, "%s,", lstr);
            llen = Ltoa(ftell(fd3), lstr);
            if (!llen) {
                printf("Ltoa err in advent3.txt\n");
                exit(-1);
            }                       /* if (!llen)   */
            if (++cnt == 5) {
                fprintf(isam, "\n\t");
                cnt = 0;
            }                       /* if (cnt)     */
        }                               /* if (itxt[0]) */
    }                                       /* while fgets  */
    fprintf(isam, "%s\n\t};\n\n", lstr);

    cnt = -1;
    lstr[0] = '\0';
    fprintf(isam, "long\tidx4[MAXMSG] = {\n\t");
    while (fgets(itxt, 255, fd4)) {
/*              printf("%s", itxt); */
        if (itxt[0] == '#') {
            if (lstr[0])
                fprintf(isam, "%s,", lstr);
            llen = Ltoa(ftell(fd4), lstr);
            if (!llen) {
                printf("Ltoa err in advent4.txt\n");
                exit(-1);
            }                       /* if (!llen)   */
            if (++cnt == 5) {
                fprintf(isam, "\n\t");
                cnt = 0;
            }                       /* if (cnt)     */
        }                               /* if (itxt[0]) */
    }                                       /* while fgets  */
    fprintf(isam, "%s\n\t};\n\n", lstr);

    fclose(isam);
    fclose(fd1);
    fclose(fd2);
    fclose(fd3);
    fclose(fd4);
    printf("Datafile processing done!!\n");
    return(0);
}                                               /* main         */


