
void FUN_00634353(void)

{
  int iVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(extraout_ECX + -0x14);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined ***)(*(int *)(iVar1 + 4) + -0x14 + extraout_ECX) = &PTR_LAB_00689170;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00632511();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006327ec();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

