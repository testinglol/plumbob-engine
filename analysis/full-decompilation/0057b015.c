
void FUN_0057b015(void)

{
  char cVar1;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  cVar1 = *(char *)(extraout_ECX + 0x14);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xc) + 0x10) + 4))();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0057376b(0x26,*(undefined4 *)(unaff_EBP + 8),0,0,0);
    FUN_0057b05c();
    return;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

