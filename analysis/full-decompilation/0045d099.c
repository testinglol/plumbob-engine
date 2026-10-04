
void FUN_0045d099(void)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  int unaff_EBP;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  FUN_00434353(iVar1,iVar2,*(undefined4 *)(unaff_EBP + 0x10));
  if (iVar2 < 0xb) {
    FUN_00464b48(unaff_EBP + -0xc0,0x1c);
  }
  if (2 < iVar2) {
    (**(code **)(**(int **)(extraout_ECX + 0xadc) + 0x84))
              (iVar1,iVar2,*(undefined4 *)(unaff_EBP + 0x10));
    if (3 < iVar2) {
      FUN_00464b48(extraout_ECX + 0x78c,0x10);
    }
    if (iVar2 < 8) {
      if (*(int *)(iVar1 + 0xc) == 0) {
        puVar3 = (undefined4 *)(extraout_ECX + 0x7cc);
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        }
        iVar2 = *(int *)(unaff_EBP + 0xc);
      }
    }
    else {
      FUN_00464b48(extraout_ECX + 0x7cc,0x10);
    }
  }
  if (10 < iVar2) {
    if (iVar2 < 0x47) {
      if (iVar2 < 0x29) {
        uVar4 = 0x40;
      }
      else {
        uVar4 = 0x50;
      }
    }
    else {
      uVar4 = 0x100;
    }
    FUN_00464973(extraout_ECX + 0x58c,uVar4);
  }
  if (0xc < iVar2) {
    FUN_0046058f(extraout_ECX + 0xaf0,iVar1,iVar2);
  }
  if (0x2a < iVar2) {
    FUN_0041f1c7(iVar1,iVar2);
    FUN_0041f1c7(iVar1,iVar2);
    *(int *)(unaff_EBP + 8) = *(int *)(extraout_ECX + 0xa44) - *(int *)(extraout_ECX + 0xa40);
    FUN_00464a4e(unaff_EBP + 8,1);
    *(undefined4 *)(unaff_EBP + 0x10) = 0;
    if (0 < *(int *)(unaff_EBP + 8)) {
      do {
        if (*(int *)(iVar1 + 0xc) == 0) {
          uVar4 = FUN_0041ed45();
          *(undefined4 *)(unaff_EBP + -4) = 0;
          FUN_0045f8b0(uVar4);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005b8770();
        }
        FUN_0041f1c7(iVar1,*(undefined4 *)(unaff_EBP + 0xc));
        *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) + 1;
      } while (*(int *)(unaff_EBP + 0x10) < *(int *)(unaff_EBP + 8));
    }
    FUN_00460652(extraout_ECX + 0xb00,iVar1,*(undefined4 *)(unaff_EBP + 0xc));
    iVar2 = *(int *)(unaff_EBP + 0xc);
  }
  if (0x2b < iVar2) {
    FUN_004606cd(extraout_ECX + 0xad0,iVar1,iVar2);
  }
  if (iVar2 < 0x2d) {
    *(undefined2 *)(extraout_ECX + 0x58e) = 0;
    *(undefined2 *)(extraout_ECX + 0x59c) = 0;
    *(undefined2 *)(extraout_ECX + 0x5b6) = 0;
    *(undefined2 *)(extraout_ECX + 0x5b8) = 0;
    *(undefined2 *)(extraout_ECX + 0x5ba) = 0;
    *(undefined2 *)(extraout_ECX + 0x5bc) = 0;
    *(undefined2 *)(extraout_ECX + 0x5be) = 0;
    *(undefined2 *)(extraout_ECX + 0x5c0) = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

