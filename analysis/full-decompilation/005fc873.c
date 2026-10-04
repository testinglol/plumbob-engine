
bool FUN_005fc873(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *extraout_ECX;
  int unaff_EBP;
  bool bVar4;
  
  FUN_00634c24();
  iVar3 = DAT_006fecc8;
  if ((char)extraout_ECX[0x5f] == '\0') {
    bVar4 = false;
  }
  else {
    *(int **)(unaff_EBP + -0x18) = &DAT_006fecc8;
    *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
    (**(code **)(iVar3 + 4))();
    iVar3 = DAT_006fed00;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    while (iVar3 != 0) {
      FUN_00580a92(unaff_EBP + -0x14);
      piVar1 = *(int **)(*(int *)(unaff_EBP + -0x14) + 4);
      uVar2 = (**(code **)(*piVar1 + 0x1c))();
      FUN_005b86bd(uVar2);
      iVar3 = *piVar1;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      (**(code **)(iVar3 + 0x28))();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_005b8770();
      iVar3 = DAT_006fed00;
    }
    *(int **)(unaff_EBP + -0x10) = extraout_ECX;
    FUN_005fcad4(unaff_EBP + -0x28,unaff_EBP + -0x10);
    iVar3 = (**(code **)(*(int *)extraout_ECX[0x61] + 0x1c))((int *)extraout_ECX[0x61]);
    bVar4 = -1 < iVar3;
    if (!bVar4) {
      (**(code **)(*extraout_ECX + 0xc))();
    }
    iVar3 = DAT_006fecc8;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    (**(code **)(iVar3 + 8))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return bVar4;
}

