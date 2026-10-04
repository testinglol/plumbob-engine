
undefined4 FUN_00600b50(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int iVar6;
  int iVar7;
  int unaff_EBP;
  int *piVar8;
  bool bVar9;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(&DAT_006c0fdc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d4956(&DAT_006c21c8);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  iVar6 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if ((iVar3 < 1) && (iVar3 < 0)) {
    bVar9 = iVar6 != 0;
    iVar6 = -iVar6;
    *(undefined1 *)(unaff_EBP + 0xf) = 1;
    iVar3 = -(iVar3 + (uint)bVar9);
  }
  else {
    *(undefined1 *)(unaff_EBP + 0xf) = 0;
  }
  FUN_005d5156(unaff_EBP + -0x34,s__I64d_006d9028,iVar6,iVar3);
  (**(code **)(*extraout_ECX + 0x30))(unaff_EBP + -0x40);
  iVar6 = FUN_005d49d6();
  iVar3 = iVar6;
  piVar8 = extraout_ECX;
  if (3 < iVar6) {
    do {
      iVar7 = iVar3 % 3;
      if (iVar7 == 0) {
        iVar7 = 3;
      }
      puVar4 = (undefined4 *)FUN_005d4c48(unaff_EBP + -100,iVar6 - iVar3,iVar7);
      uVar5 = puVar4[1];
      uVar1 = *puVar4;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_00412d8a(uVar1,uVar5);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x3c));
      iVar3 = iVar3 - iVar7;
    } while (3 < iVar3);
    piVar8 = *(int **)(unaff_EBP + -0x10);
  }
  puVar4 = (undefined4 *)FUN_005d4c15(unaff_EBP + -100,iVar3);
  uVar5 = puVar4[1];
  uVar1 = *puVar4;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_00412d8a(uVar1,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  if (*(char *)(unaff_EBP + 0xf) == '\0') {
    FUN_005d499c(unaff_EBP + -0x1c);
    goto LAB_00600d76;
  }
  uVar2 = piVar8[2];
  if (uVar2 == 0) goto LAB_00600d76;
  if (uVar2 < 0xb) {
LAB_00600d24:
    uVar5 = FUN_00412ab1(unaff_EBP + -0x7c,unaff_EBP + -0x4c,unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005b86bd(uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005d499c(unaff_EBP + -100);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
  }
  else {
    if (uVar2 != 0xb) {
      if ((uVar2 < 0xc) || ((0xd < uVar2 && ((uVar2 < 0xf || (0x13 < uVar2)))))) goto LAB_00600d76;
      goto LAB_00600d24;
    }
    uVar5 = FUN_00412ab1(unaff_EBP + -0x70,unaff_EBP + -0x1c,unaff_EBP + -0x4c);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005b86bd(uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005d499c(unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
  }
  FUN_00401729();
LAB_00600d76:
  uVar5 = FUN_004096c2();
  FUN_005d49b7(uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

