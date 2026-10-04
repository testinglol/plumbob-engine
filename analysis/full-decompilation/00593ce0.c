
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_00593ce0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float *pfVar10;
  float *pfVar11;
  float fVar12;
  float *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pfVar10 = *(float **)(unaff_EBP + 8);
  *(float **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c4870(pfVar10);
  pfVar11 = *(float **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c4870(pfVar11);
  fVar2 = pfVar11[2];
  fVar3 = pfVar10[2];
  fVar4 = pfVar11[1];
  fVar5 = pfVar10[1];
  *extraout_ECX = *pfVar10;
  fVar6 = *pfVar10;
  fVar7 = *pfVar11;
  extraout_ECX[1] = pfVar10[1];
  extraout_ECX[2] = pfVar10[2];
  fVar8 = pfVar11[3];
  fVar9 = pfVar10[3];
  extraout_ECX[3] = pfVar10[3];
  extraout_ECX[4] = *pfVar11;
  extraout_ECX[5] = pfVar11[1];
  extraout_ECX[6] = pfVar11[2];
  fVar12 = pfVar11[3];
  extraout_ECX[8] = fVar8 * fVar9 + fVar6 * fVar7 + fVar4 * fVar5 + fVar2 * fVar3;
  iVar1 = *(int *)(unaff_EBP + 0x10);
  extraout_ECX[7] = fVar12;
  extraout_ECX[9] = (float)iVar1 * DAT_00673438;
  fVar2 = *extraout_ECX * extraout_ECX[4] +
          extraout_ECX[5] * extraout_ECX[1] +
          extraout_ECX[6] * extraout_ECX[2] + extraout_ECX[7] * extraout_ECX[3];
  fVar3 = (float)_DAT_006669e8;
  extraout_ECX[8] = fVar2;
  if (fVar3 <= fVar2) {
    *(undefined1 *)(extraout_ECX + 10) = 0;
  }
  else {
    extraout_ECX[8] = -fVar2;
    *(undefined1 *)(extraout_ECX + 10) = 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

