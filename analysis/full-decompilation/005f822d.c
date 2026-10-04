
void FUN_005f822d(void)

{
  int iVar1;
  char cVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00676094;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  cVar2 = FUN_005f95a3();
  if (cVar2 != '\0') {
    FUN_005f9798();
  }
  InterlockedDecrement((LONG *)&DAT_006fed7c);
  FUN_005f884f();
  iVar1 = DAT_006fed08;
  *(int **)(unaff_EBP + -0x24) = &DAT_006fed08;
  *(undefined ***)(unaff_EBP + -0x28) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00575b11(unaff_EBP + -0x20,unaff_EBP + -0x10);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_005fd55a(unaff_EBP + -0x14);
  }
  iVar1 = DAT_006fed08;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar1 + 8))();
  if (extraout_ECX[0x1a] != 0) {
    FUN_005ed911();
    extraout_ECX[0x1a] = 0;
  }
  if (extraout_ECX[0x19] != 0) {
    FUN_005ed911();
    extraout_ECX[0x19] = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d9122();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005b8770();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

