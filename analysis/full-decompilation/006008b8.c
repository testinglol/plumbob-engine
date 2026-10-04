
undefined4 FUN_006008b8(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  int *piVar8;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x34) = extraout_ECX;
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
  iVar3 = *(int *)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  *(bool *)(unaff_EBP + 0xb) = iVar3 < 0;
  if (*(char *)(unaff_EBP + 0xb) != '\0') {
    iVar3 = -iVar3;
  }
  FUN_005d5156(unaff_EBP + -0x40,&DAT_006c08e4,iVar3);
  (**(code **)(*extraout_ECX + 0x30))(unaff_EBP + -0x4c);
  iVar4 = FUN_005d49d6();
  iVar3 = iVar4;
  piVar8 = extraout_ECX;
  if (3 < iVar4) {
    do {
      iVar7 = iVar3 % 3;
      if (iVar7 == 0) {
        iVar7 = 3;
      }
      puVar5 = (undefined4 *)FUN_005d4c48(unaff_EBP + -0x24,iVar4 - iVar3,iVar7);
      uVar6 = puVar5[1];
      uVar1 = *puVar5;
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_00412d8a(uVar1,uVar6);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_005b8770();
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x4c),*(undefined4 *)(unaff_EBP + -0x48));
      iVar3 = iVar3 - iVar7;
    } while (3 < iVar3);
    piVar8 = *(int **)(unaff_EBP + -0x34);
  }
  puVar5 = (undefined4 *)FUN_005d4c15(unaff_EBP + -0x24,iVar3);
  uVar6 = puVar5[1];
  uVar1 = *puVar5;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00412d8a(uVar1,uVar6);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  if (*(char *)(unaff_EBP + 0xb) == '\0') {
    FUN_005d499c(unaff_EBP + -0x18);
    goto LAB_00600ad7;
  }
  uVar2 = piVar8[2];
  if (uVar2 == 0) goto LAB_00600ad7;
  if (uVar2 < 0xb) {
LAB_00600a85:
    uVar6 = FUN_00412ab1(unaff_EBP + -0x70,unaff_EBP + -0x58,unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005b86bd(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005d499c(unaff_EBP + -0x24);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  else {
    if (uVar2 != 0xb) {
      if ((uVar2 < 0xc) || ((0xd < uVar2 && ((uVar2 < 0xf || (0x13 < uVar2)))))) goto LAB_00600ad7;
      goto LAB_00600a85;
    }
    uVar6 = FUN_00412ab1(unaff_EBP + -0x88,unaff_EBP + -0x18,unaff_EBP + -0x58);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b86bd(uVar6);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005d499c(unaff_EBP + -100);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 6;
  }
  FUN_00401729();
LAB_00600ad7:
  uVar6 = FUN_004096c2();
  FUN_005d49b7(uVar6);
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

