
void __thiscall FUN_005105d2(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  iVar1 = param_1 + param_2 * 0x28;
  iVar4 = *(int *)(param_1 + 0x2c + param_2 * 0x28);
  if ((iVar4 != 0) && (iVar2 = *(int *)(iVar1 + 0x30), iVar2 != 0)) {
    if (iVar4 == 2) {
      cVar3 = (**(code **)(*param_3 + 0x20))(0x10);
      if (cVar3 != '\0') {
        if (*(int *)(iVar1 + 0x38) == 0) {
          local_34 = *(int *)(iVar2 + 0x14);
          local_30 = *(int *)(iVar2 + 0x18);
          local_1c = *(int *)(iVar2 + 0x1c);
          local_28 = *(int *)(iVar2 + 0x20);
        }
        else {
          local_1c = *(int *)(iVar1 + 0x44);
          local_34 = *(int *)(iVar1 + 0x3c);
          local_30 = *(int *)(iVar1 + 0x40);
          local_28 = *(int *)(iVar1 + 0x48);
        }
        local_14 = *param_4;
        local_8 = param_4[1];
        if (local_1c - local_34 < param_4[2] - local_14) {
          local_14 = local_14 + (((param_4[2] - local_1c) - local_14) + local_34) / 2;
        }
        if (local_28 - local_30 < param_4[3] - local_8) {
          local_8 = local_8 + (((param_4[3] - local_8) - local_28) + local_30) / 2;
        }
        local_2c = local_1c;
        local_c = local_14 - local_34;
        local_8 = local_8 - local_30;
        local_24 = local_34;
        local_20 = local_30;
        local_18 = local_28;
        FUN_004ba5ac(&local_c);
        (**(code **)(*param_3 + 0x9c))(iVar2,&local_24,&local_34,0);
        (**(code **)(*param_3 + 0x24))(0x10);
      }
    }
    else if (iVar4 == 1) {
      iVar4 = iVar1 + 0x4c;
      if (*(int *)(iVar1 + 0x4c) == 0) {
        iVar4 = 0;
      }
      FUN_004e5447(iVar2,*(undefined4 *)(iVar1 + 0x34),param_3,param_4,iVar4);
    }
  }
  return;
}

