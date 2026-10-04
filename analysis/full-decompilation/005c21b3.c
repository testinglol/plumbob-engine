
undefined4 FUN_005c21b3(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  iVar1 = FUN_004096c2();
  if (iVar1 == 0) {
    pvVar3 = operator_new(100);
    *(void **)(unaff_EBP + 8) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005c2475(1);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar4 == (int *)0x0) {
      uVar2 = 6;
      goto LAB_005c22aa;
    }
    if (*(int *)(*(int *)(unaff_EBP + -0x10) + 0xc) == 0) {
      uVar2 = 0xa1;
    }
    else {
      uVar2 = 0x21;
    }
    FUN_00632c55(*(undefined4 *)(unaff_EBP + 0xc),uVar2,DAT_00689070);
    if (*(int *)(*(int *)(*piVar4 + 4) + 8 + (int)piVar4) == 0) {
      FUN_005b8e25();
      uVar2 = FUN_005b9b0c(*(undefined4 *)(unaff_EBP + 0xc));
      FUN_005c341d(uVar2);
      FUN_005c3387(piVar4);
      goto LAB_005c220b;
    }
    (*(code *)**(undefined4 **)(*(int *)(*piVar4 + 4) + (int)piVar4))(1);
    FUN_005c3387(0);
    FUN_005c341d(0);
  }
  else if (iVar1 == 1) {
    uVar5 = 0;
    uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
    FUN_005b8e25(uVar2,0);
    iVar1 = FUN_005b936f(uVar2,uVar5);
    if (iVar1 != 0) {
      FUN_005c341d(*(undefined4 *)(iVar1 + 0x10));
      FUN_005c33c0(iVar1);
LAB_005c220b:
      uVar2 = 0;
      goto LAB_005c22aa;
    }
  }
  uVar2 = 5;
LAB_005c22aa:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return uVar2;
}

