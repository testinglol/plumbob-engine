
undefined4 __thiscall FUN_005f243e(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  int local_8;
  
  *(undefined1 *)(param_1 + 0x157) = 0;
  local_c = param_1;
  local_8 = param_1;
  iVar1 = FUN_00492d2c();
  if (iVar1 == param_1) {
    FUN_005d9912(param_1);
    iVar3 = 0;
    local_c = param_2 - *(int *)(param_1 + 0xfc);
    local_8 = param_3 - *(int *)(param_1 + 0x100);
    iVar1 = -1;
    if (0 < (int)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) & 0xfffffffcU)) {
      do {
        piVar4 = &local_c;
        uVar2 = FUN_004096c2(piVar4);
        iVar1 = FUN_005f22d5(*(undefined4 *)(param_1 + 0x114),uVar2,piVar4);
        if (-1 < iVar1) break;
        if ((iVar1 == -1) &&
           (iVar3 == (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2) + -1)) {
          piVar4 = *(int **)(*(int *)(param_1 + 0xf0) + iVar3 * 4);
          iVar1 = piVar4[1] + *piVar4;
          break;
        }
        if (iVar1 == -3) {
          iVar1 = **(int **)(*(int *)(param_1 + 0xf0) + iVar3 * 4);
          break;
        }
        iVar3 = iVar3 + 1;
        iVar1 = -1;
      } while (iVar3 < *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2);
    }
    if (iVar1 != *(int *)(param_1 + 0xd4)) {
      FUN_005f2c6c(iVar1 - *(int *)(param_1 + 0xd4),iVar1 != *(int *)(param_1 + 0x158),0);
    }
  }
  return 1;
}

