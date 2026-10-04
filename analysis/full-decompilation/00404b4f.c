
undefined1 FUN_00404b4f(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_00634c24();
  uVar4 = 0;
  FUN_0046f824(unaff_EBP + -0x120,0,0x104);
  *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
  uVar2 = FUN_0041532c(0x42,&DAT_006c0c5c,unaff_EBP + -300);
  FUN_004ee9ce(uVar2);
  FUN_0046f5cd();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_0046f71c(unaff_EBP + -300,1);
  puVar5 = DAT_006de7f8;
  if (iVar3 == 0) {
    for (; puVar5 != DAT_006de7fc; puVar5 = puVar5 + 1) {
      puVar1 = (undefined4 *)*puVar5;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x43415252;
      *(undefined4 **)(unaff_EBP + -0x14) = puVar1;
      *(undefined ***)(unaff_EBP + -0x18) = &PTR_FUN_0066656c;
      uVar2 = *puVar1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      iVar3 = FUN_00464eab(unaff_EBP + -0x18,0,unaff_EBP + -0x370,uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00465055();
      if (iVar3 != 0) goto LAB_00404c1d;
    }
    uVar4 = 1;
  }
LAB_00404c1d:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046b2e6();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

