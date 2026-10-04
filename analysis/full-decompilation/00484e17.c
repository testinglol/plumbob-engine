
void FUN_00484e17(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_00490beb(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  FUN_00492d46(0);
  *(char *)(unaff_EBP + 0x14) = (char)(*(int *)(unaff_EBP + 0xc) >> 4);
  *(char *)(unaff_EBP + 0x15) = (char)(*(int *)(unaff_EBP + 8) >> 4);
  *(undefined1 *)(unaff_EBP + 0x16) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049122d(unaff_EBP + 0x14,unaff_EBP + 0x14,1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

