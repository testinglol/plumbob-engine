
undefined4 FUN_00580279(void)

{
  char cVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar1 = (**(code **)(**(int **)(unaff_EBP + 8) + 0x94))(unaff_EBP + -0x18);
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(extraout_ECX + 0xc0) + 0x18))(unaff_EBP + -0x18);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

