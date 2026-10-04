
void FUN_004d33cb(void)

{
  uint uVar1;
  char cVar2;
  undefined1 uVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  int *piVar9;
  undefined1 auStack_5c [4];
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  
  FUN_00634c24();
  piVar4 = DAT_006f2a90;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffb8;
  *(int **)(unaff_EBP + -0x1c) = piVar4;
  uStack_50 = 0x4d33f2;
  FUN_005d4956();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar4 == (int *)0x0) goto LAB_004d367b;
  iVar6 = *piVar4;
  FUN_005d49d6();
  uStack_50 = 0x4d3411;
  uStack_50 = FUN_004096c2();
  iStack_54 = unaff_EBP + -0x38;
  uStack_58 = 0x4d341b;
  (**(code **)(iVar6 + 0x50))();
  *(undefined1 *)(unaff_EBP + 0xf) = 0;
  *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x2c) + 4;
  *(int *)(unaff_EBP + -0x40) = *(int *)(unaff_EBP + -0x30) + 4;
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x38);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x34);
  uStack_50 = 0x4d345d;
  piVar4 = (int *)FUN_005a58fe();
  *(int **)(unaff_EBP + -0x14) = piVar4;
  if (piVar4 == (int *)0x0) {
    uStack_50 = 0x4d3470;
    piVar4 = (int *)FUN_005a5927();
    *(int **)(unaff_EBP + -0x14) = piVar4;
  }
  piVar9 = (int *)*piVar4;
  *(int **)(unaff_EBP + -0x18) = piVar9;
  if (piVar9 == (int *)0x0) {
    uStack_50 = 0x4d3485;
    pvVar5 = operator_new(100);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar5 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_005dfb13();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *piVar4 = iVar6;
    FUN_005e357a();
    piVar9 = (int *)*piVar4;
    uStack_50 = 0;
    iVar6 = *piVar9;
    iStack_54 = 0;
    *(undefined1 **)(unaff_EBP + 8) = auStack_5c;
    *(int **)(unaff_EBP + -0x18) = piVar9;
    uStack_58 = extraout_ECX;
    FUN_00436a50(4);
    uVar7 = FUN_004a946b();
    uVar7 = FUN_004a9465(uVar7);
    cVar2 = (**(code **)(iVar6 + 0xc))(uVar7);
    if (cVar2 == '\0') {
      piVar4 = *(int **)(unaff_EBP + -0x14);
      cVar2 = *(char *)(unaff_EBP + 0xf);
    }
    else {
      cVar2 = '\x01';
LAB_004d34e4:
      piVar4 = *(int **)(unaff_EBP + -0x14);
    }
  }
  else {
    iVar6 = piVar9[7];
    *(int *)(unaff_EBP + -0x38) = piVar9[5];
    *(int *)(unaff_EBP + -0x34) = piVar9[6];
    *(int *)(unaff_EBP + -0x2c) = piVar9[8];
    iVar8 = *(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x48);
    *(int *)(unaff_EBP + -0x30) = iVar6;
    if (iVar6 - *(int *)(unaff_EBP + -0x38) < iVar8) {
      iVar6 = *(int *)(unaff_EBP + -0x38) + iVar8;
      *(int *)(unaff_EBP + -0x30) = iVar6;
    }
    iVar8 = *(int *)(unaff_EBP + -0x3c) - *(int *)(unaff_EBP + -0x44);
    if (*(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x34) < iVar8) {
      *(int *)(unaff_EBP + -0x2c) = iVar8 + *(int *)(unaff_EBP + -0x34);
    }
    if ((((*(int *)(unaff_EBP + -0x38) != piVar9[5]) || (iVar6 != piVar9[7])) ||
        (*(int *)(unaff_EBP + -0x34) != piVar9[6])) || (*(int *)(unaff_EBP + -0x2c) != piVar9[8])) {
      (**(code **)(*piVar9 + 0x18))();
      iVar6 = *piVar9;
      uStack_50 = 0;
      iStack_54 = 0;
      *(undefined1 **)(unaff_EBP + 8) = auStack_5c;
      uStack_58 = extraout_ECX_00;
      FUN_00436a50(4);
      uVar7 = FUN_004a946b();
      uVar7 = FUN_004a9465(uVar7);
      cVar2 = (**(code **)(iVar6 + 0xc))(uVar7);
      goto LAB_004d34e4;
    }
    cVar2 = '\x01';
  }
  uVar1 = *(uint *)(*(int *)(DAT_006e486c + 0x1c) + 0x98);
  *(uint *)(unaff_EBP + 0xc) = uVar1;
  if (((cVar2 != '\0') && (piVar9 != (int *)0x0)) &&
     ((piVar4[5] + 100U < uVar1 || ((char)piVar4[6] == '\0')))) {
    piVar4[1] = *(int *)(unaff_EBP + -0x48);
    piVar4[2] = *(int *)(unaff_EBP + -0x44);
    piVar4[3] = *(int *)(unaff_EBP + -0x40);
    piVar4[4] = *(int *)(unaff_EBP + -0x3c);
    uStack_50 = 0x4d35e9;
    cVar2 = (**(code **)(*piVar9 + 0x20))();
    if (cVar2 != '\0') {
      iVar6 = *piVar9;
      uStack_50 = *(undefined4 *)(unaff_EBP + 0x10);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iStack_54 = 0x4d3603;
      uVar3 = (**(code **)(iVar6 + 0x38))();
      *(undefined1 *)(unaff_EBP + 0xb) = uVar3;
      FUN_004d3618();
      return;
    }
  }
LAB_004d367b:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

