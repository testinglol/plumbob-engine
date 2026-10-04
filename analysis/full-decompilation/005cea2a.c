
undefined4 __fastcall FUN_005cea2a(int param_1)

{
  undefined4 uVar1;
  
  if ((uint)((*(int *)(param_1 + 0x1c0) - *(int *)(param_1 + 0x1bc)) / 0x44) < 2) {
    uVar1 = 0;
  }
  else {
    FUN_005cf292();
    uVar1 = FUN_005cea64(*(int *)(param_1 + 0x1c0) + -0x44);
  }
  return uVar1;
}

