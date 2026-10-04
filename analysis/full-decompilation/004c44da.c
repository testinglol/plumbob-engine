
void FUN_004c44da(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  short sVar10;
  int extraout_ECX;
  int iVar11;
  int unaff_EBP;
  int iVar12;
  int iVar13;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(unaff_EBP + 0x10);
  *(undefined1 *)(unaff_EBP + -0x16) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if ((*(int *)(extraout_ECX + 0x10) == 0) || (*(char *)(extraout_ECX + 0x1c) == '\0')) {
LAB_004c4533:
    *(undefined1 *)(unaff_EBP + -0xd) = 0;
  }
  else {
    *(undefined1 **)(unaff_EBP + -0x1c) = &stack0xffffffc0;
    iVar7 = FUN_00486420();
    if (iVar7 != 0) goto LAB_004c4533;
    *(undefined1 *)(unaff_EBP + -0xd) = 1;
  }
  pbVar3 = *(byte **)(unaff_EBP + 0x1c);
  if (*(int **)(extraout_ECX + 0x18) != (int *)0x0) {
    (**(code **)(**(int **)(extraout_ECX + 0x18) + 0x14))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  }
  if (*(char *)(unaff_EBP + -0xd) != '\0') {
    (**(code **)(**(int **)(extraout_ECX + 0x10) + 0x14))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  }
  if (*(char *)(extraout_ECX + 0x1d) != '\0') {
    if ((((*(int *)(DAT_006e54d8 + 0x70) + 1 <= (int)*(char *)(unaff_EBP + 0xc)) &&
         ((int)*(char *)(unaff_EBP + 0xc) <= *(int *)(DAT_006e54d8 + 0x74) + -1)) &&
        (*(int *)(DAT_006e54d8 + 0x78) + 1 <= (int)*(char *)(unaff_EBP + 0x10))) &&
       ((int)*(char *)(unaff_EBP + 0x10) <= *(int *)(DAT_006e54d8 + 0x7c) + -1)) {
      bVar1 = pbVar3[1];
      bVar2 = pbVar3[3];
      *(undefined1 *)(unaff_EBP + 0x1f) = 0;
      if ((uint)bVar2 <= bVar1 + 5) {
        iVar12 = *(int *)(unaff_EBP + 0x20);
        iVar8 = 8 << ((byte)iVar12 & 0x1f);
        iVar7 = *(int *)(unaff_EBP + 0x14);
        iVar13 = iVar7 - iVar8;
        bVar9 = (byte)iVar12 + 1;
        *(int *)(unaff_EBP + 0x14) = iVar13;
        *(int *)(unaff_EBP + -0x2c) = iVar13;
        *(int *)(unaff_EBP + -0x24) = iVar8 + iVar7;
        bVar2 = pbVar3[2];
        iVar7 = *(int *)(unaff_EBP + 0x18) - ((uint)bVar1 << (bVar9 & 0x1f));
        *(int *)(unaff_EBP + -0x28) = iVar7;
        *(int *)(unaff_EBP + -0x20) = iVar7;
        iVar8 = *(int *)(unaff_EBP + 0x18) - (bVar2 - 2 << (bVar9 & 0x1f));
        if (iVar8 < iVar7) {
          *(int *)(unaff_EBP + -0x28) = iVar8;
          iVar7 = iVar8;
        }
        if (*(int *)(unaff_EBP + -0x20) < iVar8) {
          *(int *)(unaff_EBP + -0x20) = iVar8;
        }
        iVar8 = *(int *)(unaff_EBP + 0x18) - (*pbVar3 - 2 << (bVar9 & 0x1f));
        if (iVar8 < iVar7) {
          *(int *)(unaff_EBP + -0x28) = iVar8;
          iVar7 = iVar8;
        }
        if (*(int *)(unaff_EBP + -0x20) < iVar8) {
          *(int *)(unaff_EBP + -0x20) = iVar8;
        }
        iVar8 = *(int *)(unaff_EBP + 0x18) - (pbVar3[3] - 4 << (bVar9 & 0x1f));
        if (iVar8 < iVar7) {
          *(int *)(unaff_EBP + -0x28) = iVar8;
          iVar7 = iVar8;
        }
        if (*(int *)(unaff_EBP + -0x20) < iVar8) {
          *(int *)(unaff_EBP + -0x20) = iVar8;
        }
        if (*(char *)(unaff_EBP + -0xd) == '\0') {
          iVar8 = *(int *)(unaff_EBP + -0x14);
          if (*(int **)(iVar8 + 0x18) != (int *)0x0) {
            (**(code **)(**(int **)(iVar8 + 0x18) + 0x10))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),iVar12);
            iVar7 = *(int *)(unaff_EBP + -0x28);
          }
        }
        else {
          *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x2c);
          *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x24);
          *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
          iVar7 = *(int *)(unaff_EBP + -0x14);
          piVar4 = *(int **)(iVar7 + 0x18);
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 0x10))
                      (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                       *(undefined4 *)(unaff_EBP + 0x20));
          }
          (**(code **)(**(int **)(iVar7 + 0x10) + 0x10))
                    (*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 0x10),
                     *(undefined4 *)(unaff_EBP + 0x20));
          UnionRect((LPRECT)(unaff_EBP + -0x2c),(RECT *)(unaff_EBP + -0x3c),
                    (RECT *)(unaff_EBP + -0x2c));
          iVar7 = *(int *)(unaff_EBP + -0x28);
          iVar12 = *(int *)(unaff_EBP + 0x20);
          iVar8 = *(int *)(unaff_EBP + -0x14);
        }
        iVar13 = (int)DAT_006f0bc0;
        if (((iVar13 < *(int *)(unaff_EBP + -0x20)) &&
            (*(int *)(unaff_EBP + -0x2c) < (int)DAT_006f0bc6)) &&
           (((int)DAT_006f0bc2 < *(int *)(unaff_EBP + -0x24) &&
            (iVar11 = (int)DAT_006f0bc4, iVar7 < iVar11)))) {
          iVar5 = *(int *)(s_Lights_006c6278 + iVar12 * 4 + 4);
          *(int *)(unaff_EBP + -0x28) = iVar7 - iVar5;
          if (((iVar7 - iVar5 < iVar13) || (iVar11 < *(int *)(unaff_EBP + -0x20))) ||
             (((int)DAT_006f0bc6 < *(int *)(unaff_EBP + -0x24) ||
              (*(int *)(unaff_EBP + -0x2c) < (int)DAT_006f0bc2)))) {
            *(undefined1 *)(unaff_EBP + 0x1f) = 1;
          }
          *(int *)(unaff_EBP + 0x18) = *(int *)(unaff_EBP + 0x18) + (4 << ((byte)iVar12 & 0x1f));
          if (*(char *)(iVar8 + 0x1f) != '\0') {
            sVar10 = (ushort)pbVar3[1] - (ushort)*pbVar3;
            if ((5 < sVar10) || (sVar10 < -5)) goto LAB_004c480c;
            sVar10 = (ushort)pbVar3[1] - (ushort)pbVar3[2];
            if ((5 < sVar10) || (sVar10 < -5)) goto LAB_004c480c;
            sVar10 = (ushort)pbVar3[3] - (ushort)*pbVar3;
            if ((((5 < sVar10) || (sVar10 < -5)) ||
                (sVar10 = (ushort)pbVar3[3] - (ushort)pbVar3[2], 5 < sVar10)) || (sVar10 < -5))
            goto LAB_004c480c;
            iVar8 = *(int *)(unaff_EBP + -0x14);
          }
          cVar6 = FUN_004b465e();
          if (cVar6 != '\0') {
            piVar4 = *(int **)(iVar8 + 0x18);
            if (*(char *)(unaff_EBP + 0x1f) == '\0') {
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 0x18))
                          (*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                           pbVar3);
              }
              if (*(char *)(unaff_EBP + -0xd) != '\0') {
                (**(code **)(**(int **)(iVar8 + 0x10) + 0x18))
                          (*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                           pbVar3);
              }
            }
            else {
              if (piVar4 != (int *)0x0) {
                (**(code **)(*piVar4 + 0x1c))
                          (*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                           pbVar3);
              }
              if (*(char *)(unaff_EBP + -0xd) != '\0') {
                (**(code **)(**(int **)(iVar8 + 0x10) + 0x1c))
                          (*(undefined4 *)(unaff_EBP + 0x14),*(undefined4 *)(unaff_EBP + 0x18),
                           pbVar3);
              }
            }
          }
        }
      }
    }
  }
LAB_004c480c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

