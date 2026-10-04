
int __fastcall FUN_005d4518(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar2 == *(int *)(param_1 + 8)) {
      return 0;
    }
    iVar1 = FUN_005d474e();
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 4;
  }
  return iVar1;
}

