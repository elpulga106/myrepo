void main (){
int num;
printf ("Enter any no:");
scanf ("%d", &num);
if (num &&(num & num-1) == 0)
printf ("Number is a power of 2");
else
printf ("Number is not a power of 2");
}