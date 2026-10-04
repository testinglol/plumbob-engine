
void FUN_0040ea14(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_0040e4d9(iVar1,unaff_EBP + -0x2c);
  iVar2 = FUN_00409291();
  *(int *)(unaff_EBP + -0x10) = iVar2;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
      iVar2 = FUN_004728e9(uVar3);
      if (iVar2 != 0) {
        FUN_0046f8e4(*(undefined4 *)(unaff_EBP + -0x14));
        goto LAB_0040ea91;
      }
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
    } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10));
  }
  *(undefined2 *)(iVar1 + 8) = 0;
  **(undefined1 **)(iVar1 + 4) = 0;
LAB_0040ea91:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

