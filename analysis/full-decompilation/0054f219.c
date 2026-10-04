
void __thiscall FUN_0054f219(int param_1,int *param_2,int *param_3,int *param_4)

{
  undefined4 uVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  short *psVar8;
  short local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  short *local_c;
  short *local_8;
  
  piVar2 = param_2;
  cVar3 = (**(code **)(**(int **)(param_1 + 0xd8) + 0x20))(0x40);
  if (cVar3 != '\0') {
    cVar3 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x40);
    if (cVar3 == '\0') {
      (**(code **)(**(int **)(param_1 + 0xd8) + 0x24))(0x40);
    }
    else {
      local_14 = param_2[1];
      uVar4 = (**(code **)(**(int **)(param_1 + 0xd8) + 0xd0))();
      uVar4 = uVar4 >> 1;
      uVar5 = (**(code **)(**(int **)(param_1 + 0x5c) + 0xd0))();
      local_18 = (**(code **)(**(int **)(param_1 + 0xd8) + 0xcc))();
      local_18 = local_18 + param_3[1] * uVar4 * 2;
      local_1c = (**(code **)(**(int **)(param_1 + 0xd8) + 0xcc))();
      local_1c = local_1c + param_4[1] * uVar4 * 2;
      iVar6 = (**(code **)(**(int **)(param_1 + 0x5c) + 0xcc))();
      iVar6 = iVar6 + (uVar5 >> 1) * local_14 * 2;
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xd8) + 0x24);
      for (; local_14 < piVar2[3]; local_14 = local_14 + 1) {
        local_10 = *piVar2;
        if (local_10 < piVar2[2]) {
          local_8 = (short *)(local_1c + *param_4 * 2);
          local_c = (short *)(iVar6 + local_10 * 2);
          param_2 = (int *)(local_18 + *param_3 * 2);
          do {
            local_20 = (short)uVar1;
            if (*(short *)param_2 == local_20) {
              if (*(short *)param_2 != *local_8) {
                sVar7 = *local_c;
                psVar8 = (short *)param_2;
LAB_0054f35d:
                *psVar8 = sVar7;
              }
            }
            else if ((*local_8 == local_20) && (*local_8 != *(short *)param_2)) {
              sVar7 = *local_c;
              psVar8 = local_8;
              goto LAB_0054f35d;
            }
            local_10 = local_10 + 1;
            local_c = local_c + 1;
            param_2 = (int *)((int)param_2 + 2);
            local_8 = local_8 + 1;
          } while (local_10 < piVar2[2]);
        }
        local_18 = local_18 + uVar4 * 2;
        local_1c = local_1c + uVar4 * 2;
        iVar6 = iVar6 + (uVar5 >> 1) * 2;
      }
      (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x40);
      (**(code **)(**(int **)(param_1 + 0xd8) + 0x24))(0x40);
    }
  }
  return;
}

