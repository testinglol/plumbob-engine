
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004ca45a(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  tagRECT local_20;
  int local_10;
  int *local_c;
  int local_8;
  
  local_8 = 3 - param_3;
  local_c = (int *)(param_1 + 0x10 + local_8 * 4);
  if (*(int *)(param_1 + 0x10 + local_8 * 4) == 0) {
    iVar3 = *(int *)(param_2 + 4);
    local_20.left = *(int *)(iVar3 + 0x68);
    local_20.top = *(int *)(iVar3 + 0x6c);
    local_20.right = *(LONG *)(iVar3 + 0x70);
    local_20.bottom = *(int *)(iVar3 + 0x74);
    OffsetRect(&local_20,-local_20.left,-local_20.top);
    *(LONG *)(param_1 + 0x28) = (local_20.bottom - local_20.top) * 0xc;
    local_10 = 8 << ((byte)param_3 & 0x1f);
    piVar1 = (int *)(param_1 + 0x1c + local_8 * 4);
    iVar3 = local_10 * 0x100 + 1;
    *piVar1 = iVar3;
    pvVar4 = operator_new((iVar3 + *(int *)(param_1 + 0x28)) * 4);
    piVar2 = local_c;
    *local_c = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      return 0x9b0b0001;
    }
    *local_c = (int)((int)pvVar4 + *piVar1 * 4);
    local_c = (int *)(*(float *)(param_2 + (8 - param_3) * 4) -
                     *(float *)(param_2 + (0x61 - param_3) * 4));
    FUN_00636264(_DAT_00668308);
    FUN_00636264(_DAT_006682f8);
    iVar3 = -*piVar1;
    if (iVar3 < *(int *)(param_1 + 0x28)) {
      do {
        uVar5 = __ftol();
        *(undefined4 *)(*piVar2 + iVar3 * 4) = uVar5;
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x28));
    }
  }
  return 0;
}

