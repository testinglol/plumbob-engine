
void FUN_0053cdb5(void)

{
  int *piVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  undefined1 uVar6;
  byte *pbVar7;
  int extraout_ECX;
  int unaff_EBP;
  byte *pbVar8;
  undefined4 uStack_28;
  int iStack_24;
  int iStack_20;
  uint uStack_1c;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 4;
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 0x10;
  do {
    iVar4 = **(int **)(unaff_EBP + -0x14);
    uStack_28 = 0;
    if (iVar4 != 0) {
      if (extraout_ECX == *(int *)(iVar4 + 0x20)) {
        pbVar8 = *(byte **)(iVar4 + 0x30);
      }
      else {
        pbVar8 = (byte *)(*(int *)(iVar4 + 0x34) + -6);
      }
      iStack_20 = unaff_EBP + -0xd;
      iStack_24 = 0x53cdfb;
      pbVar7 = (byte *)FUN_0053cd94();
      bVar2 = *pbVar7;
      uStack_1c = (uint)pbVar8[1];
      iStack_20 = 0x53ce08;
      cVar5 = FUN_0053cedf();
      bVar3 = *pbVar8;
      uStack_28 = CONCAT31((int3)(uStack_1c >> 8),bVar3);
      if ((bVar3 & 6) == 0) {
        if (cVar5 != '\0') {
LAB_0053ce4b:
          *(byte *)(extraout_ECX + 0xb) = *(byte *)(extraout_ECX + 0xb) | bVar2;
        }
      }
      else {
        iVar4 = *(int *)(**(int **)(unaff_EBP + -0x14) + 0x10);
        if (iVar4 != 0) {
          if (iVar4 < 1) goto LAB_0053ce4e;
          if ((2 < iVar4) && (iVar4 != 3)) {
            if (iVar4 == 6) {
              bVar3 = bVar3 & 2;
            }
            else {
              if (iVar4 != 7) goto LAB_0053ce4e;
              bVar3 = bVar3 & 4;
            }
            if (bVar3 == 0) goto LAB_0053ce4b;
          }
        }
        *(byte *)(extraout_ECX + 0xc) = *(byte *)(extraout_ECX + 0xc) | bVar2;
      }
LAB_0053ce4e:
      if (((*pbVar8 & 1) != 0) &&
         ((((bVar3 = pbVar8[1], bVar3 == 3 || (bVar3 == 5)) || (bVar3 == 6)) ||
          ((bVar3 == 0xf || (bVar3 == 0x17)))))) {
        *(byte *)(extraout_ECX + 0xb) = *(byte *)(extraout_ECX + 0xb) | bVar2;
      }
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    piVar1 = (int *)(unaff_EBP + -0x18);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      uStack_1c = extraout_ECX + 0x28;
      iStack_20 = extraout_ECX + 0xc;
      *(undefined4 **)(unaff_EBP + -0x18) = &uStack_28;
      iStack_24 = extraout_ECX + 0xb;
      FUN_00438c54(extraout_ECX + 10);
      uVar6 = FUN_0053cf03();
      *(undefined1 *)(extraout_ECX + 0x24) = uVar6;
      uStack_1c = extraout_ECX + 0x3c;
      iStack_20 = 0x53ceb1;
      iStack_20 = FUN_0053cefd();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      *(undefined4 **)(unaff_EBP + -0x18) = &uStack_28;
      iStack_24 = extraout_ECX + 0xb;
      FUN_00438c54(extraout_ECX + 9);
      uVar6 = FUN_0053cf03();
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      *(undefined1 *)(extraout_ECX + 0x25) = uVar6;
      return;
    }
  } while( true );
}

