
int * FUN_00633aef(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *extraout_ECX = (int)&DAT_0068912c;
    extraout_ECX[3] = (int)&DAT_00689124;
    FUN_00632a8e();
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  pvVar1 = operator_new(100);
  *(void **)(unaff_EBP + 8) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006337a0();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006342de(uVar2,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_00689120;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  return extraout_ECX;
}

