
void __thiscall FUN_0049341e(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = FUN_00401f73();
  if ((iVar2 != 1) && (iVar2 = FUN_004931c9(), iVar2 != 0)) {
    FUN_0049353b();
    FUN_0049356e();
    FUN_0042004f();
    return;
  }
  piVar1 = (int *)(param_1 + 4);
  if (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2 == 0x3fffffff) {
    if (*(int *)*piVar1 != 0) {
      FUN_00485b4c();
      *(undefined4 *)*piVar1 = 0;
    }
    FUN_0052ea87(*piVar1,*piVar1 + 4);
  }
  iVar2 = FUN_00401f73();
  if (iVar2 == 1) {
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
    FUN_0049322e(&param_2);
    FUN_0049356e();
  }
  FUN_0040766a(0xee,0);
  return;
}

