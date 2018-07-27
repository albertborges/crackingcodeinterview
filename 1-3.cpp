const int chunk = 3;

int countSpaces( const char* str, int length )
{
  int cch = 0;
  int numSpaces = 0;
  while(cch<length)
  {
    if(*(str+cch) == ' ')
      numSpaces++;
    cch++;
  }
  
  return numSpaces;
}

void applyOffset( char* str, int spaces, int length )
{
  char* iter = (str+(length-1));
  while(spaces!=0)
  {
    if(*iter!=' ')
    {
      *(iter+(chunk-1)*spaces)=*iter;
    }
    else
    {
      spaces--;
      int offset = (chunk-1)*(spaces);
      *(iter+offset) = '%';
      *(iter+offset+1) = '2';
      *(iter+offset+2) = '0';
    }
    iter--;
  }
}

void urlify( char* str, int length )
{
  int numSpaces = countSpaces(str, length);
  int trueLength = numSpaces * 2 + length;
  char* writer = (str+trueLength-1);
  char* reader = (str+length-1);
  while(length!=0)
  {
    if(*reader == ' ')
    {
      *writer = '0';
      *(writer-1) = '2';
      *(writer-2) = '%';
      writer -= 3;
    }
    else
    {
      *writer = *reader;
      writer--;
    }
    reader--;
    length--;
  }
}

int main(int argc, const char * argv[]) {
  char str[] = "Mr John Smith    ";
  urlify(str, 13);
  return 0;
}
