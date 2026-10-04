
char * FUN_0063b900(char *param_1,int param_2,size_t param_3)

{
  char *pcVar1;
  char cVar2;
  
  if (DAT_0070513c == 0) {
    pcVar1 = __strnset(param_1,param_2,param_3);
    return pcVar1;
  }
  cVar2 = (char)((uint)param_2 >> 8);
  pcVar1 = param_1;
  if (cVar2 == '\0') {
    for (; (param_3 != 0 && (*pcVar1 != '\0')); pcVar1 = pcVar1 + 1) {
      *pcVar1 = (char)param_2;
      param_3 = param_3 - 1;
    }
  }
  else {
    while( true ) {
      if (param_3 == 0) {
        return param_1;
      }
      if (*pcVar1 == '\0') {
        return param_1;
      }
      if ((param_3 == 1) || (pcVar1[1] == '\0')) break;
      *pcVar1 = cVar2;
      pcVar1[1] = (char)param_2;
      pcVar1 = pcVar1 + 2;
      param_3 = param_3 - 2;
    }
    *pcVar1 = ' ';
  }
  return param_1;
}

