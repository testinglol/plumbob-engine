
undefined4 __fastcall FUN_005e7998(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 4) = 1;
    uVar1 = (**(code **)(*DAT_006fe8bc + 0x10))();
    *(undefined4 *)(param_1 + 8) = uVar1;
    uVar1 = (**(code **)(*DAT_006fe8bc + 0x14))();
    *(undefined4 *)(param_1 + 0xc) = uVar1;
  }
  return 1;
}

