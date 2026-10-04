
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048432f(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float local_1c [5];
  int local_8;
  
  iVar8 = 0;
  do {
    iVar4 = iVar8 + 4;
    local_8 = (int)*(short *)((int)param_1 + *(int *)((int)&DAT_006c5bd4 + iVar8) * 2);
    *(float *)((int)local_1c + iVar8) = (float)local_8 * _DAT_00666a4c;
    iVar8 = iVar4;
  } while (iVar4 < 0x14);
  iVar4 = -1;
  param_1 = 1e+38;
  iVar8 = 1;
  pfVar6 = (float *)&DAT_006c5be8;
  do {
    pfVar5 = local_1c;
    fVar3 = 0.0;
    iVar7 = 5;
    do {
      fVar1 = *pfVar5;
      fVar2 = *pfVar6;
      pfVar5 = pfVar5 + 1;
      pfVar6 = pfVar6 + 1;
      iVar7 = iVar7 + -1;
      fVar3 = (fVar1 - fVar2) * (fVar1 - fVar2) + fVar3;
    } while (iVar7 != 0);
    if (fVar3 < param_1) {
      iVar4 = iVar8;
      param_1 = fVar3;
    }
    iVar8 = iVar8 + 1;
  } while ((int)pfVar6 < 0x6c5cc5);
  if ((iVar4 < 1) || (0xc < iVar4)) {
    iVar4 = 1;
  }
  return CONCAT22((short)((uint)pfVar5 >> 0x10),(short)iVar4);
}

