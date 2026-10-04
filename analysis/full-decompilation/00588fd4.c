
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00588fd4(int param_1)

{
  int iVar1;
  float fVar2;
  float10 fVar3;
  
  fVar3 = (float10)1;
  if (*(short *)(*(int *)(param_1 + 0x138) + 0x6c) != 1) goto LAB_00589019;
  iVar1 = *(int *)(param_1 + 400);
  if (iVar1 != 0) {
    if ((iVar1 < 4) || ((5 < iVar1 && (9 < iVar1)))) goto LAB_00589019;
    if (1 < *(short *)(*(int *)(param_1 + 0x138) + 0x60e)) {
      fVar3 = (float10)0;
      goto LAB_00589019;
    }
  }
  fVar3 = (float10)_DAT_0066c7bc;
LAB_00589019:
  fVar2 = _DAT_006d0778;
  if (fVar3 < (float10)_DAT_0066657c) {
    fVar2 = _DAT_006d077c;
  }
  return (float10)fVar2 * fVar3 + (float10)_DAT_006d0774;
}

