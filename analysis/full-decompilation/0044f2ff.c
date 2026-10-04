
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0044f2ff(int param_1,int param_2,short *param_3)

{
  byte bVar1;
  short sVar2;
  short *psVar3;
  short sVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  ushort uVar9;
  int iVar8;
  ushort extraout_var;
  undefined2 extraout_var_00;
  bool bVar10;
  float10 fVar11;
  int iStack_18;
  float fStack_14;
  int iStack_10;
  undefined4 uStack_8;
  
  psVar3 = param_3;
  switch(*param_3) {
  case 0:
    param_3 = (short *)0x1f;
    uStack_8 = 0x12;
    break;
  case 1:
    param_3 = (short *)0x20;
    uStack_8 = 0x13;
    break;
  case 2:
    param_3 = (short *)0x21;
    uStack_8 = 0x14;
    break;
  case 3:
    param_3 = (short *)0x24;
    uStack_8 = 0x15;
    break;
  default:
    goto LAB_0044f678;
  case 6:
    param_3 = (short *)0x25;
    uStack_8 = 0x18;
    break;
  case 7:
    param_3 = (short *)0x26;
    uStack_8 = 0x19;
    break;
  case 8:
    iVar5 = FUN_006359f2(param_1,0,&cXObject::RTTI_Type_Descriptor,&cXPerson::RTTI_Type_Descriptor,0
                        );
    if (iVar5 == 0) {
      return 0;
    }
    if (1 < *(short *)(iVar5 + 0x60e)) {
      return 0;
    }
    param_3 = (short *)0xffffffff;
    uStack_8 = 0x1a;
    break;
  case 10:
    param_3 = (short *)0x3d;
    uStack_8 = 0xe;
    break;
  case 0xb:
    param_3 = (short *)0x27;
    uStack_8 = 0x1c;
    break;
  case 0xc:
    param_3 = (short *)0x40;
    uStack_8 = 0x10;
    break;
  case 0xd:
    param_3 = (short *)0x41;
    uStack_8 = 0x11;
    break;
  case 0xe:
    param_3 = (short *)0xf;
    uStack_8 = 0x1d;
    break;
  case 0xf:
    param_3 = (short *)0xffffffff;
  }
  fStack_14 = 0.0;
  iStack_18 = 0;
  iStack_10 = 0;
  sVar2 = 0;
  if ((*(byte *)(psVar3 + 3) & 8) != 0) {
    sVar4 = FUN_00453181(psVar3[2],psVar3[1],0);
    iStack_10 = FUN_00407498((int)sVar4);
    if (iStack_10 == 0) {
      param_3 = (short *)0x17;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(&param_3,&DAT_00698f30);
    }
  }
  if ((*(byte *)(psVar3 + 3) & 4) != 0) {
    if ((*(byte *)(psVar3 + 3) & 8) == 0) {
      sVar2 = *(short *)(param_1 + 0x84);
    }
    else {
      sVar2 = *(short *)(iStack_10 + 0x84);
    }
  }
  iVar5 = *(int *)(*(short **)(param_1 + 0xdc) + 0x18);
  psVar6 = *(short **)(param_1 + 0xdc);
  if (iVar5 != 0) {
    do {
      psVar7 = psVar6;
      if (*(short *)(iVar5 + 0x7c) < 1) {
        psVar7 = (short *)0x0;
        if ((*(ushort *)(iVar5 + 0x5a) & 0x200) == 0) {
          bVar1 = *(byte *)(psVar3 + 3);
          psVar7 = (short *)0x0;
          uVar9 = (ushort)((uint)psVar6 >> 0x19);
          if ((bVar1 & 1) == 0) {
            if ((bVar1 & 2) == 0) {
              if ((bVar1 & 4) != 0) {
                psVar7 = (short *)0x0;
                bVar10 = *(short *)(iVar5 + 0x84) == sVar2;
code_r0x0044f53c:
                if (!bVar10) goto code_r0x0044f650;
              }
            }
            else {
              psVar7 = (short *)CONCAT22(uVar9,*(short *)(iVar5 + 0x84));
              if (*(short *)(iVar5 + 0x84) == -5) goto code_r0x0044f650;
              iVar8 = FUN_004670a4(psVar7);
              psVar7 = (short *)0x0;
              if (iVar8 != 0) {
                psVar7 = (short *)FUN_00468851();
                bVar10 = (char)psVar7 == '\0';
                goto code_r0x0044f53c;
              }
            }
          }
          else {
            psVar7 = (short *)CONCAT22(uVar9,*(short *)(iVar5 + 0x84));
            if (*(short *)(iVar5 + 0x84) != -5) {
              iVar8 = FUN_004670a4(psVar7);
              psVar7 = (short *)0x0;
              if ((iVar8 != 0) && (psVar7 = (short *)FUN_00468851(), (char)psVar7 == '\0'))
              goto code_r0x0044f650;
            }
          }
          if (*psVar3 == 0xf) {
            if (*(short *)(iVar5 + 0xc0) == 4) {
              *(undefined2 *)(param_1 + 0xce) = 0x32;
code_r0x0044f5e6:
              sVar4 = *(short *)(param_1 + 0xce);
              fVar11 = (float10)FUN_004341ed(iVar5);
              if (((float10)_DAT_00666748 < fVar11) && (*psVar3 == 0xb)) {
                fVar11 = fVar11 * (float10)_DAT_00666578;
              }
              fVar11 = (float10)(int)sVar4 - (float10)_DAT_006c4384 * fVar11;
              if (fVar11 < (float10)_DAT_00666748) {
                fVar11 = (float10)1;
              }
              psVar7 = (short *)((uint)extraout_var << 0x10);
              if ((float10)fStack_14 < fVar11) {
                fStack_14 = (float)fVar11;
                iStack_18 = iVar5;
              }
            }
          }
          else {
            FUN_00457da4();
            psVar7 = (short *)FUN_004561c2(uStack_8);
            if ((psVar7 != (short *)0x0) && (*psVar7 != 0)) {
              if (param_3 == (short *)0xffffffff) {
                *(undefined2 *)(param_1 + 0xce) = 0x32;
              }
              else {
                sVar4 = *(short *)(iVar5 + 0x4a + (int)param_3 * 2);
                *(short *)(param_1 + 0xce) = sVar4;
                if (sVar4 == 0) goto code_r0x0044f650;
              }
              if ((psVar7[1] == 0) ||
                 ((psVar7 = (short *)FUN_00474b22(*(undefined4 *)(*(int *)(iVar5 + 0x11c) + 0xc),
                                                  *(undefined2 *)(iVar5 + 0xf0),
                                                  CONCAT22(extraout_var_00,psVar7[1]),0),
                  (char)psVar7 != '\0' && (*(short *)(param_1 + 0xce) != 0))))
              goto code_r0x0044f5e6;
            }
          }
        }
      }
code_r0x0044f650:
      iVar5 = *(int *)(iVar5 + 0xe0);
      psVar6 = psVar7;
    } while (iVar5 != 0);
    if (iStack_18 != 0) {
      *(undefined2 *)(param_2 + 4) = *(undefined2 *)(iStack_18 + 0xf0);
      return 1;
    }
  }
LAB_0044f678:
  return 0;
}

