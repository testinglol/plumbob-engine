
void FUN_0053bdc6(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  puVar7 = extraout_ECX;
  puVar8 = (uint *)(unaff_EBP + -0x44);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  iVar4 = *(int *)(unaff_EBP + 8);
  *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) | 0x10;
  *(uint *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar4 & 3;
  uVar3 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = 0;
  if (uVar3 == 0) {
    *(undefined4 *)(unaff_EBP + 8) = 0;
  }
  else {
    uVar5 = 1;
    if (((byte)uVar3 & 1) != 1) {
      do {
        uVar5 = uVar5 * 2;
      } while ((uVar3 & uVar5) != uVar5);
    }
    *(uint *)(unaff_EBP + 8) = uVar5;
  }
  if (*(int *)(unaff_EBP + 8) != 0) {
    iVar6 = iVar4 << 6;
    *(int *)(unaff_EBP + -0x14) = iVar6;
    do {
      uVar3 = *(uint *)(&DAT_006f4620 + (iVar6 + *(int *)(unaff_EBP + 8)) * 4);
      *(uint *)(unaff_EBP + -0x44) = *(uint *)(unaff_EBP + -0x44) | uVar3;
      *(uint *)(unaff_EBP + -0x10) = uVar3;
      if ((uVar3 == 0x10) || (uVar3 == 0x20)) {
        *(undefined2 *)(unaff_EBP + -0x3c) = 0;
        *(undefined2 *)(unaff_EBP + -0x30) = 0;
      }
      *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) | 0x10;
      iVar1 = FUN_00435221(*(int *)(unaff_EBP + 8),0);
      FUN_004633e3(*(undefined2 *)((int)extraout_ECX + iVar1 * 2 + 8),
                   *(undefined4 *)(unaff_EBP + -0x10));
      if (*(int *)(unaff_EBP + 8) == 0x20) {
        *(undefined4 *)(unaff_EBP + -0x18) = (&DAT_006f45d4)[iVar4 * 5];
        iVar6 = FUN_00435221(0x20,1);
        FUN_00493b0f(*(undefined2 *)((int)extraout_ECX + iVar6 * 2 + 0x14),
                     *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x18));
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(&DAT_006f45dc + iVar4 * 0x14);
        iVar6 = FUN_00435221(0x20,3);
        FUN_00493b0f(*(undefined2 *)((int)extraout_ECX + iVar6 * 2 + 0x14),
                     *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x18));
        if ((*(int *)(&DAT_006f45dc + iVar4 * 0x14) == 2) ||
           (*(int *)(&DAT_006f45dc + iVar4 * 0x14) == 1)) {
          *(short *)(unaff_EBP + -0x3c) = (short)extraout_ECX[5];
        }
        else {
          *(short *)(unaff_EBP + -0x30) = (short)extraout_ECX[5];
        }
        iVar6 = (&DAT_006f45d4)[iVar4 * 5];
        *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) | 0x10;
        if ((iVar6 == 2) || (iVar6 == 1)) {
          *(short *)(unaff_EBP + -0x3c) = (short)extraout_ECX[2];
        }
        else {
          *(short *)(unaff_EBP + -0x30) = (short)extraout_ECX[2];
        }
        *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) | 0x10;
LAB_0053bf1c:
        iVar6 = *(int *)(unaff_EBP + -0x14);
      }
      else {
        if (*(int *)(unaff_EBP + 8) == 0x10) {
          *(undefined4 *)(unaff_EBP + -0x18) = (&DAT_006f45d8)[iVar4 * 5];
          iVar6 = FUN_00435221(0x10,2);
          FUN_00493b0f(*(undefined2 *)((int)extraout_ECX + iVar6 * 2 + 0x14),
                       *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x18));
          *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(&DAT_006f45e0 + iVar4 * 0x14);
          iVar6 = FUN_00435221(0x10,4);
          FUN_00493b0f(*(undefined2 *)((int)extraout_ECX + iVar6 * 2 + 0x14),
                       *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x18));
          uVar9 = (&DAT_006f45d8)[iVar4 * 5];
          uVar2 = FUN_0053c028(2);
          FUN_0053c043(uVar2,uVar9);
          uVar9 = *(undefined4 *)(&DAT_006f45e0 + iVar4 * 0x14);
          uVar2 = FUN_0053c028(4);
          FUN_0053c043(uVar2,uVar9);
          goto LAB_0053bf1c;
        }
        uVar10 = 0;
        uVar9 = *(undefined4 *)(unaff_EBP + -0x10);
        uVar2 = FUN_00467e89(*(undefined4 *)(unaff_EBP + 8),0);
        FUN_00493b0f(uVar2,uVar9,uVar10);
      }
      uVar9 = *(undefined4 *)(unaff_EBP + -0x10);
      uVar2 = FUN_0053bd4d(*(undefined4 *)(unaff_EBP + 8));
      FUN_0053bd78(uVar2,uVar9);
      uVar3 = *(uint *)(unaff_EBP + 8);
      do {
        uVar3 = uVar3 * 2;
        if ((*extraout_ECX & uVar3) == uVar3) break;
      } while ((int)uVar3 < 0x20);
    } while (((int)uVar3 < 0x20) && (*(uint *)(unaff_EBP + 8) = uVar3, uVar3 != 0));
  }
  puVar7 = (uint *)(unaff_EBP + -0x44);
  puVar8 = extraout_ECX;
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

