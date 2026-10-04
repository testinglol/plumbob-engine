
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_005fc013(int param_1,undefined2 *param_2,undefined2 *param_3)

{
  byte bVar1;
  undefined2 uVar2;
  int iVar3;
  double dVar4;
  uint uVar5;
  int local_c;
  
  if (0xeff < *(int *)(param_1 + 0xf04)) {
    FUN_005fc3af();
  }
  if (*(int *)(param_1 + 0xf08) == 0) {
    iVar3 = *(int *)(param_1 + 0xf04);
    *(undefined4 *)(param_1 + 0xf08) = 0xf;
    uVar5 = (uint)(*(byte *)(iVar3 + 4 + param_1) >> 4);
    *(uint *)(param_1 + 0xf40) = uVar5;
    *(undefined4 *)(param_1 + 0xf10) = *(undefined4 *)(&DAT_006d7c8c + uVar5 * 4);
    *(undefined4 *)(param_1 + 0xf14) = *(undefined4 *)(&DAT_006d7c9c + uVar5 * 4);
    bVar1 = *(byte *)(iVar3 + 4 + param_1);
    *(undefined4 *)(param_1 + 0xf08) = 0xe;
    *(uint *)(param_1 + 0xf40) = bVar1 & 0xf;
    *(int *)(param_1 + 0xf04) = iVar3 + 1;
  }
  dVar4 = _DAT_00673d40;
  iVar3 = *(int *)(param_1 + 0xf04);
  *(uint *)(param_1 + 0xf30) = (uint)(*(byte *)(iVar3 + 4 + param_1) >> 4);
  *(uint *)(param_1 + 0xf34) = *(byte *)(iVar3 + 4 + param_1) & 0xf;
  local_c = SUB84((double)*(int *)(param_1 + 0xf20) * (double)*(float *)(param_1 + 0xf10) +
                  (double)*(int *)(param_1 + 0xf24) * (double)*(float *)(param_1 + 0xf14) +
                  (double)*(float *)(&DAT_006d7cac +
                                    (*(int *)(param_1 + 0xf40) * 0x10 + *(int *)(param_1 + 0xf30)) *
                                    4) + dVar4,0);
  *(int *)(param_1 + 0xf24) = local_c + -0x80000000;
  local_c = SUB84((double)*(int *)(param_1 + 0xf20) * (double)*(float *)(param_1 + 0xf14) +
                  (double)(local_c + -0x80000000) * (double)*(float *)(param_1 + 0xf10) +
                  (double)*(float *)(&DAT_006d7cac +
                                    (*(int *)(param_1 + 0xf40) * 0x10 + *(int *)(param_1 + 0xf34)) *
                                    4) + dVar4,0);
  *(int *)(param_1 + 0xf08) = *(int *)(param_1 + 0xf08) + -1;
  *(int *)(param_1 + 0xf20) = local_c + -0x80000000;
  *(int *)(param_1 + 0xf04) = iVar3 + 1;
  *param_2 = *(undefined2 *)(param_1 + 0xf24);
  uVar2 = *(undefined2 *)(param_1 + 0xf20);
  *param_3 = uVar2;
  return CONCAT31((int3)(CONCAT22((short)((uint)(iVar3 + 1) >> 0x10),uVar2) >> 8),1);
}

