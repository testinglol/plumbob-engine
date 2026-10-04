
void __fastcall FUN_00595e86(int param_1)

{
  int *piVar1;
  
  *(int *)(param_1 + 0x134) = *(int *)(param_1 + 0x134) + 1;
  if (*(int *)(param_1 + 0x1c) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x1c) + 0xac);
    *piVar1 = *piVar1 + 1;
  }
  return;
}

