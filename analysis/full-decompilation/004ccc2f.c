
undefined1 FUN_004ccc2f(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uStack_74;
  int iStack_70;
  int iStack_6c;
  undefined4 uStack_68;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = extraout_ECX;
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    uStack_68 = 0x4cccea;
    pvVar5 = operator_new(100);
    *(void **)(unaff_EBP + -0x1c) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar5 != (void *)0x0) {
      FUN_005dfb13();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    uStack_68 = 0x4ccd12;
    FUN_005a5e48();
    cVar1 = FUN_005a5e72();
    if (cVar1 == '\0') {
LAB_004ccd1d:
      uVar2 = 0;
      goto LAB_004ccebc;
    }
    puVar7 = (undefined4 *)FUN_004096c2();
    uStack_68 = 0;
    iStack_6c = 0;
    uVar8 = *puVar7;
    *(undefined4 **)(unaff_EBP + -0x1c) = &uStack_74;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar8;
    FUN_00436a50(4);
    (**(code **)(*(int *)(unaff_EBP + -0x18) + 0xc))(0x2d,0x2d);
  }
  else {
    iVar3 = FUN_004096c2();
    iVar3 = *(int *)(iVar3 + 0x1c);
    iVar4 = FUN_004096c2();
    if ((iVar3 != 0x2d) || (*(int *)(iVar4 + 0x20) != 0x2d)) {
      uStack_68 = 0x4ccc85;
      FUN_005a5e48();
      uStack_68 = 0x4ccc8c;
      pvVar5 = operator_new(100);
      *(void **)(unaff_EBP + -0x1c) = pvVar5;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar5 != (void *)0x0) {
        FUN_005dfb13();
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      uStack_68 = 0x4cccae;
      FUN_005a5e48();
      cVar1 = FUN_005a5e72();
      if (cVar1 == '\0') goto LAB_004ccd1d;
      piVar6 = (int *)FUN_004096c2();
      iVar3 = *piVar6;
      uStack_68 = 0;
      iStack_6c = 0;
      *(undefined4 **)(unaff_EBP + -0x1c) = &uStack_74;
      *(int **)(unaff_EBP + -0x18) = piVar6;
      FUN_00436a50(4);
      (**(code **)(iVar3 + 0xc))(0x2d,0x2d);
    }
  }
  piVar6 = (int *)FUN_004096c2();
  uStack_68 = 0x4ccd62;
  cVar1 = (**(code **)(*piVar6 + 0x20))();
  if (cVar1 != '\0') {
    *(undefined4 *)(unaff_EBP + -0x40) = 0;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    *(undefined4 *)(unaff_EBP + -0x38) = 0x2d;
    *(undefined4 *)(unaff_EBP + -0x34) = 0x2d;
    *(undefined4 *)(unaff_EBP + -0x50) = 0;
    *(undefined4 *)(unaff_EBP + -0x4c) = 0;
    *(undefined4 *)(unaff_EBP + -0x48) = 0x2d;
    *(undefined4 *)(unaff_EBP + -0x44) = 0x2d;
    uStack_68 = 0x4ccd89;
    puVar7 = (undefined4 *)FUN_004096c2();
    uVar8 = *puVar7;
    *(undefined4 **)(unaff_EBP + -0x18) = puVar7;
    iStack_6c = unaff_EBP + -0x40;
    uStack_68 = 0;
    iStack_70 = unaff_EBP + -0x50;
    *(undefined4 *)(unaff_EBP + -0x1c) = uVar8;
    uStack_74 = 0x4ccda4;
    uStack_74 = FUN_004096c2();
    (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x9c))();
    FUN_005c1719();
    iVar3 = *(int *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    cVar1 = FUN_004cc7f7(unaff_EBP + -0x14);
    *(char *)(unaff_EBP + -0xd) = cVar1;
    if (cVar1 != '\0') {
      *(int *)(unaff_EBP + -0x20) = iVar3 + 0x2c;
      cVar1 = FUN_005a5e72();
      if (cVar1 != '\0') {
        FUN_005a5e1c(unaff_EBP + -0x14);
        iVar3 = FUN_004096c2();
        *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(iVar3 + 0x14);
        *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(iVar3 + 0x18);
        *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(iVar3 + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar3 + 0x20);
        iVar3 = FUN_004096c2();
        if (*(int *)(iVar3 + 0x1c) < 0x2e) {
          iVar3 = *(int *)(unaff_EBP + -0x28);
        }
        else {
          iVar3 = *(int *)(unaff_EBP + -0x28) / 2;
          *(int *)(unaff_EBP + -0x28) = iVar3;
        }
        iVar4 = ((*(int *)(unaff_EBP + -0x30) - iVar3) + 0x2d) / 2;
        *(int *)(unaff_EBP + -0x58) = iVar4 + iVar3;
        iVar3 = ((*(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x24)) + 0x2d) / 2;
        *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x30) + iVar4;
        *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x2c) + iVar3;
        *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x24) + iVar3;
        piVar6 = (int *)FUN_004096c2();
        iVar3 = *piVar6;
        uVar8 = FUN_004096c2(unaff_EBP + -0x30,unaff_EBP + -0x60,0);
        uVar2 = (**(code **)(iVar3 + 0x9c))(uVar8);
        *(undefined1 *)(unaff_EBP + -0xd) = uVar2;
      }
    }
    piVar6 = (int *)FUN_004096c2();
    (**(code **)(*piVar6 + 0x24))(0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
  }
  uVar2 = *(undefined1 *)(unaff_EBP + -0xd);
LAB_004ccebc:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

