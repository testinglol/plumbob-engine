
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00416618(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[10] = 0;
  piVar5 = (int *)(*(int *)(param_1 + 0x24) + 4);
  iVar3 = *(int *)(*piVar5 + 8);
  iVar4 = *piVar5;
  while (iVar3 != iVar4) {
    iVar4 = *(int *)(iVar3 + 0x14);
    if (((iVar4 != 0) && (*(int *)(iVar4 + 0x34) != 0)) && (cVar1 = FUN_00468851(), cVar1 == '\0'))
    {
      iVar2 = FUN_004681ec();
      *param_2 = *param_2 + iVar2 * 9;
      if (0 < *(int *)(iVar4 + 0x5c)) {
        param_2[3] = param_2[3] + 1;
      }
      if (0 < *(int *)(iVar4 + 0x58)) {
        param_2[2] = param_2[2] + 1;
      }
    }
    FUN_0041674f();
    iVar4 = *piVar5;
  }
  iVar3 = 0;
  param_2[4] = (*(char *)(*(int *)(param_1 + 0x1c) + 0x80) != '\0') + 1;
  iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x10);
  if (0x27 < iVar4) {
    iVar3 = (0x31 < iVar4) + 1;
  }
  param_2[5] = iVar3;
  FUN_0044532b(*(undefined4 *)(param_1 + 0x24),param_2);
  iVar4 = FUN_004102e1();
  param_2[1] = iVar4;
  iVar4 = 5;
  do {
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = __ftol();
  param_2[6] = iVar4;
  return;
}

