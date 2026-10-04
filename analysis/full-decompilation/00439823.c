
void FUN_00439823(undefined4 *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar1 = *(undefined1 *)((int)param_1 + 5);
  uVar4 = *param_1;
  uVar2 = *(undefined1 *)((int)param_1 + 6);
  uVar3 = *(undefined1 *)(param_1 + 1);
  uVar5 = param_1[3];
  uVar6 = param_1[2];
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)((int)param_1 + 5) = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  *param_2 = uVar4;
  *(undefined1 *)((int)param_2 + 5) = uVar1;
  *(undefined1 *)(param_2 + 1) = uVar3;
  *(undefined1 *)((int)param_2 + 6) = uVar2;
  param_2[2] = uVar6;
  param_2[3] = uVar5;
  return;
}

