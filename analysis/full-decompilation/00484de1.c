
void FUN_00484de1(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0x10) = 0xff;
  *(undefined1 *)(unaff_EBP + -0xf) = 0xff;
  *(undefined1 *)(unaff_EBP + -0xe) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0049122d(unaff_EBP + -0x10,unaff_EBP + -0x10,1);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

