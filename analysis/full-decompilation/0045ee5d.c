
void FUN_0045ee5d(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0xa44) != *(int *)(extraout_ECX + 0xa40)) {
    FUN_0041ed45();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0045f8e7(unaff_EBP + -0x50);
    if (*(int *)(unaff_EBP + -0x48) != 0) {
      FUN_00422d79(4,*(undefined2 *)(extraout_ECX + 0xf0),0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

