
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __thiscall FUN_0046989d(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  uint *puVar5;
  float10 fVar6;
  
  fVar3 = _DAT_0066657c;
  if ((((param_2 != 0) && (param_2 != 1)) &&
      (puVar5 = (uint *)FUN_00469872(), fVar3 = _DAT_0066657c, puVar5 != (uint *)0x0)) &&
     (((uVar1 = *puVar5, -1 < (int)uVar1 &&
       (piVar2 = *(int **)*param_1, uVar1 < (uint)((piVar2[1] - *piVar2) / 0x14))) &&
      ((-1 < (int)puVar5[1] && (puVar5[1] < (uint)((int)(param_1[4] - param_1[3]) / 0x14))))))) {
    piVar2 = (int *)(*piVar2 + uVar1 * 0x14);
    fVar3 = (float)(int)((piVar2[2] + *piVar2) / 2 - puVar5[5]);
    fVar4 = (float)(int)((piVar2[3] + piVar2[1]) / 2 - puVar5[6]);
    fVar6 = (float10)FUN_00636264((double)(fVar3 * fVar3 + fVar4 * fVar4));
    fVar3 = (float)fVar6;
  }
  return (float10)fVar3;
}

