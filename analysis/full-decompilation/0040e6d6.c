
void FUN_0040e6d6(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  FUN_0040b75a();
  iVar3 = *(int *)(unaff_EBP + 8);
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040e4d9(iVar3,unaff_EBP + -0x184);
  FUN_00472fca(*(undefined4 *)(extraout_ECX + 8),2);
  FUN_0046f824(unaff_EBP + -0x4c,0,0x40);
  *(undefined ***)(unaff_EBP + -0x58) = &PTR_FUN_0066651c;
  FUN_0040b7bc(unaff_EBP + -0x1d0,unaff_EBP + -0x58);
  FUN_004727bd(*(undefined4 *)(unaff_EBP + -0x54),&DAT_006de560);
  FUN_004089ca();
  iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
  if (0 < iVar2) {
    *(int *)(unaff_EBP + 8) = iVar2;
    do {
      FUN_004089ca();
      FUN_00472b1d(DAT_006e4860 + iVar4);
      iVar4 = iVar4 + 0x4c;
      piVar1 = (int *)(unaff_EBP + 8);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined2 *)(iVar3 + 8) = 0;
  **(undefined1 **)(iVar3 + 4) = 0;
  iVar3 = (*(code *)**(undefined4 **)(unaff_EBP + -0x164))();
  if (iVar3 != 0) {
    FUN_0046f8e4(&DAT_006f6b88);
    FUN_0046f917(unaff_EBP + -0x164,0xffffffff);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

