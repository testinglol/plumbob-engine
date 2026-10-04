
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_005992ca(int param_1,int param_2,undefined4 param_3,char param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (((*(int *)(param_1 + 0x94) != 0) || (param_2 != *(int *)(param_1 + 0xb8))) ||
     (param_4 != '\0')) {
    iVar2 = *(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 2;
    FUN_00599214();
    if (0 < iVar2) {
      do {
        FUN_00597c54(param_2,param_3);
        iVar1 = iVar1 + 1;
      } while (iVar1 < iVar2);
    }
    iVar1 = *(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c) >> 2;
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + iVar1 * 4);
      if ((*(int *)(iVar2 + 100) != 0) && (*(float *)(iVar2 + 0x2c) <= _DAT_0066657c)) {
        FUN_005991b7(iVar2);
      }
    }
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
    *(int *)(param_1 + 0xb8) = param_2;
  }
  return;
}

