
char * FUN_0062b8f0(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  
  cVar4 = '\0';
  cVar3 = '\0';
  iVar5 = 0;
  cVar2 = *param_2;
  while (cVar2 != '\0') {
    cVar2 = *param_2;
    if (iVar5 == 0) {
      if ((((cVar2 == ',') || ((cVar2 == '.' && (param_2[1] == '.')))) ||
          ((cVar2 == '+' && (param_2[1] == '=')))) || ((cVar2 == '-' && (param_2[1] == '='))))
      break;
      if (((cVar2 == '(') || (((cVar2 == '{' || (cVar2 == '[')) || (cVar2 == '\"')))) ||
         ((cVar2 == '`' || (cVar2 == '\'')))) {
        cVar4 = cVar2;
        if (cVar2 == '(') {
          cVar3 = ')';
          iVar5 = 1;
        }
        else if (cVar2 == '{') {
          cVar3 = '}';
          iVar5 = 1;
        }
        else {
          cVar3 = cVar2;
          if (cVar2 == '[') {
            cVar3 = ']';
          }
          iVar5 = 1;
        }
      }
    }
    else if (cVar2 == cVar3) {
      iVar5 = iVar5 + -1;
    }
    else if (cVar2 == cVar4) {
      iVar5 = iVar5 + 1;
    }
    *param_1 = cVar2;
    pcVar1 = param_2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    cVar2 = *pcVar1;
  }
  *param_1 = '\0';
  return param_2;
}

