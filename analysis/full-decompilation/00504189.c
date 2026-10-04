
void FUN_00504189(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  bool bVar4;
  
  FUN_00634c24();
  if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0xe) & 0x20) != 0) {
    iVar2 = FUN_004cfdd6();
    if (*(int *)(extraout_ECX + 0xdc) != 0) {
      FUN_005e46f0(iVar2 == 0);
    }
    if (*(int *)(extraout_ECX + 0xe0) != 0) {
      FUN_005e46f0(iVar2 == 1);
    }
    if (*(int *)(extraout_ECX + 0xe4) != 0) {
      FUN_005e46f0(iVar2 == 2);
    }
    if (*(int *)(extraout_ECX + 0xe8) != 0) {
      FUN_005e46f0(iVar2 == 3);
      piVar1 = *(int **)(extraout_ECX + 0xe8);
      bVar4 = iVar2 == 3;
      if ((bool)(char)piVar1[0x5a] != bVar4) {
        *(bool *)(piVar1 + 0x5a) = bVar4;
        (**(code **)(*piVar1 + 0x168))();
      }
      (**(code **)(**(int **)(extraout_ECX + 0xe8) + 0x90))(0x400,bVar4);
      FUN_0046f824(unaff_EBP + -0x118,0,0x100);
      *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_00666524;
      if (iVar2 == 3) {
        uVar3 = FUN_004cfddd();
        FUN_0046fa40(uVar3);
        FUN_0046f847(&DAT_006c6f28,0xffffffff);
        uVar3 = FUN_004cfde4();
        FUN_0046fa40(uVar3);
      }
      uVar3 = FUN_005d4956(*(undefined4 *)(unaff_EBP + -0x120));
      piVar1 = *(int **)(extraout_ECX + 0xe8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar1 + 0x9c))(uVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    iVar2 = FUN_004cfdeb();
    if (*(int *)(extraout_ECX + 0xf0) != 0) {
      FUN_005e46f0(iVar2 == 0);
    }
    if (*(int *)(extraout_ECX + 0xf4) != 0) {
      FUN_005e46f0(iVar2 == 1);
    }
    if (*(int *)(extraout_ECX + 0xf8) != 0) {
      FUN_005e46f0(iVar2 == 2);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

