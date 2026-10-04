
undefined4 FUN_0059e1b5(void)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int *piVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005c22bb();
  FUN_005c32ce();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_005b8e25();
  puVar1 = *(undefined4 **)(unaff_EBP + 0xc);
  if (*(char *)(iVar3 + 0x2c) != '\0') {
    FUN_0047354f(1);
    iVar3 = FUN_005c1b28(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8),&DAT_006f7660,*puVar1,1);
    if (iVar3 == 0) {
      pvVar4 = operator_new(0xac);
      *(void **)(unaff_EBP + 8) = pvVar4;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      if (pvVar4 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_0059e338();
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      *(int *)(unaff_EBP + -0x10) = iVar3;
      uVar5 = FUN_00401f73();
      cVar2 = FUN_0059a93f(uVar5);
      if (cVar2 == '\0') {
        if (iVar3 != 0) {
          FUN_00599cef();
          FUN_006321f0(iVar3);
        }
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
      goto LAB_0059e319;
    }
  }
  uVar5 = FUN_00401f77();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar5;
  FUN_00476033(1);
  FUN_0047354f(0);
  iVar3 = FUN_005c1b28(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8),&DAT_006f7664,*puVar1,1);
  if (iVar3 == 0) {
    pvVar4 = operator_new(0xac);
    *(void **)(unaff_EBP + 8) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar4 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0059e338();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x10) = iVar3;
    uVar5 = FUN_00401f73(iVar3);
    FUN_0059a636(uVar5);
    piVar6 = (int *)FUN_00401f73();
    if (*(int *)(*(int *)(*piVar6 + 4) + 8 + (int)piVar6) != 0) {
      if (iVar3 != 0) {
        FUN_00599cef();
        FUN_006321f0(iVar3);
      }
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
    }
  }
  FUN_00476033(*(undefined4 *)(unaff_EBP + 0xc));
LAB_0059e319:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c3314();
  uVar5 = *(undefined4 *)(unaff_EBP + -0x10);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar5;
}

