
void FUN_004568c7(void)

{
  ushort uVar1;
  ushort *puVar2;
  undefined2 *puVar3;
  int extraout_ECX;
  undefined2 *puVar4;
  int unaff_EBP;
  short *psVar5;
  uint uVar6;
  
  FUN_00634c24();
  puVar2 = *(ushort **)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (puVar2 == (ushort *)0x0) {
    for (psVar5 = *(short **)(extraout_ECX + 0x244); psVar5 != *(short **)(extraout_ECX + 0x248);
        psVar5 = psVar5 + 4) {
      if (*psVar5 == *(short *)(unaff_EBP + 8)) {
        FUN_006321f0(*(undefined4 *)(psVar5 + 2));
        FUN_004c9496(psVar5);
        break;
      }
    }
  }
  else {
    uVar1 = *puVar2;
    uVar6 = uVar1 & 0x7fff;
    puVar3 = operator_new(uVar6 * 2 + 2);
    *puVar3 = (short)uVar6;
    if ((uVar1 & 0x7fff) != 0) {
      puVar4 = puVar3;
      do {
        puVar4 = puVar4 + 1;
        *puVar4 = *(undefined2 *)(((int)puVar2 - (int)puVar3) + (int)puVar4);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    *(undefined2 **)(unaff_EBP + -0x14) = puVar3;
    *(undefined2 *)(unaff_EBP + -0x18) = *(undefined2 *)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00456cdb(unaff_EBP + -0x18);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

