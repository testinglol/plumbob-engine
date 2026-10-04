
void __fastcall FUN_00542651(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x38c) != 0) {
    param_1 = param_1 + 0x90;
    iVar1 = 0x15;
    do {
      FUN_0054286c(param_1);
      param_1 = param_1 + 0x24;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

