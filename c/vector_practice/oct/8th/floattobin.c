
//please work
 
 int scanf(const char*,...);
 int printf(const char*,...);
 int system(const char* clear);
 
 void flo(float); 
// long int bin(); 
 
  int main()
 {
  float f;	 
  system("clear");
  printf("enter a float value: ");
  scanf("%f",&f); 
  flo(f);
  return 0;
 } 

  void flo(float f)
 {
 
  int t=(int)f;
  float g = f-t;
  printf("\nthe data is  %f\n",g);
  //printf("\nthe data is  %f\n",g);
 }
