
undefined4 FUN_0057af3f(void)

{
  char cVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  cVar1 = *(char *)(extraout_ECX + 0x14);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  if (cVar1 == '\0') {
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return 8;
  }
  (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xc) + 0x10) + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0057376b(0x2a,unaff_EBP + -0x18,0,0,0);
  uVar2 = FUN_0057af8d();
  return uVar2;
}

