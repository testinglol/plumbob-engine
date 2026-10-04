
void FUN_00578b81(void)

{
  int *extraout_ECX;
  int unaff_EBP;
  int iVar1;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x10) = &DAT_006f63e8;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(char *)((int)extraout_ECX + 0x40a9) != '\0') {
    iVar1 = extraout_ECX[0x102c] + extraout_ECX[10];
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    (**(code **)(*extraout_ECX + 0x70))(iVar1);
    if (((iVar1 <= extraout_ECX[0x102d]) && (extraout_ECX[0x102b] != 0)) &&
       ((char)extraout_ECX[0x102e] != '\0')) {
      (**(code **)(*extraout_ECX + 0x88))();
    }
  }
  iVar1 = DAT_006f63e8;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

