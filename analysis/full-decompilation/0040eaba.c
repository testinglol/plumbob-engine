
void FUN_0040eaba(void)

{
  int *piVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x28) = extraout_ECX;
  FUN_0046f824(unaff_EBP + -0x68,0,0x40);
  *(undefined ***)(unaff_EBP + -0x74) = &PTR_FUN_0066651c;
  FUN_0046f824(unaff_EBP + -0x100,0,0x40);
  *(undefined ***)(unaff_EBP + -0x10c) = &PTR_FUN_0066651c;
  FUN_00455edc(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x74,unaff_EBP + -0x10c,0);
  iVar8 = *(int *)(unaff_EBP + 0x10);
  if ((int)(uint)*(ushort *)(unaff_EBP + -0x6a) <= iVar8) {
    iVar8 = *(ushort *)(unaff_EBP + -0x6a) - 1;
  }
  *(short *)(unaff_EBP + -0x6c) = (short)iVar8;
  *(undefined1 *)(*(int *)(unaff_EBP + -0x70) + iVar8) = 0;
  FUN_0046f9f6();
  piVar2 = *(int **)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + -0x10) = (piVar2[1] - *piVar2) / 0x98;
  FUN_0055e4e2(unaff_EBP + 0xf);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (0 < *(int *)(unaff_EBP + -0x10)) {
    iVar8 = 0;
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x10);
    do {
      FUN_004030b4(*piVar2 + iVar8);
      iVar4 = *(int *)(unaff_EBP + 0x10);
      if (iVar4 <= (int)(uint)*(ushort *)(unaff_EBP + -0xb8)) {
        if ((int)(uint)*(ushort *)(unaff_EBP + -0xb6) <= iVar4) {
          iVar4 = *(ushort *)(unaff_EBP + -0xb6) - 1;
        }
        *(short *)(unaff_EBP + -0xb8) = (short)iVar4;
        *(undefined1 *)(*(int *)(unaff_EBP + -0xbc) + iVar4) = 0;
        pcVar3 = *(char **)(unaff_EBP + -0xbc);
        if (**(char **)(unaff_EBP + -0x70) == *pcVar3) {
          *(undefined4 *)(unaff_EBP + -0x14) = 4;
          if (4 < *(int *)(unaff_EBP + 0x10)) {
            pcVar5 = pcVar3 + 4;
            do {
              if (pcVar5[(int)*(char **)(unaff_EBP + -0x70) - (int)pcVar3] != *pcVar5) break;
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
              pcVar5 = pcVar5 + 1;
            } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + 0x10));
          }
          if (*(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + 0x10)) {
            FUN_0040f46e(*piVar2 + iVar8);
          }
        }
      }
      iVar8 = iVar8 + 0x98;
      piVar1 = (int *)(unaff_EBP + -0x18);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  FUN_0040d302();
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    uVar6 = (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24)) / 0x98;
    if (uVar6 == 0) {
      iVar8 = *piVar2;
      uVar6 = FUN_0046f556();
      iVar8 = (uVar6 % *(uint *)(unaff_EBP + -0x10)) * 0x98 + iVar8;
    }
    else {
      uVar7 = FUN_0046f556();
      iVar8 = (uVar7 % uVar6) * 0x98 + *(int *)(unaff_EBP + -0x24);
    }
    FUN_00473077(iVar8);
    FUN_0046f824(unaff_EBP + -0x2a4,0,0x100);
    *(undefined ***)(unaff_EBP + -0x2b0) = &PTR_FUN_00666524;
    FUN_00473047(unaff_EBP + -0x2b0);
    FUN_005876ac(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x2ac));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0040f5fc();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

