
undefined4 FUN_004dedc6(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  undefined4 uVar3;
  
  FUN_00634c24();
  FUN_0041308b();
  uVar3 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar1 = FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),0);
  if (((iVar1 == 0) && (iVar1 = FUN_00412fc7(unaff_EBP + -0x10), iVar1 == 0)) &&
     (pvVar2 = operator_new(*(uint *)(unaff_EBP + -0x10)), pvVar2 != (void *)0x0)) {
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + -0x10);
    iVar1 = FUN_004131a0(0);
    if ((iVar1 == 0) && (iVar1 = FUN_00413178(pvVar2,unaff_EBP + -0x14), iVar1 == 0)) {
      if (*(int *)(unaff_EBP + 0xc) == 3) {
        uVar3 = FUN_004df2ca();
      }
      else {
        uVar3 = FUN_004deed2(pvVar2);
      }
    }
    FUN_006321f0(pvVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004130c0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

