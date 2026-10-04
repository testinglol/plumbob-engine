
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049b248(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  int extraout_ECX;
  int unaff_EBP;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  
  FUN_00634c24();
  iVar8 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar8 + 0x68);
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar8 + 0x6c);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar8 + 0x70);
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(iVar8 + 0x74);
  iVar8 = *(int *)(unaff_EBP + -0x40);
  iVar9 = *(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x4c);
  iVar2 = *(int *)(unaff_EBP + -0x48);
  *(undefined4 *)(extraout_ECX + 0x174) = 0x42480000;
  *(int *)(unaff_EBP + -0x38) = iVar9;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x437f0000;
  fVar10 = (float10)FUN_00454f69();
  *(float *)(unaff_EBP + -0x2c) = (float)(fVar10 * (float10)_DAT_006682e0 + (float10)_DAT_00668310);
  fVar10 = (float10)FUN_00636264(_DAT_00668308);
  *(float *)(unaff_EBP + -0x1c) = (float)(fVar10 * (float10)_DAT_006682e0 * (float10)_DAT_00668300);
  uVar4 = _DAT_006682f8;
  *(int *)(unaff_EBP + -0x30) = extraout_ECX + (8 - *(int *)(unaff_EBP + 8)) * 4;
  fVar10 = (float10)FUN_00636264(uVar4);
  **(float **)(unaff_EBP + -0x30) =
       (float)((float10)*(float *)(unaff_EBP + -0x2c) * (float10)_DAT_00666578 +
              fVar10 * (float10)*(float *)(unaff_EBP + -0x1c) * (float10)_DAT_00667270);
  *(float *)(unaff_EBP + -0x1c) = (float)*(int *)(unaff_EBP + -0x38);
  fVar11 = (float10)FUN_00636264(_DAT_00668308);
  iVar3 = *(int *)(unaff_EBP + 8);
  fVar10 = (float10)_DAT_006682e0;
  *(int *)(unaff_EBP + 8) = 0x10 << ((byte)iVar3 & 0x1f);
  fVar10 = (fVar11 * (float10)*(float *)(unaff_EBP + -0x1c) * fVar10) /
           (float10)*(int *)(unaff_EBP + 8);
  *(float *)(unaff_EBP + -0x3c) = (float)fVar10;
  *(float *)(unaff_EBP + -0x34) = (float)(fVar10 / (float10)*(float *)(unaff_EBP + -0x1c));
  fVar1 = **(float **)(unaff_EBP + -0x30) - _DAT_006682f4;
  *(float *)(unaff_EBP + -0x50) = fVar1;
  *(float *)(extraout_ECX + (0x61 - iVar3) * 4) = fVar1;
  *(float *)(unaff_EBP + -0x2c) =
       DAT_00673438 * (_DAT_00667430 - (float)*(int *)(unaff_EBP + 0x14) * _DAT_006682f0) *
       _DAT_0066742c;
  *(float *)(unaff_EBP + -0x1c) = DAT_00673438 * _DAT_006682ec;
  uVar5 = FUN_005c38c0(unaff_EBP + -0x200,1,unaff_EBP + -0x2c);
  *(undefined4 *)(unaff_EBP + 8) = uVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar5 = FUN_005c38c0(unaff_EBP + -0x1bc,0,unaff_EBP + -0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0049b9e6(unaff_EBP + -0x134,uVar5,*(undefined4 *)(unaff_EBP + 8));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + -0x50);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  FUN_005c3840(unaff_EBP + -0x18,unaff_EBP + -0x28,unaff_EBP + -0x134);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  puVar6 = (undefined4 *)FUN_0049b849(unaff_EBP + -0x48,unaff_EBP + -0x28,unaff_EBP + -0x18);
  *(undefined4 *)(extraout_ECX + 0x184) = *puVar6;
  *(undefined4 *)(extraout_ECX + 0x188) = puVar6[1];
  *(undefined4 *)(extraout_ECX + 0x18c) = puVar6[2];
  FUN_0049b802();
  FUN_0049b967();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_0049b891();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + 8) = 0;
  fVar1 = *(float *)(unaff_EBP + -0x34) * _DAT_00666c18;
  *(float *)(unaff_EBP + -0x34) = fVar1;
  *(float *)(unaff_EBP + -0x28) = fVar1;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  FUN_005c3840(unaff_EBP + -0x5c,unaff_EBP + -0x28,unaff_EBP + -0x178);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_EBP + 8);
  FUN_005c3840(unaff_EBP + -0x68,unaff_EBP + -0x28,unaff_EBP + -0x178);
  iVar3 = *(int *)(unaff_EBP + 0x14);
  if (iVar3 == 1) {
    fVar1 = _DAT_006682e0 * _DAT_00668300;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x10);
    *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + fVar1;
  }
  else if (iVar3 == 2) {
    fVar1 = _DAT_006682e0 * _DAT_00668300;
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x14);
    *(float *)(unaff_EBP + 8) = fVar1;
    *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + fVar1;
    *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + *(float *)(unaff_EBP + 8);
  }
  else if (iVar3 == 3) {
    fVar1 = _DAT_006682e0 * _DAT_00668300;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x14);
    *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + fVar1;
  }
  *(int *)(unaff_EBP + 8) = -*(int *)(unaff_EBP + 0xc);
  *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
  pfVar7 = (float *)FUN_0049b86e(unaff_EBP + -0x48,unaff_EBP + 8,unaff_EBP + -0x5c);
  *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + *pfVar7;
  *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) + pfVar7[1];
  fVar1 = pfVar7[2];
  *(int *)(unaff_EBP + 8) = -*(int *)(unaff_EBP + 0x10);
  *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + fVar1;
  *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
  pfVar7 = (float *)FUN_0049b86e(unaff_EBP + -0x48,unaff_EBP + 8,unaff_EBP + -0x68);
  *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + *pfVar7;
  *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) + pfVar7[1];
  fVar1 = pfVar7[2];
  *(int *)(unaff_EBP + 8) = iVar9 >> 1;
  *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + fVar1;
  *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
  pfVar7 = (float *)FUN_0049b86e(unaff_EBP + -0x48,unaff_EBP + 8,unaff_EBP + -0x5c);
  *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + *pfVar7;
  *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) + pfVar7[1];
  fVar1 = pfVar7[2];
  *(int *)(unaff_EBP + 8) = iVar8 - iVar2 >> 1;
  *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + fVar1;
  *(float *)(unaff_EBP + 8) = (float)*(int *)(unaff_EBP + 8);
  pfVar7 = (float *)FUN_0049b86e(unaff_EBP + -0x48,unaff_EBP + 8,unaff_EBP + -0x68);
  *(float *)(unaff_EBP + -0x18) = *(float *)(unaff_EBP + -0x18) + *pfVar7;
  *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) + pfVar7[1];
  *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x10) + pfVar7[2];
  FUN_005d0422(unaff_EBP + -0x18,extraout_ECX + 0x184);
  *(undefined4 *)(*(int *)(extraout_ECX + 0x10) + 0xbc) = 0x3f800000;
  FUN_005d06b6();
  puVar6 = *(undefined4 **)(unaff_EBP + -0x30);
  *(undefined4 *)(*(int *)(extraout_ECX + 0x10) + 0xc0) = *puVar6;
  FUN_005d06b6();
  *(float *)(unaff_EBP + 8) =
       *(float *)(*(int *)(extraout_ECX + 4) + 0x18) / *(float *)(*(int *)(extraout_ECX + 4) + 0x1c)
  ;
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  uVar5 = FUN_0049ba2e(unaff_EBP + -0xf0,unaff_EBP + 0xc,puVar6,unaff_EBP + -0x3c,unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_005ce950(uVar5,0);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  iVar8 = FUN_005cf11a();
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 300) = *(undefined4 *)(iVar8 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  *(undefined4 *)(extraout_ECX + 300) = 0;
  *(undefined4 *)(extraout_ECX + 0x114) = 0x477fff00;
  uVar5 = FUN_0049b9e6(unaff_EBP + -0xac,*(int *)(extraout_ECX + 4) + 300,
                       *(int *)(extraout_ECX + 4) + 0x170);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  iVar8 = FUN_0049b9e6(unaff_EBP + -0xf0,uVar5,extraout_ECX + 0xec);
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 300) = *(undefined4 *)(iVar8 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  iVar8 = FUN_0049b967();
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 0xe8) = *(undefined4 *)(iVar8 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  *(uint *)(unaff_EBP + 0x14) = -*(int *)(unaff_EBP + 0x14) & 3;
  *(float *)(unaff_EBP + 0x14) = (float)*(int *)(unaff_EBP + 0x14) * DAT_00673438 * _DAT_00666578;
  iVar8 = FUN_005c38c0(unaff_EBP + -0xac,1,unaff_EBP + 0x14);
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_00462f2f();
  *(undefined4 *)(extraout_ECX + 0x170) = *(undefined4 *)(iVar8 + 0x40);
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

