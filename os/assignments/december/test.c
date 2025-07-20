int printf(char const*,...);
int scanf(char const*,...);

int main()
{
 double d;
 printf("please enter a double: ");
 scanf("%lf",&d);
 printf("%lf|\n",d);
}
