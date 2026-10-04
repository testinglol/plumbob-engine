
void __fastcall FUN_00416f95(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
    *(undefined1 *)(param_1 + 0x28) = 1;
  }
  return;
}

