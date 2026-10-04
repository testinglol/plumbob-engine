
void __thiscall FUN_00465090(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while( true ) {
    if (piVar2 == (int *)param_1[1]) {
      return;
    }
    if (*(int *)(*piVar2 + 0xc) == param_2) break;
    piVar2 = piVar2 + 1;
  }
  iVar1 = *piVar2;
  if (iVar1 != 0) {
    FUN_005481b6();
    FUN_006321f0(iVar1);
  }
  FUN_005db2f2(piVar2);
  return;
}

