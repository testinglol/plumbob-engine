
void FUN_004a4bac(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int extraout_ECX;
  int iVar8;
  int iVar9;
  int iVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  float10 fVar12;
  
  FUN_00634c24();
  FUN_004c49d3();
  fVar12 = (float10)FUN_00637084((double)*(float *)(extraout_ECX + 0x44));
  *(float *)(unaff_EBP + -0x14) = (float)fVar12;
  fVar12 = (float10)FUN_00636d14((double)*(float *)(extraout_ECX + 0x44));
  *(double *)(unaff_EBP + -0x30) = (double)fVar12;
  fVar12 = (float10)FUN_00636d14((double)*(float *)(extraout_ECX + 0x40));
  *(float *)(unaff_EBP + -0x24) = (float)-(fVar12 * (float10)*(double *)(unaff_EBP + -0x30));
  fVar12 = (float10)FUN_00636d14((double)*(float *)(extraout_ECX + 0x44));
  *(double *)(unaff_EBP + -0x30) = (double)fVar12;
  fVar12 = (float10)FUN_00637084((double)*(float *)(extraout_ECX + 0x40));
  *(undefined4 *)(unaff_EBP + -0x38) = *(undefined4 *)(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -0x34) = *(undefined4 *)(unaff_EBP + -0x14);
  *(float *)(unaff_EBP + -0x3c) = (float)(fVar12 * (float10)*(double *)(unaff_EBP + -0x30));
  FUN_004c49de();
  iVar10 = *(int *)(DAT_006e54d8 + 0x10);
  uVar5 = FUN_0046f546();
  *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
  FUN_0046f54c();
  iVar8 = *(int *)(extraout_ECX + 8);
  *(int *)(unaff_EBP + -0x24) = iVar8;
  *(undefined4 *)(unaff_EBP + -0x1c) = 1;
  if (1 < iVar10) {
    *(int *)(unaff_EBP + -0x20) = iVar8 + 4;
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      puVar7 = (undefined4 *)**(undefined4 **)(unaff_EBP + -0x20);
      do {
        puVar7 = puVar7 + 1;
        bVar4 = FUN_004a499b(unaff_EBP + -0x288,*(undefined4 *)(unaff_EBP + -0x1c));
        *(byte *)(unaff_EBP + -0xf) = bVar4;
        if (((int)(uint)bVar4 < *(int *)(extraout_ECX + 0x38)) ||
           (*(int *)(extraout_ECX + 0x3c) < (int)(uint)bVar4)) {
          *(undefined1 *)(unaff_EBP + -0xf) = 0;
        }
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        *puVar7 = *(undefined4 *)(unaff_EBP + -0x10);
      } while (*(int *)(unaff_EBP + -0x18) < iVar10);
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 4;
    } while (*(int *)(unaff_EBP + -0x1c) < iVar10);
    iVar8 = *(int *)(unaff_EBP + -0x24);
  }
  FUN_0046f54c();
  iVar9 = *(int *)(DAT_006e54d8 + 0x10);
  iVar10 = iVar9 + -1;
  *(int *)(unaff_EBP + -0x20) = iVar10;
  if (1 < iVar10) {
    piVar6 = (int *)(iVar8 + 4);
    *(int *)(unaff_EBP + -0x28) = iVar9 + -2;
    do {
      iVar10 = *piVar6;
      iVar8 = 1;
      *(int **)(unaff_EBP + -0x14) = piVar6 + 1;
      do {
        iVar9 = iVar8 * 4;
        *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar10 + iVar8 * 4);
        *(undefined1 *)(unaff_EBP + -0x10) = *(undefined1 *)(iVar10 + 5 + iVar8 * 4);
        iVar2 = **(int **)(unaff_EBP + -0x14) + iVar8 * 4;
        iVar8 = iVar8 + 1;
        iVar3 = *(int *)(unaff_EBP + -0x20);
        *(undefined1 *)(unaff_EBP + -0xe) = *(undefined1 *)(iVar2 + 1);
        *(undefined1 *)(unaff_EBP + -0xd) = *(undefined1 *)(iVar2 + 5);
        *(undefined4 *)(iVar10 + iVar9) = *(undefined4 *)(unaff_EBP + -0x10);
      } while (iVar8 < iVar3);
      piVar1 = (int *)(unaff_EBP + -0x28);
      *piVar1 = *piVar1 + -1;
      piVar6 = *(int **)(unaff_EBP + -0x14);
    } while (*piVar1 != 0);
    iVar8 = *(int *)(unaff_EBP + -0x24);
  }
  iVar10 = *(int *)(DAT_006e54d8 + 0x10);
  *(int *)(unaff_EBP + -0x20) = iVar10;
  puVar7 = (undefined4 *)(unaff_EBP + -0x68);
  for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  if (0 < iVar10) {
    *(int *)(unaff_EBP + -0x14) = iVar8;
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined1 *)(unaff_EBP + -0x22) = 1;
      *(undefined4 *)(unaff_EBP + -0x28) = **(undefined4 **)(unaff_EBP + -0x14);
      do {
        *(undefined4 *)(unaff_EBP + -0x10) = **(undefined4 **)(unaff_EBP + -0x28);
        iVar10 = DAT_006e54d8;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        uVar5 = *(undefined4 *)(iVar10 + 0x70);
        *(char *)(unaff_EBP + -0x23) =
             (char)*(undefined4 *)(iVar10 + 0x78) + *(char *)(unaff_EBP + -0x18);
        *(char *)(unaff_EBP + -0x24) = (char)uVar5 + *(char *)(unaff_EBP + -0x1c);
        *(undefined1 **)(unaff_EBP + -0x2c) = &stack0xfffffd74;
        puVar7 = (undefined4 *)FUN_00467768(unaff_EBP + -0x94);
        puVar11 = (undefined4 *)(unaff_EBP + -0x68);
        for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar11 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar11 = puVar11 + 1;
        }
        if (((byte)*(undefined4 *)(unaff_EBP + -0x68) & 2) == 2) {
          iVar10 = *(int *)(extraout_ECX + 0x3c);
          iVar8 = *(byte *)(unaff_EBP + -0xf) + 0x40;
          if (iVar10 < iVar8) {
            iVar8 = iVar10;
          }
          *(char *)(unaff_EBP + -0xf) = (char)iVar8;
          iVar8 = *(byte *)(unaff_EBP + -0xe) + 0x40;
          if (iVar10 < iVar8) {
            iVar8 = iVar10;
          }
          *(char *)(unaff_EBP + -0xe) = (char)iVar8;
          **(undefined4 **)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0x10);
        }
        if ((*(byte *)(unaff_EBP + -0x40) & 0x10) != 0) {
          puVar7 = (undefined4 *)(unaff_EBP + -0x68);
          for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
            *puVar7 = 0;
            puVar7 = puVar7 + 1;
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 4;
      } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x20));
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 1;
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    } while (*(int *)(unaff_EBP + -0x1c) < *(int *)(unaff_EBP + -0x20));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

