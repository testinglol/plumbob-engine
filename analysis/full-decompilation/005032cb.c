
void __thiscall FUN_005032cb(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x10c) == '\0') {
    iVar2 = **(int **)(param_1 + 0xe0);
    uVar1 = FUN_004096c2(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
    iVar2 = (**(code **)(iVar2 + 0x68))(uVar1);
    *param_2 = iVar2 + *(int *)(param_1 + 0xdc) * 0xc;
    iVar2 = **(int **)(param_1 + 0xe0);
    uVar1 = FUN_004096c2(*(int *)(param_1 + 0xf8) - *(int *)(param_1 + 0xf4));
    uVar1 = (**(code **)(iVar2 + 0x68))(uVar1);
    *param_3 = uVar1;
    iVar2 = **(int **)(param_1 + 0xe0);
    uVar1 = FUN_004096c2(*(int *)(param_1 + 0x104) - *(int *)(param_1 + 0x100));
    uVar1 = (**(code **)(iVar2 + 0x68))(uVar1);
    *param_4 = uVar1;
  }
  else {
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
  }
  return;
}

