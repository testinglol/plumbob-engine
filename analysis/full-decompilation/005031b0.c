
void __thiscall FUN_005031b0(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0xe4) = 1;
  *(int **)(param_1 + 0xe0) = param_2;
  uVar1 = (**(code **)(*param_2 + 0x58))();
  FUN_004ec1a7(uVar1);
  return;
}

