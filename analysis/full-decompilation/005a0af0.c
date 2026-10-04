
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a0af0(void)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  char cVar4;
  undefined4 uVar5;
  float *pfVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar8;
  int iVar9;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x34) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x30) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x3c) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x38) = 0x7fffffff;
  uVar5 = FUN_00462c49(unaff_EBP + -0x11c,*(undefined4 *)(unaff_EBP + 0xc),
                       *(undefined4 *)(unaff_EBP + 0x10));
  FUN_005c3650(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049b9e6(unaff_EBP + -0x98,extraout_ECX + 0x68,unaff_EBP + -0xdc);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  uVar5 = _DAT_0067204c;
  *(undefined4 *)(unaff_EBP + 0x10) = _DAT_0067204c;
  *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
  uVar5 = _DAT_00672048;
  *(undefined4 *)(unaff_EBP + -0x14) = _DAT_00672048;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
  cVar4 = FUN_0059a443();
  if (cVar4 == '\0') {
    FUN_0059a42e(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    iVar9 = 8;
    do {
      iVar7 = *(int *)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x48) =
           *(undefined4 *)(iVar7 + (*(uint *)(unaff_EBP + -0x18) & 1) * 0xc);
      *(undefined4 *)(unaff_EBP + -0x44) =
           *(undefined4 *)(iVar7 + 4 + (*(uint *)(unaff_EBP + -0x18) >> 1 & 1) * 0xc);
      *(undefined4 *)(unaff_EBP + -0x40) =
           *(undefined4 *)(iVar7 + 8 + (*(uint *)(unaff_EBP + -0x18) >> 2 & 1) * 0xc);
      pfVar6 = (float *)FUN_005c3840(unaff_EBP + -0x54,unaff_EBP + -0x48,unaff_EBP + -0x98);
      fVar1 = *pfVar6;
      fVar2 = pfVar6[1];
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      *(float *)(unaff_EBP + -0x24) = fVar2;
      if (fVar1 < *(float *)(unaff_EBP + 0x10)) {
        *(float *)(unaff_EBP + 0x10) = fVar1;
      }
      if (*(float *)(unaff_EBP + -0x14) < fVar1) {
        *(float *)(unaff_EBP + -0x14) = fVar1;
      }
      fVar1 = *(float *)(unaff_EBP + -0x24);
      if (fVar1 < *(float *)(unaff_EBP + 0xc)) {
        *(float *)(unaff_EBP + 0xc) = fVar1;
      }
      if (*(float *)(unaff_EBP + -0x10) < fVar1) {
        *(float *)(unaff_EBP + -0x10) = fVar1;
      }
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    iVar9 = __ftol();
    *(int *)(unaff_EBP + -0x2c) = iVar9;
    uVar5 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
    uVar5 = __ftol();
    *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
    iVar7 = __ftol();
    *(int *)(unaff_EBP + -0x20) = iVar7;
    if ((iVar9 < *(int *)(unaff_EBP + -0x24)) &&
       (puVar8 = (undefined4 *)(unaff_EBP + -0x2c), *(int *)(unaff_EBP + -0x28) < iVar7))
    goto LAB_005a0c91;
  }
  puVar8 = (undefined4 *)(unaff_EBP + -0x3c);
LAB_005a0c91:
  puVar3 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *puVar3 = *puVar8;
  puVar3[1] = puVar8[1];
  puVar3[2] = puVar8[2];
  puVar3[3] = puVar8[3];
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

