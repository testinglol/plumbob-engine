
void __thiscall FUN_00468ca3(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  uVar3 = *param_2;
  *param_2 = *param_1;
  *param_1 = uVar3;
  uVar3 = param_2[1];
  param_2[1] = param_1[1];
  uVar1 = *(undefined1 *)(param_2 + 2);
  param_1[1] = uVar3;
  uVar2 = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)(param_1 + 2) = uVar1;
  *(undefined1 *)(param_2 + 2) = uVar2;
  return;
}

