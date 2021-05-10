#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c,K,T;
    FILE *fp1,*fp2,*fp3;
 // 1. oldal bek�r�se:
    fp1=fopen("adat1.txt", "r");
    if (fp1==NULL){
        printf("Nem adta meg az \"a\" oldal hosszat!\n");
        exit(1);
    }
    else {
        fscanf(fp1,"%d",&a);
        printf("Az \"a\" oldal hossza: %d cm.\n",a);
        fclose(fp1);
    }
// 2. oldal bek�r�se:
        fp2=fopen("adat2.txt", "r");
    if (fp2==NULL){
        printf("Nem adta meg az \"b\" oldal hosszat!\n");
        exit(1);
    }
    else {
        fscanf(fp2,"%d",&b);
        printf("A \"b\" oldal hossza: %d cm.\n",b);
        fclose(fp2);
    }
 // 3. oldal bek�r�se:
        fp3=fopen("adat3.txt", "r");
    if (fp3==NULL){
        printf("Nem adta meg az \"c\" oldal hosszat!\n");
        exit(1);
    }
    else {
        fscanf(fp3,"%d",&c);
        printf("A \"c\" oldal hossza: %d cm.\n",c);
        fclose(fp3);
    }
/* T�TEL: A h�romsz�g b�rmely oldal�nak hossza kisebb a m�sik k�t oldal hossz�nak �sszeg�n�l.
Azaz a<b+c �s b<a+c �s c<a+b */
    if (a<b+c && b<a+c && c<a+b){
        K=a+b+c;

        long s = (a + b + c)/2;
        T=sqrt(s*(s-a)*(s-b)*(s-c));

        printf("A haromszog szerkesztheto.\nK=%d cm\nT=%d cm2",K,T);
        FILE * fpointer = fopen("kimenet.txt", "w");
        fprintf(fpointer, "A h�romsz�g szerkeszthet�.\nK=%d cm\nT=%d cm2",K,T);
        fclose(fpointer);
    }
    else {
        K=-1;
        T=-1;
        printf("A haromszog nem szerkesztheto.\nK=%d cm\nT=%d cm2",K,T);
        FILE * fpointer2 = fopen("kimenet.txt", "w");
        fprintf(fpointer2, "A h�romsz�g nem szerkeszthet�.\nK=%d cm\nT=%d cm2",K,T);
        fclose(fpointer2);
    }


    return 0;
}


















/* int main() {
	FILE *fp = fopen("adat.txt", "r");
	char *str = (char*) malloc(30 * sizeof(char));

	fgets(str, 30, fp);
	while(!feof(fp)) {
		printf("%s", str);
		fgets(str, 30, fp);
	}
	fclose(fp);
} */
