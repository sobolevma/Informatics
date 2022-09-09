char* Ruc(char s[]) 
{ 

int i; 
static char ss[257]; 
for (i=0;s[i] != '\0'; i++) 
{ 
if (s[i]>= -64 && s[i] <= -17) 
ss[i]=(-64+s[i]); 
else if (s[i]>= -16 && s[i] <= 0) 
ss[i]=(char)(-16+s[i]); 
else if (s[i] == -72) 
ss[i]=(char)(-15);  
else if (s[i] == -88) 
ss[i]=(char)(-16);  
else 
ss[i]=s[i]; 
}
ss[i]='\0'; 
return ss; 
}
