
void FUN_00578941(void)

{
  int iVar1;
  int unaff_EBP;
  bool bVar2;
  
  FUN_00634c24();
  bVar2 = DAT_006c9f93 == '\0';
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  if (bVar2) {
    InterlockedIncrement(&DAT_006f29fc);
    FUN_00578b81();
    InterlockedDecrement(&DAT_006f29fc);
  }
  else {
    iVar1 = FUN_005d5f70();
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_00578b81();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

