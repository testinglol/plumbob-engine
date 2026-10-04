
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9843(void)

{
  int iVar1;
  byte bVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  float *extraout_ECX;
  int iVar10;
  int unaff_EBP;
  float10 fVar11;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0x18);
  extraout_ECX[3] = *(float *)(unaff_EBP + 0x14);
  iVar5 = FUN_00492d2c();
  iVar6 = FUN_004cebb0();
  iVar10 = iVar5 * -0xc + 0xb8;
  iVar5 = iVar6 + iVar10;
  *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar6 + iVar10);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar5 + 4);
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar5 + 8);
  *(int *)(unaff_EBP + 0x14) = *(int *)(iVar1 + 0x1c) / -2;
  *(float *)(unaff_EBP + 0x14) = (float)*(int *)(unaff_EBP + 0x14) * DAT_00673438 * _DAT_00666578;
  uVar7 = FUN_005c38c0(unaff_EBP + -0x68,1,unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar8 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x24,unaff_EBP + -0x18,uVar7);
  uVar7 = *puVar8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar7;
  *(undefined4 *)(unaff_EBP + -0x14) = puVar8[1];
  *(undefined4 *)(unaff_EBP + -0x10) = puVar8[2];
  FUN_005c4890();
  *(int *)(unaff_EBP + 0x14) = (int)extraout_ECX[3] + -1;
  fVar3 = (float)*(int *)(unaff_EBP + 0x14);
  bVar2 = DAT_006f0670 & 1;
  *(float *)(unaff_EBP + -0x24) = *(float *)(unaff_EBP + -0x18) * fVar3;
  *(float *)(unaff_EBP + -0x20) = *(float *)(unaff_EBP + -0x14) * fVar3;
  *(float *)(unaff_EBP + 8) = *(float *)(unaff_EBP + 8) - *(float *)(unaff_EBP + -0x24);
  *(float *)(unaff_EBP + 0xc) = *(float *)(unaff_EBP + 0xc) - *(float *)(unaff_EBP + -0x20);
  if (bVar2 == 0) {
    _DAT_006f066c = _DAT_00666a54 / _DAT_0066881c;
    DAT_006f0670 = DAT_006f0670 | 1;
  }
  *extraout_ECX =
       (*(float *)(unaff_EBP + 0x10) - *(float *)(unaff_EBP + -0x10) * fVar3) * _DAT_006f066c;
  extraout_ECX[1] = _DAT_006f066c * *(float *)(unaff_EBP + 8);
  *(float *)(unaff_EBP + 0x14) = *(float *)(unaff_EBP + 0xc) * _DAT_00668818;
  fVar11 = (float10)FUN_00434e9b(unaff_EBP + 0x14);
  extraout_ECX[2] = (float)fVar11;
  uVar7 = __ftol();
  uVar9 = __ftol();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar9;
  *(undefined4 *)(unaff_EBP + 0x10) = uVar7;
  cVar4 = FUN_0045ef89(unaff_EBP + 0xc);
  if (cVar4 == '\0') {
    FUN_004b9b69(iVar1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

