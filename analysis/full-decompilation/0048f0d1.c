
char * __thiscall FUN_0048f0d1(char *param_1,undefined4 param_2)

{
  char *pcVar1;
  char cVar2;
  
  cVar2 = FUN_0048f12a();
  if (cVar2 == '\0') {
    param_1[3] = param_1[3] + -1;
    param_1[4] = param_1[4] + -1;
    pcVar1 = param_1 + 3;
    FUN_00434ffd(param_2);
    FUN_00434ffd(param_2);
    cVar2 = *param_1;
    if (*pcVar1 < cVar2) {
      *param_1 = *pcVar1;
      *pcVar1 = cVar2;
    }
    cVar2 = param_1[1];
    if (param_1[4] < cVar2) {
      param_1[1] = param_1[4];
      param_1[4] = cVar2;
    }
    *pcVar1 = *pcVar1 + '\x01';
    param_1[4] = param_1[4] + '\x01';
  }
  return param_1;
}

