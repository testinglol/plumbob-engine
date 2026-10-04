
void FUN_004089ca(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar4 = extraout_ECX[1];
  *(int **)(unaff_EBP + -0x24) = extraout_ECX;
  if ((iVar4 - *extraout_ECX) / 0x4c == 0) {
    FUN_005c22bb();
    uVar2 = FUN_005caeef();
    FUN_005c1033();
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005c11b1();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_005c174f(&PTR_DAT_006c0f80);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar3 = FUN_005c1940(unaff_EBP + -0x44,uVar2,uVar3);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
    if (*(int *)(unaff_EBP + -0x14) == 0) {
      uVar3 = FUN_005c174f(&DAT_006c0f7c);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      iVar4 = FUN_005c1940(unaff_EBP + -0x44,uVar2,uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      if (iVar4 == 0) {
        uVar2 = FUN_005c1171(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        FUN_005c11bb(uVar2);
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_0042004f();
        uVar2 = FUN_005c1186(unaff_EBP + -0x18);
        while( true ) {
          *(undefined1 *)(unaff_EBP + -4) = 5;
          uVar1 = FUN_005c11f5(uVar2);
          *(undefined1 *)(unaff_EBP + -0xd) = uVar1;
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
          if (*(char *)(unaff_EBP + -0xd) == '\0') break;
          FUN_005c1209();
          uVar2 = FUN_00401f77();
          FUN_0046f824(unaff_EBP + -0x84,0,0x40);
          *(undefined ***)(unaff_EBP + -0x90) = &PTR_FUN_0066651c;
          FUN_0046f847(uVar2,0xffffffff);
          FUN_0040f4f6(unaff_EBP + -0x90);
          FUN_005c11ce();
          uVar2 = FUN_005c1186(unaff_EBP + -0x18);
        }
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0042004f();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c1070();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

