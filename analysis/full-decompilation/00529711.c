
bool FUN_00529711(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x120,0,0x104);
  *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_006664e8;
  uVar2 = FUN_0041532c(0xf,0,unaff_EBP + -300);
  FUN_004ee9ce(uVar2);
  FUN_0052a419(*(undefined4 *)(extraout_ECX + 0xf8),*(undefined4 *)(extraout_ECX + 0xfc));
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x128);
  FUN_0046f824(unaff_EBP + -0x230,0,0x104);
  *(undefined ***)(unaff_EBP + -0x23c) = &PTR_FUN_006664e8;
  FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
  FUN_004de865(unaff_EBP + -0x23c,&PTR_DAT_006ccc14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while( true ) {
    iVar3 = FUN_004deaa1();
    if (iVar3 == 0) break;
    uVar2 = FUN_004deaa1();
    FUN_005d4956(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_004054fa(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    FUN_004de998();
  }
  iVar3 = *(int *)(extraout_ECX + 0xfc);
  iVar1 = *(int *)(extraout_ECX + 0xf8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004de981();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return (iVar3 - iVar1) / 0xc != 0;
}

