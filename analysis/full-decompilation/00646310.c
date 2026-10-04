
/* Library Function - Single Match
    __strset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl __strset(char *_Dest,int _Value)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = -1;
  pcVar3 = _Dest;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  pcVar3 = _Dest;
  for (iVar2 = -(iVar2 + 2); iVar2 != 0; iVar2 = iVar2 + -1) {
    *pcVar3 = (char)_Value;
    pcVar3 = pcVar3 + 1;
  }
  return _Dest;
}

