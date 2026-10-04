
undefined4 __fastcall FUN_00458026(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 0xb8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x60) + 0x1c);
  }
  iVar1 = FUN_0043e17b(iVar1);
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 8);
}

