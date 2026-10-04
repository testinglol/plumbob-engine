
void __thiscall FUN_00464895(int *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = param_1[3];
  if (*(char *)((int)param_1 + 0x13) == '\0') {
    if (iVar3 == 2) {
      param_1[2] = param_1[2] + param_3;
    }
    else {
      if (iVar3 == 0) {
        pcVar1 = (char *)(param_1[2] + *param_1);
        pcVar2 = param_2;
      }
      else {
        pcVar2 = (char *)(param_1[2] + *param_1);
        pcVar1 = param_2;
      }
      if (0 < param_3) {
        do {
          *pcVar2 = *pcVar1;
          param_1[2] = param_1[2] + 1;
          pcVar1 = pcVar1 + 1;
          pcVar2 = pcVar2 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
  }
  else if ((iVar3 == 1) || (iVar3 == 2)) {
    iVar3 = param_3;
    pcVar1 = param_2;
    if (0 < param_3) {
      do {
        param_2 = (char *)(int)*pcVar1;
        FUN_00464696(&param_2,&DAT_006e52e8);
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  else {
    iVar3 = param_3;
    pcVar1 = param_2;
    if (0 < param_3) {
      do {
        FUN_00464696(&param_2,&DAT_006e52e8);
        *pcVar1 = (char)param_2;
        iVar3 = iVar3 + -1;
        pcVar1 = pcVar1 + 1;
      } while (iVar3 != 0);
    }
  }
  return;
}

