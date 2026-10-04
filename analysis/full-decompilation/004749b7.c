
undefined4 FUN_004749b7(void)

{
  uint uVar1;
  short *psVar2;
  undefined4 uVar3;
  byte bVar4;
  short sVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  short *psVar8;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd4;
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  iVar6 = *(int *)(extraout_ECX + 0x14);
  iVar7 = *(int *)(extraout_ECX + 0x10);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX + 8;
  uVar1 = (iVar6 - iVar7 >> 2) - 1;
  if (((int)uVar1 < 0) ||
     ((uint)(*(int *)(extraout_ECX + 0x14) - *(int *)(extraout_ECX + 0x10) >> 2) <= uVar1)) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(*(int *)(extraout_ECX + 0x10) + uVar1 * 4);
  }
  iVar7 = *(int *)(unaff_EBP + 8);
  *(undefined2 *)(unaff_EBP + -0x2c) = 0xffff;
  if ((iVar7 != 0) || (iVar7 = *(int *)(iVar6 + 0xc), iVar7 != 0)) {
    psVar2 = (short *)FUN_0040204f(*(undefined4 *)(unaff_EBP + 0x10));
    sVar5 = 0;
    if (psVar2 != (short *)0x0) {
      *(int *)(unaff_EBP + -0x20) = iVar7;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      if (*(short *)(unaff_EBP + 0x10) == -1) {
        *(undefined2 *)(unaff_EBP + -0x2c) = 0xffff;
      }
      else {
        *(ushort *)(unaff_EBP + -0x2c) =
             (ushort)*(undefined4 *)(unaff_EBP + -0x2c) & 0x8000 |
             (ushort)*(undefined4 *)(unaff_EBP + 0x10);
      }
      if (iVar6 == 0) {
        *(undefined2 *)(unaff_EBP + -0x28) = 0;
      }
      else {
        *(undefined2 *)(unaff_EBP + -0x28) = *(undefined2 *)(iVar6 + 4);
      }
      psVar8 = *(short **)(unaff_EBP + 0xc);
      if (psVar8 == (short *)0x0) {
        psVar8 = *(short **)(extraout_ECX + 0x24);
      }
      if ((char)psVar2[2] == '\x04') {
        sVar5 = *psVar8;
        *(short *)(unaff_EBP + -0x2a) = sVar5;
        if (psVar2[1] <= sVar5) {
          sVar5 = psVar2[1] + -1;
          goto LAB_00474a7d;
        }
      }
      else {
LAB_00474a7d:
        *(short *)(unaff_EBP + -0x2a) = sVar5;
      }
      if ((-1 < sVar5) && (sVar5 < psVar2[1])) {
        if (*psVar2 < -0x7ffe) {
          if (*psVar2 == -0x7fff) {
            bVar4 = *(byte *)(psVar2 + 3);
            if (4 < bVar4) {
              bVar4 = 4;
            }
          }
          else {
            bVar4 = 0;
          }
        }
        else {
          bVar4 = *(byte *)(psVar2 + 3);
        }
        *(byte *)(unaff_EBP + -0x26) = bVar4;
        if (*psVar2 < -0x7ffe) {
          if ((*psVar2 != -0x7fff) ||
             (bVar4 = *(byte *)((int)psVar2 + 5), 4 < *(byte *)((int)psVar2 + 5))) {
            bVar4 = 4;
          }
        }
        else {
          bVar4 = *(byte *)((int)psVar2 + 5);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0;
        *(byte *)(unaff_EBP + -0x25) = bVar4;
        FUN_0047542b(unaff_EBP + -0x2c,psVar8);
        uVar3 = 1;
        goto LAB_00474b11;
      }
    }
  }
  uVar3 = 0;
LAB_00474b11:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

