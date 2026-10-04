
void FUN_005d69da(void)

{
  char cVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_006738a4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = (*(code *)PTR_FUN_00673930)(0x40);
  if (cVar1 != '\0') {
    FUN_005d73fd();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005dbeb0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

