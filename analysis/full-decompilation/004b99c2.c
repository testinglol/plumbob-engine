
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b99c2(void)

{
  int iVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar9;
  int iVar10;
  
  FUN_00634c24();
  uVar6 = __ftol();
  uVar7 = __ftol();
  iVar1 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x24) = uVar7;
  *(undefined4 *)(unaff_EBP + -0x20) = uVar6;
  cVar3 = FUN_004b462b(3,1);
  if (cVar3 == '\0') {
    iVar10 = *(int *)(iVar1 + 0x54);
    iVar8 = *(int *)(iVar1 + 0x50);
    *(undefined1 *)(unaff_EBP + 10) = 0;
    *(char *)(unaff_EBP + 8) = (char)(iVar10 >> 4);
    *(char *)(unaff_EBP + 9) = (char)(iVar8 >> 4);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    *(char *)(unaff_EBP + -0x10) = (char)(*(int *)(unaff_EBP + -0x20) >> 4);
    *(char *)(unaff_EBP + -0xf) = (char)(*(int *)(unaff_EBP + -0x24) >> 4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    bVar5 = FUN_00492d2c();
    cVar3 = *(char *)(unaff_EBP + -0x10);
    *(int *)(unaff_EBP + -0x18) = (int)*(char *)(unaff_EBP + -0xf);
    *(int *)(unaff_EBP + -0x14) = (int)*(char *)(unaff_EBP + 9);
    *(int *)(unaff_EBP + -0x1c) = (int)*(char *)(unaff_EBP + 8);
    *(int *)(extraout_ECX + 0x10) =
         *(int *)(extraout_ECX + 0x10) +
         ((((int)cVar3 - (int)*(char *)(unaff_EBP + 8)) - *(int *)(unaff_EBP + -0x18)) +
         *(int *)(unaff_EBP + -0x14)) * (8 << (bVar5 & 0x1f));
    bVar5 = FUN_00492d2c();
    *(int *)(extraout_ECX + 0x14) =
         *(int *)(extraout_ECX + 0x14) +
         ((((int)cVar3 - *(int *)(unaff_EBP + -0x1c)) - *(int *)(unaff_EBP + -0x14)) +
         *(int *)(unaff_EBP + -0x18)) * (4 << (bVar5 & 0x1f));
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  else {
    FUN_0047bd91(unaff_EBP + -0x20,unaff_EBP + -0x24,*(undefined4 *)(DAT_006e54d8 + 0x84),0x401);
    uVar4 = __ftol();
    *(undefined1 *)(unaff_EBP + 0xb) = uVar4;
    puVar2 = (undefined4 *)**(undefined4 **)(iVar1 + 0x18);
    uVar6 = FUN_00492d2c(unaff_EBP + 0xb);
    (*(code *)*puVar2)(unaff_EBP + -0x10,*(undefined4 *)(unaff_EBP + -0x24),
                       *(undefined4 *)(unaff_EBP + -0x20),*(undefined4 *)(extraout_ECX + 0xc),uVar6)
    ;
    *(int *)(extraout_ECX + 0x10) = (int)*(short *)(unaff_EBP + -0xe);
    *(int *)(extraout_ECX + 0x14) = (int)*(short *)(unaff_EBP + -0x10);
  }
  if (*(int *)(extraout_ECX + 0xc) == 0) {
    *(undefined4 *)(extraout_ECX + 0xc) = 1;
  }
  fVar9 = (float10)FUN_00454f69(extraout_ECX + 8);
  uVar6 = *(undefined4 *)(iVar1 + 0x20);
  uVar7 = *(undefined4 *)(extraout_ECX + 0xc);
  iVar10 = unaff_EBP + -0x1c;
  *(float *)(unaff_EBP + -0x1c) = (float)(fVar9 * (float10)_DAT_0066881c);
  *(int *)(unaff_EBP + 8) = 1 << ((char)uVar6 + 1U & 0x1f);
  iVar8 = __ftol(iVar10,uVar7);
  FUN_004c9e4d(iVar1,(iVar8 - (4 << ((byte)*(undefined4 *)(iVar1 + 0x20) & 0x1f))) +
                     *(int *)(extraout_ECX + 0x14),iVar10,uVar7);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

