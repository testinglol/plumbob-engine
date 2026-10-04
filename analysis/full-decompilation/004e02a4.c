
void FUN_004e02a4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = param_2;
  iVar4 = *(int *)(param_1 + 0xc);
  iVar6 = *(int *)(param_2 + 0xc);
  iVar5 = 0;
  piVar2 = (int *)(param_1 + 0x10);
  param_2 = 0;
  puVar3 = (uint *)(iVar1 + 0x10);
  param_1 = 0;
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    if (*piVar2 != 0) {
      param_1 = param_1 + 1;
    }
    piVar2 = piVar2 + 1;
  }
  for (; iVar6 != 0; iVar6 = iVar6 + -1) {
    if ((*puVar3 != 0) && (iVar5 = iVar5 + 1, (*puVar3 & 0x100) != 0)) {
      param_2 = param_2 + 1;
    }
    puVar3 = puVar3 + 1;
  }
  FUN_004e066d(param_3,s_Memory_Difference___ldKB_006c8ed0,(iVar5 - param_1) * DAT_006f2218);
  FUN_004e066d(param_3,s_Memory_allocated___uKB_006c8eb4,DAT_006f2218 * iVar5);
  FUN_004e066d(param_3,s_Memory_freed___uKB_006c8e9c,DAT_006f2218 * param_1);
  FUN_004e066d(param_3,s_Private_memory___uKB_Shared_pote_006c8e68,(iVar5 - param_2) * DAT_006f2218,
               DAT_006f2218 * param_2);
  return;
}

