
undefined1 __fastcall FUN_0060a6d3(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x21) != '\0') {
    iVar1 = *(int *)(param_1 + 0x1c);
    if (iVar1 != 0) {
      FUN_00609648();
      FUN_006321f0(iVar1);
    }
    iVar1 = *(int *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if (iVar1 != 0) {
      FUN_005b8770();
      FUN_006321f0(iVar1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined1 *)(param_1 + 0x21) = 0;
  }
  return 1;
}

