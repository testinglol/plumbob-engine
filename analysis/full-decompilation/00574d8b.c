
void FUN_00574d8b(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar6;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x24) = extraout_ECX;
  iVar3 = *(int *)(unaff_EBP + 0x20);
  *extraout_ECX = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[1] = *(undefined4 *)(unaff_EBP + 0xc);
  extraout_ECX[2] = iVar3;
  *(undefined1 *)(extraout_ECX + 3) = 0;
  iVar2 = FUN_005d49d6();
  if (iVar2 != 0) {
    if (iVar3 == 0) {
      uVar4 = FUN_005731df();
      extraout_ECX[2] = uVar4;
    }
    else {
      extraout_ECX[2] = iVar3;
    }
    if (extraout_ECX[2] != 0) {
      iVar3 = FUN_0057d4e4(extraout_ECX[2]);
      if (iVar3 == 0) {
        iVar3 = FUN_0057d50a(extraout_ECX[2]);
      }
      *(undefined4 *)(iVar3 + 0xc) = 1000000;
      *(undefined1 *)(iVar3 + 0x10) = 1;
      FUN_0042ecf6(unaff_EBP + 0x23);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar4 = FUN_00412ab1(unaff_EBP + -0x60,&DAT_006f6388,unaff_EBP + 0x14);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_005b86bd(uVar4);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00401729();
      FUN_005d8277(unaff_EBP + -0x3c,0,0,0);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005d8632(unaff_EBP + -0x10,7);
      FUN_00575f2f();
      puVar1 = *(undefined4 **)(unaff_EBP + -0x10);
      puVar6 = (undefined4 *)*puVar1;
      *(undefined4 **)(unaff_EBP + -0x14) = puVar1;
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
      FUN_00576b0a(puVar6,puVar1,unaff_EBP + 0xc);
      *(bool *)(unaff_EBP + 0xf) = 2 < *(uint *)(unaff_EBP + 0xc);
      FUN_005d4956(&DAT_006cf084);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0042ecf6(unaff_EBP + -0x19);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      FUN_005d8ab4(unaff_EBP + -0x54,1);
      FUN_005d8632(unaff_EBP + -0x18,8);
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      FUN_00576b0a(**(undefined4 **)(unaff_EBP + -0x18),*(undefined4 **)(unaff_EBP + -0x18),
                   unaff_EBP + -0x20);
      if ((*(int *)(unaff_EBP + -0x20) == 0) && (*(char *)(unaff_EBP + 0xf) == '\0')) {
        FUN_0042ef0d();
        FUN_005d499c(&DAT_006f6368);
        FUN_005757e5(unaff_EBP + 0x14);
        *(undefined4 **)(unaff_EBP + -0x14) = *(undefined4 **)(unaff_EBP + -0x10);
        puVar6 = (undefined4 *)**(undefined4 **)(unaff_EBP + -0x10);
      }
      while (puVar6 != *(undefined4 **)(unaff_EBP + -0x14)) {
        FUN_005b86bd(unaff_EBP + -0x3c);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005d4c15(unaff_EBP + -0x48,1);
        *(undefined1 *)(unaff_EBP + -4) = 9;
        if ((**(char **)(unaff_EBP + -0x48) != '\\') && (**(char **)(unaff_EBP + -0x48) != '/')) {
          sVar5 = _strlen(&DAT_006cc070);
          FUN_00412d8a(&DAT_006cc070,&DAT_006cc070 + sVar5);
        }
        FUN_00412d8a(puVar6[2],puVar6[3]);
        uVar4 = FUN_00575062(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x30);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
        FUN_0057d4e4(uVar4);
        iVar3 = FUN_00575047();
        if (iVar3 != 0) {
          FUN_005806fe(*(undefined4 *)(unaff_EBP + 0xc));
        }
        puVar6 = (undefined4 *)*puVar6;
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_005b8770();
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_005b8770();
      }
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0042ed0e();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0042a889();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042ed0e();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

