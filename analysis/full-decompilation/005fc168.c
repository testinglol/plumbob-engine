
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_005fc168(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5)

{
  undefined2 uVar1;
  double dVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_10;
  
  if (0xeff < *(int *)(param_1 + 0xf04)) {
    FUN_005fc3af();
  }
  if (*(int *)(param_1 + 0xf08) == 0) {
    iVar6 = *(int *)(param_1 + 0xf04);
    *(undefined4 *)(param_1 + 0xf08) = 0xf;
    iVar3 = iVar6 + param_1;
    *(uint *)(param_1 + 0xf40) = (uint)(*(byte *)(iVar6 + 4 + param_1) >> 4);
    *(uint *)(param_1 + 0xf44) = (uint)(*(byte *)(iVar3 + 5) >> 4);
    iVar4 = *(int *)(param_1 + 0xf40) * 4;
    *(undefined4 *)(param_1 + 0xf10) = *(undefined4 *)(&DAT_006d7c8c + iVar4);
    *(undefined4 *)(param_1 + 0xf14) = *(undefined4 *)(&DAT_006d7c9c + iVar4);
    iVar4 = *(int *)(param_1 + 0xf44) * 4;
    *(undefined4 *)(param_1 + 0xf18) = *(undefined4 *)(&DAT_006d7c8c + iVar4);
    *(undefined4 *)(param_1 + 0xf1c) = *(undefined4 *)(&DAT_006d7c9c + iVar4);
    *(uint *)(param_1 + 0xf40) = *(byte *)(iVar3 + 4) & 0xf;
    *(uint *)(param_1 + 0xf44) = *(byte *)(iVar3 + 5) & 0xf;
    *(int *)(param_1 + 0xf04) = iVar6 + 2;
    *(undefined4 *)(param_1 + 0xf08) = 0xd;
  }
  dVar2 = _DAT_00673d40;
  uVar5 = (uint)(*(byte *)(param_1 + 4 + *(int *)(param_1 + 0xf04)) >> 4);
  *(uint *)(param_1 + 0xf30) = uVar5;
  *(uint *)(param_1 + 0xf34) = *(byte *)(param_1 + 4 + *(int *)(param_1 + 0xf04)) & 0xf;
  iVar3 = *(int *)(param_1 + 0xf40) * 0x10;
  local_10 = SUB84((double)*(int *)(param_1 + 0xf20) * (double)*(float *)(param_1 + 0xf10) +
                   (double)*(int *)(param_1 + 0xf24) * (double)*(float *)(param_1 + 0xf14) +
                   (double)*(float *)(&DAT_006d7cac + (uVar5 + iVar3) * 4) + dVar2,0);
  iVar6 = local_10 + -0x80000000;
  *(int *)(param_1 + 0xf24) = iVar6;
  local_10 = SUB84((double)*(int *)(param_1 + 0xf20) * (double)*(float *)(param_1 + 0xf14) +
                   (double)iVar6 * (double)*(float *)(param_1 + 0xf10) +
                   (double)*(float *)(&DAT_006d7cac + (iVar3 + *(int *)(param_1 + 0xf34)) * 4) +
                   dVar2,0);
  *(int *)(param_1 + 0xf20) = local_10 + -0x80000000;
  *param_2 = (short)iVar6;
  *param_4 = *(undefined2 *)(param_1 + 0xf20);
  uVar5 = (uint)(*(byte *)(param_1 + 5 + *(int *)(param_1 + 0xf04)) >> 4);
  *(uint *)(param_1 + 0xf38) = uVar5;
  *(uint *)(param_1 + 0xf3c) = *(byte *)(param_1 + 5 + *(int *)(param_1 + 0xf04)) & 0xf;
  iVar3 = *(int *)(param_1 + 0xf44) * 0x10;
  local_10 = SUB84((double)*(int *)(param_1 + 0xf28) * (double)*(float *)(param_1 + 0xf18) +
                   (double)*(int *)(param_1 + 0xf2c) * (double)*(float *)(param_1 + 0xf1c) +
                   (double)*(float *)(&DAT_006d7cac + (uVar5 + iVar3) * 4) + dVar2,0);
  iVar6 = local_10 + -0x80000000;
  *(int *)(param_1 + 0xf2c) = iVar6;
  local_10 = SUB84((double)*(int *)(param_1 + 0xf28) * (double)*(float *)(param_1 + 0xf1c) +
                   (double)iVar6 * (double)*(float *)(param_1 + 0xf18) +
                   (double)*(float *)(&DAT_006d7cac + (iVar3 + *(int *)(param_1 + 0xf3c)) * 4) +
                   dVar2,0);
  *(int *)(param_1 + 0xf28) = local_10 + -0x80000000;
  *param_3 = (short)iVar6;
  uVar1 = *(undefined2 *)(param_1 + 0xf28);
  *param_5 = uVar1;
  *(int *)(param_1 + 0xf04) = *(int *)(param_1 + 0xf04) + 2;
  *(int *)(param_1 + 0xf08) = *(int *)(param_1 + 0xf08) + -2;
  return CONCAT31((int3)(CONCAT22((short)((uint)(local_10 + -0x80000000) >> 0x10),uVar1) >> 8),1);
}

