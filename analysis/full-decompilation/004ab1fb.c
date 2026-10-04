
void __thiscall FUN_004ab1fb(int param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  if ((*(int *)(param_1 + 0x170) != 0) || (*(int *)(param_1 + 0x174) != 0)) {
    local_10 = -*(int *)(param_1 + 0x170);
    local_18 = *param_2 + local_10;
    local_10 = param_2[2] + local_10;
    local_14 = param_2[1] + -*(int *)(param_1 + 0x174);
    local_c = param_2[3] + -*(int *)(param_1 + 0x174);
    FUN_004a7901();
    local_24 = local_14 + *(int *)(param_1 + 0x174);
    local_20 = local_10 + *(int *)(param_1 + 0x170);
    local_1c = local_c + *(int *)(param_1 + 0x174);
    local_28 = local_18 + *(int *)(param_1 + 0x170);
    if (DAT_006e4870 == '\0') {
      cVar4 = FUN_004b465e();
      if (cVar4 != '\0') {
        puVar1 = (undefined4 *)(param_1 + 0x70 + param_3 * 4);
        cVar4 = (**(code **)(**(int **)(param_1 + 0x70 + param_3 * 4) + 0x20))(0x10);
        if (cVar4 != '\0') {
          local_8 = (int *)*puVar1;
          uVar7 = 0;
          iVar2 = *local_8;
          uVar5 = FUN_005de822(&local_28);
          uVar6 = FUN_005de822(&local_18);
          (**(code **)(iVar2 + 0x9c))(local_8,uVar6,uVar5,uVar7);
          (**(code **)(*(int *)*puVar1 + 0x24))(0x10);
        }
      }
      cVar4 = FUN_004b4665();
      if (cVar4 != '\0') {
        piVar8 = (int *)(param_1 + 0x70 + param_3 * 4);
        cVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0x70 + param_3 * 4) + 0x5c) + 0x20))
                          (0x10);
        if (cVar4 != '\0') {
          uVar7 = 0;
          piVar3 = *(int **)(*piVar8 + 0x5c);
          iVar2 = *piVar3;
          uVar5 = FUN_005de822(&local_28);
          uVar6 = FUN_005de822(&local_18);
          (**(code **)(iVar2 + 0x9c))(piVar3,uVar6,uVar5,uVar7);
          (**(code **)(**(int **)(*piVar8 + 0x5c) + 0x24))(0x10);
        }
      }
      cVar4 = FUN_004b466e();
      if (cVar4 == '\0') {
        return;
      }
      piVar8 = param_2;
      FUN_005cf10c(param_2);
      FUN_005cddcf(piVar8);
    }
    else {
      FUN_005cab71(&local_18,&local_28);
    }
    FUN_004ab376(param_2);
  }
  return;
}

