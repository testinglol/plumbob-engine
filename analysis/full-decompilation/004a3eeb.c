
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a3eeb(int param_1,undefined4 *param_2)

{
  double dVar1;
  undefined1 uVar2;
  int iVar3;
  ushort *puVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 fVar9;
  int iStack00000008;
  undefined4 local_40 [4];
  float local_30;
  float local_2c;
  double local_28;
  double local_20;
  void *local_18;
  float local_14;
  undefined4 local_10;
  float fStack_c;
  uint local_8;
  
  iVar6 = 0;
  if (*(int *)(param_1 + 0x38) == 0) {
    iVar3 = FUN_004c8f7a(*(int *)(param_1 + 0x10) * 0x100 + -0x100);
    puVar4 = (ushort *)(*(int *)(*(int *)(iVar3 + 0xc) + 0xc) + *(int *)(iVar3 + 0xc));
    *(uint *)(param_1 + 0x38) = (uint)*puVar4;
    *(uint *)(param_1 + 0x3c) = (uint)puVar4[1];
  }
  local_8 = *(uint *)(param_1 + 0x38);
  if ((local_8 & 1) != 0) {
    local_8 = local_8 + 1;
  }
  puVar8 = local_40;
  do {
    iVar3 = FUN_004a3b2c(iVar6);
    iVar6 = iVar6 + 1;
    *puVar8 = *(undefined4 *)(param_1 + 0x18 + iVar3 * 4);
    puVar8 = puVar8 + 1;
  } while (iVar6 < 4);
  pvVar5 = _malloc(*(int *)(param_1 + 0x3c) * *(int *)(param_1 + 0x38));
  iStack00000008 = 0;
  iVar6 = *(int *)(param_1 + 0x40);
  local_18 = pvVar5;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      iVar3 = *(int *)(param_1 + 0x38);
      iVar7 = 0;
      if (0 < iVar3) {
        do {
          if (*(char *)(iVar7 + iVar6) == -1) {
            *(undefined1 *)(iVar3 * iStack00000008 + iVar7 + (int)pvVar5) = 0xff;
          }
          else {
            local_20 = ((double)iVar7 - (double)(int)local_8 * _DAT_00667270) * _DAT_00667270;
            dVar1 = (double)iStack00000008 - (double)*(int *)(param_1 + 0x3c) * _DAT_00667270;
            local_28 = _DAT_00668308 / (double)(int)local_8;
            fVar9 = ((float10)dVar1 + (float10)local_20) * (float10)local_28 +
                    (float10)_DAT_00667270;
            local_14 = (float)(((float10)dVar1 - (float10)local_20) * (float10)local_28 +
                              (float10)_DAT_00667270);
            _local_10 = CONCAT44(local_14,SUB84(dVar1,0));
            if ((float10)_DAT_0066657c <= fVar9) {
              if ((float10)_DAT_00666748 < fVar9) {
                fVar9 = (float10)1;
              }
            }
            else {
              fVar9 = (float10)0;
            }
            if (_DAT_0066657c <= local_14) {
              if (_DAT_00666748 < local_14) {
                local_14 = 1.0;
              }
            }
            else {
              local_14 = 0.0;
            }
            local_30 = (float)fVar9;
            local_2c = local_14;
            FUN_004a40c9(&local_30,local_40);
            uVar2 = __ftol();
            *(undefined1 *)(iStack00000008 * *(int *)(param_1 + 0x38) + iVar7 + (int)local_18) =
                 uVar2;
            pvVar5 = local_18;
          }
          iVar3 = *(int *)(param_1 + 0x38);
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar3);
      }
      iStack00000008 = iStack00000008 + 1;
      iVar6 = iVar6 + *(int *)(param_1 + 0x44);
    } while (iStack00000008 < *(int *)(param_1 + 0x3c));
  }
  param_2[1] = *(undefined4 *)(param_1 + 0x38);
  *param_2 = pvVar5;
  return;
}

