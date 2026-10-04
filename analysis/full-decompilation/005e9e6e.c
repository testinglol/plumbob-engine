
void __thiscall FUN_005e9e6e(int param_1,undefined4 *param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  if (*(int *)(param_1 + 0xd8) == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
  }
  else {
    cVar2 = (**(code **)(*(int *)(param_1 + 0xd4) + 8))(2);
    if (cVar2 == '\0') {
      iVar6 = **(int **)(param_1 + 0xd8);
      uVar5 = FUN_005d49d6();
      uVar5 = FUN_004096c2(uVar5);
      (**(code **)(iVar6 + 0x50))(&local_18,uVar5);
      *param_2 = local_18;
      param_2[1] = local_14;
      param_2[2] = local_10;
      param_2[3] = local_c;
    }
    else {
      iVar6 = (*(int *)(param_1 + 0x84) + *(int *)(param_1 + 0xdc) * -2) - *(int *)(param_1 + 0x7c);
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      piVar1 = *(int **)(param_1 + 0xd8);
      local_8 = piVar1;
      iVar3 = (**(code **)(*piVar1 + 100))
                        (*(int *)(param_1 + 0x4c),
                         *(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c),iVar6);
      iVar4 = (**(code **)(*piVar1 + 0x58))();
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = iVar6;
      param_2[3] = iVar3 * iVar4;
    }
  }
  return;
}

