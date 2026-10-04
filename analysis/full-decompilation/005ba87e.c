
undefined1 FUN_005ba87e(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  undefined4 extraout_ECX;
  undefined1 uVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b96fe(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x2c,unaff_EBP + -0x38);
  if (*(int *)(unaff_EBP + -0x2c) != *(int *)(unaff_EBP + -0x28)) {
    FUN_005a509f(unaff_EBP + -0x20,unaff_EBP + -0x2c);
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      iVar2 = *(int *)(unaff_EBP + 0xc);
      *(int *)(iVar2 + 0x28) = *(int *)(unaff_EBP + -0x20) + 0x10;
      FUN_005d499c(unaff_EBP + -0x2c);
      FUN_005d499c(unaff_EBP + -0x38);
      FUN_00580a92(unaff_EBP + -0x18);
      piVar1 = (int *)(iVar2 + 0x2c);
      *piVar1 = *(int *)(unaff_EBP + -0x18);
      *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(unaff_EBP + -0x14);
      while (iVar3 = *piVar1, iVar3 != 0) {
        cVar4 = FUN_005ba810(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar2 + 0x1c),0);
        if (cVar4 != '\0') {
          *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(iVar3 + 0x22);
          *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)(iVar3 + 0x21);
          FUN_005d499c(*piVar1 + 4);
          uVar5 = 1;
          goto LAB_005ba95e;
        }
        FUN_005bb2f8();
      }
    }
  }
  uVar5 = 0;
LAB_005ba95e:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

