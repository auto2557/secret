#ifndef _function_
#define _function_

void pnum(int nb);       
void pchar(char c);      
void pstr(char *str);     

int atoi_custom(char *s); 
int slen(char *s);        
int *get_nums(char *s);   
int chk(int ac, char **av); 
int chk_dbl(int t[4][4], int p, int n); 
int chk_case(int t[4][4], int p, int e[16]);

#endif
