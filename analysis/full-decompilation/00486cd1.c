
undefined4 __thiscall FUN_00486cd1(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  short local_28;
  int local_14;
  
  if (param_2 == 0x2c) {
LAB_00486de2:
    if (*(int **)(param_1 + 0x3c) == (int *)0x0) {
      return 0;
    }
    iVar2 = **(int **)(param_1 + 0x3c);
    uVar4 = 0xffffffff;
  }
  else {
    if (param_2 != 0x2e) {
      if (param_2 != 0x2f) {
        if (param_2 == 0x3c) goto LAB_00486de2;
        if (param_2 == 0x3e) goto LAB_00486dd5;
        if (param_2 != 0x3f) {
          return 0;
        }
      }
      if (*(int *)(param_1 + 0x3c) == 0) {
        return 0;
      }
      FUN_0043270d(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1ac));
      if (local_14 == 0) {
        return 0;
      }
      if ((*(int *)(local_14 + 0x134) - *(int *)(local_14 + 0x130)) / 0x24 + -1 < 2) {
        return 0;
      }
      iVar2 = (*(int *)(local_14 + 0x134) - *(int *)(local_14 + 0x130)) / 0x24 + -1;
      FUN_0043270d(*(undefined4 *)(*(int *)(param_1 + 0x3c) + 0x1ac));
      (**(code **)(**(int **)(param_1 + 0x3c) + 0x50))(1);
      iVar3 = local_28 + 1;
      if (iVar2 <= iVar3) {
        iVar3 = 0;
      }
      while (cVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x3c) + 0x1ac) + 0x60))
                               (local_14 + 0xf4,*(undefined4 *)(local_14 + 0x110),local_14,iVar3),
            cVar1 == '\0') {
        iVar3 = iVar3 + 1;
        if (iVar2 <= iVar3) {
          iVar3 = 0;
        }
      }
      (**(code **)(**(int **)(param_1 + 0x3c) + 0x58))
                (local_14 + 0xf4,*(undefined4 *)(local_14 + 0x110),local_14,iVar3,1);
      FUN_00486f2a();
      goto LAB_00486df7;
    }
LAB_00486dd5:
    if (*(int **)(param_1 + 0x3c) == (int *)0x0) {
      return 0;
    }
    iVar2 = **(int **)(param_1 + 0x3c);
    uVar4 = 1;
  }
  (**(code **)(iVar2 + 0x4c))(uVar4);
  FUN_00486f2a();
LAB_00486df7:
  if (DAT_006e5780 != '\0') {
    FUN_0040766a(0x91,0);
    DAT_006e5780 = '\0';
  }
  return 1;
}

