
void FUN_005ed0c3(void)

{
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00675064;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)(extraout_ECX + 4) != '\0') {
    FUN_005ed1ac();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

