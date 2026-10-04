
undefined4 FUN_005f443e(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(**(int **)(extraout_ECX + 0x114) + 0x48))();
  if (cVar2 == '\0') {
    iVar1 = *(int *)(extraout_ECX + 0x140);
    if (iVar1 < *(int *)(extraout_ECX + 0x144)) {
      uVar3 = FUN_005f4a03(unaff_EBP + -0x24,iVar1,*(int *)(extraout_ECX + 0x144) - iVar1);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_005b86bd(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00401729();
      FUN_005db0c6(unaff_EBP + -0x18,1);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

