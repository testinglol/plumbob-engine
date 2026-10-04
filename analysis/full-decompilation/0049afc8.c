
undefined4 FUN_0049afc8(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar7;
  
  FUN_00634c24();
  piVar1 = (int *)(extraout_ECX + 4);
  if (*(int *)(extraout_ECX + 4) == 0) {
    puVar4 = *(undefined4 **)(unaff_EBP + 8);
    DAT_006ede68 = 1;
    *(undefined4 *)(extraout_ECX + 400) = *puVar4;
    *(undefined4 *)(extraout_ECX + 0x194) = puVar4[1];
    iVar5 = FUN_005cfc78(piVar1,0);
    if (iVar5 != 0) {
      puVar7 = &DAT_006c08dc;
      uVar6 = FUN_005cbdcb(iVar5,&DAT_006c08dc);
      FUN_005bc69b(uVar6);
      FUN_005bc69b(puVar7);
    }
    FUN_005cf06d((int)*(short *)(extraout_ECX + 0x196),*(short *)(extraout_ECX + 0x194) + -100);
    iVar5 = FUN_005cea9b(extraout_ECX + 0x10);
    if (iVar5 != 0) {
      puVar7 = &DAT_006c08dc;
      uVar6 = FUN_005cbdcb(iVar5,&DAT_006c08dc);
      FUN_005bc69b(uVar6);
      FUN_005bc69b(puVar7);
    }
    fVar2 = *(float *)(*piVar1 + 0x18);
    fVar3 = *(float *)(*piVar1 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x14) = 0x43480000;
    *(undefined4 *)(unaff_EBP + -0x10) = 0x447a0000;
    *(undefined4 *)(unaff_EBP + -0x18) = 0x41200000;
    *(float *)(unaff_EBP + 8) = fVar2 / fVar3;
    uVar6 = FUN_0049ba2e(unaff_EBP + -0xb4,unaff_EBP + -0x18,unaff_EBP + -0x10,unaff_EBP + -0x14,
                         unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005ce950(uVar6,0);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c4890();
    FUN_0049b1e4();
    iVar5 = *piVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (iVar5 != 0) {
      FUN_005ce783(unaff_EBP + -0x54);
      if (*(char *)(unaff_EBP + -0x53) != '\0') {
        *(undefined1 *)(unaff_EBP + -0x53) = 0;
        *(undefined1 *)(unaff_EBP + -0x2c) = 1;
      }
      if (*(char *)(unaff_EBP + -0x3f) != '\0') {
        *(undefined1 *)(unaff_EBP + -0x3f) = 0;
        *(undefined1 *)(unaff_EBP + -0x2c) = 1;
      }
      if (*(int *)(unaff_EBP + -0x50) != 2) {
        *(undefined4 *)(unaff_EBP + -0x50) = 2;
        *(undefined1 *)(unaff_EBP + -0x2c) = 1;
      }
      FUN_005ce796(unaff_EBP + -0x54);
    }
    *(int *)(unaff_EBP + -0x24) = (int)*(short *)(extraout_ECX + 400);
    *(int *)(unaff_EBP + -0x1c) = (int)*(short *)(extraout_ECX + 0x194);
    *(int *)(unaff_EBP + -0x28) = (int)*(short *)(extraout_ECX + 0x192);
    *(int *)(unaff_EBP + -0x20) = (int)*(short *)(extraout_ECX + 0x196);
    *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -100) = *(undefined4 *)(unaff_EBP + -0x1c);
    FUN_005caedd(unaff_EBP + -0x70);
    FUN_0046f824(unaff_EBP + -0x1b8,0,0x104);
    *(undefined ***)(unaff_EBP + -0x1c4) = &PTR_FUN_006664e8;
    uVar6 = FUN_0041532c(0,s_Lights_006c6278,unaff_EBP + -0x1c4);
    FUN_004ee9ce(uVar6);
    FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x1c0));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005c4f70(unaff_EBP + -0x60);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005c2ee6();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

