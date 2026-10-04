
undefined4 FUN_00422083(void)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *extraout_ECX;
  undefined4 unaff_EBX;
  uint uVar7;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  if (extraout_ECX[0x6b] != 0) {
    uVar3 = FUN_00407498((int)(short)extraout_ECX[0x71]);
    piVar5 = *(int **)(unaff_EBP + 8);
    cVar2 = (**(code **)(*(int *)extraout_ECX[0x6b] + 0x60))
                      (piVar5,*(undefined4 *)(unaff_EBP + 0xc),uVar3,
                       (int)*(short *)((int)extraout_ECX + 0x1c6));
    if (cVar2 != '\0') goto LAB_004222b6;
    if ((DAT_006e4a7c == 0xb) && (*(short *)(*(int *)(extraout_ECX[0x6b] + 0x118) + 0x14) == 0)) {
      uVar7 = CONCAT22((short)((uint)unaff_EBX >> 0x10),*(undefined2 *)(extraout_ECX[0x6b] + 0x52));
      *(char *)(unaff_EBP + -0x10) = (char)(piVar5[1] >> 4);
      *(char *)(unaff_EBP + -0xf) = (char)(*piVar5 >> 4);
      *(uint *)(unaff_EBP + -0x1c) = uVar7;
      *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(unaff_EBP + 0xc);
      puVar1 = DAT_006e486c;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_0043f371(*puVar1,unaff_EBP + -0x10,0);
      iVar6 = *(int *)(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      if (iVar6 != 0) {
        do {
          iVar8 = *(int *)(iVar6 + 0x134);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
          iVar8 = (iVar8 - *(int *)(iVar6 + 0x130)) / 0x24 + -1;
          if (0 < iVar8) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0x24;
            do {
              if ((*(int *)(unaff_EBP + -0x14) < 0x24) ||
                 ((*(int *)(iVar6 + 0x134) - *(int *)(iVar6 + 0x130)) / 0x24 + -1 <=
                  *(int *)(unaff_EBP + -0x10))) {
                iVar4 = 0;
              }
              else {
                iVar4 = *(int *)(unaff_EBP + -0x14) + *(int *)(iVar6 + 0x130);
              }
              if ((iVar4 != 0) &&
                 ((ushort)((ushort)(1 << ((char)*(undefined4 *)(iVar4 + 0x14) - 1U & 0x1f)) &
                          (ushort)*(undefined4 *)(unaff_EBP + -0x1c)) != 0)) {
                cVar2 = (**(code **)(*(int *)extraout_ECX[0x6b] + 0x60))
                                  (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
                                   iVar6,*(undefined4 *)(unaff_EBP + -0x10));
                if (cVar2 != '\0') {
                  iVar6 = *(int *)(unaff_EBP + -0x28);
                  iVar8 = 0;
                  *(undefined2 *)(extraout_ECX + 0x71) = *(undefined2 *)(iVar6 + 0xf0);
                  *(undefined2 *)((int)extraout_ECX + 0x1c6) = *(undefined2 *)(unaff_EBP + -0x10);
                  iVar4 = (int)*(short *)(iVar6 + 0x4c);
                  if (*(short *)(*(int *)(iVar6 + 0x118) + 0x14) != 0) goto LAB_0042224a;
                  goto LAB_00422299;
                }
                iVar6 = *(int *)(unaff_EBP + -0x28);
              }
              *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 0x24;
            } while (*(int *)(unaff_EBP + -0x10) < iVar8);
          }
          FUN_0043f3b9();
          iVar6 = *(int *)(unaff_EBP + -0x28);
        } while (iVar6 != 0);
        uVar7 = *(uint *)(unaff_EBP + -0x1c);
      }
      DAT_006e4a7c = 0xb;
      if (((short)uVar7 != 0) && ((uVar7 & 0xfff7) == 0)) {
        DAT_006e4a7c = 0x24;
      }
    }
  }
  uVar3 = 0;
  goto LAB_00422206;
LAB_0042224a:
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar6 + 0xf4);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar6 + 0xf8);
  piVar5 = (int *)FUN_004222bd(iVar4);
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + piVar5[1];
  *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + *piVar5;
  iVar6 = FUN_004324fc(unaff_EBP + -0x20,*(undefined4 *)(unaff_EBP + 0xc));
  if (iVar6 == 0) goto LAB_0042228a;
  iVar4 = iVar4 + 2;
  iVar8 = iVar8 + 1;
  if (3 < iVar8) goto LAB_0042228a;
  iVar6 = *(int *)(unaff_EBP + -0x28);
  goto LAB_0042224a;
LAB_0042228a:
  if (iVar8 == 4) {
    iVar4 = (int)*(short *)(extraout_ECX[0x6b] + 0x4c);
  }
LAB_00422299:
  (**(code **)(*extraout_ECX + 0x4c))
            ((iVar4 - *(short *)(extraout_ECX[0x6b] + 0x4c)) /
             (int)*(short *)(extraout_ECX[0x6b] + 0x78));
LAB_004222b6:
  uVar3 = 1;
LAB_00422206:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

