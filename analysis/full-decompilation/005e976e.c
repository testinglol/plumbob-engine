
void __thiscall FUN_005e976e(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0xd4);
  if ((puVar1 != param_2) && (puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 **)(param_1 + 0xd4) = param_2;
  *(int *)(param_1 + 0xd8) = param_3;
  *(undefined4 *)(param_1 + 0xdc) = param_4;
  if (param_2 != (undefined4 *)0x0) {
    if (param_3 == 0) {
      param_3 = param_2[7] - param_2[5];
    }
    else {
      param_3 = (int)(param_2[7] - param_2[5]) / param_3;
    }
    FUN_004ec186(param_3);
    FUN_004ec1a7(*(int *)(*(int *)(param_1 + 0xd4) + 0x20) -
                 *(int *)(*(int *)(param_1 + 0xd4) + 0x18));
  }
  return;
}

