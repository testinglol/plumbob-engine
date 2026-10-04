
undefined1 FUN_00595299(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  cVar4 = FUN_005b90c2(unaff_EBP + -0x120,0x100);
  uVar5 = 0;
  if (cVar4 == '\0') goto LAB_00595378;
  FUN_005b870f(unaff_EBP + -0x120);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b88c2();
  FUN_005d499c(unaff_EBP + -0x20);
  FUN_005b88c2();
  cVar4 = FUN_005b8f4a(4);
  if (cVar4 == '\0') {
LAB_00595309:
    uVar5 = 0;
  }
  else {
    cVar4 = FUN_005b9095(unaff_EBP + -0x14);
    if (cVar4 == '\0') goto LAB_00595309;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      cVar4 = FUN_00594196(uVar1);
      if (cVar4 == '\0') goto LAB_00595309;
    }
    cVar4 = FUN_005b9095(unaff_EBP + -0x10);
    if (cVar4 == '\0') goto LAB_00595309;
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < *(int *)(unaff_EBP + -0x10)) {
      iVar2 = *(int *)(unaff_EBP + 0x10);
      do {
        uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(iVar2 + 0x28) = extraout_ECX;
        cVar4 = FUN_00594be7(uVar1,uVar3);
        if (cVar4 == '\0') goto LAB_00595309;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10));
    }
    uVar5 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00595378:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

