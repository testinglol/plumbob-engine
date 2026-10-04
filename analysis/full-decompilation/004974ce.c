
void __fastcall FUN_004974ce(int param_1)

{
  undefined4 uVar1;
  
  DAT_006e5be8 = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_00485b4c();
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(param_1 + 0x54) = 0;
  FUN_004790b8(uVar1);
  FUN_0047736d(uVar1);
  FUN_004b12b6(*(undefined4 *)(param_1 + 0x3c));
  FUN_004b0de0();
  if (*(char *)(param_1 + 0x4c) != '\0') {
    *(undefined1 *)(param_1 + 0x4c) = 0;
  }
  FUN_004d25a5(0);
  FUN_0040766a(0x91,0);
  return;
}

