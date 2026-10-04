
void FUN_005f8612(void)

{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006fed08;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  *(int **)(unaff_EBP + -0x14) = &DAT_006fed08;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00575b11(unaff_EBP + -0x20,unaff_EBP + -0x10);
  if (*(int *)(unaff_EBP + -0x20) != 0) {
    iVar1 = extraout_ECX[0x1c];
    iVar2 = extraout_ECX[10] + iVar1;
    if (((0 < iVar1) && (extraout_ECX[0x1d] <= iVar2)) ||
       ((iVar1 < 0 && (iVar2 <= extraout_ECX[0x1d])))) {
      if ((int *)extraout_ECX[0x1a] != (int *)0x0) {
        (**(code **)(*(int *)extraout_ECX[0x1a] + 0x18))();
        FUN_005ed911();
        extraout_ECX[0x1a] = 0;
      }
      iVar2 = extraout_ECX[0x1d];
      if ((char)extraout_ECX[0x1b] != '\0') {
        (**(code **)(*extraout_ECX + 0x28))();
        (**(code **)(*extraout_ECX + 4))();
        goto LAB_005f86ae;
      }
    }
    (**(code **)(*extraout_ECX + 0x78))(iVar2);
  }
LAB_005f86ae:
  iVar1 = DAT_006fed08;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

