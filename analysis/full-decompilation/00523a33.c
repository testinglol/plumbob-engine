
void FUN_00523a33(void)

{
  int iVar1;
  void *pvVar2;
  int *extraout_ECX;
  int unaff_EBP;
  int *piVar3;
  
  FUN_00634c24();
  piVar3 = (int *)0x0;
  if (extraout_ECX[0x3b] == 0) {
    FUN_005a5631(*(undefined4 *)(unaff_EBP + 0xc),unaff_EBP + 0xc,4);
    if (*(int **)(unaff_EBP + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(unaff_EBP + 0xc) + 0x68))(DAT_006f2a64);
      pvVar2 = operator_new(0x194);
      *(void **)(unaff_EBP + -0x10) = pvVar2;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar2 != (void *)0x0) {
        piVar3 = (int *)FUN_005e372a();
      }
      iVar1 = *piVar3;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      (**(code **)(iVar1 + 0x19c))(*(undefined4 *)(unaff_EBP + 0xc),4,1);
      iVar1 = *(int *)(unaff_EBP + 8);
      *(undefined1 *)((int)piVar3 + 0x16b) = 1;
      piVar3[2] = iVar1;
      extraout_ECX[0x3b] = (int)piVar3;
      (**(code **)(*extraout_ECX + 0x20))(piVar3);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

