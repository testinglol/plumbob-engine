
int * FUN_005c4ba0(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = param_1;
  do {
    FUN_006340db(&param_1);
    iVar2 = FUN_00636918((int)(char)param_1);
  } while (iVar2 != 0);
  if ((char)param_1 == '|') {
    iVar2 = param_2 + 0xc;
    iVar5 = param_2 + 8;
    iVar4 = param_2 + 4;
    FUN_00633f35(param_2);
    FUN_00633f35(iVar4);
    FUN_00633f35(iVar5);
    FUN_00633f35(iVar2);
    do {
      piVar3 = (int *)FUN_006340db(&param_1);
      if (piVar3 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*piVar3 + 4) + (int)piVar3;
      }
      if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) break;
      iVar2 = FUN_00636918((int)(char)param_1);
    } while (iVar2 != 0);
    if ((char)param_1 != '|') {
      iVar2 = *(int *)(*piVar1 + 4);
      if (*(int *)(iVar2 + 0x34 + (int)piVar1) < 0) {
        FUN_00633e5e((int)piVar1 + iVar2 + 0x38);
      }
      *(undefined4 *)((int)piVar1 + iVar2 + 8) = 4;
      if (*(int *)((int)piVar1 + iVar2 + 0x34) < 0) {
        FUN_00633e69((int)piVar1 + iVar2 + 0x38);
        return piVar1;
      }
    }
  }
  else {
    FUN_006329a8(param_1);
    iVar2 = param_2 + 0xc;
    iVar5 = param_2 + 8;
    iVar4 = param_2 + 4;
    FUN_00633f35(param_2);
    FUN_00633f35(iVar4);
    FUN_00633f35(iVar5);
    FUN_00633f35(iVar2);
  }
  return piVar1;
}

