
undefined4 FUN_004fab8b(int param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  if (param_2 < (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc) {
    pcVar2 = *(char **)(*(int *)(param_1 + 4) + param_2 * 0xc);
    cVar1 = *pcVar2;
    pcVar5 = pcVar2;
    while (cVar1 != '\0') {
      iVar3 = FUN_006368c3((int)*pcVar5);
      if (iVar3 == 0) goto LAB_004fabdb;
      pcVar5 = pcVar5 + 1;
      cVar1 = *pcVar5;
    }
    uVar4 = FUN_00635f62(pcVar2);
    *param_3 = uVar4;
    uVar4 = 1;
  }
  else {
LAB_004fabdb:
    uVar4 = 0;
  }
  return uVar4;
}

