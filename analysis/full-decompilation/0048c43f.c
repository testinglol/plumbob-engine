
void FUN_0048c43f(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_006e5790;
  if (param_1 != 0) {
    for (; piVar1 != DAT_006e5794; piVar1 = piVar1 + 1) {
      if (*(int *)(*piVar1 + 8) == param_1) {
        iVar2 = *piVar1;
        goto LAB_0048c469;
      }
    }
    iVar2 = 0;
LAB_0048c469:
    if (iVar2 != 0) {
      piVar1 = (int *)(iVar2 + 4);
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        FUN_0048c34e(iVar2);
      }
    }
  }
  return;
}

