
void __fastcall FUN_004934fd(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00493210();
  if (iVar1 == 0) {
    FUN_0049322e(*(int *)(param_1 + 0x14) + -4);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -4;
  }
  else {
    FUN_0049356e();
  }
  FUN_0040766a(0xee,0);
  return;
}

