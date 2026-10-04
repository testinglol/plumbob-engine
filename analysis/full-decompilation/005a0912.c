
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_005a0912(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  int extraout_ECX;
  int iVar9;
  int iVar10;
  undefined1 uVar11;
  int unaff_EBP;
  int iVar12;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  uVar5 = FUN_00462c49(unaff_EBP + -0x110,*(undefined4 *)(unaff_EBP + 8),
                       *(undefined4 *)(unaff_EBP + 0xc));
  FUN_005c3650(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049b9e6(unaff_EBP + -0x8c,extraout_ECX + 0x68,unaff_EBP + -0xd0);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  uVar5 = _DAT_0067204c;
  *(undefined4 *)(unaff_EBP + 0xc) = _DAT_0067204c;
  *(undefined4 *)(unaff_EBP + 8) = uVar5;
  uVar5 = _DAT_00672048;
  *(undefined4 *)(unaff_EBP + -0x18) = _DAT_00672048;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
  cVar4 = FUN_0059a443();
  if (cVar4 != '\0') {
    uVar11 = 0;
    goto LAB_005a0acf;
  }
  FUN_0059a42e(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  iVar12 = 8;
  do {
    iVar7 = *(int *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x3c) =
         *(undefined4 *)(iVar7 + (*(uint *)(unaff_EBP + -0x1c) & 1) * 0xc);
    *(undefined4 *)(unaff_EBP + -0x38) =
         *(undefined4 *)(iVar7 + 4 + (*(uint *)(unaff_EBP + -0x1c) >> 1 & 1) * 0xc);
    *(undefined4 *)(unaff_EBP + -0x34) =
         *(undefined4 *)(iVar7 + 8 + (*(uint *)(unaff_EBP + -0x1c) >> 2 & 1) * 0xc);
    pfVar6 = (float *)FUN_005c3840(unaff_EBP + -0x48,unaff_EBP + -0x3c,unaff_EBP + -0x8c);
    fVar1 = *pfVar6;
    fVar2 = pfVar6[1];
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
    *(float *)(unaff_EBP + -0x28) = fVar2;
    if (fVar1 < *(float *)(unaff_EBP + 0xc)) {
      *(float *)(unaff_EBP + 0xc) = fVar1;
    }
    if (*(float *)(unaff_EBP + -0x18) < fVar1) {
      *(float *)(unaff_EBP + -0x18) = fVar1;
    }
    fVar1 = *(float *)(unaff_EBP + -0x28);
    if (fVar1 < *(float *)(unaff_EBP + 8)) {
      *(float *)(unaff_EBP + 8) = fVar1;
    }
    if (*(float *)(unaff_EBP + -0x14) < fVar1) {
      *(float *)(unaff_EBP + -0x14) = fVar1;
    }
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  iVar12 = __ftol();
  iVar7 = __ftol();
  uVar5 = __ftol();
  *(undefined4 *)(unaff_EBP + -0x28) = uVar5;
  iVar8 = __ftol();
  if ((iVar12 < *(int *)(unaff_EBP + -0x28)) && (iVar7 < iVar8)) {
    piVar3 = *(int **)(unaff_EBP + 0x10);
    iVar10 = iVar8 - iVar7 >> 2;
    iVar9 = *(int *)(unaff_EBP + -0x28) - iVar12 >> 2;
    if ((piVar3[3] < iVar7 - iVar10) ||
       (((piVar3[2] < iVar12 - iVar9 || (iVar10 + iVar8 < piVar3[1])) ||
        (iVar9 + *(int *)(unaff_EBP + -0x28) < *piVar3)))) goto LAB_005a0ac7;
  }
  else {
LAB_005a0ac7:
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  uVar11 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_005a0acf:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar11;
}

