
void FUN_005b6e50(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005b6db0();
  iVar2 = FUN_005b6db0();
  for (iVar2 = iVar2 - (iVar1 + param_1); iVar2 < 0; iVar2 = iVar2 - (iVar1 + param_1)) {
    FUN_005b7e10(0);
    iVar2 = FUN_005b6db0();
  }
  return;
}

