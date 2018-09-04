#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void main(int argc,char *argv[]){
unsigned char isf=1;
if(argc!=3){
printf("bta <binary> <c>\n");
exit(1);
}
FILE *bin=fopen(argv[1],"r");
assert(bin!=NULL);
FILE *c=fopen(argv[2],"w");
assert(c!=NULL);
fprintf(c,"unsigned char *bin={");
unsigned int this;
while(1){
this=fgetc(bin);
if(this==EOF){
fprintf(c,"};");
exit(0);
}
if(isf==1){
fprintf(c,"0x%.2X",(unsigned char)this);
isf=0;
continue;
}
fprintf(c,",0x%.2X",(unsigned char)this);
}
fprintf(stderr,"?? Jumped out while(1)?\n");
assert(0);
}
