
void __fastcall FUN_0060c356(int param_1)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int local_c;
  int iStack_8;
  
  local_c = param_1;
  iStack_8 = param_1;
  if (*(int *)(*(int *)(param_1 + 0x38) + 0x24) != *(int *)(param_1 + 0x3c)) {
    FUN_006321f0(*(undefined4 *)(param_1 + 0x40));
    iVar7 = *(int *)(*(int *)(param_1 + 0x38) + 0x24);
    *(int *)(param_1 + 0x3c) = iVar7;
    pvVar3 = operator_new(iVar7 << 2);
    *(void **)(param_1 + 0x40) = pvVar3;
  }
  iVar7 = 0;
  if (*(int *)(param_1 + 0x40) != 0) {
    piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    (**(code **)(*piVar4 + 0xc))(&local_c);
    if (local_c == 7) {
      if (0 < *(int *)(param_1 + 0x3c)) {
        do {
          iVar2 = *(int *)(param_1 + 0x38);
          iVar8 = iVar7 * 4;
          bVar1 = *(byte *)(iVar8 + 0x2a + iVar2);
          if (bVar1 == *(byte *)(iVar8 + iVar2 + 0x2b)) {
            *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar8) = *(undefined4 *)(param_1 + 0x14);
          }
          else {
            uVar5 = FUN_0049a775(CONCAT31((int3)((uint)iVar2 >> 8),bVar1 >> 3));
            *(uint *)(*(int *)(param_1 + 0x40) + iVar8) = uVar5 & 0xffff;
          }
          puVar6 = (uint *)(*(int *)(param_1 + 0x40) + iVar8);
          *puVar6 = *puVar6 | (uint)*(byte *)(iVar8 + 0x2b + *(int *)(param_1 + 0x38)) << 0x10;
          iVar7 = iVar7 + 1;
        } while (iVar7 < *(int *)(param_1 + 0x3c));
      }
    }
    else if (0 < *(int *)(param_1 + 0x3c)) {
      do {
        iVar2 = *(int *)(param_1 + 0x38);
        iVar8 = iVar7 * 4;
        bVar1 = *(byte *)(iVar8 + 0x2a + iVar2);
        if (bVar1 == *(byte *)(iVar8 + iVar2 + 0x2b)) {
          *(undefined4 *)(*(int *)(param_1 + 0x40) + iVar8) = *(undefined4 *)(param_1 + 0x14);
        }
        else {
          uVar5 = FUN_0049a996(CONCAT31((int3)((uint)iVar2 >> 8),bVar1 >> 3));
          *(uint *)(*(int *)(param_1 + 0x40) + iVar8) = uVar5 & 0xffff;
        }
        puVar6 = (uint *)(*(int *)(param_1 + 0x40) + iVar8);
        *puVar6 = *puVar6 | (uint)*(byte *)(iVar8 + 0x2b + *(int *)(param_1 + 0x38)) << 0x10;
        iVar7 = iVar7 + 1;
      } while (iVar7 < *(int *)(param_1 + 0x3c));
    }
  }
  *(undefined1 *)(param_1 + 0x23) = 0;
  return;
}

