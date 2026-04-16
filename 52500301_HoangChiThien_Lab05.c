#include <stdio.h>
#include <string.h>
#define SIZE 200

void removeNewline(char s[]){
    int len = strlen(s);
    if(len > 0 && s[len-1] == '\n') s[len-1] = '\0';
}

//////////////////// 1 ////////////////////
int strLength(char s[]){
    int i=0;
    while(s[i] != '\0') i++;
    return i;
}

//////////////////// 2 ////////////////////
void reverseString(char s[]){
    int n = strLength(s);
    for(int i=n-1;i>=0;i--) printf("%c", s[i]);
    printf("\n");
}

//////////////////// 3 ////////////////////
void firstLastName(char s[]){
    char *first = strtok(s," ");
    char *last;
    while(first != NULL){
        last = first;
        first = strtok(NULL," ");
    }
    printf("First name: %s\nLast name: %s\n", strtok(s," "), last);
}

//////////////////// 4 ////////////////////
void normalize(char s[]){
    char temp[SIZE];
    int i=0, j=0;

    while(s[i]==' ') i++;

    int newWord = 1;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            temp[j++] = ' ';
            while(s[i]==' ') i++; 
            newWord = 1;
        }
        else{
            if(newWord){
                // uppercase first char
                if(s[i]>='a' && s[i]<='z') temp[j++] = s[i]-32;
                else temp[j++] = s[i];
                newWord = 0;
            }else{
                // lowercase others
                if(s[i]>='A' && s[i]<='Z') temp[j++] = s[i]+32;
                else temp[j++] = s[i];
            }
            i++;
        }
    }
    temp[j]='\0';
    strcpy(s,temp);
}

//////////////////// 5 ////////////////////
void concatNoLib(char s1[], char s2[]){
    int i=strLength(s1);
    int j=0;
    while(s2[j] != '\0'){
        s1[i++] = s2[j++];
    }
    s1[i]='\0';
}

//////////////////// 6 ////////////////////
int firstCharPos(char s[], char c){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c) return i;
    return -1;
}

//////////////////// 7 ////////////////////
void allCharPos(char s[], char c){
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c) printf("%d ",i);
    printf("\n");
}

//////////////////// 8 ////////////////////
int wordPos(char s[], char word[]){
    char temp[SIZE];
    strcpy(temp,s);
    char *token = strtok(temp," ");
    int pos=0;

    while(token!=NULL){
        if(strcmp(token,word)==0) return pos;
        pos += strlen(token)+1;
        token=strtok(NULL," ");
    }
    return -1;
}

//////////////////// 9 ////////////////////
int substringPos(char s1[], char s2[]){
    for(int i=0; s1[i]!='\0'; i++){
        int j=0;
        while(s2[j]!='\0' && s1[i+j]==s2[j]) j++;
        if(s2[j]=='\0') return i;
    }
    return -1;
}

//////////////////// 10 ////////////////////
void insertString(char s1[], char s2[], int pos){
    char temp[SIZE];
    strcpy(temp, s1+pos);
    s1[pos]='\0';
    strcat(s1,s2);
    strcat(s1,temp);
}

//////////////////// 11 ////////////////////
void deleteChars(char s[], int pos, int n){
    int len=strlen(s);
    for(int i=pos+n;i<=len;i++)
        s[i-n]=s[i];
}

//////////////////////////////////////////////////
int main(){
    char s1[SIZE], s2[SIZE];
    char c;
    int pos, n;

    printf("=== EX1 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    printf("Length = %d\n\n", strLength(s1));

    printf("=== EX2 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    reverseString(s1);
    printf("\n");

    printf("=== EX3 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    firstLastName(s1);
    printf("\n");

    printf("=== EX4 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    normalize(s1);
    printf("%s\n\n", s1);

    printf("=== EX5 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    fgets(s2,SIZE,stdin); removeNewline(s2);
    concatNoLib(s1,s2);
    printf("%s\n\n", s1);

    printf("=== EX6 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    scanf(" %c",&c);
    printf("First position: %d\n\n", firstCharPos(s1,c));
    getchar();

    printf("=== EX7 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    scanf(" %c",&c);
    allCharPos(s1,c);
    getchar();

    printf("=== EX8 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    fgets(s2,SIZE,stdin); removeNewline(s2);
    printf("Word position: %d\n\n", wordPos(s1,s2));

    printf("=== EX9 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    fgets(s2,SIZE,stdin); removeNewline(s2);
    printf("Substring position: %d\n\n", substringPos(s1,s2));

    printf("=== EX10 ===\n");
    fgets(s1,SIZE,stdin); removeNewline(s1);
    fgets(s2,SIZE,stdin); removeNewline(s2);
    scanf("%d",&pos);
    insertString(s1,s2,pos);
    printf("%s\n\n", s1);

    printf("=== EX11 ===\n");
    getchar();
    fgets(s1,SIZE,stdin); removeNewline(s1);
    scanf("%d%d",&pos,&n);
    deleteChars(s1,pos,n);
    printf("%s\n", s1);

    return 0;
}