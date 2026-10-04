
void FUN_005216a8(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((*(int *)(extraout_ECX + 0x198) != -1) && (*(int *)(extraout_ECX + 0x19c) != 0)) {
    iVar2 = FUN_004e9744(*(int *)(extraout_ECX + 0x198));
    iVar3 = FUN_004ea79e(*(undefined4 *)(extraout_ECX + 0x198));
    iVar3 = (int)*(short *)(iVar3 + *(int *)(extraout_ECX + 0x194) * 2) / 100;
    if (*(char *)(extraout_ECX + 0x1d8) == '\0') {
      if ((iVar2 == 0) || (1 < *(short *)(iVar2 + 0x60e))) {
        if (iVar3 < 3) {
          FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1c0));
          uVar4 = *(undefined4 *)(extraout_ECX + 0x1cc);
        }
        else if (iVar3 < 8) {
          FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1c4));
          uVar4 = *(undefined4 *)(extraout_ECX + 0x1d0);
        }
        else {
          FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1c8));
          uVar4 = *(undefined4 *)(extraout_ECX + 0x1d4);
        }
      }
      else if (iVar3 < 3) {
        FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1a8));
        uVar4 = *(undefined4 *)(extraout_ECX + 0x1b4);
      }
      else if (iVar3 < 8) {
        FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1ac));
        uVar4 = *(undefined4 *)(extraout_ECX + 0x1b8);
      }
      else {
        FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1b0));
        uVar4 = *(undefined4 *)(extraout_ECX + 0x1bc);
      }
      FUN_00510775(uVar4);
    }
    FUN_005c1719();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_004e93e4(*(undefined4 *)(extraout_ECX + 0x198),unaff_EBP + -0x10);
    if (cVar1 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x2d;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x2d;
      iVar2 = unaff_EBP + -0x20;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      uVar4 = FUN_004096c2(iVar2);
      FUN_0051052c(0,uVar4,iVar2);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005a5e09();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

