
void __thiscall FUN_0062f99c(int param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined8 *puVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined8 uVar15;
  int local_14;
  undefined2 *local_10;
  int local_c;
  
  local_14 = 0;
  bVar2 = *(char *)(param_1 + 0x4a0c) - 1U & 0xf;
  *(byte *)(param_1 + 0x4a0c) = bVar2;
  uVar6 = bVar2 & 1;
  iVar1 = (uint)bVar2 + (uVar6 ^ 1);
  if (0 < *(int *)(param_1 + 0x4a40)) {
    local_10 = param_2;
    local_c = param_3;
    param_3 = param_1 + 4;
    iVar7 = (uVar6 ^ 1) * 0x240;
    iVar3 = iVar7 + 4 + iVar1 * 2 + param_1;
    do {
      puVar5 = (undefined8 *)(param_3 + iVar7);
      FUN_005a5e80(param_3 + ((*(byte *)(param_1 + 0x4a0c) + uVar6 & 0xf) + uVar6 * 0x120) * 2,iVar3
                   ,local_c);
      if (param_2 != (undefined2 *)0x0) {
        if (*(int *)(param_1 + 0x4a40) == 2) {
          iVar4 = iVar1 * 0x220;
          uVar8 = pmaddwd(*puVar5,*(undefined8 *)(&DAT_00701748 + iVar4));
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701750 + iVar4),puVar5[1]);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701758 + iVar4),puVar5[2]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701760 + iVar4),puVar5[3]);
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00701768 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00701770 + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701778 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701780 + iVar4),puVar5[7]);
          *local_10 = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00701788 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701790 + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701798 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007017a0 + iVar4),puVar5[0xb]);
          local_10[2] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_007017a8 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_007017b0 + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007017b8 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007017c0 + iVar4),puVar5[0xf]);
          local_10[4] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_007017c8 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_007017d0 + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007017d8 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007017e0 + iVar4),puVar5[0x13]);
          local_10[6] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_007017e8 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_007017f0 + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007017f8 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701800 + iVar4),puVar5[0x17]);
          local_10[8] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00701808 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701810 + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701818 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701820 + iVar4),puVar5[0x1b]);
          local_10[10] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00701828 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00701830 + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701838 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701840 + iVar4),puVar5[0x1f]);
          local_10[0xc] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00701848 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701850 + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701858 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701860 + iVar4),puVar5[0x23]);
          local_10[0xe] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00701868 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00701870 + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701878 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701880 + iVar4),puVar5[0x27]);
          local_10[0x10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00701888 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701890 + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701898 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007018a0 + iVar4),puVar5[0x2b]);
          local_10[0x12] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_007018a8 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_007018b0 + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007018b8 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007018c0 + iVar4),puVar5[0x2f]);
          local_10[0x14] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_007018c8 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_007018d0 + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007018d8 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_007018e0 + iVar4),puVar5[0x33]);
          local_10[0x16] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_007018e8 + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_007018f0 + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_007018f8 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701900 + iVar4),puVar5[0x37]);
          local_10[0x18] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00701908 + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00701910 + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701918 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701920 + iVar4),puVar5[0x3b]);
          local_10[0x1a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00701928 + iVar4),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00701930 + iVar4),puVar5[0x3d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00701938 + iVar4),puVar5[0x3e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00701940 + iVar4),puVar5[0x3f]);
          local_10[0x1c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmulhw(*(undefined8 *)(&DAT_00701948 + iVar4),puVar5[0x40]);
          uVar11 = pmulhw(*(undefined8 *)(&DAT_00701950 + iVar4),puVar5[0x41]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmulhw(*(undefined8 *)(&DAT_00701958 + iVar4),puVar5[0x42]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar15 = pmulhw(*(undefined8 *)(&DAT_00701960 + iVar4),puVar5[0x43]);
          iVar4 = iVar1 * 0x1e0;
          local_10[0x1e] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar11 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar13 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar15 >> 0x20) * 0x10000;
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ff948 + iVar1 * 0x78),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ff950 + iVar4),puVar5[0x3d]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ff958 + iVar4),puVar5[0x3e]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 * 0x10000 + (int)uVar11 * 0x10000 + (int)uVar13 * 0x10000 +
                           (int)uVar15 * 0x10000 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff960 + iVar4),puVar5[0x3f]);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x20] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar14 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ff968 + iVar1 * 0x78),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ff970 + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar14 + (int)uVar13 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff978 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ff980 + iVar4),puVar5[0x3b]);
          local_10[0x22] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ff988 + iVar1 * 0x78),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ff990 + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff998 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ff9a0 + iVar4),puVar5[0x37]);
          local_10[0x24] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ff9a8 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ff9b0 + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff9b8 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ff9c0 + iVar4),puVar5[0x33]);
          local_10[0x26] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ff9c8 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ff9d0 + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff9d8 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ff9e0 + iVar4),puVar5[0x2f]);
          local_10[0x28] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ff9e8 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ff9f0 + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ff9f8 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffa00 + iVar4),puVar5[0x2b]);
          local_10[0x2a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ffa08 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ffa10 + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffa18 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffa20 + iVar4),puVar5[0x27]);
          local_10[0x2c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ffa28 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ffa30 + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffa38 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffa40 + iVar4),puVar5[0x23]);
          local_10[0x2e] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ffa48 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ffa50 + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffa58 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffa60 + iVar4),puVar5[0x1f]);
          local_10[0x30] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ffa68 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ffa70 + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffa78 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffa80 + iVar4),puVar5[0x1b]);
          local_10[0x32] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ffa88 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ffa90 + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffa98 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffaa0 + iVar4),puVar5[0x17]);
          local_10[0x34] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ffaa8 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ffab0 + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffab8 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffac0 + iVar4),puVar5[0x13]);
          local_10[0x36] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ffac8 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ffad0 + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffad8 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffae0 + iVar4),puVar5[0xf]);
          local_10[0x38] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006ffae8 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ffaf0 + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffaf8 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006ffb00 + iVar4),puVar5[0xb]);
          local_10[0x3a] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006ffb08 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006ffb10 + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006ffb18 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006ffb20 + iVar4),puVar5[7]);
          local_10[0x3c] = (short)uVar8;
          iVar4 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar11 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = CONCAT44(iVar4 >> 0xd,
                           (int)uVar10 + (int)uVar12 + (int)uVar11 + (int)uVar13 + iVar4 >> 0xd);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x3e] = (short)uVar8;
        }
        else {
          iVar4 = iVar1 * -2;
          uVar8 = pmaddwd(*puVar5,*(undefined8 *)((int)&DAT_006882a2 + iVar4 + 2));
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_006882ac + iVar4),puVar5[1]);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006882b4 + iVar4),puVar5[2]);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006882bc + iVar4),puVar5[3]);
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)((int)&DAT_006882e4 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_006882ec + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006882f4 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006882fc + iVar4),puVar5[7]);
          *local_10 = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_00688324 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_0068832c + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688334 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068833c + iVar4),puVar5[0xb]);
          local_10[1] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_00688364 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_0068836c + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688374 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068837c + iVar4),puVar5[0xf]);
          local_10[2] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_006883a4 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_006883ac + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006883b4 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006883bc + iVar4),puVar5[0x13]);
          local_10[3] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_006883e4 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_006883ec + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006883f4 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006883fc + iVar4),puVar5[0x17]);
          local_10[4] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_00688424 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_0068842c + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688434 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068843c + iVar4),puVar5[0x1b]);
          local_10[5] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_00688464 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_0068846c + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688474 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068847c + iVar4),puVar5[0x1f]);
          local_10[6] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_006884a4 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_006884ac + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006884b4 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006884bc + iVar4),puVar5[0x23]);
          local_10[7] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_006884e4 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_006884ec + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006884f4 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006884fc + iVar4),puVar5[0x27]);
          local_10[8] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_00688524 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_0068852c + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688534 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068853c + iVar4),puVar5[0x2b]);
          local_10[9] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_00688564 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_0068856c + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688574 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068857c + iVar4),puVar5[0x2f]);
          local_10[10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_006885a4 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_006885ac + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006885b4 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006885bc + iVar4),puVar5[0x33]);
          local_10[0xb] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_006885e4 + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_006885ec + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_006885f4 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_006885fc + iVar4),puVar5[0x37]);
          local_10[0xc] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&UNK_00688624 + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&UNK_0068862c + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688634 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068863c + iVar4),puVar5[0x3b]);
          local_10[0xd] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&UNK_00688664 + iVar4),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&UNK_0068866c + iVar4),puVar5[0x3d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&UNK_00688674 + iVar4),puVar5[0x3e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&UNK_0068867c + iVar4),puVar5[0x3f]);
          local_10[0xe] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmulhw(*(undefined8 *)(&UNK_006886a4 + iVar4),puVar5[0x40]);
          uVar11 = pmulhw(*(undefined8 *)(&UNK_006886ac + iVar4),puVar5[0x41]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmulhw(*(undefined8 *)(&UNK_006886b4 + iVar4),puVar5[0x42]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar15 = pmulhw(*(undefined8 *)(&UNK_006886bc + iVar4),puVar5[0x43]);
          local_10[0xf] = (short)uVar10;
          iVar4 = iVar1 * -2;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar11 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar13 >> 0x20) * 0x10000 +
                  (int)((ulonglong)uVar15 >> 0x20) * 0x10000;
          uVar10 = pmaddwd(*(undefined8 *)((int)&DAT_00687ea2 + iVar4 + 2),puVar5[0x3c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00687eac + iVar4),puVar5[0x3d]);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687eb4 + iVar4),puVar5[0x3e]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 * 0x10000 + (int)uVar11 * 0x10000 + (int)uVar13 * 0x10000 +
                           (int)uVar15 * 0x10000 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687ebc + iVar4),puVar5[0x3f]);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x10] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar14 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)((int)&DAT_00687ee4 + iVar4),puVar5[0x38]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00687eec + iVar4),puVar5[0x39]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar14 + (int)uVar13 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687ef4 + iVar4),puVar5[0x3a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687efc + iVar4),puVar5[0x3b]);
          local_10[0x11] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00687f24 + iVar4),puVar5[0x34]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00687f2c + iVar4),puVar5[0x35]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687f34 + iVar4),puVar5[0x36]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687f3c + iVar4),puVar5[0x37]);
          local_10[0x12] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00687f64 + iVar4),puVar5[0x30]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00687f6c + iVar4),puVar5[0x31]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687f74 + iVar4),puVar5[0x32]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687f7c + iVar4),puVar5[0x33]);
          local_10[0x13] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00687fa4 + iVar4),puVar5[0x2c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_00687fac + iVar4),puVar5[0x2d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687fb4 + iVar4),puVar5[0x2e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687fbc + iVar4),puVar5[0x2f]);
          local_10[0x14] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00687fe4 + iVar4),puVar5[0x28]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00687fec + iVar4),puVar5[0x29]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00687ff4 + iVar4),puVar5[0x2a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_00687ffc + iVar4),puVar5[0x2b]);
          local_10[0x15] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00688024 + iVar4),puVar5[0x24]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_0068802c + iVar4),puVar5[0x25]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00688034 + iVar4),puVar5[0x26]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_0068803c + iVar4),puVar5[0x27]);
          local_10[0x16] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00688064 + iVar4),puVar5[0x20]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_0068806c + iVar4),puVar5[0x21]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00688074 + iVar4),puVar5[0x22]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_0068807c + iVar4),puVar5[0x23]);
          local_10[0x17] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006880a4 + iVar4),puVar5[0x1c]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006880ac + iVar4),puVar5[0x1d]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006880b4 + iVar4),puVar5[0x1e]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006880bc + iVar4),puVar5[0x1f]);
          local_10[0x18] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006880e4 + iVar4),puVar5[0x18]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006880ec + iVar4),puVar5[0x19]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006880f4 + iVar4),puVar5[0x1a]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006880fc + iVar4),puVar5[0x1b]);
          local_10[0x19] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00688124 + iVar4),puVar5[0x14]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_0068812c + iVar4),puVar5[0x15]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00688134 + iVar4),puVar5[0x16]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_0068813c + iVar4),puVar5[0x17]);
          local_10[0x1a] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_00688164 + iVar4),puVar5[0x10]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_0068816c + iVar4),puVar5[0x11]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_00688174 + iVar4),puVar5[0x12]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_0068817c + iVar4),puVar5[0x13]);
          local_10[0x1b] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_006881a4 + iVar4),puVar5[0xc]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_006881ac + iVar4),puVar5[0xd]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006881b4 + iVar4),puVar5[0xe]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006881bc + iVar4),puVar5[0xf]);
          local_10[0x1c] = (short)uVar8;
          iVar9 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar8 = pmaddwd(*(undefined8 *)(&DAT_006881e4 + iVar4),puVar5[8]);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_006881ec + iVar4),puVar5[9]);
          uVar10 = CONCAT44(iVar9 >> 0xd,
                            (int)uVar10 + (int)uVar12 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_006881f4 + iVar4),puVar5[10]);
          uVar10 = packssdw(uVar10,uVar10);
          uVar14 = pmaddwd(*(undefined8 *)(&DAT_006881fc + iVar4),puVar5[0xb]);
          local_10[0x1d] = (short)uVar10;
          iVar9 = (int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
                  (int)((ulonglong)uVar13 >> 0x20) + (int)((ulonglong)uVar14 >> 0x20);
          uVar10 = pmaddwd(*(undefined8 *)(&DAT_00688224 + iVar4),puVar5[4]);
          uVar12 = pmaddwd(*(undefined8 *)(&DAT_0068822c + iVar4),puVar5[5]);
          uVar8 = CONCAT44(iVar9 >> 0xd,
                           (int)uVar8 + (int)uVar11 + (int)uVar13 + (int)uVar14 + iVar9 >> 0xd);
          uVar11 = pmaddwd(*(undefined8 *)(&DAT_00688234 + iVar4),puVar5[6]);
          uVar8 = packssdw(uVar8,uVar8);
          uVar13 = pmaddwd(*(undefined8 *)(&DAT_0068823c + iVar4),puVar5[7]);
          local_10[0x1e] = (short)uVar8;
          iVar4 = (int)((ulonglong)uVar10 >> 0x20) + (int)((ulonglong)uVar12 >> 0x20) +
                  (int)((ulonglong)uVar11 >> 0x20) + (int)((ulonglong)uVar13 >> 0x20);
          uVar8 = CONCAT44(iVar4 >> 0xd,
                           (int)uVar10 + (int)uVar12 + (int)uVar11 + (int)uVar13 + iVar4 >> 0xd);
          uVar8 = packssdw(uVar8,uVar8);
          local_10[0x1f] = (short)uVar8;
        }
      }
      local_14 = local_14 + 1;
      local_c = local_c + 0x40;
      local_10 = local_10 + 1;
      param_3 = param_3 + 0x480;
      iVar3 = iVar3 + 0x480;
    } while (local_14 < *(int *)(param_1 + 0x4a40));
  }
  return;
}

