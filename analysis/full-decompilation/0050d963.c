
undefined1 FUN_0050d963(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  undefined1 uVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  void *pvVar10;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  
  FUN_00634c24();
  cVar5 = (**(code **)(*extraout_ECX + 200))();
  if (cVar5 != '\0') {
    uVar6 = FUN_005dbf32();
    goto LAB_0050df60;
  }
  cVar5 = FUN_005dbf32();
  uVar6 = 0;
  if (cVar5 == '\0') goto LAB_0050df60;
  FUN_005a5631(0xbc0,extraout_ECX + 0x3c,4);
  FUN_005a5631(0x1382,extraout_ECX + 0x3b,4);
  iVar9 = extraout_ECX[0x3b];
  if (iVar9 != 0) {
    iVar13 = *(int *)(iVar9 + 0x14);
    iVar1 = *(int *)(iVar9 + 0x1c);
    iVar2 = *(int *)(iVar9 + 0x20);
    iVar4 = extraout_ECX[0x38];
    *(int *)(unaff_EBP + -0x20) = *(int *)(iVar9 + 0x18) + -0x10;
    *(int *)(unaff_EBP + -0x24) = iVar13 + -0x10;
    *(int *)(unaff_EBP + -0x1c) = iVar1 + 0x10;
    *(int *)(unaff_EBP + -0x18) = iVar2 + 0x10;
    if ((char)iVar4 == '\0') {
      piVar7 = (int *)FUN_005e7743();
      iVar9 = *piVar7;
      *(int **)(unaff_EBP + -0x10) = piVar7;
      uVar8 = FUN_005e50fa(3);
    }
    else {
      piVar7 = (int *)FUN_005e7743();
      iVar9 = *piVar7;
      *(int **)(unaff_EBP + -0x10) = piVar7;
      uVar8 = FUN_005e50fa(4);
    }
    iVar9 = (**(code **)(iVar9 + 0x24))(3,uVar8);
    extraout_ECX[0x3d] = iVar9;
    if (iVar9 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar9);
    }
    if ((char)extraout_ECX[0x38] != '\0') {
      piVar7 = (int *)FUN_005e7743();
      iVar9 = *piVar7;
      *(int **)(unaff_EBP + -0x10) = piVar7;
      uVar8 = FUN_005e50fa(1);
      iVar9 = (**(code **)(iVar9 + 0x24))(1,uVar8);
      extraout_ECX[0x3f] = iVar9;
      if (iVar9 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar9);
      }
      piVar7 = (int *)FUN_005e7743();
      iVar9 = *piVar7;
      *(int **)(unaff_EBP + -0x10) = piVar7;
      uVar8 = FUN_005e50fa(2);
      iVar9 = (**(code **)(iVar9 + 0x24))(2,uVar8);
      extraout_ECX[0x3e] = iVar9;
      if (iVar9 != 0) {
        (**(code **)(*extraout_ECX + 0x20))(iVar9);
      }
    }
    iVar9 = extraout_ECX[0x3d];
    if (iVar9 != 0) {
      *(int *)(unaff_EBP + -0x18) =
           *(int *)(unaff_EBP + -0x18) + (*(int *)(iVar9 + 0x88) - *(int *)(iVar9 + 0x80));
    }
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 0x10;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -*(int *)(unaff_EBP + -0x20);
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + -*(int *)(unaff_EBP + -0x20);
    iVar9 = *extraout_ECX;
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -*(int *)(unaff_EBP + -0x24);
    *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + -*(int *)(unaff_EBP + -0x24);
    (**(code **)(iVar9 + 0x60))
              (*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
               *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18));
    FUN_005ddfdc(1);
    extraout_ECX[0x40] = 0x10;
    extraout_ECX[0x41] = 0x10;
    pvVar10 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x14) = pvVar10;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar10 == (void *)0x0) {
      iVar9 = 0;
    }
    else {
      iVar9 = FUN_005f179a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x3a] = iVar9;
    FUN_0050e1eb();
    if (extraout_ECX[0x3a] != 0) {
      FUN_005f42c3(DAT_006f2a9c);
      FUN_005f4336(DAT_006f2a48);
      FUN_005f4256(0,DAT_006f2a48,DAT_006f2a48);
      FUN_005f42b6(1);
      FUN_005f489f(1);
      iVar9 = extraout_ECX[0x40];
      iVar13 = *(int *)(extraout_ECX[0x3b] + 0x14);
      piVar7 = (int *)extraout_ECX[0x3a];
      *(int *)(unaff_EBP + -0x1c) = *(int *)(extraout_ECX[0x3b] + 0x1c) + -4 + iVar9 + 4;
      (**(code **)(*piVar7 + 0x60))
                (iVar13 + 4 + iVar9 + 4,0x19,*(undefined4 *)(unaff_EBP + -0x1c),0x2d);
      *(int *)(extraout_ECX[0x3a] + 8) = extraout_ECX[0x39];
      FUN_005f4294(0);
      (**(code **)(*(int *)extraout_ECX[0x3a] + 0x90))(0x2000,0);
      FUN_005f42a1(0);
      FUN_005f435f(0x31);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3a]);
      uVar12 = 1;
      uVar11 = 0;
      uVar8 = FUN_004096c2(0,1);
      FUN_005f436c(uVar8,uVar11,uVar12);
    }
    pvVar10 = operator_new(0x1b8);
    *(void **)(unaff_EBP + -0x14) = pvVar10;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar10 == (void *)0x0) {
      iVar9 = 0;
    }
    else {
      iVar9 = FUN_005f179a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x39] = iVar9;
    if (iVar9 != 0) {
      FUN_005f42c3(DAT_006f2a9c);
      FUN_005f4336(DAT_006f2a48);
      FUN_005f4256(0,DAT_006f2a48,DAT_006f2a48);
      FUN_005f42b6(0xffffffff);
      FUN_005f489f(1);
      iVar9 = extraout_ECX[0x3b];
      iVar13 = *(int *)(iVar9 + 0x14);
      *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar9 + 0x18);
      iVar1 = *(int *)(iVar9 + 0x1c);
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar9 + 0x20);
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + -4;
      *(int *)(unaff_EBP + -0x24) = iVar13 + 4;
      iVar9 = extraout_ECX[0x41];
      *(int *)(unaff_EBP + -0x1c) = iVar1 + -4;
      iVar13 = extraout_ECX[0x40];
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar9 + 4;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar13 + 4;
      piVar7 = (int *)extraout_ECX[0x39];
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar13 + 4;
      (**(code **)(*piVar7 + 0x60))
                (*(undefined4 *)(unaff_EBP + -0x24),*(int *)(unaff_EBP + -0x20) + 0x1e,
                 *(undefined4 *)(unaff_EBP + -0x1c),*(int *)(unaff_EBP + -0x18) + iVar9 + 4 + -0x1e)
      ;
      *(int *)(extraout_ECX[0x39] + 8) = extraout_ECX[0x39];
      FUN_005f4294(0);
      (**(code **)(*(int *)extraout_ECX[0x39] + 0x90))(0x2000,0);
      FUN_005f42a1(0);
      FUN_005f435f(0xfe);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
      uVar12 = 1;
      uVar11 = 0;
      uVar8 = FUN_004096c2(0,1);
      FUN_005f436c(uVar8,uVar11,uVar12);
    }
    if ((char)extraout_ECX[0x38] != '\0') {
      pvVar10 = operator_new(0x6c);
      *(void **)(unaff_EBP + -0x10) = pvVar10;
      *(undefined4 *)(unaff_EBP + -4) = 2;
      if (pvVar10 == (void *)0x0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      else {
        FUN_0046fca5();
        puVar3 = *(undefined4 **)(unaff_EBP + -0x10);
        *(undefined4 **)(unaff_EBP + -0x10) = puVar3;
        *puVar3 = &PTR_FUN_0066643c;
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uVar8 = FUN_0041532c(9,*(undefined4 *)(unaff_EBP + -0x10),0);
      cVar5 = FUN_004fff98(0x99,uVar8);
      if (cVar5 != '\0') {
        uVar8 = FUN_004705f2(5,0xffffffff);
        FUN_005d4bbf(uVar8);
      }
      if (*(undefined4 **)(unaff_EBP + -0x10) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(unaff_EBP + -0x10))(1);
      }
    }
    iVar9 = extraout_ECX[0x3d];
    iVar13 = extraout_ECX[0x21];
    iVar1 = extraout_ECX[0x1f];
    iVar2 = *(int *)(iVar9 + 0x7c);
    iVar4 = *(int *)(iVar9 + 0x84);
    *(int *)(unaff_EBP + -0x14) = iVar13 - iVar1;
    *(int *)(unaff_EBP + -0x10) = ((iVar2 - iVar4) + (iVar13 - iVar1)) / 2;
    if (iVar9 != 0) {
      if ((char)extraout_ECX[0x38] == '\0') {
        iVar13 = ((*(int *)(iVar9 + 0x80) - *(int *)(iVar9 + 0x88)) - extraout_ECX[0x20]) + -0x10 +
                 extraout_ECX[0x22];
        uVar8 = *(undefined4 *)(unaff_EBP + -0x10);
      }
      else {
        if ((iVar9 == 0) || ((char)extraout_ECX[0x38] == '\0')) goto LAB_0050de8a;
        iVar1 = *(int *)(iVar9 + 0x80);
        iVar13 = extraout_ECX[0x22];
        iVar9 = *(int *)(iVar9 + 0x88);
        *(undefined4 *)(unaff_EBP + -0x10) = 5;
        iVar13 = ((iVar1 - iVar9) - extraout_ECX[0x20]) + -5 + iVar13;
        uVar8 = 5;
      }
      FUN_004cb21d(uVar8,iVar13);
    }
LAB_0050de8a:
    iVar9 = extraout_ECX[0x3f];
    if (iVar9 != 0) {
      FUN_004cb21d((((extraout_ECX[0x21] - *(int *)(iVar9 + 0x84)) - extraout_ECX[0x1f]) -
                   *(int *)(unaff_EBP + -0x10)) + *(int *)(iVar9 + 0x7c),
                   ((*(int *)(iVar9 + 0x80) - *(int *)(iVar9 + 0x88)) - extraout_ECX[0x20]) + -5 +
                   extraout_ECX[0x22]);
    }
    iVar9 = extraout_ECX[0x3e];
    if (iVar9 != 0) {
      FUN_004cb21d(((*(int *)(unaff_EBP + -0x14) - *(int *)(iVar9 + 0x84)) + *(int *)(iVar9 + 0x7c))
                   / 2,((*(int *)(extraout_ECX[0x3f] + 0x80) - *(int *)(extraout_ECX[0x3f] + 0x88))
                       - extraout_ECX[0x20]) + -5 + extraout_ECX[0x22]);
    }
    (**(code **)(*extraout_ECX + 0x90))(0x2000,1);
    (**(code **)(*(int *)extraout_ECX[0x3d] + 0x90))(0x2000,1);
    if ((char)extraout_ECX[0x38] != '\0') {
      (**(code **)(*(int *)extraout_ECX[0x3f] + 0x90))(0x2000,1);
      (**(code **)(*(int *)extraout_ECX[0x3e] + 0x90))(0x2000,1);
    }
  }
  uVar6 = 1;
LAB_0050df60:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

