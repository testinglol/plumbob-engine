
int FUN_0059d83f(void)

{
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00635e55(extraout_ECX,0x6c,2,FUN_00401000,FUN_0040102e);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00635e55(extraout_ECX + 0xd8,0x6c,2,FUN_00401000,FUN_0040102e);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00635e55(extraout_ECX + 0x1b0,0x6c,2,FUN_00401000,FUN_0040102e);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00401000();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00401000();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00635e55(extraout_ECX + 0x360,0x6c,2,FUN_00401000,FUN_0040102e);
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00635e55(extraout_ECX + 0x438,0x6c,3,FUN_00401000,FUN_0040102e);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

