
void FUN_004c2896(void)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int *piVar4;
  int iVar5;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x174,0,0x104);
  *(undefined ***)(unaff_EBP + -0x180) = &PTR_FUN_006664e8;
  uVar3 = FUN_0041532c(0,s_stalk_ini_006c75d8,unaff_EBP + -0x180);
  FUN_004ee9ce(uVar3);
  piVar1 = (int *)(extraout_ECX + 0x28);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0x24);
  *(int *)(unaff_EBP + -0x10) = *piVar1;
  FUN_0063344c(1);
  uVar3 = DAT_00689070;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00633510(*(undefined4 *)(unaff_EBP + -0x17c),1,uVar3);
  if (*(int *)(*(int *)(unaff_EBP + -0x6c + *(int *)(*(int *)(unaff_EBP + -0x70) + 4)) + 0x4c) != -1
     ) {
    iVar5 = extraout_ECX + 0x18;
    piVar4 = piVar1;
    FUN_006326ae((int *)(extraout_ECX + 0x24));
    FUN_006326ae(piVar4);
    FUN_006335fc(iVar5);
    FUN_00633552();
    *(int *)(extraout_ECX + 0x18) = *(int *)(extraout_ECX + 0x18) * 1000;
  }
  if ((*(int *)(extraout_ECX + 0x24) != *(int *)(unaff_EBP + -0x14)) ||
     (*piVar1 != *(int *)(unaff_EBP + -0x10))) {
    uVar2 = FUN_004c27b6();
    *(undefined1 *)(extraout_ECX + 0x150) = uVar2;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_006334fd();
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

