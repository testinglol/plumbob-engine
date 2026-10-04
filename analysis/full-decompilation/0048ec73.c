
void __fastcall FUN_0048ec73(int param_1)

{
  undefined4 uVar1;
  
  DAT_006e57a0 = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_00485b4c();
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  *(undefined4 *)(param_1 + 0x34) = 0;
  FUN_004b0e72(*(undefined4 *)(param_1 + 0x38));
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  FUN_004790b4(uVar1);
  FUN_004616c3(uVar1);
  FUN_004b0de0();
  if (*(char *)(param_1 + 0x58) != '\0') {
    *(undefined1 *)(param_1 + 0x58) = 0;
  }
  FUN_0040766a(0x91,0);
  return;
}

