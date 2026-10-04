
undefined4 __thiscall FUN_00401502(int param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  while( true ) {
    iVar1 = FUN_004015a1(uVar2);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
    iVar1 = _strcmp(param_2,*(char **)(iVar1 + 4));
    if (iVar1 == 0) break;
    if (*(int *)(param_1 + 0xc) <= *(int *)(param_1 + 8)) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  iVar1 = FUN_004015a1(*(undefined4 *)(param_1 + 0xc));
  return *(undefined4 *)(iVar1 + 0x10);
}

