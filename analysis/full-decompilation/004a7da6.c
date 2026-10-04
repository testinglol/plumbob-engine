
void FUN_004a7da6(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if ((DAT_006f0088 != *(int *)(unaff_EBP + 8)) || (*(char *)(unaff_EBP + 0xc) != '\0')) {
    if (DAT_006e4870 != '\0') {
      if (*(char *)((int)extraout_ECX + 0x17a) == '\0') {
        iVar3 = extraout_ECX[0x5c] + DAT_006f0080;
        iVar4 = extraout_ECX[0x5d] + DAT_006f0084;
      }
      else {
        iVar3 = FUN_004c9d30();
        iVar4 = FUN_004c9d53();
      }
      *(int *)(unaff_EBP + 0xc) = iVar4;
      FUN_004b0542();
      uVar5 = *(undefined4 *)(unaff_EBP + 0xc);
      extraout_ECX[0x5c] = 0;
      extraout_ECX[0x5d] = 0;
      FUN_004a83dc(iVar3,uVar5,1);
    }
    FUN_004a7d6c(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x14) = DAT_006e54d8;
    uVar5 = FUN_00433116(unaff_EBP + -0x1c,1);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    cVar1 = FUN_00434d5c(uVar5);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (cVar1 != '\0') {
      iVar3 = *(int *)(DAT_006e54d8 + 0x10);
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      uVar2 = (undefined1)(iVar3 / 4);
      *(undefined1 *)(unaff_EBP + -0x10) = uVar2;
      *(undefined1 *)(unaff_EBP + -0xf) = uVar2;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_004a8000(unaff_EBP + -0x10);
      puVar6 = (undefined4 *)FUN_00434d3d(unaff_EBP + -0x24);
      uVar5 = *puVar6;
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar5;
      *(undefined4 *)(unaff_EBP + -0x18) = puVar6[1];
    }
    DAT_006f0088 = *(int *)(unaff_EBP + 8);
    extraout_ECX[0x16] = 0x10 << ((byte)DAT_006f0088 & 0x1f);
    extraout_ECX[0x17] = 8 << ((byte)DAT_006f0088 & 0x1f);
    extraout_ECX[0x18] = 8 << ((byte)DAT_006f0088 & 0x1f);
    extraout_ECX[0x19] = 4 << ((byte)DAT_006f0088 & 0x1f);
    FUN_004a7d36();
    FUN_004ca03f(extraout_ECX[0x15],DAT_006f0088);
    FUN_004a7baa(*(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18),
                 extraout_ECX[6],0,1);
    iVar4 = DAT_006f0084 + extraout_ECX[0x5d];
    iVar3 = DAT_006f0080 + extraout_ECX[0x5c];
    extraout_ECX[0x5c] = 0;
    extraout_ECX[0x5d] = 0;
    FUN_004a83dc(iVar3,iVar4,1);
    if (DAT_006f0095 == '\0') {
      FUN_004b1891();
    }
    if (DAT_006f6b5c != (int *)0x0) {
      piVar7 = (int *)(**(code **)(*DAT_006f6b5c + 0x2c))();
      if (piVar7 != (int *)0x0) {
        (**(code **)(*piVar7 + 0xa4))(0);
      }
    }
    (**(code **)(*extraout_ECX + 0x48))();
    if (*(char *)((int)extraout_ECX + 0x49) != '\0') {
      FUN_004abb9e((char)extraout_ECX[0x7e]);
    }
    iVar3 = DAT_006f0088;
    FUN_004b5717(DAT_006f0088);
    FUN_00607db7(iVar3);
    FUN_004ca711(*(undefined4 *)(extraout_ECX[0x15] + (8 - DAT_006f0088) * 4));
    FUN_0040766a(0xf9,DAT_006f0088);
    if (*(char *)(unaff_EBP + 0x10) != '\0') {
      FUN_0043e0a9();
    }
    (**(code **)(*DAT_006fe8bc + 0x18))();
    FUN_005db0b7();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

