
void FUN_00512cb4(void)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  iVar5 = *(int *)(extraout_ECX + 0x84);
  iVar1 = *(int *)(extraout_ECX + 0x7c);
  FUN_005dda18(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
  *(undefined4 *)(extraout_ECX + 0xe0) = 0;
  *(undefined4 *)(extraout_ECX + 0xe4) = 0;
  *(int *)(extraout_ECX + 0xe8) = *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c);
  *(int *)(extraout_ECX + 0xec) = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
  iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x58))();
  *(int *)(extraout_ECX + 0xec) = *(int *)(extraout_ECX + 0xe4) + iVar3 * 2;
  *(undefined4 *)(extraout_ECX + 0x100) = 0;
  *(undefined4 *)(extraout_ECX + 0x104) = 0;
  *(int *)(extraout_ECX + 0x108) = *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c);
  *(int *)(extraout_ECX + 0x10c) = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
  *(undefined4 *)(extraout_ECX + 0x104) = *(undefined4 *)(extraout_ECX + 0x10c);
  cVar2 = FUN_004e076c(extraout_ECX + 0x14c);
  if (cVar2 != '\0') {
    iVar3 = (**(code **)(**(int **)(extraout_ECX + 0xd8) + 0x58))();
    *(int *)(extraout_ECX + 0x104) = *(int *)(extraout_ECX + 0x104) + iVar3 * -3;
  }
  *(undefined4 *)(extraout_ECX + 0xf0) = 0;
  *(undefined4 *)(extraout_ECX + 0xf4) = 0;
  *(int *)(extraout_ECX + 0xf8) = *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c);
  *(int *)(extraout_ECX + 0xfc) = *(int *)(extraout_ECX + 0x88) - *(int *)(extraout_ECX + 0x80);
  *(int *)(extraout_ECX + 0xf0) = *(int *)(extraout_ECX + 0xf0) + 5;
  *(int *)(extraout_ECX + 0xf8) = *(int *)(extraout_ECX + 0xf8) + -5;
  *(int *)(extraout_ECX + 0xf4) = *(int *)(extraout_ECX + 0xf4) + 5;
  *(int *)(extraout_ECX + 0xfc) = *(int *)(extraout_ECX + 0xfc) + -5;
  *(undefined4 *)(extraout_ECX + 0xfc) = *(undefined4 *)(extraout_ECX + 0x104);
  *(int *)(extraout_ECX + 0xf4) = *(int *)(extraout_ECX + 0xec) + 3;
  if ((iVar5 - iVar1 != *(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c)) ||
     ((*(int *)(extraout_ECX + 0x144) - *(int *)(extraout_ECX + 0x140)) / 0xc == 0)) {
    *(undefined1 *)(extraout_ECX + 0x118) = 1;
    iVar5 = *(int *)(extraout_ECX + 0xf8) - *(int *)(extraout_ECX + 0xf0);
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    FUN_005e6b22(iVar5,unaff_EBP + 0x17);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar4 = FUN_00461407(*(undefined4 *)(unaff_EBP + -0x18),iVar5,unaff_EBP + -0x24,
                         *(undefined4 *)(unaff_EBP + 0x14));
    *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_00512efb(unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_004d6053();
  }
  iVar5 = *(int *)(extraout_ECX + 0xdc);
  if (iVar5 != 0) {
    FUN_004cb21d(((*(int *)(extraout_ECX + 0x84) - *(int *)(iVar5 + 0x84)) -
                 *(int *)(extraout_ECX + 0x7c)) + -2 + *(int *)(iVar5 + 0x7c),2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

