
undefined4 FUN_00461f92(void)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  byte *pbVar7;
  char cVar8;
  int extraout_ECX;
  int iVar9;
  char cVar10;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar4 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + 8) = *puVar4;
  uVar1 = puVar4[1];
  uVar2 = puVar4[2];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined1 *)(unaff_EBP + 9) = uVar1;
  *(undefined1 *)(unaff_EBP + 10) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    FUN_00434ffd(-*(int *)(DAT_006e54d8 + 0x84) & 3);
  }
  if (-1 < *(char *)(unaff_EBP + 8)) {
    iVar9 = *(int *)(DAT_006e54dc + 0x10);
    if (((*(char *)(unaff_EBP + 8) < iVar9) && (-1 < *(char *)(unaff_EBP + 9))) &&
       (*(char *)(unaff_EBP + 9) < iVar9)) {
      iVar5 = *(int *)(extraout_ECX + 0x10);
      *(uint *)(unaff_EBP + -0x14) =
           (uint)*(byte *)(*(int *)(iVar5 + *(char *)(unaff_EBP + 8) * 4) +
                          (int)*(char *)(unaff_EBP + 9));
      pbVar7 = &DAT_006e5250;
      do {
        if (((uint)*pbVar7 & *(uint *)(unaff_EBP + -0x14)) == (uint)*pbVar7) {
          cVar8 = pbVar7[1] + *(char *)(unaff_EBP + 8);
          cVar10 = pbVar7[2] + *(char *)(unaff_EBP + 9);
          if ((((-1 < cVar8) && (cVar8 < iVar9)) &&
              ((-1 < cVar10 &&
               ((cVar10 < iVar9 &&
                (bVar3 = *(byte *)(*(int *)(iVar5 + cVar8 * 4) + (int)cVar10),
                (pbVar7[3] & bVar3) == 0)))))) && ((pbVar7[4] & bVar3) != 0)) {
            cVar8 = pbVar7[5] + *(char *)(unaff_EBP + 8);
            cVar10 = pbVar7[6] + *(char *)(unaff_EBP + 9);
            if (((((-1 < cVar8) && (cVar8 < iVar9)) && (-1 < cVar10)) &&
                ((cVar10 < iVar9 &&
                 (bVar3 = *(byte *)(*(int *)(iVar5 + cVar8 * 4) + (int)cVar10),
                 (pbVar7[7] & bVar3) == 0)))) && ((pbVar7[8] & bVar3) != 0)) {
              *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | (uint)pbVar7[9];
            }
          }
        }
        pbVar7 = pbVar7 + 10;
      } while ((int)pbVar7 < 0x6e5278);
      iVar9 = *(int *)(unaff_EBP + 0xc);
      if ((iVar9 != 0) && (0 < iVar9)) {
        do {
          bVar3 = *(byte *)(unaff_EBP + -0x10);
          *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) >> 1;
          if ((bVar3 & 1) != 0) {
            *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) | 8;
          }
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
      }
      uVar6 = *(undefined4 *)(unaff_EBP + -0x10);
      goto LAB_004620d1;
    }
  }
  uVar6 = 0;
LAB_004620d1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

