
undefined1 FUN_004cad42(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined1 uVar8;
  int unaff_EBP;
  int iStack_6c;
  int iStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  uVar8 = 0;
  iVar5 = *(int *)(iVar1 + 0x1c);
  iVar7 = *(int *)(iVar1 + 0x20);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  if (iVar5 == 0x2d) {
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
  }
  else if (iVar5 == 0xb4) {
    *(undefined4 *)(unaff_EBP + -0x10) = 4;
  }
  else if (iVar5 == 0x10e) {
    *(undefined4 *)(unaff_EBP + -0x10) = 6;
  }
  if (iVar7 == 0x2d) {
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
  }
  else if (iVar7 == 0x87) {
    *(undefined4 *)(unaff_EBP + -0x14) = 3;
    *(undefined4 *)(unaff_EBP + -0x1c) = 1;
  }
  piVar3 = (int *)FUN_005e7743();
  uVar4 = (**(code **)(*piVar3 + 0x44))();
  *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_005a5e72();
  if (cVar2 == '\0') {
    uStack_60 = 0x4cae79;
    pvVar6 = operator_new(100);
    *(void **)(unaff_EBP + -0x24) = pvVar6;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar6 != (void *)0x0) {
      FUN_005dfb13();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    uStack_60 = 0x4cae9c;
    FUN_005a5e48();
    cVar2 = FUN_005a5e72();
    if (cVar2 == '\0') goto LAB_004cb093;
    piVar3 = (int *)FUN_004096c2();
    iVar5 = *piVar3;
    uStack_60 = 0;
    uStack_64 = 0;
    *(int **)(unaff_EBP + -0x24) = &iStack_6c;
    *(int **)(unaff_EBP + -0x20) = piVar3;
    iStack_6c = extraout_ECX_00;
    iStack_68 = extraout_ECX_00;
    FUN_00436a50(4);
    (**(code **)(iVar5 + 0xc))(0x2d,0x2d);
  }
  else {
    uStack_60 = 0x4cadde;
    FUN_005a5e1c();
    iVar5 = FUN_004096c2();
    if ((*(int *)(iVar5 + 0x1c) != 0x2d) || (iVar5 = FUN_004096c2(), *(int *)(iVar5 + 0x20) != 0x2d)
       ) {
      uStack_60 = 0x4cae06;
      FUN_005a5e48();
      uStack_60 = 0x4cae0d;
      pvVar6 = operator_new(100);
      *(void **)(unaff_EBP + -0x20) = pvVar6;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar6 != (void *)0x0) {
        FUN_005dfb13();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      uStack_60 = 0x4cae2f;
      FUN_005a5e48();
      cVar2 = FUN_005a5e72();
      if (cVar2 == '\0') goto LAB_004cb093;
      piVar3 = (int *)FUN_004096c2();
      iVar5 = *piVar3;
      uStack_60 = 0;
      uStack_64 = 0;
      *(int **)(unaff_EBP + -0x24) = &iStack_6c;
      *(int **)(unaff_EBP + -0x20) = piVar3;
      iStack_6c = extraout_ECX;
      iStack_68 = extraout_ECX;
      FUN_00436a50(4);
      (**(code **)(iVar5 + 0xc))(0x2d,0x2d);
      uStack_60 = 0x4cae70;
      FUN_005a5e1c();
    }
  }
  piVar3 = (int *)FUN_004096c2();
  uStack_60 = 0x4caee5;
  cVar2 = (**(code **)(*piVar3 + 0x20))();
  if (cVar2 != '\0') {
    uStack_60 = 0x4caef1;
    piVar3 = (int *)FUN_004096c2();
    uStack_60 = 0;
    uStack_64 = *(undefined4 *)(unaff_EBP + -0x18);
    iStack_68 = 0x4caefc;
    (**(code **)(*piVar3 + 0x38))();
    iStack_68 = 0x4caf04;
    piVar3 = (int *)FUN_004096c2();
    iStack_68 = 1;
    iStack_6c = 0x4caf0d;
    (**(code **)(*piVar3 + 0x24))();
  }
  uStack_60 = 0x4caf15;
  piVar3 = (int *)FUN_004096c2();
  uStack_60 = *(undefined4 *)(unaff_EBP + -0x18);
  uStack_64 = 0x4caf1f;
  (**(code **)(*piVar3 + 0x68))();
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar1 + 0x18);
  *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar1 + 0x20);
  uStack_64 = 0x4caf3f;
  iVar5 = FUN_004096c2();
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar5 + 0x14);
  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar5 + 0x18);
  *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar5 + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(iVar5 + 0x20);
  uStack_64 = 0x4caf62;
  iVar5 = FUN_004096c2();
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(iVar5 + 0x14);
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(iVar5 + 0x18);
  *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(iVar5 + 0x1c);
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(iVar5 + 0x20);
  iVar7 = (*(int *)(unaff_EBP + -0x28) - *(int *)(unaff_EBP + -0x30)) / *(int *)(unaff_EBP + -0x14);
  iVar5 = *(int *)(unaff_EBP + -0x34);
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(int *)(unaff_EBP + -0x2c) = (*(int *)(unaff_EBP + -0x2c) - iVar5) / *(int *)(unaff_EBP + -0x10);
  *(int *)(unaff_EBP + -0x30) = iVar7 * *(int *)(unaff_EBP + -0x1c);
  *(int *)(unaff_EBP + -0x28) = (*(int *)(unaff_EBP + -0x1c) + 1) * iVar7;
  uStack_64 = 0x4cafb3;
  piVar3 = (int *)FUN_004096c2();
  uStack_64 = 0x10;
  iStack_68 = 0x4cafbc;
  (**(code **)(*piVar3 + 0x20))();
  iStack_68 = 0x4cafc4;
  piVar3 = (int *)FUN_004096c2();
  iStack_6c = unaff_EBP + -0x54;
  iStack_68 = 0;
  (**(code **)(*piVar3 + 0x9c))(iVar1,unaff_EBP + -0x34);
  if (*(char *)(unaff_EBP + 0xc) == '\0') {
    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + 0x2d;
    *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + 0x2d;
  }
  if (DAT_006f0e80 == (int *)0x0) {
    piVar3 = (int *)FUN_005e7743();
    uVar4 = (**(code **)(*piVar3 + 0x44))(0x10);
    FUN_005a5631(0x1068,&DAT_006f0e80,4);
    (**(code **)(*DAT_006f0e80 + 0x68))(uVar4);
    if (DAT_006f0e84 == (int *)0x0) {
      FUN_005a5631(0x232c,&DAT_006f0e84,4);
      (**(code **)(*DAT_006f0e84 + 0x68))(DAT_006f2a64);
    }
  }
  piVar3 = (int *)FUN_004096c2();
  (**(code **)(*piVar3 + 0x9c))(DAT_006f0e80,unaff_EBP + -0x44,unaff_EBP + -0x54,0);
  piVar3 = (int *)FUN_004096c2();
  (**(code **)(*piVar3 + 0x24))(0x10);
  uStack_60 = 0x4cb088;
  FUN_005a5e1c();
  uStack_60 = 0x4cb091;
  FUN_005a5e48();
  uVar8 = 1;
LAB_004cb093:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a5e09();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

