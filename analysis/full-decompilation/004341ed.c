
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_004341ed(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (*(short *)(*(int *)(param_2 + 0x118) + 0x12) == 7) {
    fVar3 = (float10)_DAT_0066657c;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xf8) - *(int *)(param_2 + 0xf8);
    iVar2 = *(int *)(param_1 + 0xf4) - *(int *)(param_2 + 0xf4);
    fVar3 = (float10)((*(int *)(param_2 + 0x110) - *(int *)(param_1 + 0x110)) * 0x14);
    fVar3 = SQRT(fVar3 * fVar3 + (float10)(iVar2 * iVar2 + iVar1 * iVar1) * (float10)_DAT_00666dbc);
  }
  return fVar3;
}

