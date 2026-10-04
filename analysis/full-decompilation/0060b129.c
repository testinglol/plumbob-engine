
undefined1 __fastcall FUN_0060b129(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_0060b933(0);
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_006321f0(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_005e3581();
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  FUN_006321f0(*(undefined4 *)(param_1 + 0x40));
  FUN_0060c46a();
  return uVar1;
}

