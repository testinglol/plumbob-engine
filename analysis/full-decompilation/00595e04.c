
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595e04(int *param_1,int *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  
  fVar2 = (float)*param_1;
  iVar4 = *param_2;
  fVar1 = (float)iVar4;
  fVar1 = fVar2 * fVar2 + fVar1 * fVar1;
  if (_DAT_0066657c < fVar1) {
    fVar1 = (float)param_3 / SQRT(fVar1);
    FUN_006369f9((double)(fVar1 * fVar2 + _DAT_00666578));
    iVar3 = __ftol();
    *param_1 = iVar3;
    FUN_006369f9((double)(fVar1 * (float)iVar4 + _DAT_00666578));
    iVar4 = __ftol();
    *param_2 = iVar4;
  }
  return;
}

