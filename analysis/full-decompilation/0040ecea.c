
void __fastcall FUN_0040ecea(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0040cd0e();
  iVar2 = param_1;
  if (-1 < iVar1) {
    if (iVar1 < 2) {
      iVar2 = 9;
    }
    else if (iVar1 < 6) {
      iVar2 = 7;
    }
  }
  FUN_0040d0d9();
  FUN_0040eaba(2,*(undefined4 *)(param_1 + 0x7c),iVar2);
  return;
}

