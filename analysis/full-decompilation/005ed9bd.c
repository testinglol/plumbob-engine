
undefined4 __thiscall FUN_005ed9bd(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(char *)(param_1 + 0x14) == '\0') && (*(int *)(param_1 + 4) != 0)) {
    if (param_2 != 0) {
      *(int *)(param_1 + 0x10) = param_2;
    }
    *(undefined1 *)(param_1 + 0x14) = 1;
    iVar1 = FUN_00607401(&LAB_005eda8f,param_1,param_1,*(undefined4 *)(param_1 + 0x10),0,0);
    *(int *)(param_1 + 0x18) = iVar1;
    if (iVar1 != 0) {
      return 1;
    }
    *(undefined1 *)(param_1 + 0x14) = 0;
  }
  return 0;
}

