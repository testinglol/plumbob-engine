
int __fastcall FUN_00416cf5(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  for (piVar1 = (int *)*param_1; piVar1 != (int *)param_1[1]; piVar1 = piVar1 + 0x14) {
    if (iVar2 < *piVar1) {
      iVar2 = *piVar1;
    }
  }
  return iVar2 + 1;
}

