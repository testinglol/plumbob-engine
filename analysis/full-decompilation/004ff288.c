
void FUN_004ff288(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_004ff0ee(*(undefined4 *)(unaff_EBP + 0xc));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

