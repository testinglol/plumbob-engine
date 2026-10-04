
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __thiscall FUN_00453181(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  short *psVar1;
  ushort uVar2;
  char cVar3;
  short sVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  bool bVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 local_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = 0;
  uVar2 = (ushort)param_3;
  switch((undefined2)param_2) {
  case 0:
    if (((short)(ushort)param_3 < 0) ||
       (iVar7 = (int)(short)(ushort)param_3, *(int *)(param_1 + 0x30) <= iVar7)) {
      uStack_80 = 6;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_80,&DAT_00698f30);
    }
    iVar6 = *(int *)(param_1 + 0x2c);
    goto LAB_00453a9d;
  case 1:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_a0 = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_a0,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (*(int *)(iVar6 + 0x30) <= (int)(short)(ushort)param_3)) {
      uStack_98 = 6;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_98,&DAT_00698f30);
    }
    iVar7 = (short)(ushort)param_3 * 2;
    local_8 = (uint)*(ushort *)(*(int *)(iVar6 + 0x2c) + iVar7);
    if ((char)param_4 == '\0') break;
    puVar5 = (ushort *)(*(int *)(iVar6 + 0x2c) + iVar7);
    goto LAB_00454215;
  default:
    local_120 = 9;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_120,&DAT_00698f30);
  case 3:
    if (((short)(ushort)param_3 < 0) || (0x47 < (short)(ushort)param_3)) {
      uStack_b8 = 7;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_b8,&DAT_00698f30);
    }
    local_8 = (uint)*(ushort *)(param_1 + 0x4a + (short)(ushort)param_3 * 2);
    if ((char)param_4 != '\0') {
      **(int **)(param_1 + 0x128) = param_1 + 0x4a + (short)(ushort)param_3 * 2;
    }
    if ((ushort)param_3 != 0x19) break;
    sVar4 = *(short *)(param_1 + 0xf0);
    goto LAB_004540ef;
  case 4:
    if (((short)(ushort)param_3 < 0) || (0x47 < (short)(ushort)param_3)) {
      uStack_c8 = 7;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_c8,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_c0 = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_c0,&DAT_00698f30);
    }
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(iVar6 + 0x4a + (short)uVar2 * 2));
    if ((char)param_4 != '\0') {
      **(int **)(param_1 + 0x128) = iVar6 + 0x4a + (short)uVar2 * 2;
    }
    if (uVar2 != 0x19) break;
    sVar4 = *(short *)(iVar6 + 0xf0);
LAB_004540ef:
    FUN_0044578b((int)sVar4);
    break;
  case 6:
    if (((short)(ushort)param_3 < 0) || (0x3f < (short)(ushort)param_3)) {
      uStack_d0 = 0x3f;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_d0,&DAT_00698f30);
    }
    local_8 = (uint)*(ushort *)(*(int *)(DAT_006e486c + 0x1c) + 0x10 + (param_3 & 0xff) * 2);
    if ((ushort)param_3 == 0x24) {
      if ((char)param_4 == '\0') break;
      puVar5 = (ushort *)(*(int *)(DAT_006e486c + 0x1c) + 0x58);
    }
    else {
      if ((ushort)param_3 != 0x22) break;
      puVar5 = (ushort *)(*(int *)(DAT_006e486c + 0x1c) + 0x54);
    }
    goto LAB_00454215;
  case 7:
    local_8 = param_3;
    break;
  case 8:
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_d8 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_d8,&DAT_00698f30);
    }
    goto LAB_004541b4;
  case 9:
    if ((short)(ushort)param_3 < 0) {
LAB_004542df:
      uStack_100 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_100,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    if ((short)(ushort)*(byte *)(iVar6 + 7) <= (short)(ushort)param_3) goto LAB_004542df;
    FUN_004750a6();
    iVar6 = FUN_004752f8();
    goto LAB_00454320;
  case 10:
    if ((ushort)param_3 != 0) {
      uStack_90 = 0xf;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_90,&DAT_00698f30);
    }
    iVar6 = FUN_00475126();
    iVar6 = FUN_00475115(iVar6 + -1);
    puVar5 = (ushort *)(iVar6 + 4);
    goto LAB_00454205;
  case 0xb:
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_f8 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_f8,&DAT_00698f30);
    }
    uVar2 = *(ushort *)(param_1 + 0x3a + (short)(ushort)param_3 * 2);
    if (((short)uVar2 < 0) || (7 < (short)uVar2)) {
      uStack_f0 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_f0,&DAT_00698f30);
    }
