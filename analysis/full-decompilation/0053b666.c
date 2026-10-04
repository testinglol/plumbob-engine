
void __fastcall FUN_0053b666(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_005dae65(param_1);
  if (*(int *)(param_1 + 0x1e4) == 3) {
    iVar1 = FUN_004cebb0();
    iVar2 = FUN_0046d386();
    if (iVar1 != iVar2) {
      FUN_005e46f0(*(int *)(*(int *)(param_1 + 0x124) + 0xe0) == 0);
    }
  }
  else if ((*(int *)(param_1 + 0x1e4) == 2) && (*(int *)(param_1 + 0x118) != 0)) {
    FUN_005e4320(*(int *)(*(int *)(param_1 + 0x118) + 0xe4) == 0);
  }
  FUN_005dadff(param_1,500,0);
  return;
}

