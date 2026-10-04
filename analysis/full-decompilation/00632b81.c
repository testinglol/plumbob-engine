
int * FUN_00632b81(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if (*(int *)(unaff_EBP + 8) != 0) {
    *extraout_ECX = (int)&DAT_00689068;
    extraout_ECX[3] = (int)&DAT_00689060;
    FUN_00632a8e();
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
  }
  pvVar1 = operator_new(0x54);
  *(void **)(unaff_EBP + 8) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00632ca8();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006342de(uVar2,0);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined ***)(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX) = &PTR_LAB_0068905c;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  *(undefined4 *)(*(int *)(*extraout_ECX + 4) + 0x1c + (int)extraout_ECX) = 1;
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

