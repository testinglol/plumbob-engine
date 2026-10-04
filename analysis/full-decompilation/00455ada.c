
char * FUN_00455ada(char *param_1,char *param_2,char *param_3,char *param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = param_1;
  if ((param_1 != param_2) && (param_3 != param_4)) {
    pcVar1 = param_3 + 1;
    if (pcVar1 == param_4) {
      do {
        if (*pcVar2 == *param_3) {
          return pcVar2;
        }
        pcVar2 = pcVar2 + 1;
      } while (pcVar2 != param_2);
    }
    else {
      while (pcVar2 = param_2, param_1 != param_2) {
        do {
          pcVar2 = param_1;
          if (*param_1 == *param_3) break;
          param_1 = param_1 + 1;
          pcVar2 = param_1;
        } while (param_1 != param_2);
        if (pcVar2 == param_2) {
          return param_2;
        }
        do {
          if (*pcVar2 == *param_3) break;
          pcVar2 = pcVar2 + 1;
        } while (pcVar2 != param_2);
        if (pcVar2 == param_2) {
          return param_2;
        }
        param_1 = pcVar2 + 1;
        if (param_1 == param_2) {
          return param_2;
        }
        pcVar3 = param_1;
        pcVar4 = pcVar1;
        if (*param_1 == *pcVar1) {
          do {
            pcVar4 = pcVar4 + 1;
            if (pcVar4 == param_4) {
              return pcVar2;
            }
            pcVar3 = pcVar3 + 1;
            if (pcVar3 == param_2) {
              return param_2;
            }
          } while (*pcVar3 == *pcVar4);
        }
        if (param_1 == param_2) {
          return param_1;
        }
      }
    }
  }
  return pcVar2;
}

