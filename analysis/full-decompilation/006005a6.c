
undefined4 FUN_006005a6(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  bool bVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4956(&DAT_006c0fdc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d4956(&DAT_006c21c8);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  iVar3 = *(int *)(unaff_EBP + 0xc);
  iVar6 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if ((iVar3 < 1) && (iVar3 < 0)) {
    bVar7 = iVar6 != 0;
    iVar6 = -iVar6;
    *(undefined1 *)(unaff_EBP + 0xf) = 1;
    iVar3 = -(iVar3 + (uint)bVar7);
  }
  else {
    *(undefined1 *)(unaff_EBP + 0xf) = 0;
  }
  FUN_005d5156(unaff_EBP + -0x4c,s__I64d_006d9028,iVar6,iVar3);
  (**(code **)(*extraout_ECX + 0x30))(unaff_EBP + -100);
  iVar6 = *(int *)(unaff_EBP + -0x48) - *(int *)(unaff_EBP + -0x4c);
  for (iVar3 = iVar6; 3 < iVar3; iVar3 = iVar3 - *(int *)(unaff_EBP + -0x10)) {
    *(int *)(unaff_EBP + -0x10) = iVar3 % 3;
    if (iVar3 % 3 == 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 3;
    }
    puVar4 = (undefined4 *)
             FUN_005d4c48(unaff_EBP + -0x70,iVar6 - iVar3,*(undefined4 *)(unaff_EBP + -0x10));
    uVar5 = puVar4[1];
    uVar8 = *puVar4;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_00412d8a(uVar8,uVar5);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    FUN_00412d8a(*(undefined4 *)(unaff_EBP + -100),*(undefined4 *)(unaff_EBP + -0x60));
  }
  puVar4 = (undefined4 *)FUN_005d4c15(unaff_EBP + -0x70,iVar3);
  uVar5 = puVar4[1];
  uVar8 = *puVar4;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00412d8a(uVar8,uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  cVar2 = (**(code **)(*extraout_ECX + 0x28))();
  if (cVar2 == '\0') {
    FUN_005d499c(unaff_EBP + -0x1c);
    cVar2 = (**(code **)(*extraout_ECX + 0x2c))();
    if (cVar2 != '\0') {
      FUN_004015e4(0x20);
    }
    (**(code **)(*extraout_ECX + 0x24))(unaff_EBP + -0x58);
    uVar5 = *(undefined4 *)(unaff_EBP + -0x54);
    uVar8 = *(undefined4 *)(unaff_EBP + -0x58);
  }
  else {
    (**(code **)(*extraout_ECX + 0x24))(unaff_EBP + -0x34);
    cVar2 = (**(code **)(*extraout_ECX + 0x2c))();
    if (cVar2 != '\0') {
      FUN_004015e4(0x20);
    }
    uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
    uVar8 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  FUN_00412d8a(uVar8,uVar5);
  if (*(char *)(unaff_EBP + 0xf) == '\0') {
    FUN_005d499c(unaff_EBP + -0x34);
    goto LAB_00600842;
  }
  uVar1 = extraout_ECX[2];
  if (uVar1 < 0xb) {
    if (uVar1 == 10) {
      (**(code **)(*extraout_ECX + 0x24))(*(undefined4 *)(unaff_EBP + 0x10));
LAB_006007cd:
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x3c));
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
      goto LAB_00600842;
    }
    if (uVar1 == 0) goto LAB_00600842;
    if (7 < uVar1) {
      if (uVar1 == 8) goto LAB_006007b9;
      if (uVar1 != 9) goto LAB_00600842;
    }
  }
  else if (uVar1 != 0xb) {
    if (uVar1 == 0xc) {
LAB_006007b9:
      (**(code **)(*extraout_ECX + 0x24))(*(undefined4 *)(unaff_EBP + 0x10));
      FUN_004015e4(0x20);
      goto LAB_006007cd;
    }
    if ((uVar1 < 0xd) || (0x13 < uVar1)) goto LAB_00600842;
  }
  uVar5 = FUN_00412ab1(unaff_EBP + -0x7c,unaff_EBP + -0x40,unaff_EBP + -0x34);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005b86bd(uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_005d499c(unaff_EBP + -0x70);
  *(undefined1 *)(unaff_EBP + -4) = 9;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00401729();
LAB_00600842:
  uVar5 = FUN_004096c2();
  FUN_005d49b7(uVar5);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
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

