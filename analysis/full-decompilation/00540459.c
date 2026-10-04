
void FUN_00540459(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  
  uVar1 = *param_1;
  uVar2 = param_1[1];
  uVar3 = *(undefined2 *)(param_1 + 2);
  uVar4 = *(undefined2 *)(param_1 + 4);
  param_1[1] = param_2[1];
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 4);
  *param_1 = *param_2;
  *(undefined2 *)(param_2 + 4) = uVar4;
  *(undefined2 *)(param_2 + 2) = uVar3;
  param_2[1] = uVar2;
  *param_2 = uVar1;
  return;
}

