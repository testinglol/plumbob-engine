
void FUN_0042a3f4(void)

{
  undefined4 uVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x134,0,0x104);
  *(undefined ***)(unaff_EBP + -0x140) = &PTR_FUN_006664e8;
  uVar1 = FUN_0041532c(0xe,unaff_EBP + -0x140);
  uVar1 = FUN_004096c2(uVar1);
  FUN_004ee9ce(uVar1);
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  iVar2 = *(int *)(extraout_ECX + 0x180);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d5156(unaff_EBP + -0x24,&DAT_006c08e4,*(undefined1 *)(iVar2 + 0x10));
  uVar1 = FUN_004096c2();
  FUN_005d4bbf(uVar1);
  iVar2 = FUN_005d49d6();
  uVar1 = FUN_005d4be4(unaff_EBP + -0x30,iVar2 + -1);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(uVar1);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  FUN_004fc0f2(s_SIMS_CURRENT_NEIGHBORHOOD_NUM_006c25cc,unaff_EBP + -0x24);
  FUN_004fc0f2(s_SIMS_CURRENT_NEIGHBORHOOD_PATH_006c25ac,unaff_EBP + -0x18);
  FUN_0046f8e4(unaff_EBP + -0x140);
  FUN_00424749();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

