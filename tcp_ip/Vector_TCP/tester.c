int printf(const char *,...);
struct song{
             int bitrate;
	     char name[10];
	     char artist[11];
             };

 int main()
{
 printf("this is a theory of greatness\n");
struct song first={"goodday","greenday"};
 printf("the data of the song %s is it is sung by %s and is of %d bitrate",first.name,first.artist,first.bitrate);
 //return 0;
}
