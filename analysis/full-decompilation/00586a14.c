
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00586a14(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  FUN_00634c24();
  if ((char)extraout_ECX[0x42] == '\0') {
    if (ABS((float)extraout_ECX[0x20] - DAT_00671d64) <= _DAT_0067343c) {
      uVar6 = (**(code **)(*extraout_ECX + 0x10c))();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      extraout_ECX[0x20] = (int)(float)*(int *)(unaff_EBP + -0x10);
    }
    if (ABS((float)extraout_ECX[0x21] - DAT_00671d64) <= _DAT_0067343c) {
      uVar6 = (**(code **)(*extraout_ECX + 0x110))();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      extraout_ECX[0x21] = (int)(float)*(int *)(unaff_EBP + -0x10);
    }
    if (ABS((float)extraout_ECX[0x22] - DAT_00671d64) <= _DAT_0067343c) {
      uVar6 = (**(code **)(*extraout_ECX + 0x118))();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      extraout_ECX[0x22] = (int)(float)*(int *)(unaff_EBP + -0x10);
    }
    *(float *)(unaff_EBP + -0x2c) = (float)extraout_ECX[0x23] + (float)extraout_ECX[0x20];
    *(float *)(unaff_EBP + -0x30) = (float)extraout_ECX[0x24] + (float)extraout_ECX[0x21];
    *(float *)(unaff_EBP + -0x48) = (float)extraout_ECX[0x25] + (float)extraout_ECX[0x22];
    uVar6 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x40) = uVar6;
    uVar6 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x44) = uVar6;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    cVar5 = FUN_0045ef89(unaff_EBP + -0x44);
    if (cVar5 == '\0') {
      fVar11 = (float10)FUN_00478f70(unaff_EBP + -0x44);
      if ((DAT_00703e88 & 1) == 0) {
        DAT_00703e88 = DAT_00703e88 | 1;
        _DAT_00703e8c =
             (float)((float10)_DAT_00667280 /
                    (SQRT((float10)_DAT_00666dc0) + SQRT((float10)_DAT_00666dc0)));
      }
      *(float *)(unaff_EBP + -0x10) =
           (float)((float10)_DAT_00703e8c * (float10)_DAT_00671d5c * fVar11);
    }
    piVar3 = *(int **)(DAT_006e486c + 4);
    uVar6 = (**(code **)(*piVar3 + 0x14))();
    *(undefined4 *)(unaff_EBP + -0x14) = uVar6;
    iVar7 = (**(code **)(*piVar3 + 0x18))();
    iVar8 = (**(code **)(*piVar3 + 0x24))();
    *(int *)(unaff_EBP + -0x18) = *(int *)(extraout_ECX[1] + 0x110) + -1;
    iVar4 = *(int *)(unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x14) = -iVar7;
    *(float *)(unaff_EBP + -0x18) = (float)*(int *)(unaff_EBP + -0x18);
    iVar8 = iVar8 + iVar4 * -0xc;
    fVar1 = *(float *)(iVar8 + 0xc0);
    fVar2 = *(float *)(iVar8 + 0xbc);
    *(float *)(unaff_EBP + -0x28) = *(float *)(unaff_EBP + -0x18) * *(float *)(iVar8 + 0xb8);
    *(float *)(unaff_EBP + -0x24) = *(float *)(unaff_EBP + -0x18) * fVar2;
    *(float *)(unaff_EBP + -0x20) = *(float *)(unaff_EBP + -0x18) * fVar1;
    *(float *)(unaff_EBP + -0x14) =
         (float)*(int *)(unaff_EBP + -0x14) * DAT_00673438 * _DAT_00666578;
    uVar6 = FUN_005c38c0(unaff_EBP + -0xa0,1,unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    puVar9 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x5c,unaff_EBP + -0x28,uVar6);
    uVar6 = *puVar9;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x28) = uVar6;
    *(undefined4 *)(unaff_EBP + -0x24) = puVar9[1];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar9[2];
    FUN_005c4890();
    fVar1 = _DAT_00671d5c * _DAT_00667278;
    *(float *)(unaff_EBP + -0x14) = fVar1 * *(float *)(unaff_EBP + -0x2c);
    *(float *)(unaff_EBP + -0x3c) =
         *(float *)(unaff_EBP + -0x28) + fVar1 * *(float *)(unaff_EBP + -0x30);
    *(float *)(unaff_EBP + -0x38) = *(float *)(unaff_EBP + -0x24) + *(float *)(unaff_EBP + -0x10);
    *(float *)(unaff_EBP + -0x34) = *(float *)(unaff_EBP + -0x20) + *(float *)(unaff_EBP + -0x14);
    *(float *)(unaff_EBP + -0x1c) =
         DAT_00673438 * (*(float *)(unaff_EBP + -0x48) + _DAT_00666cbc) * _DAT_00667430 *
         _DAT_0066742c;
    uVar6 = FUN_00462f96(unaff_EBP + -0x128,unaff_EBP + -0x3c);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    uVar10 = FUN_005c38c0(unaff_EBP + -0xe4,1,unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar6 = FUN_0049b9e6(unaff_EBP + -0xa0,uVar10,uVar6);
    iVar4 = *extraout_ECX;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    (**(code **)(iVar4 + 0xb8))(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005c4890();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005c4890();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
  }
  else {
    fVar1 = _DAT_00671d5c * _DAT_00667278;
    *(int *)(unaff_EBP + -0x34) = extraout_ECX[0x1c];
    *(float *)(unaff_EBP + -0x1c) = fVar1;
    uVar6 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x4c) = uVar6;
    *(float *)(unaff_EBP + -0x10) = (float)(extraout_ST1 * extraout_ST0);
    uVar6 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x50) = uVar6;
    (**(code **)(*extraout_ECX + 0x114))(unaff_EBP + -0x50);
    fVar1 = *(float *)(unaff_EBP + -0x34);
    fVar2 = *(float *)(unaff_EBP + -0x1c);
    extraout_ECX[0x21] = *(int *)(unaff_EBP + -0x10);
    extraout_ECX[0x20] = (int)(fVar1 * fVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

