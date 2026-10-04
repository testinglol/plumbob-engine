
void __fastcall FUN_005bdc4a(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_1[2] - iVar1 >> 1;
  if ((iVar1 != 0) && (iVar2 != 0)) {
    FUN_0040189d(iVar1,iVar2 * 2);
  }
  return;
}

