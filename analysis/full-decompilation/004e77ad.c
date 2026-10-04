
undefined1 FUN_004e77ad(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  iVar5 = FUN_004096c2();
  *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar5 + 0x14);
  iVar1 = *(int *)(iVar5 + 0x1c);
  iVar2 = *(int *)(iVar5 + 0x20);
  *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar5 + 0x18);
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0x4c;
  *(undefined4 *)(unaff_EBP + -0x20) = 0x2d;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0x7a;
  *(undefined4 *)(unaff_EBP + -0x18) = 0x7d;
  cVar3 = FUN_004e7902(*(undefined4 *)(unaff_EBP + 8),0,0,(iVar1 - *(int *)(unaff_EBP + -0x54)) + -2
                       ,(iVar2 - *(int *)(unaff_EBP + -0x50)) + -2,unaff_EBP + -0x34,0,
                       unaff_EBP + -0x14,unaff_EBP + -0x24);
  if (cVar3 == '\0') {
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  cVar3 = FUN_005a5e72();
  if (cVar3 != '\0') {
    iVar6 = FUN_004096c2();
    iVar1 = *(int *)(iVar6 + 0x14);
    *(int *)(unaff_EBP + -0x44) = iVar1;
    iVar2 = *(int *)(iVar6 + 0x18);
    *(int *)(unaff_EBP + -0x40) = iVar2;
    iVar5 = *(int *)(iVar6 + 0x1c);
    *(int *)(unaff_EBP + -0x3c) = iVar5;
    iVar6 = *(int *)(iVar6 + 0x20);
    *(int *)(unaff_EBP + -0x38) = iVar6;
    *(int *)(unaff_EBP + -0x24) = iVar1 + 1;
    *(int *)(unaff_EBP + -0x1c) = iVar5 + 1;
    *(int *)(unaff_EBP + -0x20) = iVar2 + 1;
    *(int *)(unaff_EBP + -0x18) = iVar6 + 1;
    piVar7 = (int *)FUN_004096c2();
    cVar3 = (**(code **)(*piVar7 + 0x20))(0x10);
    if (cVar3 != '\0') {
      piVar7 = (int *)FUN_004096c2();
      iVar1 = *piVar7;
      uVar8 = FUN_004096c2(unaff_EBP + -0x44,unaff_EBP + -0x24,0);
      uVar4 = (**(code **)(iVar1 + 0x9c))(uVar8);
      *(undefined1 *)(unaff_EBP + 0xb) = uVar4;
      piVar7 = (int *)FUN_004096c2();
      (**(code **)(*piVar7 + 0x24))(0x10);
      if (*(char *)(unaff_EBP + 0xb) == '\0') {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005a5e09();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

