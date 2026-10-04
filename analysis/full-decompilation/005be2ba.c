
undefined1 FUN_005be2ba(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_2 + 1;
  do {
    cVar1 = *param_2;
    if ((cVar1 == '*') && (*pcVar2 == '\0')) {
      return 1;
    }
    if (*param_1 == '\0') {
      if (cVar1 == '\0') {
        return 1;
      }
      return 0;
    }
    if (cVar1 == '*') {
      cVar1 = FUN_005be2ba(param_1,pcVar2);
      if (cVar1 != '\0') {
        return 1;
      }
    }
    else {
      if ((cVar1 != '?') && (*param_1 != cVar1)) {
        return 0;
      }
      param_2 = param_2 + 1;
      pcVar2 = pcVar2 + 1;
    }
    param_1 = param_1 + 1;
  } while( true );
}

