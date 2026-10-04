
undefined4 __fastcall FUN_00497c73(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    if (DAT_006e5be8 == '\0') {
      FUN_004790b8(iVar1);
      FUN_0047736d(iVar1);
      FUN_004b0de0();
      FUN_0040766a(0x91,0);
    }
    else {
      FUN_0047736d(iVar1);
      FUN_0047736d(*(undefined4 *)(param_1 + 0x28));
    }
    iVar1 = *(int *)(param_1 + 0x2c);
    if (iVar1 == 0) {
      FUN_00492cca();
    }
    else {
      if (0 < iVar1) {
        FUN_00492bb0(iVar1 * DAT_006c618c);
      }
      FUN_00492bc4();
      FUN_00492c68();
    }
  }
  return 0;
}

