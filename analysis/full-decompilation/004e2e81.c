
void FUN_004e2e81(void)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  iVar2 = *(int *)(extraout_ECX + 0x194);
  iVar1 = *(int *)(extraout_ECX + 0x198);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (iVar2 != iVar1) {
    do {
      if (*(undefined4 **)(iVar2 + 0xc) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(iVar2 + 0xc))(1);
      }
      iVar2 = iVar2 + 0x10;
    } while (iVar2 != *(int *)(extraout_ECX + 0x198));
  }
  FUN_004e3bfc(*(undefined4 *)(extraout_ECX + 0x194),*(undefined4 *)(extraout_ECX + 0x198));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004e3b8e();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_004e1909();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

