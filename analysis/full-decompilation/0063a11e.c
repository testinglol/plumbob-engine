
char * FUN_0063a11e(char *param_1)

{
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = 0;
  sVar1 = _strlen(param_1);
  pcVar2 = _malloc(sVar1 + 1);
  if (pcVar2 != (char *)0x0) {
    cVar4 = *param_1;
    pcVar3 = pcVar2;
    if (cVar4 != '\0') {
      do {
        if (cVar4 == '\"') {
          iVar5 = iVar5 + 1;
        }
        else {
          *pcVar3 = cVar4;
          pcVar3 = pcVar3 + 1;
        }
        param_1 = param_1 + 1;
        cVar4 = *param_1;
      } while (cVar4 != '\0');
      if (iVar5 != 0) {
        *pcVar3 = '\0';
        return pcVar2;
      }
    }
    FUN_00634ecc(pcVar2);
  }
  return (char *)0x0;
}

