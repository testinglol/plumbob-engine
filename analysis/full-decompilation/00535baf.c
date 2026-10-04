
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_00535baf(void)

{
  uint *puVar1;
  float fVar2;
  undefined2 uVar3;
  int *piVar4;
  int iVar5;
  char cVar6;
  short sVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  size_t sVar15;
  undefined4 uVar16;
  int *extraout_ECX;
  int unaff_EBP;
  char *pcVar17;
  bool bVar18;
  float10 fVar19;
  undefined *puVar20;
  undefined *puVar21;
  
  FUN_00634c24();
  uVar3 = **(undefined2 **)(unaff_EBP + 8);
  *(undefined2 *)(unaff_EBP + -0x14) = (*(undefined2 **)(unaff_EBP + 8))[2];
  piVar4 = DAT_006e486c;
  *(undefined2 *)(unaff_EBP + -0x12) = uVar3;
  puVar1 = (uint *)(extraout_ECX + 0x35);
  puVar8 = (uint *)(**(code **)(*(int *)piVar4[1] + 4))();
  *puVar1 = *puVar8;
  extraout_ECX[0x36] = puVar8[1];
  iVar9 = (**(code **)(*(int *)DAT_006e486c[1] + 0x38))();
  extraout_ECX[0x37] = iVar9;
  FUN_00633aef();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar6 = FUN_004a7d04();
  if (cVar6 == '\0') {
    if ((char)extraout_ECX[0x3c] == '\0') {
      *(uint *)(unaff_EBP + -0x14) = extraout_ECX[0x36] & 0xf;
      *(uint *)(unaff_EBP + -0x18) = *puVar1 & 0xf;
      FUN_006323d0();
      FUN_006321fb();
      if (*(int *)(unaff_EBP + -0x14) != 0) {
        FUN_006323d0(&DAT_006c3d7c);
        FUN_006321fb();
      }
      FUN_006323d0();
      FUN_006321fb();
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        FUN_006323d0(&DAT_006c3d7c);
        FUN_006321fb();
      }
      FUN_006323d0();
      *(uint *)(unaff_EBP + -0x2c) = *puVar1;
      *(int *)(unaff_EBP + -0x28) = extraout_ECX[0x36];
      FUN_0047bd91(unaff_EBP + -0x28,unaff_EBP + -0x2c);
      uVar11 = *(uint *)(unaff_EBP + -0x28);
      *(uint *)(unaff_EBP + -0x18) = *(uint *)(unaff_EBP + -0x2c) & 0xf;
      FUN_006323d0();
      FUN_006321fb();
      if ((uVar11 & 0xf) != 0) {
        FUN_006323d0(&DAT_006c3d7c);
        FUN_006321fb();
      }
      FUN_006323d0();
      FUN_006321fb();
      if (*(int *)(unaff_EBP + -0x18) != 0) {
        FUN_006323d0(&DAT_006c3d7c);
        FUN_006321fb();
      }
      FUN_006323d0();
      iVar9 = extraout_ECX[0x36];
      *(char *)(unaff_EBP + -0x9a) = (char)extraout_ECX[0x37];
      iVar5 = DAT_006e54d8;
      iVar10 = extraout_ECX[0x35];
      *(undefined1 *)(unaff_EBP + -4) = 1;
      uVar16 = *(undefined4 *)(iVar5 + 0x70);
      *(int *)(unaff_EBP + -0x20) = -*(int *)(iVar5 + 0x78);
      cVar6 = (char)(iVar9 >> 4) - (char)uVar16;
      *(char *)(unaff_EBP + -0x9b) = (char)(iVar10 >> 4) + *(char *)(unaff_EBP + -0x20);
      *(char *)(unaff_EBP + -0x9c) = cVar6;
      iVar9 = (int)cVar6;
      FUN_006323d0(&DAT_006cd12c);
      FUN_006321fb(iVar9);
      FUN_006323d0();
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Level___006cd120);
      FUN_006321fb();
      FUN_006323d0();
      uVar16 = **(undefined4 **)(unaff_EBP + 8);
      FUN_006323d0(s_ScrollDep__006cd114);
      FUN_00633280(uVar16);
      FUN_006323d0();
      FUN_00633280();
      FUN_006323d0();
      iVar9 = **(int **)(unaff_EBP + 8) - DAT_006f0080;
      FUN_006323d0(s_ScrollIndep__006cd104);
      FUN_00633280(iVar9);
      FUN_006323d0();
      FUN_00633280();
      FUN_006323d0();
      iVar9 = extraout_ECX[0x35];
      *(char *)(unaff_EBP + -0x10) = (char)(extraout_ECX[0x36] >> 4);
      *(char *)(unaff_EBP + -0xf) = (char)(iVar9 >> 4);
      *(char *)(unaff_EBP + -0xe) = (char)extraout_ECX[0x37];
      *(undefined1 *)(unaff_EBP + -4) = 2;
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
      FUN_004796d9();
      uVar11 = (uint)*(byte *)(unaff_EBP + -0x32);
      uVar12 = (uint)*(byte *)(unaff_EBP + -0x33);
      puVar21 = &DAT_006c0fdc;
      uVar13 = (uint)*(byte *)(unaff_EBP + -0x34);
      puVar20 = &DAT_006c0fdc;
      FUN_006323d0(s_Altitude_____006cd0f4);
      FUN_006321fb(uVar13);
      FUN_006323d0(puVar20);
      FUN_006321fb(uVar12);
      FUN_006323d0(puVar21);
      FUN_006321fb(uVar11);
      FUN_006323d0();
      FUN_006321fb();
      FUN_006323d0();
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
      sVar7 = FUN_00489b59();
      if (sVar7 != -5) {
        *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff50;
        FUN_00461b74(unaff_EBP + -0x10);
        FUN_00489b59();
        goto LAB_00536581;
      }
      iVar9 = extraout_ECX[0x37];
      *(char *)(unaff_EBP + 8) = (char)(*(int *)(unaff_EBP + -0x28) >> 4);
      *(char *)(unaff_EBP + 9) = (char)(*(int *)(unaff_EBP + -0x2c) >> 4);
      *(char *)(unaff_EBP + 10) = (char)iVar9;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      cVar6 = FUN_004672d0(unaff_EBP + 8,unaff_EBP + -0x18,unaff_EBP + -0x30);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      iVar9 = DAT_006e54d8;
      if (cVar6 == '\0') {
LAB_005365a2:
        FUN_006323d0();
      }
      else {
        if (*(int *)(unaff_EBP + -0x20) == 0) {
          iVar10 = 0;
        }
        else {
          iVar10 = ((*(int *)(unaff_EBP + -0x20) - *(int *)(DAT_006e54d8 + 0x84)) - 1U & 3) + 1;
        }
        *(int *)(unaff_EBP + -0x20) = iVar10;
        if (*(int *)(unaff_EBP + -0x14) == 0) {
          iVar9 = 0;
        }
        else {
          iVar9 = ((*(int *)(unaff_EBP + -0x14) - *(int *)(iVar9 + 0x84)) - 1U & 3) + 1;
        }
        *(int *)(unaff_EBP + -0x14) = iVar9;
        if (iVar10 == 0) {
          if (*(int *)(unaff_EBP + -0x18) != 0) goto LAB_005364f4;
LAB_00536515:
          FUN_006323d0();
        }
        else if ((((iVar10 == 1) || (iVar10 == 2)) || (iVar10 == 3)) || (iVar10 == 4)) {
LAB_005364f4:
          FUN_006323d0();
          FUN_00633bc3();
          goto LAB_00536515;
        }
        iVar9 = *(int *)(unaff_EBP + -0x14);
        if (iVar9 == 0) {
          if ((*(int *)(unaff_EBP + -0x18) == 0) && (*(int *)(unaff_EBP + -0x30) != 0)) {
LAB_00536581:
            FUN_006323d0();
            FUN_00633bc3();
            goto LAB_005365a2;
          }
        }
        else if (((iVar9 == 1) || (iVar9 == 2)) || ((iVar9 == 3 || (iVar9 == 4))))
        goto LAB_00536581;
      }
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff50;
      FUN_00461b74(unaff_EBP + -0x10);
      FUN_00486420();
      FUN_006323d0(s_Floor___006cd02c);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0();
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
      cVar6 = FUN_004893e4();
      *(char *)(unaff_EBP + 0xb) = cVar6;
      if (cVar6 != '\0') {
        bVar18 = (*(byte *)(unaff_EBP + 0xb) & 1) != 0;
        if (bVar18) {
          FUN_006323d0();
        }
        if ((*(byte *)(unaff_EBP + 0xb) & 2) != 0) {
          if (bVar18) {
            FUN_006323d0();
          }
          FUN_006323d0();
          bVar18 = true;
        }
        if ((*(byte *)(unaff_EBP + 0xb) & 4) != 0) {
          if (bVar18) {
            FUN_006323d0();
          }
          FUN_006323d0();
          bVar18 = true;
        }
        if ((*(byte *)(unaff_EBP + 0xb) & 0x20) != 0) {
          if (bVar18) {
            FUN_006323d0();
          }
          FUN_006323d0();
        }
      }
      FUN_006323d0();
      iVar9 = extraout_ECX[0x37];
      *(char *)(unaff_EBP + 8) = (char)(*(int *)(unaff_EBP + -0x28) >> 4);
      *(char *)(unaff_EBP + 9) = (char)(*(int *)(unaff_EBP + -0x2c) >> 4);
      *(char *)(unaff_EBP + 10) = (char)iVar9;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar16 = FUN_005890dc();
      *(undefined4 *)(unaff_EBP + 8) = uVar16;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_006323d0();
      switch(*(undefined4 *)(unaff_EBP + 8)) {
      case 0:
        break;
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      case 7:
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 0xb:
      }
      FUN_006323d0();
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
      uVar16 = FUN_00492b33();
      *(undefined4 *)(unaff_EBP + 8) = uVar16;
      if ((short)uVar16 != 0) {
        FUN_006323d0(s_Object_ID___006ccf14);
        FUN_00633bc3();
        FUN_006323d0();
        uVar11 = (uint)*(ushort *)(unaff_EBP + 8);
        iVar9 = *(int *)(*DAT_006e486c + 0x14);
        if (((uVar11 != 0) && (uVar11 < (*(int *)(iVar9 + 0x1c) - *(int *)(iVar9 + 0x18) >> 2) + 1U)
            ) && (*(int *)(*(int *)(iVar9 + 0x18) + -4 + uVar11 * 4) != 0)) {
          FUN_006323d0();
        }
        FUN_006323d0();
      }
      fVar19 = (float10)FUN_0046755a();
      *(float *)(unaff_EBP + 8) = (float)fVar19;
      iVar9 = FUN_006323d0();
      fVar2 = *(float *)(unaff_EBP + 8);
      *(undefined4 *)(iVar9 + 4) = 1;
      FUN_0063332a((double)fVar2);
      FUN_006323d0();
      *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
      FUN_004aef32();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      iVar9 = FUN_004aeea6();
      if (iVar9 == 2) {
        iVar9 = (int)*(char *)(unaff_EBP + -0x24);
        FUN_006323d0(s_Light_Entry__1_____006ccef0);
        FUN_006321fb(iVar9);
        FUN_006323d0();
        FUN_006321fb();
        FUN_006323d0();
        cVar6 = *(char *)(unaff_EBP + -0x22);
        pcVar14 = s_Light_Entry__2_____006ccedc;
LAB_00536915:
        iVar9 = (int)cVar6;
        FUN_006323d0(pcVar14);
        FUN_006321fb(iVar9);
        FUN_006323d0();
        FUN_006321fb();
        FUN_006323d0();
      }
      else {
        iVar9 = FUN_004aeea6();
        if (iVar9 == 1) {
          cVar6 = *(char *)(unaff_EBP + -0x24);
          pcVar14 = s_Light_Entry__1_____006ccef0;
          goto LAB_00536915;
        }
      }
      iVar9 = extraout_ECX[0x37];
      *(char *)(unaff_EBP + -0x1c) = (char)(*(int *)(unaff_EBP + -0x28) >> 4);
      *(char *)(unaff_EBP + -0x1b) = (char)(*(int *)(unaff_EBP + -0x2c) >> 4);
      *(char *)(unaff_EBP + -0x1a) = (char)iVar9;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      cVar6 = FUN_004790bc();
      if (cVar6 != '\0') {
        iVar9 = FUN_004790b8();
        *(undefined1 *)(unaff_EBP + 8) =
             *(undefined1 *)
              (*(int *)(*(int *)(iVar9 + 0x10) + *(char *)(unaff_EBP + -0x1c) * 4) +
              (int)*(char *)(unaff_EBP + -0x1b));
        *(undefined1 *)(unaff_EBP + -4) = 7;
        FUN_00461628();
        FUN_006323d0(s_Water_tile__006ccecc);
        FUN_006321fb();
        FUN_006323d0();
        *(undefined1 *)(unaff_EBP + -4) = 6;
      }
      cVar6 = FUN_004790e8();
      if (cVar6 != '\0') {
        iVar9 = FUN_004790b4();
        *(undefined1 *)(unaff_EBP + -0x20) =
             *(undefined1 *)
              (*(int *)(*(int *)(iVar9 + 0x10) + *(char *)(unaff_EBP + -0x1c) * 4) +
              (int)*(char *)(unaff_EBP + -0x1b));
        *(undefined1 *)(unaff_EBP + -4) = 8;
        FUN_00461628();
        FUN_006323d0(s_Pool_tile__006ccec0);
        FUN_006321fb();
        FUN_006323d0();
        iVar9 = extraout_ECX[0x37];
        iVar10 = extraout_ECX[0x35];
        *(char *)(unaff_EBP + 8) = (char)(extraout_ECX[0x36] >> 4);
        *(char *)(unaff_EBP + 9) = (char)(iVar10 >> 4);
        *(char *)(unaff_EBP + 10) = (char)iVar9;
        *(undefined1 *)(unaff_EBP + -4) = 9;
        FUN_004790b4();
        iVar9 = FUN_00461f92();
        *(undefined1 *)(unaff_EBP + -4) = 8;
        if (iVar9 != 0) {
          FUN_006323d0(s_Overlap_Mask__006cceb0);
          FUN_0063301c();
          FUN_006323d0();
        }
        *(undefined1 *)(unaff_EBP + -4) = 6;
      }
      FUN_00435a8f();
      FUN_006323d0(s_cXObject_WallBlockFlags___006cce94);
      FUN_006321fb();
      FUN_006323d0();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      goto LAB_00536aeb;
    }
    FUN_006323d0();
    *(undefined1 **)(unaff_EBP + 8) = &stack0xffffff54;
    uVar16 = FUN_00489b59();
    *(undefined4 *)(unaff_EBP + 8) = uVar16;
    FUN_006323d0(s_Tile_RoomID___006cd2b8);
    FUN_00633bc3();
    FUN_006323d0();
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*DAT_006e486c + 0x24);
    if ((*(short *)(unaff_EBP + 8) != -5) && (iVar9 = FUN_004670a4(), iVar9 != 0)) {
      FUN_006323d0(s_ID___006c49d8);
      FUN_00633bc3();
      FUN_006323d0();
      FUN_006323d0(s_Area___006cd2a4);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Floored_Area___006cd294);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Object_Cnt___006cd284);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Window_Light___006cd274);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Object_Light___006cd264);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Dirty_Total___006cd254);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Room_Impact___006cd244);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Good_Obj_Cnt___006cd234);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Bed_Cnt___006cd228);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Bath_Obj_Cnt___006cd218);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Wall_Cnt___006cd20c);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Patt_Wall_Cnt___006cd1f8);
      FUN_006321fb();
      FUN_006323d0();
      iVar10 = FUN_006323d0();
      fVar2 = *(float *)(iVar9 + 0x6c);
      *(undefined4 *)(iVar10 + 4) = 1;
      FUN_0063332a((double)fVar2);
      FUN_006323d0();
      iVar10 = FUN_006323d0();
      fVar2 = *(float *)(iVar9 + 0x68);
      *(undefined4 *)(iVar10 + 4) = 1;
      FUN_0063332a((double)fVar2);
      FUN_006323d0();
      FUN_00468851();
      FUN_006323d0(s_IsOutside___006cd1c8);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Overhead_lights_on___006cd1b0);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Wants_roof___006cd1a0);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_Lamp_count___006cd190);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0(s_People_Count___006cd180);
      FUN_006321fb();
      FUN_006323d0();
      FUN_006323d0();
      FUN_004681ec();
      FUN_006323d0(s_GetArea___006cd174);
      FUN_006321fb();
      FUN_006323d0();
      FUN_0046894e();
      FUN_006323d0(s_GetPeopleCount___006cd160);
      FUN_006321fb();
      FUN_006323d0();
      iVar9 = FUN_006323d0();
      fVar19 = (float10)FUN_0045d060();
      *(undefined4 *)(iVar9 + 4) = 1;
      FUN_0063332a((double)fVar19);
    }
  }
  FUN_006323d0();
