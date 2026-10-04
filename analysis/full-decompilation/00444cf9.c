
/* WARNING: Removing unreachable block (ram,0x00444d38) */
/* WARNING: Removing unreachable block (ram,0x004452f0) */
/* WARNING: Removing unreachable block (ram,0x0044520d) */
/* WARNING: Removing unreachable block (ram,0x00444d66) */
/* WARNING: Removing unreachable block (ram,0x00444d7b) */
/* WARNING: Removing unreachable block (ram,0x0044518a) */
/* WARNING: Removing unreachable block (ram,0x004452ff) */

void __thiscall
FUN_00444cf9(int param_1,int *param_2,int *param_3,undefined1 *param_4,undefined1 *param_5,
            undefined1 *param_6,uint *param_7)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  int local_68;
  int local_24;
  
  *param_2 = 0;
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  *param_6 = 0;
  *param_7 = 0;
  bVar4 = false;
  bVar3 = false;
  bVar5 = false;
  bVar6 = false;
  bVar7 = false;
  iVar1 = *(int *)(param_1 + 0x30);
LAB_00444daf:
  local_24 = iVar1;
  if (local_24 == 0) {
    if ((bVar3) && (!bVar4)) {
      bVar3 = false;
    }
    if ((bVar5) && (!bVar4)) {
      bVar5 = false;
    }
    if ((bVar6) && (!bVar4)) {
      bVar6 = false;
    }
    if (bVar6) {
      *param_7 = *param_7 | 8;
    }
    if (bVar3) {
      *param_7 = *param_7 | 0x10;
    }
    if ((bVar5) || (bVar7)) {
      *param_7 = *param_7 | 0x20;
    }
    return;
  }
  iVar1 = *(int *)(local_24 + 0xe0);
  sVar9 = *(short *)(local_24 + 0xc0);
  if (0x3b < sVar9) {
    if (sVar9 < 0x51) {
      if (sVar9 == 0x50) {
        *param_7 = *param_7 | 0x80;
      }
      else if (sVar9 == 0x47) {
LAB_00444f96:
        *param_7 = *param_7 | 1;
      }
      else {
        if (sVar9 == 0x48) goto LAB_00444fa7;
        if (sVar9 == 0x49) {
          *param_7 = *param_7 | 4;
        }
        else {
          if (sVar9 == 0x4a) goto LAB_00444fcf;
          if (sVar9 == 0x4b) {
            bVar3 = true;
          }
          else if (sVar9 == 0x4c) {
            bVar5 = true;
          }
          else if (sVar9 == 0x4d) goto LAB_00444fe1;
        }
      }
    }
    else if (sVar9 == 0x53) {
      *param_7 = *param_7 | 0x400;
    }
    else if (sVar9 == 0x54) {
      *param_7 = *param_7 | 0x100;
    }
    else if (sVar9 == 0x55) {
      *param_7 = *param_7 | 0x200;
    }
    else if (0x5c < sVar9) {
      if (sVar9 < 0x5f) {
        *param_7 = *param_7 | 0x1000;
      }
      else if (sVar9 == 0x5f) {
        *param_7 = *param_7 | 0x800;
      }
      else if (sVar9 == 0x61) {
        bVar7 = true;
      }
    }
    goto LAB_0044504c;
  }
  if (sVar9 < 0x3a) {
    if (sVar9 < 0x1f) {
      if (sVar9 == 0x1e) goto LAB_00444fcf;
      if (sVar9 < 0xb) {
        if (sVar9 == 10) {
          bVar4 = true;
        }
        else if (sVar9 == 1) {
          cVar8 = FUN_00432644();
          if (cVar8 != '\0') {
            *param_4 = 1;
          }
        }
        else {
          if (sVar9 == 4) goto LAB_00444f96;
          if (sVar9 == 9) {
            *param_5 = 1;
          }
        }
      }
      else {
        if (sVar9 == 0x11) goto LAB_00444fcf;
        if (0x14 < sVar9) {
          if (sVar9 < 0x19) goto LAB_00444fcf;
          if ((0x18 < sVar9) && (sVar9 < 0x1b)) goto LAB_00444fa7;
        }
      }
    }
    else if (sVar9 < 0x32) {
      if (sVar9 == 0x31) {
LAB_00444fe1:
        *param_7 = *param_7 | 0x40;
      }
      else if (0x26 < sVar9) {
        if (sVar9 < 0x29) goto LAB_00444fcf;
        if (sVar9 == 0x2b) goto LAB_00444fe1;
        if ((0x2d < sVar9) && (sVar9 < 0x31)) goto LAB_00444f96;
      }
    }
    else if (sVar9 == 0x32) {
LAB_00444fa7:
      *param_7 = *param_7 | 2;
    }
    else if (sVar9 == 0x33) goto LAB_00444fe1;
  }
  else {
LAB_00444fcf:
    bVar6 = true;
  }
LAB_0044504c:
  if ((*(short *)(*(int *)(local_24 + 0x118) + 0x14) != 0) &&
     (iVar10 = FUN_006359f2(local_24,0,&cXObject::RTTI_Type_Descriptor,
                            &cXMTObject::RTTI_Type_Descriptor,0), iVar10 != 0))
  goto code_r0x00445088;
  goto LAB_004450b5;
code_r0x00445088:
  local_68 = iVar10;
  if (*(int *)(iVar10 + 400) != 0) {
    local_68 = *(int *)(iVar10 + 400);
  }
  if (iVar10 == local_68) {
LAB_004450b5:
    if (*(short *)(*(int *)(local_24 + 0x118) + 0x12) != 7) {
      cVar8 = FUN_00432644();
      if (cVar8 != '\0') {
        iVar10 = *(int *)(local_24 + 0x118);
        if ((*(short *)(iVar10 + 0x4e) == 0) && (*(short *)(iVar10 + 0x50) == 0)) {
          if (*(short *)(iVar10 + 0x8a) == 0) {
            bVar2 = false;
          }
          else {
            bVar2 = true;
          }
        }
        else {
          bVar2 = true;
        }
        if ((bVar2) && (uVar11 = FUN_0044530c(local_24 + 0xfc), (uVar11 & 0x20) == 0)) {
          *param_6 = 1;
        }
      }
      cVar8 = FUN_00432644();
      if ((cVar8 == '\0') || (cVar8 = FUN_0043557a(), cVar8 == '\0')) {
        iVar10 = FUN_004573f9();
        sVar9 = *(short *)(*(int *)(iVar10 + 0x60) + 0x8a);
        if ((sVar9 != 0) && (sVar9 != 4)) {
          sVar9 = FUN_00432249();
          *param_3 = *param_3 + (int)sVar9;
        }
      }
      else {
        sVar9 = FUN_00432249();
        *param_2 = *param_2 + (int)sVar9;
      }
    }
  }
  goto LAB_00444daf;
}

