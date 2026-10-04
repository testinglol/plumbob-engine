
void FUN_005a5e80(undefined2 *param_1,undefined2 *param_2,undefined8 *param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  short sVar6;
  short sVar12;
  short sVar13;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  short sVar14;
  short sVar18;
  short sVar19;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  short sVar20;
  short sVar23;
  short sVar24;
  undefined8 uVar21;
  undefined8 uVar22;
  short sVar25;
  short sVar28;
  short sVar29;
  undefined8 uVar26;
  undefined8 uVar27;
  
  uVar16 = DAT_00707228;
  uVar8 = DAT_00707220;
  uVar7 = param_3[7];
  uVar15 = param_3[6];
  uVar10 = param_3[5];
  uVar11 = param_3[4];
  uVar9 = *param_3;
  uVar17 = param_3[1];
  uVar4 = param_3[2];
  uVar5 = param_3[3];
  sVar6 = (short)((ulonglong)uVar7 >> 0x30);
  sVar12 = (short)((ulonglong)uVar7 >> 0x20);
  sVar13 = (short)((ulonglong)uVar7 >> 0x10);
  uVar2 = CONCAT26((short)((ulonglong)uVar9 >> 0x30) - (short)uVar7,
                   CONCAT24((short)((ulonglong)uVar9 >> 0x20) - sVar13,
                            CONCAT22((short)((ulonglong)uVar9 >> 0x10) - sVar12,(short)uVar9 - sVar6
                                    )));
  sVar14 = (short)((ulonglong)uVar15 >> 0x30);
  sVar18 = (short)((ulonglong)uVar15 >> 0x20);
  sVar19 = (short)((ulonglong)uVar15 >> 0x10);
  uVar3 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) - (short)uVar15,
                   CONCAT24((short)((ulonglong)uVar17 >> 0x20) - sVar19,
                            CONCAT22((short)((ulonglong)uVar17 >> 0x10) - sVar18,
                                     (short)uVar17 - sVar14)));
  sVar20 = (short)((ulonglong)uVar10 >> 0x30);
  sVar23 = (short)((ulonglong)uVar10 >> 0x20);
  sVar24 = (short)((ulonglong)uVar10 >> 0x10);
  uVar4 = CONCAT26((short)((ulonglong)uVar4 >> 0x30) - (short)uVar10,
                   CONCAT24((short)((ulonglong)uVar4 >> 0x20) - sVar24,
                            CONCAT22((short)((ulonglong)uVar4 >> 0x10) - sVar23,
                                     (short)uVar4 - sVar20)));
  sVar25 = (short)((ulonglong)uVar11 >> 0x30);
  sVar28 = (short)((ulonglong)uVar11 >> 0x20);
  sVar29 = (short)((ulonglong)uVar11 >> 0x10);
  uVar5 = CONCAT26((short)((ulonglong)uVar5 >> 0x30) - (short)uVar11,
                   CONCAT24((short)((ulonglong)uVar5 >> 0x20) - sVar29,
                            CONCAT22((short)((ulonglong)uVar5 >> 0x10) - sVar28,
                                     (short)uVar5 - sVar25)));
  uVar9 = *param_3;
  uVar17 = param_3[1];
  uVar9 = CONCAT26((short)((ulonglong)uVar9 >> 0x30) + (short)uVar7,
                   CONCAT24((short)((ulonglong)uVar9 >> 0x20) + sVar13,
                            CONCAT22((short)((ulonglong)uVar9 >> 0x10) + sVar12,(short)uVar9 + sVar6
                                    )));
  uVar7 = param_3[2];
  uVar17 = CONCAT26((short)((ulonglong)uVar17 >> 0x30) + (short)uVar15,
                    CONCAT24((short)((ulonglong)uVar17 >> 0x20) + sVar19,
                             CONCAT22((short)((ulonglong)uVar17 >> 0x10) + sVar18,
                                      (short)uVar17 + sVar14)));
  uVar15 = param_3[3];
  uVar10 = CONCAT26((short)((ulonglong)uVar7 >> 0x30) + (short)uVar10,
                    CONCAT24((short)((ulonglong)uVar7 >> 0x20) + sVar24,
                             CONCAT22((short)((ulonglong)uVar7 >> 0x10) + sVar23,
                                      (short)uVar7 + sVar20)));
  uVar11 = CONCAT26((short)((ulonglong)uVar15 >> 0x30) + (short)uVar11,
                    CONCAT24((short)((ulonglong)uVar15 >> 0x20) + sVar29,
                             CONCAT22((short)((ulonglong)uVar15 >> 0x10) + sVar28,
                                      (short)uVar15 + sVar25)));
  uVar7 = pmaddwd(DAT_00707200,uVar9);
  uVar15 = pmaddwd(DAT_00707208,uVar17);
  uVar21 = pmaddwd(DAT_00707210,uVar10);
  uVar26 = pmaddwd(DAT_00707218,uVar11);
  param_1[0x100] =
       (short)((int)((ulonglong)uVar21 >> 0x20) + (int)((ulonglong)uVar7 >> 0x20) +
               (int)((ulonglong)uVar26 >> 0x20) + (int)((ulonglong)uVar15 >> 0x20) +
               (int)uVar21 + (int)uVar7 + (int)uVar26 + (int)uVar15 >> 0xe);
  uVar7 = DAT_00707258;
  uVar15 = pmaddwd(uVar8,uVar9);
  uVar16 = pmaddwd(uVar16,uVar17);
  uVar26 = pmaddwd(DAT_00707230,uVar10);
  uVar27 = pmaddwd(DAT_00707238,uVar11);
  uVar8 = pmaddwd(DAT_00707240,uVar9);
  uVar21 = pmaddwd(DAT_00707248,uVar17);
  uVar22 = pmaddwd(DAT_00707250,uVar10);
  param_1[0xe0] =
       (short)((int)((ulonglong)uVar26 >> 0x20) + (int)((ulonglong)uVar15 >> 0x20) +
               (int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)uVar26 + (int)uVar15 + (int)uVar27 + (int)uVar16 >> 0xe);
  uVar15 = DAT_00707278;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_00707260,uVar9);
  uVar26 = pmaddwd(DAT_00707268,uVar17);
  uVar27 = pmaddwd(DAT_00707270,uVar10);
  param_1[0xc0] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_00707298;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_00707280,uVar9);
  uVar21 = pmaddwd(DAT_00707288,uVar17);
  uVar22 = pmaddwd(DAT_00707290,uVar10);
  param_1[0xa0] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_007072b8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_007072a0,uVar9);
  uVar26 = pmaddwd(DAT_007072a8,uVar17);
  uVar27 = pmaddwd(DAT_007072b0,uVar10);
  param_1[0x80] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_007072d8;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_007072c0,uVar9);
  uVar21 = pmaddwd(DAT_007072c8,uVar17);
  uVar22 = pmaddwd(DAT_007072d0,uVar10);
  param_1[0x60] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_007072f8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_007072e0,uVar9);
  uVar26 = pmaddwd(DAT_007072e8,uVar17);
  uVar27 = pmaddwd(DAT_007072f0,uVar10);
  param_1[0x40] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_00707318;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_00707300,uVar9);
  uVar21 = pmaddwd(DAT_00707308,uVar17);
  uVar22 = pmaddwd(DAT_00707310,uVar10);
  param_1[0x20] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_00707338;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_00707320,uVar9);
  uVar26 = pmaddwd(DAT_00707328,uVar17);
  uVar27 = pmaddwd(DAT_00707330,uVar10);
  uVar1 = (undefined2)
          ((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
           (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
           (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  *param_1 = uVar1;
  uVar15 = pmaddwd(uVar15,uVar11);
  *param_2 = uVar1;
  uVar7 = DAT_00707358;
  uVar8 = pmaddwd(DAT_00707340,uVar9);
  uVar21 = pmaddwd(DAT_00707348,uVar17);
  uVar22 = pmaddwd(DAT_00707350,uVar10);
  param_2[0x20] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_00707378;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_00707360,uVar9);
  uVar26 = pmaddwd(DAT_00707368,uVar17);
  uVar27 = pmaddwd(DAT_00707370,uVar10);
  param_2[0x40] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_00707398;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_00707380,uVar9);
  uVar21 = pmaddwd(DAT_00707388,uVar17);
  uVar22 = pmaddwd(DAT_00707390,uVar10);
  param_2[0x60] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_007073b8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar16 = pmaddwd(DAT_007073a0,uVar9);
  uVar26 = pmaddwd(DAT_007073a8,uVar17);
  uVar27 = pmaddwd(DAT_007073b0,uVar10);
  param_2[0x80] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_007073d8;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar8 = pmaddwd(DAT_007073c0,uVar9);
  uVar21 = pmaddwd(DAT_007073c8,uVar17);
  uVar22 = pmaddwd(DAT_007073d0,uVar10);
  param_2[0xa0] =
       (short)((int)((ulonglong)uVar27 >> 0x20) + (int)((ulonglong)uVar16 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar26 >> 0x20) +
               (int)uVar27 + (int)uVar16 + (int)uVar15 + (int)uVar26 >> 0xe);
  uVar15 = DAT_007073f8;
  uVar7 = pmaddwd(uVar7,uVar11);
  uVar9 = pmaddwd(DAT_007073e0,uVar9);
  uVar17 = pmaddwd(DAT_007073e8,uVar17);
  uVar16 = pmaddwd(DAT_007073f0,uVar10);
  param_2[0xc0] =
       (short)((int)((ulonglong)uVar22 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar21 >> 0x20) +
               (int)uVar22 + (int)uVar8 + (int)uVar7 + (int)uVar21 >> 0xe);
  uVar7 = DAT_00707018;
  uVar15 = pmaddwd(uVar15,uVar11);
  uVar10 = pmaddwd(DAT_00707000,uVar2);
  uVar8 = pmaddwd(DAT_00707008,uVar3);
  uVar21 = pmaddwd(DAT_00707010,uVar4);
  param_2[0xe0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar16 + (int)uVar9 + (int)uVar15 + (int)uVar17 >> 0xe);
  uVar15 = DAT_00707038;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_00707020,uVar2);
  uVar9 = pmaddwd(DAT_00707028,uVar3);
  uVar16 = pmaddwd(DAT_00707030,uVar4);
  param_1[0xf0] =
       (short)((int)((ulonglong)uVar21 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar8 >> 0x20) +
               (int)uVar21 + (int)uVar10 + (int)uVar7 + (int)uVar8 >> 0xe);
  uVar7 = DAT_00707058;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_00707040,uVar2);
  uVar17 = pmaddwd(DAT_00707048,uVar3);
  uVar8 = pmaddwd(DAT_00707050,uVar4);
  param_1[0xd0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_00707078;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_00707060,uVar2);
  uVar9 = pmaddwd(DAT_00707068,uVar3);
  uVar16 = pmaddwd(DAT_00707070,uVar4);
  param_1[0xb0] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_00707098;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_00707080,uVar2);
  uVar17 = pmaddwd(DAT_00707088,uVar3);
  uVar8 = pmaddwd(DAT_00707090,uVar4);
  param_1[0x90] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_007070b8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_007070a0,uVar2);
  uVar9 = pmaddwd(DAT_007070a8,uVar3);
  uVar16 = pmaddwd(DAT_007070b0,uVar4);
  param_1[0x70] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_007070d8;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_007070c0,uVar2);
  uVar17 = pmaddwd(DAT_007070c8,uVar3);
  uVar8 = pmaddwd(DAT_007070d0,uVar4);
  param_1[0x50] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_007070f8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_007070e0,uVar2);
  uVar9 = pmaddwd(DAT_007070e8,uVar3);
  uVar16 = pmaddwd(DAT_007070f0,uVar4);
  param_1[0x30] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_00707118;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_00707100,uVar2);
  uVar17 = pmaddwd(DAT_00707108,uVar3);
  uVar8 = pmaddwd(DAT_00707110,uVar4);
  param_1[0x10] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_00707138;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_00707120,uVar2);
  uVar9 = pmaddwd(DAT_00707128,uVar3);
  uVar16 = pmaddwd(DAT_00707130,uVar4);
  param_2[0x10] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_00707158;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_00707140,uVar2);
  uVar17 = pmaddwd(DAT_00707148,uVar3);
  uVar8 = pmaddwd(DAT_00707150,uVar4);
  param_2[0x30] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_00707178;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_00707160,uVar2);
  uVar9 = pmaddwd(DAT_00707168,uVar3);
  uVar16 = pmaddwd(DAT_00707170,uVar4);
  param_2[0x50] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_00707198;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_00707180,uVar2);
  uVar17 = pmaddwd(DAT_00707188,uVar3);
  uVar8 = pmaddwd(DAT_00707190,uVar4);
  param_2[0x70] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_007071b8;
  uVar7 = pmaddwd(uVar7,uVar5);
  uVar11 = pmaddwd(DAT_007071a0,uVar2);
  uVar9 = pmaddwd(DAT_007071a8,uVar3);
  uVar16 = pmaddwd(DAT_007071b0,uVar4);
  param_2[0x90] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar7 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar7 + (int)uVar17 >> 0xe);
  uVar7 = DAT_007071d8;
  uVar15 = pmaddwd(uVar15,uVar5);
  uVar10 = pmaddwd(DAT_007071c0,uVar2);
  uVar17 = pmaddwd(DAT_007071c8,uVar3);
  uVar8 = pmaddwd(DAT_007071d0,uVar4);
  param_2[0xb0] =
       (short)((int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar9 >> 0x20) +
               (int)uVar16 + (int)uVar11 + (int)uVar15 + (int)uVar9 >> 0xe);
  uVar15 = DAT_007071f8;
  uVar16 = pmaddwd(uVar7,uVar5);
  uVar7 = pmaddwd(DAT_007071e0,uVar2);
  uVar11 = pmaddwd(DAT_007071e8,uVar3);
  uVar9 = pmaddwd(DAT_007071f0,uVar4);
  param_2[0xd0] =
       (short)((int)((ulonglong)uVar8 >> 0x20) + (int)((ulonglong)uVar10 >> 0x20) +
               (int)((ulonglong)uVar16 >> 0x20) + (int)((ulonglong)uVar17 >> 0x20) +
               (int)uVar8 + (int)uVar10 + (int)uVar16 + (int)uVar17 >> 0xe);
  uVar15 = pmaddwd(uVar15,uVar5);
  param_2[0xf0] =
       (short)((int)((ulonglong)uVar9 >> 0x20) + (int)((ulonglong)uVar7 >> 0x20) +
               (int)((ulonglong)uVar15 >> 0x20) + (int)((ulonglong)uVar11 >> 0x20) +
               (int)uVar9 + (int)uVar7 + (int)uVar15 + (int)uVar11 >> 0xe);
  return;
}