LAB_004541b4:
    puVar5 = (ushort *)(param_1 + 0x3a + (short)uVar2 * 2);
    goto LAB_00454205;
  case 0xc:
    if (((short)(ushort)param_3 < 0) ||
       (*(int *)(PTR_DAT_006c436c + 4) <= (int)(short)(ushort)param_3)) {
      uStack_c = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_c,&DAT_00698f30);
    }
    puVar5 = (ushort *)(*(int *)(PTR_DAT_006c436c + 8) + 4 + (short)(ushort)param_3 * 6);
    goto LAB_00454205;
  case 0xd:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_e8 = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_e8,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_e0 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_e0,&DAT_00698f30);
    }
    puVar5 = (ushort *)(iVar6 + 0x3a + (short)(ushort)param_3 * 2);
    goto LAB_00454205;
  case 0xe:
    if (((short)(ushort)param_3 < 0) || (0xf < (short)(ushort)param_3)) {
      uStack_78 = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_78,&DAT_00698f30);
    }
    if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) != 2) {
      uStack_70 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_70,&DAT_00698f30);
    }
    param_2 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor
                           ,0);
    uVar9 = (uint)(short)(ushort)param_3;
    FUN_0045d283(uVar9);
    local_8 = __ftol();
    if ((char)param_4 == '\0') break;
    uVar13 = FUN_0045d291(uVar9);
    **(undefined4 **)(param_1 + 300) = uVar13;
    uVar11 = param_2;
    goto LAB_00453e62;
  case 0xf:
    if (((short)(ushort)param_3 < 0) || (0xf < (short)(ushort)param_3)) {
      uStack_48 = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_48,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_38 = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_38,&DAT_00698f30);
    }
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) != 2) {
      uStack_40 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_40,&DAT_00698f30);
    }
    param_2 = FUN_006359f2(iVar6,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                          );
    uVar9 = (uint)(short)(ushort)param_3;
    FUN_0045d283(uVar9);
    local_8 = __ftol();
    if ((char)param_4 == '\0') break;
    uVar13 = FUN_0045d291(uVar9);
    **(undefined4 **)(param_1 + 300) = uVar13;
    uVar11 = param_2;
    goto LAB_00453e62;
  case 0x10:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_30 = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_30,&DAT_00698f30);
    }
    iVar7 = (int)(short)(ushort)param_3;
    if ((iVar7 < 0) || ((*(int *)(iVar6 + 0x134) - *(int *)(iVar6 + 0x130)) / 0x24 + -1 <= iVar7)) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0x130) + (iVar7 * 9 + 9) * 4;
    }
    if (iVar6 == 0) {
      uStack_28 = 0x1b;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_28,&DAT_00698f30);
    }
    goto LAB_00453b8d;
  case 0x11:
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_68 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_68,&DAT_00698f30);
    }
    param_2 = (uint)(short)(ushort)param_3;
    psVar1 = (short *)(param_1 + 0x3a + param_2 * 2);
    sVar4 = *(short *)(param_1 + 0x3a + param_2 * 2);
    if ((sVar4 < 0) || (0xf < sVar4)) {
      uStack_60 = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_60,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_50 = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_50,&DAT_00698f30);
    }
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) != 2) {
      uStack_58 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_58,&DAT_00698f30);
    }
    param_3 = FUN_006359f2(iVar6,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                          );
    FUN_0045d283((int)*psVar1);
    local_8 = __ftol();
    if ((char)param_4 == '\0') break;
    uVar13 = FUN_0045d291((int)*psVar1);
    **(undefined4 **)(param_1 + 300) = uVar13;
    uVar11 = param_3;
    uVar9 = param_2;
LAB_00453e62:
    FUN_00444890(uVar11,uVar9);
    break;
  case 0x12:
    if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) != 2) {
      uStack_114 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_114,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (iVar6 = param_1, 0xff < (short)(ushort)param_3)) {
      uStack_64 = 0x21;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_64,&DAT_00698f30);
    }
    goto LAB_0045390f;
  case 0x13:
    if (((short)(ushort)param_3 < 0) || (0xff < (short)(ushort)param_3)) {
      uStack_94 = 0x21;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_94,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_8c = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_8c,&DAT_00698f30);
    }
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) != 2) {
      uStack_fc = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_fc,&DAT_00698f30);
    }
