
void FUN_005f8510(void)

{
  int iVar1;
  LONG LVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006fed08;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffdc;
  *(int **)(unaff_EBP + -0x18) = &DAT_006fed08;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(unaff_EBP + 8);
  FUN_00575b11(unaff_EBP + -0x24,unaff_EBP + -0x14);
  if (*(int *)(unaff_EBP + -0x24) != 0) {
    if (DAT_006c9f93 == '\0') {
      InterlockedIncrement(&DAT_006f29fc);
      LVar2 = InterlockedExchange((LONG *)&DAT_006fed80,1);
      if (LVar2 == 0) {
        FUN_005f8612();
        InterlockedExchange((LONG *)&DAT_006fed80,0);
      }
      InterlockedDecrement(&DAT_006f29fc);
    }
    else {
      iVar1 = FUN_005d5f70();
      if (iVar1 == 0) {
        *(undefined1 *)(unaff_EBP + -4) = 1;
        LVar2 = InterlockedExchange((LONG *)&DAT_006fed80,1);
        if (LVar2 == 0) {
          FUN_005f8612();
          InterlockedExchange((LONG *)&DAT_006fed80,0);
        }
      }
    }
  }
  iVar1 = DAT_006fed08;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

