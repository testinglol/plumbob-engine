
undefined4 FUN_005f8725(void)

{
  int iVar1;
  undefined1 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = extraout_ECX[0xf];
  *(int **)(unaff_EBP + -0x10) = extraout_ECX + 0xf;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00431779(*(int *)(unaff_EBP + 8),*(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + 8));
  iVar1 = *(int *)(unaff_EBP + 0x10);
  *(undefined1 *)(extraout_ECX + 9) = 0;
  extraout_ECX[0x1f] = iVar1;
  *(undefined1 *)(extraout_ECX + 0xb) = 1;
  if (iVar1 == 1) {
    *(undefined1 *)((int)extraout_ECX + 0x25) = 1;
  }
  else if (iVar1 == 2) {
    uVar2 = (**(code **)(*extraout_ECX + 0xd8))();
    *(undefined1 *)((int)extraout_ECX + 0x25) = uVar2;
  }
  else {
    *(undefined1 *)((int)extraout_ECX + 0x25) = 0;
  }
  FUN_005d4bbf(&DAT_006de560);
  iVar1 = extraout_ECX[0xf];
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

