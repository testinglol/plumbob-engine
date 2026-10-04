
void __fastcall FUN_004ed6d3(int param_1)

{
  int iVar1;
  
  if ((((*(int *)(param_1 + 8) - *(int *)(param_1 + 4) & 0xfffffffcU) != 0) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10) * 4), iVar1 != 0)) &&
     (*(int *)(iVar1 + 4) != 0)) {
    FUN_004ed640();
  }
  return;
}

