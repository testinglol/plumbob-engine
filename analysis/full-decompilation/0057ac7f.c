
void FUN_0057ac7f(void)

{
  char cVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  cVar1 = *(char *)(extraout_ECX + 0x14);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  if (cVar1 != '\0') {
    if (DAT_006c9f93 == '\0') {
      InterlockedIncrement(&DAT_006f29fc);
      (**(code **)(**(int **)(*(int *)(extraout_ECX + 0xc) + 0x10) + 4))();
      *(undefined4 *)(unaff_EBP + -4) = 4;
      FUN_0057376b(0x21,0,0,0,0);
      FUN_0057ad47();
      return;
    }
    iVar2 = FUN_005d5f70();
    if (iVar2 == 0) {
      iVar2 = *(int *)(extraout_ECX + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(**(int **)(iVar2 + 0x10) + 4))();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0057376b(0x21,0,0,0,0);
      FUN_0057ace9();
      return;
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

