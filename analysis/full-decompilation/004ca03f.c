
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ca03f(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  float10 fVar7;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_c = -param_3 + 3;
  *(undefined1 *)(-param_3 + 0x93 + param_1) = 1;
  if (*(int *)(param_1 + 4 + local_c * 4) == 0) {
    iVar2 = *(int *)(param_2 + 4);
    local_1c.left = *(int *)(iVar2 + 0x68);
    local_1c.top = *(int *)(iVar2 + 0x6c);
    local_1c.right = *(int *)(iVar2 + 0x70);
    local_1c.bottom = *(LONG *)(iVar2 + 0x74);
    OffsetRect(&local_1c,-local_1c.left,-local_1c.top);
    fVar7 = (float10)FUN_00636264();
    iVar2 = local_c;
    local_8 = local_1c.right - local_1c.left;
    fVar7 = (fVar7 / (float10)(0x10 << ((byte)param_3 & 0x1f))) * (float10)local_8;
    *(float *)(param_1 + 0x54 + local_c * 4) = (float)fVar7;
    fVar7 = fVar7 * (float10)DAT_00668988;
    *(float *)(param_1 + 0x54 + local_c * 4) = (float)fVar7;
    *(float *)(param_1 + 0x60 + local_c * 4) =
         (float)(fVar7 / ((float10)*(float *)(*(int *)(param_2 + 4) + 0x18) /
                         (float10)*(float *)(*(int *)(param_2 + 4) + 0x1c)));
    FUN_004ca342(param_2,param_3);
    FUN_004ca45a(param_2,param_3);
    uVar6 = FUN_004ca1d3(param_2,param_3);
    FUN_004ca589(param_2,param_3);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x6c) = 0xe8;
      *(undefined4 *)(param_1 + 0x78) = 0x17;
    }
    else if (iVar2 == 1) {
      *(undefined4 *)(param_1 + 0x70) = 0x74;
      *(undefined4 *)(param_1 + 0x7c) = 0xc;
    }
    else if (iVar2 == 2) {
      *(undefined4 *)(param_1 + 0x74) = 0x3a;
      *(undefined4 *)(param_1 + 0x80) = 6;
    }
    uVar5 = _DAT_00668308;
    psVar3 = *(short **)(param_1 + 4 + iVar2 * 4);
    *(int *)(param_1 + 0x84 + iVar2 * 4) =
         ((int)psVar3[*(int *)(param_1 + 0x6c + iVar2 * 4)] - (int)*psVar3) + -0x41;
    FUN_00636264(uVar5);
    FUN_00636264(_DAT_006682f8);
    FUN_00636264(_DAT_006682f8);
    FUN_00636264(_DAT_00668308);
    uVar4 = _DAT_00666578;
    puVar1 = (undefined4 *)(param_1 + 0x94 + iVar2 * 0xc);
    *puVar1 = _DAT_00666578;
    puVar1[2] = uVar4;
    puVar1[1] = 0x4114cee5;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}