LAB_0045390f:
    iVar6 = FUN_006359f2(iVar6,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
    sVar4 = (ushort)param_3;
LAB_0045391b:
    iVar7 = (int)sVar4;
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(iVar6 + 0x58c + iVar7 * 2));
    if ((char)param_4 != '\0') {
      **(int **)(param_1 + 0x128) = iVar6 + 0x58c + iVar7 * 2;
      if ((iVar7 != 0x44) && (iVar7 != 0x4a)) {
        if (iVar7 == 0x4d) {
          FUN_004448e6(iVar6);
          break;
        }
        if (iVar7 == 0x51) {
          FUN_004449a2(iVar6);
          break;
        }
        if (iVar7 != 0x54) {
          if ((iVar7 < 2) || (7 < iVar7)) {
            if ((iVar7 < 9) || (0x12 < iVar7)) {
              if ((0xc < iVar7) &&
                 (((((iVar7 < 0xf || (iVar7 == 0x10)) || (iVar7 == 0x14)) || (iVar7 == 0x1a)) ||
                  ((0x2d < iVar7 && (iVar7 < 0x38)))))) {
                FUN_00444890(iVar6,iVar7);
              }
            }
            else {
              FUN_00444890(iVar6,iVar7);
            }
          }
          else {
            FUN_00444890(iVar6,iVar7);
          }
          break;
        }
      }
      FUN_00458278(1);
      FUN_004cee86(0x20000000);
    }
    break;
  case 0x14:
    iVar6 = (int)(short)(ushort)param_3;
    if ((iVar6 < 0) ||
       ((*(int *)(param_1 + 0x134) - *(int *)(param_1 + 0x130)) / 0x24 + -1 <= iVar6)) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(param_1 + 0x130) + (iVar6 * 9 + 9) * 4;
    }
    if (iVar6 == 0) {
      uStack_20 = 0x1b;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_20,&DAT_00698f30);
    }
