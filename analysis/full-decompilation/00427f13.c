
undefined1 FUN_00427f13(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046cee2();
  uVar4 = 0;
  *(undefined2 *)(unaff_EBP + -0x10) = DAT_006c1ef0;
  *(int *)(unaff_EBP + -0x18) = unaff_EBP + -0x1c8;
  uVar3 = s_IMISSUOH_006c1ef4._0_4_;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_00666730;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  iVar2 = FUN_00464f5b(unaff_EBP + -0x1c,*(undefined4 *)(unaff_EBP + 8),
                       *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 0x20));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00465055();
  if (iVar2 == 0) {
    **(int **)(unaff_EBP + 0x14) = (int)*(short *)(unaff_EBP + -0x18c);
    **(int **)(unaff_EBP + 0x1c) = (int)*(short *)(unaff_EBP + -0x16e);
    sVar1 = *(short *)(unaff_EBP + -0x184);
    **(int **)(unaff_EBP + 0x10) = (int)sVar1;
    if ((sVar1 == 0) && (*(short *)(unaff_EBP + -0x18e) == 0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    **(undefined4 **)(unaff_EBP + 0x18) = uVar3;
    iVar2 = __ftol();
    uVar4 = 1;
    **(int **)(unaff_EBP + 0xc) = iVar2 + *(int *)(unaff_EBP + -0x128) + *(int *)(unaff_EBP + -300);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046d08e();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