LAB_00536aeb:
  FUN_00633204();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  pcVar14 = (char *)FUN_00633849();
  if (pcVar14 != (char *)0x0) {
    sVar15 = _strlen(pcVar14);
    pcVar17 = pcVar14 + sVar15;
    for (; pcVar14 < pcVar17; pcVar14 = pcVar14 + *(int *)(unaff_EBP + -0x20)) {
      iVar9 = extraout_ECX[0x38];
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      uVar16 = (**(code **)(*(int *)(&DAT_006f2a74)[iVar9] + 0x60))(pcVar14);
      iVar9 = extraout_ECX[0x38];
      *(undefined4 *)(unaff_EBP + -0x20) = uVar16;
      iVar9 = (**(code **)(*(int *)(&DAT_006f2a74)[iVar9] + 0x68))(pcVar14,uVar16);
      if (*(int *)(unaff_EBP + -0x14) < iVar9) {
        *(int *)(unaff_EBP + -0x14) = iVar9;
      }
    }
    (**(code **)(*(int *)(&DAT_006f2a74)[extraout_ECX[0x38]] + 0x58))();
    FUN_00535b26();
    if (*(char *)(unaff_EBP + 0xc) != '\0') {
      (*(code *)**(undefined4 **)DAT_006e486c[1])
                (unaff_EBP + 0xc,extraout_ECX[0x35],extraout_ECX[0x36],extraout_ECX[0x37]);
      *(short *)(unaff_EBP + 0xc) =
           *(short *)(unaff_EBP + 0xc) +
           ((short)extraout_ECX[0x20] - (short)extraout_ECX[0x22]) + -5;
      FUN_004cb21d();
    }
  }
  FUN_00633849();
  FUN_005d4bbf();
  (**(code **)(*extraout_ECX + 0x168))();
  FUN_00633834();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00633bb0();
  FUN_00632b08();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

