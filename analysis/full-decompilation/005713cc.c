
void FUN_005713cc(void)

{
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d4956(s_EventMapping_006ceb54);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057b37e(unaff_EBP + -0x18,&LAB_005712a2,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_0057b268();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

