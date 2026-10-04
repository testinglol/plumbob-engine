
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005920ea(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  char cVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar11;
  
  FUN_00634c24();
  if (ABS((float)extraout_ECX[0x20] - _DAT_00671edc) <= _DAT_0067343c) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX[0x4e] + 0xf8);
    iVar1 = *(int *)(unaff_EBP + -0x14);
    extraout_ECX[0x20] = (int)(float)iVar1;
    extraout_ECX[0x71] = (int)(float)iVar1;
  }
  if (ABS((float)extraout_ECX[0x21] - _DAT_00671edc) <= _DAT_0067343c) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX[0x4e] + 0xf4);
    iVar1 = *(int *)(unaff_EBP + -0x14);
    extraout_ECX[0x21] = (int)(float)iVar1;
    extraout_ECX[0x72] = (int)(float)iVar1;
  }
  if (ABS((float)extraout_ECX[0x22] - _DAT_00671edc) <= _DAT_0067343c) {
    *(int *)(unaff_EBP + -0x14) = (int)*(short *)(extraout_ECX[0x4e] + 0x4c);
    iVar1 = *(int *)(unaff_EBP + -0x14);
    extraout_ECX[0x22] = (int)(float)iVar1;
    extraout_ECX[0x73] = (int)(float)iVar1;
  }
  *(float *)(unaff_EBP + -0x34) = (float)extraout_ECX[0x23] + (float)extraout_ECX[0x20];
  *(float *)(unaff_EBP + -0x30) = (float)extraout_ECX[0x24] + (float)extraout_ECX[0x21];
  *(float *)(unaff_EBP + -0x40) = (float)extraout_ECX[0x25] + (float)extraout_ECX[0x22];
  uVar6 = __ftol();
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar6;
  uVar6 = __ftol();
  *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  cVar5 = FUN_0045ef89(unaff_EBP + -0x20);
  if (cVar5 == '\0') {
    fVar11 = (float10)FUN_00478f70(unaff_EBP + -0x20);
    if ((DAT_00703e88 & 1) == 0) {
      DAT_00703e88 = DAT_00703e88 | 1;
      _DAT_00703e8c =
           (float)((float10)_DAT_00667280 /
                  (SQRT((float10)_DAT_00666dc0) + SQRT((float10)_DAT_00666dc0)));
    }
    *(float *)(unaff_EBP + -0x14) =
         (float)((float10)_DAT_00703e8c * (float10)_DAT_00671ed4 * fVar11);
  }
  piVar4 = *(int **)(DAT_006e486c + 4);
  uVar6 = (**(code **)(*piVar4 + 0x14))();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
  iVar7 = (**(code **)(*piVar4 + 0x18))();
  iVar8 = (**(code **)(*piVar4 + 0x24))();
  iVar1 = *(int *)(extraout_ECX[0x4e] + 0x110);
  *(int *)(unaff_EBP + -0x3c) = iVar1;
  *(int *)(unaff_EBP + -0x10) = iVar1 + -1;
  iVar1 = *(int *)(unaff_EBP + -0x18);
  *(int *)(unaff_EBP + -0x18) = -iVar7;
  *(float *)(unaff_EBP + -0x10) = (float)*(int *)(unaff_EBP + -0x10);
  iVar8 = iVar8 + iVar1 * -0xc;
  fVar2 = *(float *)(iVar8 + 0xc0);
  fVar3 = *(float *)(iVar8 + 0xbc);
  *(float *)(unaff_EBP + -0x2c) = *(float *)(unaff_EBP + -0x10) * *(float *)(iVar8 + 0xb8);
  *(float *)(unaff_EBP + -0x28) = *(float *)(unaff_EBP + -0x10) * fVar3;
  *(float *)(unaff_EBP + -0x24) = *(float *)(unaff_EBP + -0x10) * fVar2;
  *(float *)(unaff_EBP + -0x18) = (float)*(int *)(unaff_EBP + -0x18) * DAT_00673438 * _DAT_00666578;
  uVar6 = FUN_005c38c0(unaff_EBP + -0x124,1,unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar9 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x58,unaff_EBP + -0x2c,uVar6);
  uVar6 = *puVar9;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(unaff_EBP + -0x2c) = uVar6;
  *(undefined4 *)(unaff_EBP + -0x28) = puVar9[1];
  *(undefined4 *)(unaff_EBP + -0x24) = puVar9[2];
  FUN_005c4890();
  fVar2 = _DAT_00671ed4 * _DAT_00667278;
  *(float *)(unaff_EBP + -0x18) = fVar2 * *(float *)(unaff_EBP + -0x34);
  *(float *)(unaff_EBP + -0x4c) =
       *(float *)(unaff_EBP + -0x2c) + fVar2 * *(float *)(unaff_EBP + -0x30);
  *(float *)(unaff_EBP + -0x48) = *(float *)(unaff_EBP + -0x28) + *(float *)(unaff_EBP + -0x14);
  iVar1 = extraout_ECX[0x4e];
  *(float *)(unaff_EBP + -0x44) = *(float *)(unaff_EBP + -0x24) + *(float *)(unaff_EBP + -0x18);
  if (((*(byte *)(iVar1 + 0x634) & 1) != 1) && ((*(byte *)(iVar1 + 0x614) & 1) != 1)) {
    cVar5 = FUN_00422665(unaff_EBP + -0x20);
    if (cVar5 == '\0') {
      *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + -0x1c) >> 4);
      *(char *)(unaff_EBP + -0xf) = (char)(*(int *)(unaff_EBP + -0x20) >> 4);
      *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + -0x3c);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_004790e8(unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
  }
  *(float *)(unaff_EBP + -0x38) =
       DAT_00673438 * (*(float *)(unaff_EBP + -0x40) + _DAT_00666cbc) * _DAT_00667430 *
       _DAT_0066742c;
  uVar6 = FUN_00462f96(unaff_EBP + -0x168,unaff_EBP + -0x4c);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  uVar10 = FUN_005c38c0(unaff_EBP + -0xe0,1,unaff_EBP + -0x38);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar6 = FUN_0049b9e6(unaff_EBP + -0x9c,uVar10,uVar6);
  iVar1 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  (**(code **)(iVar1 + 0xb8))(uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

