
void FUN_004eec02(void)

{
  void *pvVar1;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar1 = operator_new(0x144);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_004eec6a(PTR_s_Sims_exe_006c9f5c);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

