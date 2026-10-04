
int FUN_004670ce(void)

{
  void *pvVar1;
  int iVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_0046913f(unaff_EBP + -0x10,unaff_EBP + 8);
  if (*(int *)(unaff_EBP + -0x10) == *(int *)(extraout_ECX + 4)) {
    pvVar1 = operator_new(0x288);
    *(void **)(unaff_EBP + -0x14) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00467873(*(undefined4 *)(unaff_EBP + 8),extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (iVar2 == 0) {
      iVar2 = 0;
      goto LAB_0046715c;
    }
    *(undefined2 *)(unaff_EBP + -0x18) = *(undefined2 *)(unaff_EBP + 8);
    *(int *)(unaff_EBP + -0x14) = iVar2;
    FUN_004690b0(unaff_EBP + -0x20,unaff_EBP + -0x18);
  }
  else {
    iVar2 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x14);
    FUN_00467999();
  }
  *(undefined4 *)(iVar2 + 0x34) = 1;
LAB_0046715c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar2;
}

