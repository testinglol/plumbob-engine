
void FUN_005bf2e0(void)

{
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 8) != 0) {
    FUN_005bad81(*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005bc346(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_LAB_0066933c;
    FUN_00401729();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

