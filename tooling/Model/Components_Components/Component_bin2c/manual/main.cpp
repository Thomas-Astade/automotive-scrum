 // bin2c.c
 //
 // convert a binary file into a C source vector
 //
 // put into the public domain by Sandro Sigala
 //
 // syntax:  bin2c [-c] [-z] <input_file> <output_file>
 //
 //          -c    add the "const" keyword to definition
 //          -z    terminate the array with a zero (useful for embedded C strings)
 //
 // examples:
 //     bin2c -c myimage.png myimage_png.cpp
 //     bin2c -z sometext.txt sometext_txt.cpp

#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <utime.h>
#include <sys/stat.h>

 int useconst = 0;
 int zeroterminated = 0;

 int myfgetc(FILE *f)
 {
 	int c = fgetc(f);
 	if (c == EOF && zeroterminated) {
 		zeroterminated = 0;
 		return 0;
 	}
 	return c;
 }

 void process(const char *ifname, const char *ofname)
 {
 	FILE *ifile, *ofile;

 	ifile = fopen(ifname, "rb");
 	if (ifile == NULL) {
 		fprintf(stderr, "cannot open %s for reading\n", ifname);
 		exit(1);
 	}
 	ofile = fopen(ofname, "w");
 	if (ofile == NULL) {
 		fprintf(stderr, "cannot open %s for writing\n", ofname);
 		exit(1);
 	}

	struct stat statbuf;
	stat(ifname, &statbuf);

 	char buf[PATH_MAX], *p;
 	const char *cp;
 	if ((cp = strrchr(ifname, '/')) != NULL)
 		++cp;
 	else if ((cp = strrchr(ifname, '\\')) != NULL)
 		++cp;
 	else
 		cp = ifname;
 	strcpy(buf, cp);
 	for (p = buf; *p != '\0'; ++p)
 		if (!isalnum(*p))
 			*p = '_';
 	fprintf(ofile, "static %sunsigned char %s[] = {\n", useconst ? "const " : "", buf);
 	int c, col = 1;
 	while ((c = myfgetc(ifile)) != EOF) {
 		if (col >= 78 - 6) {
 			fputc('\n', ofile);
 			col = 1;
 		}
 		fprintf(ofile, "0x%.2x, ", c);
 		col += 6;

 	}
 	fprintf(ofile, "\n};\n");

 	fclose(ifile);
 	fclose(ofile);

	struct utimbuf times;
	times.actime  = statbuf.st_mtime;
	times.modtime = statbuf.st_mtime;
	utime(ofname, &times);
 }

 void usage(void)
 {
 	fprintf(stderr, "usage: bin2c [-cz] <input_file> <output_file>\n");
 	exit(1);
 }

 int main(int argc, char **argv)
 {
 	while (argc > 3) {
 		if (!strcmp(argv[1], "-c")) {
 			useconst = 1;
 			--argc;
 			++argv;
 		} else if (!strcmp(argv[1], "-z")) {
 			zeroterminated = 1;
 			--argc;
 			++argv;
 		} else {
 			usage();
 		}
 	}
 	if (argc != 3) {
 		usage();
 	}
 	process(argv[1], argv[2]);
 	return 0;
 }