LAB_00453b8d:
    local_8 = (uint)*(ushort *)(iVar6 + 0x10);
    break;
  case 0x15:
    if (0x6b < (ushort)param_3) {
      uStack_bc = 0x23;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_bc,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_5c = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_5c,&DAT_00698f30);
    }
    iVar6 = *(int *)(iVar6 + 0x118);
    goto LAB_00454395;
  case 0x16:
    if (((short)(ushort)param_3 < 0) ||
       (iVar6 = FUN_004750a6(), (short)(ushort)*(byte *)(iVar6 + 7) <= (short)uVar2)) {
      uStack_54 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_54,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    if ((short)(ushort)*(byte *)(iVar6 + 7) <= (short)uVar2) break;
    FUN_004750a6();
    iVar6 = FUN_004752f8();
    sVar4 = *(short *)(iVar6 + (short)uVar2 * 2);
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_4c = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_4c,&DAT_00698f30);
    }
    iVar7 = (int)sVar4;
    if (*(int *)(iVar6 + 0x30) <= iVar7) {
      uStack_ec = 6;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_ec,&DAT_00698f30);
    }
    iVar6 = *(int *)(iVar6 + 0x2c);
    goto LAB_004535f9;
  case 0x17:
    sVar4 = *(short *)(param_1 + 0x3a);
    if ((ushort)param_3 == 0) {
      if (sVar4 != -5) {
        iVar6 = FUN_004670a4(sVar4);
        if (iVar6 == 0) {
          uStack_b4 = 0x28;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(&uStack_b4,&DAT_00698f30);
        }
        FUN_004689a1();
        local_8 = __ftol();
        break;
      }
    }
    else {
      if ((ushort)param_3 == 1) {
        if (sVar4 == -5) {
          local_8 = 1;
          break;
        }
        iVar6 = FUN_004670a4(sVar4);
        if (iVar6 == 0) {
          uStack_44 = 0x28;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(&uStack_44,&DAT_00698f30);
        }
        cVar3 = FUN_00468851();
        bVar10 = cVar3 != '\0';
        goto LAB_00453502;
      }
      if ((ushort)param_3 == 2) {
        if (sVar4 != -5) {
          iVar6 = FUN_004670a4(sVar4);
          if (iVar6 == 0) {
            uStack_104 = 0x28;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&uStack_104,&DAT_00698f30);
          }
          local_8 = FUN_00468838();
          break;
        }
      }
      else {
        if ((ushort)param_3 != 3) {
          uStack_ac = 0x29;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(&uStack_ac,&DAT_00698f30);
        }
        if (sVar4 != -5) {
          iVar6 = FUN_004670a4(sVar4);
          if (iVar6 == 0) {
            uStack_3c = 0x28;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(&uStack_3c,&DAT_00698f30);
          }
          local_8 = FUN_004681ec();
          break;
        }
      }
    }
    local_8 = 0;
    break;
  case 0x18:
    if ((char)param_4 == '\0') {
      uVar13 = 0;
    }
    else {
      uVar13 = *(undefined4 *)(param_1 + 0x128);
    }
    uVar11 = param_3;
    iVar6 = FUN_004750a6(param_3,uVar13);
    local_8 = FUN_00425ba7(*(undefined2 *)(iVar6 + 4),uVar11,uVar13);
    break;
  case 0x19:
    if ((short)(ushort)param_3 < 0) {
LAB_00454329:
      uStack_108 = 8;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_108,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    if ((short)(ushort)*(byte *)(iVar6 + 6) <= (short)(ushort)param_3) goto LAB_00454329;
    FUN_004750a6();
    iVar6 = FUN_004752fc();
LAB_00454320:
    iVar7 = (int)(short)(ushort)param_3;
    goto LAB_004535f9;
  case 0x1a:
    cVar3 = FUN_00481542(param_3,&param_4,&param_2);
    if (cVar3 == '\0') {
      uStack_34 = 0x2e;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_34,&DAT_00698f30);
    }
    uVar12 = 1;
    uVar13 = param_4;
    FUN_004750a6(param_4,1);
    puVar5 = (ushort *)FUN_0040235e(uVar13,uVar12);
    if (puVar5 == (ushort *)0x0) {
      uStack_2c = 0x2e;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_2c,&DAT_00698f30);
    }
    if (((int)param_2 < 0) || ((int)(*puVar5 & 0x7fff) <= (int)param_2)) {
      uStack_e4 = 0x2e;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_e4,&DAT_00698f30);
    }
    local_8 = (uint)puVar5[param_2 + 1];
    break;
  case 0x1b:
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_a4 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_a4,&DAT_00698f30);
    }
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_24 = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_24,&DAT_00698f30);
    }
    sVar4 = *(short *)(param_1 + 0x3a + (short)(ushort)param_3 * 2);
    if ((sVar4 < 0) || (*(short *)(iVar6 + 0x38) <= sVar4)) {
      uStack_11c = 0x31;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_11c,&DAT_00698f30);
    }
    iVar6 = *(int *)(iVar6 + 0x34);
    iVar7 = (int)sVar4;
    goto LAB_004535f9;
  case 0x1c:
    if (((short)(ushort)param_3 < 0) ||
       (*(int *)(PTR_DAT_006c436c + 4) <= (int)(short)(ushort)param_3)) {
      uStack_10 = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_10,&DAT_00698f30);
    }
    iVar6 = *(int *)(PTR_DAT_006c436c + 8);
    iVar7 = (short)(ushort)param_3 * 3;
LAB_00453a9d:
    puVar5 = (ushort *)(iVar6 + iVar7 * 2);
    goto LAB_00454205;
  case 0x1d:
    if (((short)(ushort)param_3 < 0) ||
       (*(int *)(PTR_DAT_006c436c + 4) <= (int)(short)(ushort)param_3)) {
      uStack_18 = 0x1a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_18,&DAT_00698f30);
    }
    puVar5 = (ushort *)(*(int *)(PTR_DAT_006c436c + 8) + 2 + (short)(ushort)param_3 * 6);
    goto LAB_00454205;
  case 0x1e:
    if (*(short *)(*(int *)(param_1 + 0x118) + 0x12) != 2) {
      uStack_c4 = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_c4,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_f4 = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_f4,&DAT_00698f30);
    }
    sVar4 = *(short *)(param_1 + 0x3a + (short)(ushort)param_3 * 2);
    if ((sVar4 < 0) || (iVar6 = param_1, 0xff < sVar4)) {
      uStack_6c = 0x21;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_6c,&DAT_00698f30);
    }
    goto LAB_0045372d;
  case 0x1f:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_74 = 0x15;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_74,&DAT_00698f30);
    }
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) != 2) {
      uStack_cc = 0x1c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_cc,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (7 < (short)(ushort)param_3)) {
      uStack_10c = 2;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_10c,&DAT_00698f30);
    }
    sVar4 = *(short *)(param_1 + 0x3a + (short)(ushort)param_3 * 2);
    if ((sVar4 < 0) || (0xff < sVar4)) {
      uStack_7c = 0x21;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_7c,&DAT_00698f30);
    }
