
void __fastcall FUN_00416fac(int param_1)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x28) != '\0') {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
  }
  return;
}

