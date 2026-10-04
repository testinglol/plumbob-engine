
char * FUN_0063b9e1(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  
  if (DAT_0070513c == 0) {
    pcVar1 = __strset(param_1,param_2);
    return pcVar1;
  }
  cVar3 = (char)((uint)param_2 >> 8);
  pcVar1 = param_1;
  if (cVar3 == '\0') {
    for (; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
      *pcVar1 = (char)param_2;
    }
  }
  else {
    while (*pcVar1 != '\0') {
      *pcVar1 = cVar3;
      pcVar2 = pcVar1 + 1;
      if (*pcVar2 == '\0') {
        *pcVar1 = ' ';
        pcVar1 = pcVar2;
      }
      else {
        *pcVar2 = (char)param_2;
        pcVar1 = pcVar1 + 2;
      }
    }
  }
  return param_1;
}