LAB_0045372d:
    iVar6 = FUN_006359f2(iVar6,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0);
    goto LAB_0045391b;
  case 0x20:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_0042573e((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_84 = 0x37;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_84,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (0xff < (short)(ushort)param_3)) {
      uStack_d4 = 0x21;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_d4,&DAT_00698f30);
    }
    local_8 = (uint)*(ushort *)(iVar6 + 0x74 + (short)(ushort)param_3 * 2);
    break;
  case 0x21:
    sVar4 = *(short *)(param_1 + 0x3a);
    sVar8 = *(short *)(param_1 + 0x3c);
    iVar6 = FUN_00404ccb((int)sVar4);
    if (iVar6 == 0) {
      uStack_9c = 0x39;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_9c,&DAT_00698f30);
    }
    if (sVar4 == -1) {
      sVar8 = 0;
    }
    cVar3 = FUN_00403647((int)sVar8,(int)(short)(ushort)param_3,&local_8);
    if (cVar3 == '\0') {
      uStack_1c = 0x3a;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_1c,&DAT_00698f30);
    }
    break;
  case 0x22:
    if (((short)(ushort)param_3 < 1) || (0xf < (short)(ushort)param_3)) {
      uStack_14 = 0x3c;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_14,&DAT_00698f30);
    }
    local_8 = (uint)*(ushort *)(*(int *)(DAT_006e486c + 0x24) + 0x128 + (short)(ushort)param_3 * 2);
    break;
  case 0x23:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_dc = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_dc,&DAT_00698f30);
    }
    FUN_00457da4();
    sVar4 = FUN_004561a0((int)(short)(ushort)param_3);
    bVar10 = sVar4 != 0;
LAB_00453502:
    local_8 = (uint)bVar10;
    break;
  case 0x24:
    if ((short)(ushort)param_3 < 0) {
LAB_00453eda:
      uStack_88 = 0x40;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_88,&DAT_00698f30);
    }
    param_2 = (uint)(short)(ushort)param_3;
    iVar6 = FUN_00458001();
    if (iVar6 <= (int)param_2) goto LAB_00453eda;
    goto LAB_00453fec;
  case 0x25:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_00407498((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_b0 = 10;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_b0,&DAT_00698f30);
    }
    if ((short)(ushort)param_3 < 0) {
LAB_00453ffb:
      uStack_a8 = 0x40;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_a8,&DAT_00698f30);
    }
    param_2 = (uint)(short)(ushort)param_3;
    iVar6 = FUN_00458001();
    if (iVar6 <= (int)param_2) goto LAB_00453ffb;
LAB_00453fec:
    iVar6 = FUN_00458026();
    iVar7 = param_2;
LAB_004535f9:
    puVar5 = (ushort *)(iVar6 + iVar7 * 2);
LAB_00454205:
    local_8 = (uint)*puVar5;
    if ((char)param_4 != '\0') {
LAB_00454215:
      **(int **)(param_1 + 0x128) = (int)puVar5;
    }
    break;
  case 0x26:
    iVar6 = FUN_004750a6();
    iVar6 = FUN_0042573e((int)*(short *)(iVar6 + 4));
    if (iVar6 == 0) {
      uStack_110 = 0x37;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_110,&DAT_00698f30);
    }
    if (((short)(ushort)param_3 < 0) || (0x6b < (ushort)param_3)) {
      uStack_118 = 0x23;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&uStack_118,&DAT_00698f30);
    }
    iVar6 = *(int *)(*(int *)(iVar6 + 8) + 0x60);
LAB_00454395:
    local_8 = (uint)*(ushort *)(iVar6 + (short)(ushort)param_3 * 2);
  }
  return local_8 & 0xffff;
}

