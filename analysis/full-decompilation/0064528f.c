
uint FUN_0064528f(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  for (; *param_1 == ';'; param_1 = param_1 + 1) {
  }
  param_3 = param_3 + -1;
  pcVar2 = param_1;
  pcVar3 = param_1;
  if (param_3 != 0) {
    cVar1 = *param_1;
    while ((cVar1 != '\0' && (cVar1 != ';'))) {
      if (cVar1 == '\"') {
        pcVar2 = pcVar3 + 1;
        while ((cVar1 = *pcVar2, cVar1 != '\0' && (cVar1 != '\"'))) {
          *param_2 = cVar1;
          param_2 = param_2 + 1;
          pcVar2 = pcVar2 + 1;
          param_3 = param_3 + -1;
          pcVar3 = pcVar2;
          if (param_3 == 0) goto LAB_006452f5;
        }
        if (*pcVar2 != '\0') {
          pcVar2 = pcVar2 + 1;
        }
      }
      else {
        *param_2 = cVar1;
        param_2 = param_2 + 1;
        pcVar2 = pcVar3 + 1;
        param_3 = param_3 + -1;
        pcVar3 = pcVar2;
        if (param_3 == 0) goto LAB_006452f5;
      }
      pcVar3 = pcVar2;
      cVar1 = *pcVar2;
    }
    for (; pcVar2 = param_1, *pcVar3 == ';'; pcVar3 = pcVar3 + 1) {
    }
  }
LAB_006452f5:
  *param_2 = '\0';
  return -(uint)(pcVar2 != pcVar3) & (uint)pcVar3;
}

