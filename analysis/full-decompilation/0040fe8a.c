
int * __fastcall FUN_0040fe8a(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  *param_1 = iVar2;
  if (iVar2 == 0) {
    iVar2 = param_1[1];
    uVar4 = FUN_0040ff51(piVar1 + 1);
    iVar3 = *param_1;
    while ((iVar3 == 0 &&
           (uVar4 = uVar4 + 1, uVar4 < (uint)(*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4) >> 2)))) {
      iVar3 = *(int *)(*(int *)(iVar2 + 4) + uVar4 * 4);
      *param_1 = iVar3;
    }
  }
  return param_1;
}

